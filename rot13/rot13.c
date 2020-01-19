#include <stdio.h>

int getStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

char getLower(char c) {
    if (c <= 109) return c + 13;
    return 97 + (12 - (122 - c));
}

char getUpper(char c) {
    if (c <= 77) return c + 13;
    return 65 + (12 - (90 - c));
}

char getIndex(char c) {
    if (c >= 'a' && c <= 'z') return getLower(c);
    if (c >= 'A' && c <= 'Z') return getUpper(c);
    return c;
}

void rot13(char *line) {
    int len = getStrLen(line);
    for (int i = 0; i < len; ++i) printf("%c", getIndex(line[i]));
    printf("\n");
    return;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        // Missing string argument
        printf("Missing string argument.\n");
        printf("Usage: rot13 STRING\n");
        return 1;
    }

    rot13(argv[1]);
    return 0;
}