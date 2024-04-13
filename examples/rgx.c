#include <regex.h>
#include <stdlib.h>
#include <stdio.h>
#include <safe_string_arr.h>

int main() {
    safe_string_arr_t *arr = match_regex(" Alon Ohana    aaaaaaa ", "[A-Za-z]+", 10);
    for(size_t i = 0; i<arr->size; i++){
        printf("%s\n", safe_string_arr_get(arr, i));
    }
}
