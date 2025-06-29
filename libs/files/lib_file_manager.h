#ifndef CLIBS_LIB_FILE_MANAGER_H
#define CLIBS_LIB_FILE_MANAGER_H

/**
 * Path to file
 */
typedef struct {
    char* path;
} CManagerFile;

typedef struct FileNode {
    char path[4096];
    struct CFileNode *next;
} CFileNode;

typedef struct {
    CFileNode *head;
    CFileNode *current;
} CFileIterator;

void cfile_scan_recursive(const char *dirpath, CFileIterator *it);
int __next_file(CFileIterator *it, CManagerFile *out);
void cfile_free_iterator(CFileIterator *it);

/**
 * forEach of all files in directory
 */
#define cfilesForEach(var, start_dir)                                     \
    FileIterator __it = {0};                                             \
    scan_recursive(start_dir, &__it);                                    \
    ManagerFile var;                                                     \
    for (; __next_file(&__it, &var); )

/**
 * Free iterator after `cfilesForEach`
 */
#define cfilesForEachEnd() free_iterator(&__it)

/**
 * Create directory if it doesnt exists
 * @param file CManagerFile
 * @return int
 */
int cfile_create_directory_if_not_exists(CManagerFile file);

/**
 * Read file content
 * @param file CManagerFile
 * @return char* text of file
 */
char* cfile_read(CManagerFile file);

/**
 * Create file if it doesnt exists
 * @param file CManagerFile
 * @return int
 */
int cfile_create_if_not_exists(CManagerFile file);

/**
 * Overwrite file content
 * @param file CManagerFile
 * @param text char* new text
 * @return int
 */
int cfile_overwrite(CManagerFile file, char* text);

/**
 * Add text to file
 * @param file CManagerFile
 * @param text char* text
 * @return int
 */
int cfile_add_text(CManagerFile file, char* text);

/**
 * Delete file
 * @param file CManagerFile
 * @return int
 */
int cfile_delete(CManagerFile file);

#endif //CLIBS_LIB_FILE_MANAGER_H
