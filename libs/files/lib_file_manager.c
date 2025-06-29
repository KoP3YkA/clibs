#include <malloc.h>
#include "stdio.h"
#include <stdlib.h>
#include <fileapi.h>
#include <errhandlingapi.h>
#include <winerror.h>
#include <dirent.h>
#include <sys/stat.h>
#include "lib_file_manager.h"

void cfile_push(CFileIterator *it, const char *path) {
    CFileNode *node = malloc(sizeof(CFileNode));
    strncpy(node->path, path, sizeof(node->path));
    node->next = NULL;
    if (!it->head) {
        it->head = it->current = node;
    } else {
        CFileNode *p = it->head;
        while (p->next) p = p->next;
        p->next = node;
    }
}

void cfile_scan_recursive(const char *dirpath, CFileIterator *it) {
    DIR *dir = opendir(dirpath);
    if (!dir) return;

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        if (strcmp(entry->d_name, "node_modules") == 0)
            continue;

        char fullpath[4096];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", dirpath, entry->d_name);

        struct stat st;
        if (stat(fullpath, &st) == -1)
            continue;

        if (S_ISDIR(st.st_mode)) {
            cfile_scan_recursive(fullpath, it);
        } else if (S_ISREG(st.st_mode)) {
            const char *ext = strrchr(entry->d_name, '.');
            if (ext && (strcmp(ext, ".ts") == 0 || strcmp(ext, ".js") == 0)) {
                cfile_push(it, fullpath);
            }
        }
    }

    closedir(dir);
}

int __next_file(CFileIterator *it, CManagerFile *out) {
    if (!it->current) return 0;
    out->path = it->current->path;
    it->current = it->current->next;
    return 1;
}

void cfile_free_iterator(CFileIterator *it) {
    CFileNode *n = it->head;
    while (n) {
        CFileNode *tmp = n;
        n = n->next;
        free(tmp);
    }
    it->head = it->current = NULL;
}

char* cfile_read(CManagerFile file) {
    FILE *readFile = fopen(file.path, "r");
    if (readFile == NULL) {
        return NULL;
    }

    fseek(readFile, 0, SEEK_END);
    long filesize = ftell(readFile);
    rewind(readFile);

    char *buffer = malloc(filesize + 1);
    if (!buffer) {
        fclose(readFile);
        return NULL;
    }

    size_t read_size = fread(buffer, 1, filesize, readFile);
    buffer[read_size] = '\0';

    fclose(readFile);
    return buffer;
}

int cfile_create_directory_if_not_exists(CManagerFile file) {
    if (CreateDirectory(file.path, NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        return 0;
    }
    return 1;
}

int cfile_create_if_not_exists(CManagerFile file) {
    FILE *newFile = fopen(file.path, "w");
    if (!newFile) return 1;
    fclose(newFile);
    return 0;
}

int cfile_overwrite(CManagerFile file, char* text) {
    FILE *newFile = fopen(file.path, "w");
    if (!newFile) return 1;
    fprintf(newFile, "%s", text);
    fclose(newFile);
    return 0;
}

int cfile_add_text(CManagerFile file, char* text) {
    FILE *newFile = fopen(file.path, "a");
    if (!newFile) return 1;
    fprintf(newFile, "%s", text);
    fclose(newFile);
    return 0;
}

int cfile_delete(CManagerFile file) {
    if (DeleteFileA(file.path)) return 0;
    else return 1;
}