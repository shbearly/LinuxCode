#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/memdata.h"

typedef enum {
    CMD_GET,
    CMD_SET,
    CMD_UNSET,
    CMD_COMMIT,
    CMD_GETENCRYPT,
    CMD_SETENCRYPT,
    CMD_ISMATCH,
    CMD_SHOW,
    CMD_DESTROY,
    CMD_UNKNOWN,
} cmd_t;

static inline void memdata_format_usage()
{
    printf("Usage: memdata_format -d mtd-device [-f file] \n");
}

static inline void memdata_create_usage()
{
    printf("Usage: memdata_create {-f file | -d mtd-device} \n");
}

static inline void memdata_usage()
{
    printf("Usage: memdata [show | set [ns] name value | get [ns] name | unset [ns] name | \n       setenncrypt [ns] name value | getencrypt [ns] name | \n       ismatch [ns] name value | commit]\n");
}

static void print_check_error(int rc, const char *mtd_device)
{
    if (0 == rc) {
        return;
    }
    switch (rc) {
    case ERR_IO_MTD_BAD_MAGIC:
        fprintf(stderr, "Error: mtd device %s not a valid memdata store\n", mtd_device);
        break; 
    case ERR_IO_MTD_INVALID:
        fprintf(stderr, "Error: %s not a valid flash partition\n", mtd_device);
        break; 
    case ERR_IO_MTD_BAD_SZ:
        fprintf(stderr, "Error: %s has invalid memdata mtd size\n", mtd_device);
        break; 
    case ERR_IO_MTD_OPEN:
    case ERR_IO_MTD_GETINFO:
    case ERR_IO_MTD_READ:
        fprintf(stderr, "Error: accessing flash partition %s\n", mtd_device);
        break; 
    }
}

static void print_format_error(int rc, const char *mtd_device, const char *seed_file)
{
    if (0 == rc) {
        return;
    }
    switch (rc) {
    case ERR_IO_MTD_BAD_MAGIC:
        fprintf(stderr, "Error: mtd device %s not a valid memdata store\n", mtd_device);
        break; 
    case ERR_IO_FILE_TOO_BIG:
        fprintf(stderr, "Error: seed file too big to fit flash parition\n");
        break; 
    case ERR_IO_MTD_INVALID:
        fprintf(stderr, "Error: %s not a valid flash partition\n", mtd_device);
        break; 
    case ERR_IO_MTD_BAD_SZ:
        fprintf(stderr, "Error: %s has invalid memdata mtd size\n", mtd_device);
        break; 
    case ERR_IO_MTD_OPEN:
    case ERR_IO_MTD_GETINFO:
    case ERR_IO_MTD_WRITE:
    case ERR_IO_MTD_ERASE:
        fprintf(stderr, "Error: formating flash partition %s\n", mtd_device);
        break; 
    case ERR_IO_FILE_OPEN:
    case ERR_IO_FILE_STAT:
        if (seed_file) {
            fprintf(stderr, "Error: reading seed file %s\n", seed_file);
        } else {
            fprintf(stderr, "Error: internal error handling tmp file\n");
        }
        break; 
    }
}

static void print_commit_error (int rc)
{
    if (0 == rc) {
        return;
    }
    switch (rc) {
    case ERR_IO_MTD_BAD_MAGIC:
        fprintf(stderr, "Error: mtd device not a valid memdata store\n");
        break; 
    case ERR_IO_FILE_TOO_BIG:
        fprintf(stderr, "Error: memdata contents too big to fit flash parition\n");
        break; 
    case ERR_IO_MTD_INVALID:
        fprintf(stderr, "Error: not a valid flash partition\n");
        break; 
    case ERR_IO_MTD_OPEN:
    case ERR_IO_MTD_GETINFO:
    case ERR_IO_MTD_WRITE:
    case ERR_IO_MTD_ERASE:
        fprintf(stderr, "Error: commiting to flash partition\n");
        break; 
    case ERR_IO_FILE_OPEN:
    case ERR_IO_FILE_STAT:
        fprintf(stderr, "Error: internal error handling tmp file\n");
        break; 
    }
}

static int get_cmd (const char *cmdstr) 
{
    if (!cmdstr) {
        return CMD_UNKNOWN;
    }

    if (0 == strcasecmp(cmdstr, "get"))         { return CMD_GET; }
    if (0 == strcasecmp(cmdstr, "ismatch"))     { return CMD_ISMATCH; }
    if (0 == strcasecmp(cmdstr, "getencrypt"))  { return CMD_GETENCRYPT; }
    if (0 == strcasecmp(cmdstr, "set"))         { return CMD_SET; }
    if (0 == strcasecmp(cmdstr, "unset"))       { return CMD_UNSET; }
    if (0 == strcasecmp(cmdstr, "setencrypt"))  { return CMD_SETENCRYPT; }
    if (0 == strcasecmp(cmdstr, "commit"))      { return CMD_COMMIT; }
    if (0 == strcasecmp(cmdstr, "show"))        { return CMD_SHOW; }
    if (0 == strcasecmp(cmdstr, "destroy"))     { return CMD_DESTROY; }

    return CMD_UNKNOWN;
}

/*
 * Return
 *    0 -- Success
 *    1 -- Failure
 */
