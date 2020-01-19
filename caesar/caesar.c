#include <stdio.h>

void shiftString(char *line, int shift) {
    return;
}

int main(int argc, char **argv) {
    int shift = 0;

    if (argc < 3) {
        // Missing argument
        printf("Missing argument.\n");
        printf("Usage: caesar NUMBER STRING1\n");
        return 1;
    }

    if (!sscanf(argv[1], " %d", &shift)) {
        printf("First argument is not a number.\n");
        printf("Usage: caesar NUMBER STRING\n");
        return 1;
    }

    shiftString(argv[2], shift);
    return 0;
}