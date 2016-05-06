#ifndef _SYSCFG_H_
#define _SYSCFG_H_

#define SYSCFG_SZ (32 * (1024))       /* max file size - 32kb */

#define NS_SEP "::"
#define NS_SEP_SZ 2

#define ERR_INVALID_PARAM     -1
#define ERR_NOT_INITIALIZED   -2
#define ERR_MEM_ALLOC         -3
#define ERR_INVALID_STATE     -4
#define ERR_SEMAPHORE_INIT    -5
#define ERR_NO_SPACE          -6
#define ERR_ENTRY_TOO_BIG     -7
#define ERR_SHM_CREATE        -10
#define ERR_SHM_INIT          -11
#define ERR_SHM_NO_FILE       -12
#define ERR_SHM_ATTACH        -13
#define ERR_SHM_FAILURE       -14
#define ERR_IO_FAILURE        -20
#define ERR_IO_FILE_OPEN      -21
#define ERR_IO_FILE_STAT      -22
#define ERR_IO_FILE_TOO_BIG   -23
#define ERR_IO_FILE_WRITE     -24
#define ERR_IO_MTD_OPEN       -30
#define ERR_IO_MTD_GETINFO    -31
#define ERR_IO_MTD_INVALID    -32
#define ERR_IO_MTD_BAD_MAGIC  -33
#define ERR_IO_MTD_BAD_SZ     -34
#define ERR_IO_MTD_ERASE      -35
#define ERR_IO_MTD_READ       -36
#define ERR_IO_MTD_WRITE      -37

/*
 * Procedure     : memdata_create
 * Purpose       : Create memdata shared memory and load entries from persistent storage
 * Parameters    :   
 *   file - filesystem 'file' where memdata is stored
 *   mtd_device - raw /dev/mtdX device where memdata is stored
 * Return Values :
 *    0              - success
 *    ERR_INVALID_PARAM - invalid arguments
 *    ERR_IO_FAILURE - memdata file unavailable
 * Notes         :
 *    When both file and mtd_device specified, file based storage takes
 *    precedence. This should be called early in system bootup
 */
int memdata_create(const char *file, long int max_file_sz, const char *mtd_device);

/*
 * Procedure     : memdata_init
 * Purpose       : Initialization to attach current process to memdata
 *                 shared memory based context
 * Parameters    :   
 * Return Values :
 *    0              - success
 *    ERR_INVALID_PARAM - invalid arguments
 *    ERR_IO_FAILURE - memdata file unavailable
 * Notes         :
 *    When both file and mtd_device specified, file based storage takes
 *    precedence 
 */
int memdata_init();

/*
 * Procedure     : memdata_destroy
 * Purpose       : Destroy memdata shared memory context
 * Parameters    :   
 *   None
 * Return Values :
 *    0              - success
 *    ERR_INVALID_PARAM - invalid arguments
 *    ERR_IO_FAILURE - memdata file unavailable
 * Notes         :
 *   memdata destroy should happen only during system shutdown.
 *   *NEVER* call this API in any other scenario!!
 */
void memdata_destroy();

/*
 * Procedure     : memdata_get
 * Purpose       : Retrieve an entry from memdata
 * Parameters    :   
 *   ns  -  namespace string (optional)
 *   name  - name string, entry to add
 *   out_val  - buffer to store output value string
 *   outbufsz  - output buffer size
 * Return Values :
 *    0 on success, -1 on error
 */
int memdata_get(const char *ns, const char *name, char *out_value, int outbufsz);

/*
 * Procedure     : memdata_getall
 * Purpose       : Retrieve all entries from memdata
 * Parameters    :   
 *   buf  -  output buffer to store memdata entries
 *   bufsz  - size of output buffer
 *   outsz  - number of bytes return into given buffer
 * Return Values :
 *    0       - on success
 *    ERR_xxx - various errors codes dependening on the failure
 * Notes         :
 *    useful for clients to dump the whole memdata data
 */
int memdata_getall(char *buf, int count, int *outsz);

/*
 * Procedure     : memdata_set
 * Purpose       : Adds an entry to memdata
 * Parameters    :   
 *   ns  -  namespace string (optional)
 *   name  - name string, entry to add
 *   value  - value string to associate with name
 * Return Values :
 *    0 - success
 *    ERR_xxx - various errors codes dependening on the failure
 * Notes         :
 *    Only changes memdata hash table, persistent store contents
 *    not changed until 'commit' operation
 */
int memdata_set(const char *ns, const char *name, const char *value);

