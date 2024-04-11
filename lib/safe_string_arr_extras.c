#include <safe_string_arr.h>

/* Other shit in the API */
safe_string_arr_t *split_by_char(char *args, char c) {
    int begin = 0;
    int end = 0;
    char *copy;
    char *tmp;
    safe_string_arr_t *splited_args = safe_string_arr_create();

    for (copy = args; *copy != '\0'; copy++) {
        end++;
        if (*copy == c) {
            tmp = (char *) malloc((end - begin - 1) * sizeof(char));
            if (tmp == NULL) {
                safe_string_arr_destroy(splited_args);
                free(tmp);
                return NULL;
            }

            strncpy(tmp, args + begin, end - begin - 1);
            safe_string_arr_add(splited_args, tmp);
            begin = end;
        }
    }

    tmp = (char *) malloc((end - begin) * sizeof(char));
    strncpy(tmp, args + begin, end - begin);
    safe_string_arr_add(splited_args, tmp);

    return splited_args;
}

safe_string_arr_t *split_by_space(char *args) {
    return split_by_char(args, ' ');
}

safe_string_arr_t *split_by_lines(char *args) {
    return split_by_char(args, '\n');
}
