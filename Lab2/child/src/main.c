#include "child.h"

int main(int argc, char* argv[], char* envp[]) {
    printf("NAME PROGRAM: %s\n", argv[NAME_PROGRAM]);
    printf("PID PROGRAM: %d\n", getpid());
    printf("PPID PROGRAM: %d\n", getppid());
    char** array_variables = (char**)calloc(INITIAL_SIZE, sizeof(char*));
    if (get_variables(argv[PATH_ENVIRONMENT_FILE], &array_variables)){
        if (strcmp(argv[NAME_BUTTON], "+") == 0) {
            for (size_t i = 0; i < INITIAL_SIZE; ++i) {
                    printf("%s\n", getenv(array_variables[i]));
            }
        }
        else if (strcmp(argv[NAME_BUTTON], "*") == 0) {
            for(size_t i = 0; i < INITIAL_SIZE; ++i)
                find_child_path_envp(envp, array_variables[i]);
        }
        else if (strcmp(argv[NAME_BUTTON], "&") == 0) {
            for(size_t i = 0; i < INITIAL_SIZE; ++i)
                find_child_path_envp(__environ, array_variables[i]);
        }
    }
    for (size_t i = 0; i < INITIAL_SIZE; ++i)
        free(array_variables[i]);
    free(array_variables);
    return 0;
}
