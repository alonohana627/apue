#include <safe_string_arr.h>
#include <stdio.h>
#include <regex.h>

safe_string_arr_t *match_regex(char *input, const char *pattern, size_t max_matches) {
    regex_t regex;
    regmatch_t pmatch[max_matches];
    size_t index = 0;
    size_t current_offset = 0;
    size_t str_size = strlen(input);
    int result;

    safe_string_arr_t *arr = safe_string_arr_create();

    if (arr == NULL) {
        safe_string_arr_destroy(arr);
        return NULL;
    }

    result = regcomp(&regex, pattern, REG_EXTENDED);
    if (result != 0) {
        goto bad_time;
    }

    do {
        result = regexec(&regex, input + current_offset, max_matches, pmatch, 0);
        if (index == 0 && result == REG_NOMATCH) {
            return arr;
        }

        if (result != 0 && result != REG_NOMATCH) {
            printf("%d\n", result);
            goto bad_time;
        }

        if (pmatch[0].rm_so == -1) {
            break;
        }

        current_offset += pmatch[0].rm_so;
        char res[pmatch[0].rm_eo - pmatch[0].rm_so];
        strncpy(res, input + current_offset, pmatch[0].rm_eo - pmatch[0].rm_so);
        res[pmatch[0].rm_eo - pmatch[0].rm_so] = '\0';

        safe_string_arr_add(arr, res);
        current_offset = current_offset + pmatch[0].rm_eo;
        index++;
    } while (pmatch[0].rm_so != -1 && index < max_matches && current_offset < str_size);

    return arr;

    bad_time:

    regfree(&regex);
    safe_string_arr_destroy(arr);
    return NULL;
}
