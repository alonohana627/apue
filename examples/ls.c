#include "dirstats.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Error: not enough args\n");
        return 1;
    }

    if(simple_print_entries_in_folder(argv[1]) != 0){
        printf("Error in reading a folder\n");
    }

    return 0;
}