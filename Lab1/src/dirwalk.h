#ifndef DIRWALK_H
#define DIRWALK_H
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>
#include <locale.h>
#include <stdbool.h>
#include <dirent.h>

enum OPTIONS {
    IS_REG = 0,
    IS_LNK = 1,
    IS_DIR = 2,
    IS_SORT = 3,
    IS_ALL_OPT = 4
};

#define COUNT_OPTIONS 5
#define CURRENT_DIR "."
#define RELOAD_OPTIND optind = 1
#define FIND_PATH_DIR while (getopt(argc, argv, "ldfs") != -1) { }

bool DOES_THE_FILE_EXIST(const char *path)
{
    DIR *d;
    if ((d = opendir(path)) == NULL)
        return false;
    closedir(d);
    return true;
}
bool DOES_THE_FILE_EXIST(const char *path);
void dirwalk(char *path, const bool options[], char ***arr, size_t *arr_size, size_t *capacity);
int compare(const void *first, const void *second);
void alloc_memory_and_copy(char ***arr, size_t *arr_size, size_t *capacity, const char *fullpath);

#endif /* DIRWALK_H */