int main(int argc, char **argv)
{
    int rc = 0;
    char *program;


    program = strrchr(argv[0], '/');
    program = program ? program+1 : argv[0];

    if (0 == strcmp(program, "memdata_check")) {
        if (argc < 3) {
            printf("Usage: memdata_check -d mtd-device \n");
            return 1;
        }

        if (0 == strcasecmp(argv[1], "-d")) {
            char *mtd_device = NULL;
            mtd_device = argv[2];
            rc = memdata_check(mtd_device);
            print_check_error(rc, mtd_device);
            return rc;
        } 
    }

    if (0 == strcmp(program, "memdata_format")) {
        if (argc < 3) {
            goto format_fail;
        }

        char *seed_file = NULL, *mtd_device = NULL;
        if (0 != strcasecmp(argv[1], "-d")) {
            goto format_fail;
        }
        mtd_device = argv[2];

        if (argc > 3) {
            if (0 != strcasecmp(argv[3], "-f")) {
                goto format_fail;
            } 
            seed_file = argv[4];
        } 
        rc = memdata_format(mtd_device, seed_file);
        print_format_error(rc, mtd_device, seed_file);
        return rc;
    format_fail:
        memdata_format_usage();
        return 1;
    }

    if (0 == strcmp(program, "memdata_create")) {
        if (argc < 3) {
            memdata_create_usage();
            return 1;
        }
        if (0 == strcasecmp(argv[1], "-f")) {
            rc = memdata_create(argv[2], 0, NULL);
        } else if (0 == strcasecmp(argv[1], "-d")) {
            rc = memdata_create(NULL, 0, argv[2]);
        } else {
            memdata_create_usage();
            return 1;
        } 
        return rc;
    }

    if (0 == strcmp(program, "memdata_destroy")) {
        printf("WARNING!!! Are your sure you want to destroy system configuration?\n This will cause the system to be unstable. Press CTRL-C to abort or ENTER to proceed.\n");
        getchar();
        rc = memdata_init();
        if (rc != 0) {
            printf("ERROR: memdata initialization failure (%d)\n", rc);
            return 1;
        }
        memdata_destroy();
        return rc;
    }

    if (argc < 2) {
        memdata_usage();
        return 1;
    } 
    rc = memdata_init();
    if (rc != 0) {
        printf("ERROR: memdata init (%d)", rc);
        return 1;
    }

   argc -= 1;
   char **cmd = argv+1;
   char *name = NULL, *value = NULL, *ns = NULL;

   cmd_t cmdtype = get_cmd(cmd[0]);
   switch (cmdtype) {
   case CMD_GET:
   case CMD_GETENCRYPT:
       if (argc < 2) {
           memdata_usage();
           return 1;
       }
       char val[512] = {0};
       if (argc > 2) {  // namespace
           ns = cmd[1];
           name = cmd[2];
       } else {
           name = cmd[1];
       }
       // scripts rely on the output of get so don't give a error message
       if (CMD_GET == cmdtype) {
           rc = memdata_get(ns, name, val, sizeof(val));
       } else {
           rc = memdata_get_encrypt(ns, name, val, sizeof(val));
       }
       if (0 == rc) {
           puts(val);
       } else {
           puts("");
       }
       break;

   case CMD_SET:
   case CMD_SETENCRYPT:
       if (argc < 3) {
           memdata_usage();
           return 1;
       }
       if (argc > 3) { // namespace specified
           ns = cmd[1];
           name = cmd[2];
           value = cmd[3];
       } else {
           name = cmd[1];
           value = cmd[2];
       }
       if (CMD_SET == cmdtype) {
           rc = memdata_set(ns, name, value);
       } else {
           rc = memdata_set_encrypt(ns, name, value);
       }
       if (0 == rc) {
           // printf("success\n");
           // memdata_commit();   -- implicit commit
       } else {
           printf("Error. code=%d\n", rc);
       }
       return rc;

   case CMD_ISMATCH:
       if (argc < 3) {
           memdata_usage();
           return 1;
       }
       if (argc > 3) { // namespace specified
           ns = cmd[1];
           name = cmd[2];
           value = cmd[3];
       } else {
           name = cmd[1];
           value = cmd[2];
       }
       unsigned int out_match = 1;
       rc = memdata_is_match(ns, name, value, &out_match);
       if (0 == rc) {
           // printf("success\n");
           // memdata_commit();   -- implicit commit
       } else {
           printf("Error. code=%d\n", rc);
       }
       return out_match;

   case CMD_UNSET:
       if (argc < 2) {
           memdata_usage();
           return 1;
       }
       if (argc > 2) {  // namespace specified
           ns = cmd[1];
           name = cmd[2];
       } else {
           name = cmd[1];
       }
       rc = memdata_unset(ns, name);
       if (0 == rc) {
           // printf("success\n");
           // memdata_commit();   // implicit commit
       } else {
           // printf("Error. code=%d\n", rc);
       }
       return rc;
   case CMD_COMMIT:
       rc = memdata_commit();
       print_commit_error(rc);
       return rc;
   case CMD_DESTROY:
       printf("WARNING!!! Are you sure you want to do this?\nPress CTRL-C to abort or ENTER to proceed\n");
       memdata_destroy();
       break;
   case CMD_SHOW:
       {
       int len, sz;
       char *buf;
       buf = malloc(SYSCFG_SZ);
       if (buf) {
           if (0 == memdata_getall(buf, SYSCFG_SZ, &sz)) {
               char *p = buf;
               while(sz > 0) {
                   len = printf("%s",p);
                   printf("\n");
                   p = p + len + 1;
                   sz -= len + 1;
               }
           } else {
               printf("No entries\n");
           }
           free(buf);
       }
       long int used_sz = 0, max_sz = 0;
       memdata_getsz(&used_sz, &max_sz);
       printf("Used: %ld of %ld\n", used_sz, max_sz);
       }
       break;
   default:
       memdata_usage(); 
   }
   return 0;
}
