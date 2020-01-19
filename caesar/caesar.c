#include <stdio.h>

int getStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

char getLower(char c, int shift) {
    if ((c + shift) <= 122) return c + shift;
    return 97 + ((shift - 1) - (122 - c));
}

char getUpper(char c, int shift) {
    if ((c + shift) <= 90) return c + shift;
    return 65 + ((shift - 1) - (90 - c));
}

char getIndex(char c, int shift) {
    if (c >= 'a' && c <= 'z') return getLower(c, shift);
    if (c >= 'A' && c <= 'Z') return getUpper(c, shift);
    return c;
}

void shiftString(char *line, int shift) {
    int len = getStrLen(line);
    shift = (shift > 25) ? (shift - 26) : shift;
    for (int i = 0; i < len; ++i) printf("%c", getIndex(line[i], shift));
    printf("\n");
    return;
}

void shiftBrute(char *line) {
    for (int i = 1; i < 26; ++i) {
        printf("%2d: ", i);
        shiftString(line, i);
    }
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

    if (argv[1][0] == '-' && argv[1][1] == 'b') {
        shiftBrute(argv[2]);
        return 0;
    }

    if (!sscanf(argv[1], " %d", &shift)) {
        printf("First argument is not a number.\n");
        printf("Usage: caesar NUMBER STRING\n");
        return 1;
    }

    shiftString(argv[2], shift);
    return 0;
}