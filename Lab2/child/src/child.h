#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/param.h>
#include <unistd.h>

#define NAME_PROGRAM 0
#define PATH_ENVIRONMENT_FILE 1
#define NAME_BUTTON 2
#define INITIAL_SIZE 7
#define MAX_LEN_FILE_STR 255

bool get_variables(const char* path, char*** buffer);
bool find_child_path_envp(char** envp, const char* name_variable);