#include <stdio_utils.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        return -1;
    }

    char *fname = argv[1];

    return create_new_file(fname);
}
