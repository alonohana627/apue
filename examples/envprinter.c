#include <stdio.h>

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char *envp[]){
    for(int i = 0; envp[i] != NULL; i++){
        printf("%s\n", envp[i]);
    }

    return 0;
}
