#include "child.h"
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

bool find_child_path_envp(char** envp, const char* name_variable) {
    size_t ind = 0;
    size_t len = strlen(name_variable);
    bool flag_find = false;
    while(envp[ind]) {
        flag_find = true;
        for (size_t i = 0; i < len; ++i) {
            if (envp[ind][i] != name_variable[i]) {
                flag_find = false;
                break;
            }
        }
        if (flag_find == true)
            break;
        ind++;
    }
    if (flag_find == false) return false;
    size_t path_len = strlen(name_variable);
    size_t find_str_len = strlen(envp[ind]);
    for (size_t i = path_len + 1; i < find_str_len; ++i) {
        printf("%c", envp[ind][i]);
    }
    printf("\n");
    return true;
}

