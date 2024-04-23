#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define INITIAL_SIZE 7
#define MAX_LEN_FILE_STR 255
#define ENVIRONMENT_VALUE_CHILD "CHILD_PATH"
#define NAME_BUTTON 2
#define NAME_PROGRAM 0
#define PATH_ENVIRONMENT_FILE 1

int compare(const void* a, const void* b);
bool get_variables(const char* path, char*** buffer);

bool find_child_path_envp(char** envp, char** path_child);
void increment_child_xx(char** file_name);