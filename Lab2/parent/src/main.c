#include "parent.h"
int main(int argc, char* argv[], char* envp[]) {
    setlocale(LC_COLLATE, "C");
    if (argc == 2) {
        char* path = argv[PATH_ENVIRONMENT_FILE];
        char** array_variables = (char**)calloc(INITIAL_SIZE, sizeof(char*));
        bool flag_alloc_memory = false;
        if(get_variables(path, &array_variables)) { // вызывает get_variablesфункцию для чтения имен переменных среды из файла
            flag_alloc_memory = true;
            qsort(array_variables, INITIAL_SIZE, sizeof(char*), compare);
            for (size_t i = 0; i < INITIAL_SIZE; ++i)
                    printf("%s\n", array_variables[i]);
            char* child_name = (char*)malloc(9); //выделяет память для имени дочернего процесса, которому изначально присвоено значение child_00
            strcpy(child_name, "child_00");
            char* newargv[] = { child_name, path, NULL, NULL };
            bool flag_continue = true;
            do {
                int ch = getchar();
                switch(ch) {
                    case '+' : {
                        pid_t pid = fork(); //для создания нового процесса
                        newargv[NAME_BUTTON] = "+";
                        if (pid == 0) { // проверка на дочерний процесс 0 - да 
                            const char* path_child = getenv(ENVIRONMENT_VALUE_CHILD); // для получения значения переменной среды
                            execve(path_child, newargv, envp); // функция для замены текущего образа процесса новым образом процесса, заданным параметром path_child.
                        }else {
                            increment_child_xx(&child_name);
                        }
                        break;
                    }
                    case '*' : {
                        pid_t pid = fork();
                        if (pid == 0) {
                            newargv[NAME_BUTTON] = "*";
                            char* path_child = NULL;
                            if (find_child_path_envp(envp, &path_child)) { // search path
                                execve(path_child, newargv, envp);
                            }
                        }else {
                            increment_child_xx(&child_name);
                        }
                        break;
                    }
                    case '&' : {
                        pid_t pid = fork();
                        if (pid == 0) {
                            newargv[NAME_BUTTON] = "&";
                            char* path_child = NULL;
                            if (find_child_path_envp(__environ, &path_child)) {// __environ— глобальная переменная, содержащая переменные среды на языке программирования C
                                execve(path_child, newargv, envp);
                            }
                        }else {
                            increment_child_xx(&child_name);
                        }
                        break;
                    }
                    default: { flag_continue = false; break; }
                }
                waitpid(-1, NULL, WNOHANG);
                // ожидает изменения состояния любого дочернего процесса. Опция WNOHANGзаставляет функцию немедленно вернуться, если ни один дочерний элемент не вышел.
                getchar();
            }while(flag_continue);
            free(child_name);
        }
        if (flag_alloc_memory) {
            for (size_t i = 0; i < INITIAL_SIZE; ++i)
                free(array_variables[i]);
        }
        free(array_variables);
    }else {
        printf("Launch parameters: parent [filename], "
               "where filename is a file with the names of environment variables.");
    }
    return 0;
}