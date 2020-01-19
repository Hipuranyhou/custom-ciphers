#include <stdio.h>
#include <stdlib.h>

int getStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

char getLower(char c) {
    if (c <= 109) return c + 13;
    if (c > 109) return 97 + (12 - (122 - c));
    return '?';
}

char getUpper(char c) {
    if (c <= 77) return c + 13;
    if (c > 77) return 65 + (12 - (90 - c));
    return '?';
}

char getIndex(char c) {
    if (c >= 'a' && c <= 'z') return getLower(c);
    if (c >= 'A' && c <= 'Z') return getUpper(c);
    return c;
}

void rot13(char *line) {
    int len = getStrLen(line);
    char *rotated = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; ++i) {
        rotated[i] = getIndex(line[i]);
    }
    rotated[len] = '\0';
    printf("%s\n", rotated);
    free(rotated);
    return;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        // Missing string argument
        printf("Missing string argument.\n");
        printf("Usage: rot13 STRING1 [STRING2...]\n");
    } else {
        // Rotate each string
        for (int i = 1; i < argc; ++i) {
            rot13(argv[i]);
        }
    }

    return 0;
}