/*
 * Procedure     : memdata_unset
 * Purpose       : Remove an entry from memdata
 * Parameters    :   
 *   ns  -  namespace string (optional)
 *   name  - name string, entry to remove
 * Return Values :
 *    0 - success
 *    ERR_xxx - various errors codes dependening on the failure
 * Notes         :
 *    Only changes memdata hash table, persistent store contents
 *    not changed until 'commit' operation
 */
int memdata_unset(const char *ns, const char *name);

/*
 * Procedure     : memdata_commit
 * Purpose       : commits current stats of memdata hash table data
 *                 to persistent store
 * Parameters    :   
 *   None
 * Return Values :
 *    0 - success
 *    ERR_IO_xxx - various IO errors dependening on the failure
 * Notes         :
 *    WARNING: will overwrite persistent store
 *    Persistent store location specified during memdata_create() is cached 
 *    in memdata shared memory and used as the target for commit
 */
int memdata_commit();

/*
 * Procedure     : memdata_get_encrypt
 * Purpose       : Retrieve an encrypted entry from memdata
 * Parameters    :   
 *   ns  -  namespace string (optional)
 *   name  - name string, entry to add
 *   out_val  - buffer to store decrypted output value string
 *   outbufsz  - output buffer size
 * Return Values :
 *    0 on success, -1 on error
 * Notes: 
 *   Use this only for retrieving values set using set_encrypt method
 */
int memdata_get_encrypt (const char *ns, const char *name, char *out_val, int outbufsz);

/*
 * Procedure     : memdata_set_encrypt
 * Purpose       : Adds an entry to memdata in encrypted form
 * Parameters    :   
 *   ns  -  namespace string (optional)
 *   name  - name string, entry to add
 *   value  - value string to associate with name
 * Return Values :
 *    0 - success
 *    ERR_xxx - various errors codes dependening on the failure
 * Notes         :
 *    Should use memdata_get_encrypt to get back the original string
 *    Only changes memdata hash table, persistent store contents
 *    not changed until 'commit' operation
 *    When committed, only the encrypted value is stored in the system
 */
int memdata_set_encrypt (const char *ns, const char *name, const char *value);

/*
 * Procedure     : memdata_is_match
 * Purpose       : Compare the value of an entry from memdata 
 * Parameters    :   
 *   ns  -  namespace string (optional)
 *   name  - name string, entry to add
 *   out_val  - buffer to store output value string
 *   outbufsz  - output buffer size
 * Return Values :
 *    0 on success, -1 on error
 */
int memdata_is_match (const char *ns, const char *name, char *value, unsigned int *out_match);

/*
 * Procedure     : memdata_getsz
 * Purpose       : Get current & maximum peristent storage size 
 *                 of memdata content
 * Parameters    : 
 *                 used_sz - return buffer of used size
 *                 max_sz - return buffer of max size
 * Return Values :
 *    0 - success
 *    ERR_xxx - various errors codes dependening on the failure
 */
int memdata_getsz (long int *used_sz, long int *max_sz);

/*
 * Procedure     : memdata_commit
 * Purpose       : commits current stats of memdata hash table data
 *                 to persistent store
 * Parameters    :   
 *   None
 * Return Values :
 *    0 - success
 *    ERR_IO_xxx - various IO errors dependening on the failure
 * Notes         :
 *    WARNING: will overwrite persistent store
 *    Persistent store location specified during memdata_create() is cached 
 *    in memdata shared memory and used as the target for commit
 */
char *memdata_parse(const char *str, char **name, char **value);

/*
 * Procedure     : memdata_format
 * Purpose       : SYSCFG persistent storage format
 * Parameters    :
 *   mtd_device - raw /dev/mtdX device where memdata is stored
 *   file - filesystem 'file' to seed memdata values (optional)
 * Return Values :
 *    0              - success
 *    ERR_INVALID_PARAM - invalid arguments
 *    ERR_IO_FAILURE - memdata file unavailable
 * Notes :
 *    WARNING: will overwrite persistent store
 *    seed file is optional, without it only the mtd header is placed
 *    at the beginning of mtd device
 */
int memdata_format (const char *mtd_device, const char *seed_file);

/*
 * Procedure     : memdata_check
 * Purpose       : Checks if given flash partition is valid memdata partition
 * Parameters    :   
 *   mtd_device  - flash mtd partition (like /dev/mtd3)
 * Return Values :
 *    0 - valid memdata partition
 *    ERR... - error/invalid memdata partition
 * Notes         :
 */
int memdata_check (const char *mtd_device);

#endif /* _SYSCFG_H_ */
