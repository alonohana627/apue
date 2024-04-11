#include <stdio.h>
#include <sys/errno.h>
#include <string.h>

/* With Ubuntu 20.10 my machine has 133 error codes
 * 0 is not a valid error
 */
int main(void) {
    for (int i = 0; i <= 133; i++) {
        printf("%s\n", strerror(i));
    }
    return 0;
}
