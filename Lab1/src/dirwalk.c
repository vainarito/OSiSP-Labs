
#include "dirwalk.h"
int compare(const void *first, const void *second)
{
    return strcoll(*(char **)first, *(char **)second);
}

void alloc_memory_and_copy(char ***arr, size_t *arr_size, size_t *capacity, const char *fullpath)
{
    if (*arr_size + 1 == *capacity)
    {
        *capacity *= 2;
        *arr = (char **)realloc(*arr, *capacity * sizeof(char *));
    }
    int len_path = strlen(fullpath) + 1;
    (*arr)[*arr_size] = (char *)malloc(len_path);
    strncpy((*arr)[(*arr_size)++], fullpath, len_path);
}

void dirwalk(char *path, const bool options[], char ***arr, size_t *arr_size, size_t *capacity)
{
    if (!path)
        return;
    struct dirent *dir;
    struct stat sb;
    DIR *d = opendir(path);
    while ((dir = readdir(d)))
    {
        char fullpath[MAXPATHLEN];
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;
        sprintf(fullpath, "%s/%s", path, dir->d_name);
        if (lstat(fullpath, &sb) == -1){
            continue;
        }
        if ((sb.st_mode & __S_IFMT) == __S_IFDIR)
            {
        if (options[IS_DIR] || options[IS_ALL_OPT])
                alloc_memory_and_copy(arr, arr_size, capacity, fullpath);
            dirwalk(fullpath, options, arr, arr_size, capacity);
        }
        else if ((sb.st_mode & __S_IFMT) == __S_IFLNK && (options[IS_LNK] || options[IS_ALL_OPT]))
            alloc_memory_and_copy(arr, arr_size, capacity, fullpath);
        else if ((sb.st_mode & __S_IFMT) == __S_IFREG && (options[IS_REG] || options[IS_ALL_OPT]))
            alloc_memory_and_copy(arr, arr_size, capacity, fullpath);
    }
    closedir(d);
}
