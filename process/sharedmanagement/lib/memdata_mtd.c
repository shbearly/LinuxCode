#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <errno.h>
#include "memdata.h"

#define SYSCFG_MTD_MAGIC     0xDADEBEEF

/*
 * Current version 0.1
 */
#define SYSCFG_MTD_VERSION_MAJOR 0
#define SYSCFG_MTD_VERSION_MINOR 1

/*
 * memdata mtd header placed at the beginning of mtd region
 */
typedef struct {
    int  magic;
    int  size;         // size of valid contents within mtd-device excluding this header
    uint version;
} memdata_mtd_hdr_t;

#define SYSCFG_TMP_FILE_PREFIX "/tmp/.memdata.tmp"

extern int commit_to_file (const char *fname);
extern int load_from_file (const char *fname);


/*
 * Write file into mtd-device after a memdata mtd header
 * If file is NULL, just place the memdata mtd header
 *
 * As of now this routine handles NAND and NOR flash types 
 * (and MTD_RAM for testing)
 * The whole flash region is erased before writing
 * A small memdata_mtd header is placed at the beginning 
 * of the mtd region. It contains metadata like memdata 
 * mtd size, this is used while reading off this space
 */
int mtd_write_from_file (const char *mtd_device, const char *file)
{
    int in_fd = 0, mtd_fd = 0, rc, content_size = 0;

    return rc;
}

int mtd_read_to_file (const char *mtd_device, const char *file)
{
    int mtd_fd = 0, out_fd = 0, rc = 0;

    return rc;
}

/*
 *  Returns
 *   0 - valid memdata mtd header
 *   rc - failure code, invalid memdata mdr header
 */
int mtd_hdr_check (const char *mtd_device)
{
    int mtd_fd = 0, rc = 0;

    return rc;
}

int mtd_get_hdrsize ()
{
    return sizeof(memdata_mtd_hdr_t);
}

long int mtd_get_devicesize ()
{
    return (64);
}

/*
 * Loading memdata data from flash device
 *
 * This is a two step process. First memdata data is
 * read from flash and written to temporary filesystem 
 * based file (excluding any sycfg mtd metadata).
 * Then regular file based memdata parsing is done
 * on the temp file to initialize/populate the hash table
 */
int load_from_mtd (const char *mtd_device)
{
    int rc = 0;
    char tmpfile[32];

    return rc;
}


/*
 * Commit memdata data to flash device
 *
 * This is a two step process. First memdata data is
 * written to filesystem file (using tmp file)
 * and this file is written to flash device along with
 * some metadata (memdata mtd header)
 */
int commit_to_mtd (const char *mtd_device)
{
    char tmpfile[32];
    int rc = 0;

    return rc;
}

