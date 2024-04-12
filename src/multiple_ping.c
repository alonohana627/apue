#include <networking.h>

void multiple_ping(const char *destination, int count){
    if(count <= 0){
        count = 1024;
    }

    printf("Send ping to %s\n", destination);
    for(int i = 0; i<count; i++){
        ping(destination);
        sleep(1);
    }
}
