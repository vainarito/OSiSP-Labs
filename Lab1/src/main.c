
#include "dirwalk.h"

int main(int argc, char *argv[])
{
    setlocale(LC_COLLATE, "ru_RU.UTF-8");
    char **arr_path = NULL;
    size_t size_arr = 0, capacity = 1;
    bool flag_free = false;
    FIND_PATH_DIR;
    char *path = NULL;
    if (optind < argc)
    {
        const int str_len = strlen(argv[optind]);
           path = (char *)malloc(str_len + 1);
        strncpy(path, argv[optind], str_len + 1);
        flag_free = true;
    }
    else
        path = CURRENT_DIR;

    RELOAD_OPTIND;
    bool options[COUNT_OPTIONS] = {false, false, false, false, false};

    if (!DOES_THE_FILE_EXIST(path))
        printf("Check if the directory or file actually exists!");
    else
    {
        bool flag_are_there_any_options = false;
        int option_ch;
        while ((option_ch = getopt(argc, argv, "ldfs")) != -1)
        {
        switch(option_ch) {
                case 'l' : { options[IS_LNK] = true;  break; }
                case 'f' : { options[IS_REG] = true;  break; }
                case 'd' : { options[IS_DIR] = true;  break; }
                case 's' : { options[IS_SORT] = true; break; }
                default : break;
            }
            if (option_ch != 's')
                flag_are_there_any_options = true;
        }
        if (!flag_are_there_any_options) options[IS_ALL_OPT] = true;
        dirwalk(path, options, &arr_path, &size_arr, &capacity);
    }

    if (arr_path)
    {
        if (options[IS_SORT])
            qsort(arr_path, size_arr, sizeof(char *), compare);
        for (size_t j = 0; j < size_arr; ++j) {  printf("%s\n", arr_path[j]); }
        for (size_t i = 0; i < size_arr; ++i) free(arr_path[i]);
        free(arr_path);
    }
    if (flag_free) free(path);
    
    return 0;
}


