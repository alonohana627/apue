#include <safe_string_arr.h>
#include <stdio.h>

int main(void){
    char *a = "b";
    char *b = "ohaaaaan";
    safe_string_arr_t* arr = safe_string_arr_create();

    safe_string_arr_add(arr, a);
    safe_string_arr_add(arr, b);
    printf("%s\n", safe_string_arr_get(arr, 0));
    printf("%s\n", safe_string_arr_get(arr, 1));
    safe_string_arr_remove(arr, 0);
    printf("%s\n", safe_string_arr_get(arr, 0));
    safe_string_arr_set(arr, 0,"jawodiawwd");
    printf("%s\n", safe_string_arr_get(arr, 0));

    safe_string_arr_destroy(arr);
}
