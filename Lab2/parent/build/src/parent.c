#include "parent.h"
int compare(const void* a, const void* b) {
    return strcoll((const char*)a, (const char*)b);
}
bool get_variables(const char* path, char*** buffer) {
    FILE* file = NULL;
    if ((file = fopen(path, "r")) != NULL) {
        size_t ind = 0;
        size_t cnt = INITIAL_SIZE;
        while(cnt--) {
            (*buffer)[ind] = (char*)realloc((*buffer)[ind], (MAX_LEN_FILE_STR + 1) * sizeof(char));
            fscanf(file, "%s", (*buffer)[ind++]);
        }
        fclose(file);
        return true;
    }
    perror("File error");
    return false;
}
bool find_child_path_envp(char** envp, char** path_фффффффhild) {
    size_t ind = 0;
    size_t len = strlen(ENVIRONMENT_VALUE_CHILD);
    bool flag_find = false;
    while(envp[ind]) {
        flag_find = true;
        for (size_t i = 0; i < len; ++i) {
            if (envp[ind][i] != ENVIRONMENT_VALUE_CHILD[i]) {
                flag_find = false;
                break;
            }
        }
        if (flag_find == true)
            break;
        ind++;
    }
    if (flag_find == false) return false;
    printf("%s\n", envp[ind]);
    size_t path_len = strlen(ENVIRONMENT_VALUE_CHILD);
    size_t find_str_len = strlen(envp[ind]);
    *path_child = (char*)malloc(find_str_len - (path_len+1) + 1);
    size_t j = 0;
    for (size_t i = path_len + 1; i < find_str_len; ++i) {
        (*path_child)[j++] = envp[ind][i];
    }
    path_child[ind] = '\0';
    return true;
}
void increment_child_xx(char** file_name) {
    //child_00
    if ((*file_name)[7] == '9') {
        (*file_name)[7] = '0';
        (*file_name)[6]++;
        return;
    }
    (*file_name)[7]++;
}