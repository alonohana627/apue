#include <unix_io.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    char *root_path = argc == 1 ? "." : argv[1];
    safe_string_arr_t *arr = get_dir_and_file(root_path);
    printf("%s\n", safe_string_arr_get(arr, 0));
    printf("%s\n", safe_string_arr_get(arr, 1));
}
