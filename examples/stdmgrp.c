#include <stdio_utils.h>

int main(int argc, char *argv[]){
    if(argc < 3){
        return -1;
    }

    safe_string_arr_t *arr;

    arr = mingrep(argv[1], argv[2]);
    for(size_t i = 0; i<arr->size; i++){
        printf("%s\n", safe_string_arr_get(arr, i));
    }

    return 0;
}
