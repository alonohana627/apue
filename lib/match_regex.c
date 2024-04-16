#include <safe_string_arr.h>
#include <stdio.h>
#include <regex.h>

safe_string_arr_t *match_regex(char *input, const char *pattern, size_t max_matches) {
    regex_t regex;
    regmatch_t pmatch[max_matches];
    size_t index = 0;
    size_t current_offset = 0;
    size_t str_size = strlen(input);
    int curr_match_length;
    int result;

    safe_string_arr_t *arr = safe_string_arr_create();

    if (arr == NULL) {
        safe_string_arr_destroy(arr);
        return NULL;
    }

    result = regcomp(&regex, pattern, REG_EXTENDED);
    if (result != 0) {
        goto error;
    }

    do {
        result = regexec(&regex, input + current_offset, max_matches, pmatch, 0);
        if (index == 0 && result == REG_NOMATCH) {
            regfree(&regex);
            return arr;
        }

        if (result != 0 && result != REG_NOMATCH) {
            printf("%d\n", result);
            goto error;
        }

        if (pmatch[0].rm_so == -1) {
            break;
        }

        curr_match_length = pmatch[0].rm_eo - pmatch[0].rm_so;
        current_offset += pmatch[0].rm_so;

        char res[curr_match_length];
        strncpy(res, input + current_offset, curr_match_length);
        res[curr_match_length] = '\0';

        safe_string_arr_add(arr, res);
        current_offset = current_offset + pmatch[0].rm_eo;
        index++;
    } while (pmatch[0].rm_so != -1 && index < max_matches && current_offset < str_size);

    regfree(&regex);
    return arr;

    error:
    regfree(&regex);
    safe_string_arr_destroy(arr);
    return NULL;
}

bool is_match(const char *input, const char *pattern) {
    regex_t regex;
    regmatch_t pmatch[1];
    int result;

    result = regcomp(&regex, pattern, REG_EXTENDED);
    if(result != 0){
        return false;
    }

    result = regexec(&regex, input, 1, pmatch, 0);
    if(result == REG_NOMATCH){
        regfree(&regex);
        return false;
    }
    if(result != 0){
        regfree(&regex);
        return false;
    }
    regfree(&regex);
    return true;
}
