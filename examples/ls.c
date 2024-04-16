#include "io_stats.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Error: not enough args\n");
        return 1;
    }
    enhanced_ls(argv[1]);
    return 0;
}