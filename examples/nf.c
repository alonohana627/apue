#include <unix_io.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        return 0;
    }

    new_file(argv[1]);
}