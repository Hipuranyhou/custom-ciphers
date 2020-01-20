#include <stdio.h>
#include <unistd.h>

void printUsage(const char *error) {
    printf("%s\n", error);
    printf("Usage: caesar -d NUMBER/KEY STRING\n");
    printf("       caesar -e NUMBER/KEY STRING\n");
    printf("       caesar -b STRING\n");
    return;
}

int getStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

char encryptLower(char c, int shift) {
    if ((c + shift) <= 'z')
        return c + shift;
    return 'a' + ((shift - 1) - ('z' - c));
}

char encryptUpper(char c, int shift) {
    if ((c + shift) <= 'Z')
        return c + shift;
    return 'A' + ((shift - 1) - ('Z' - c));
}

char decryptLower(char c, int shift) {
    if ((c - shift) >= 'a')
        return c - shift;
    return 'z' - ((shift - 1) + ('a' - c));
}

char decryptUpper(char c, int shift) {
    if ((c - shift) >= 'A')
        return c - shift;
    return 'Z' - ((shift - 1) + ('A' - c));
}

char getIndex(char mode, char c, int shift) {
    switch(mode) {
        case 'e':
            if (c >= 'a' && c <= 'z') return encryptLower(c, shift);
            if (c >= 'A' && c <= 'Z') return encryptUpper(c, shift);
            break;
        case 'd':
            if (c >= 'a' && c <= 'z') return decryptLower(c, shift);
            if (c >= 'A' && c <= 'Z') return decryptUpper(c, shift);
            break;
    }
    return  ' ';
}

void encryptString(char *line, int shift) {
    int len = getStrLen(line);
    shift = (shift > 25) ? (shift % 26) : shift;
    for (int i = 0; i < len; ++i)
        printf("%c", getIndex('e', line[i], shift));
    printf("\n");
    return;
}

void decryptString(char *line, int shift) {
    int len = getStrLen(line);
    shift = (shift > 25) ? (shift % 26) : shift;
    for (int i = 0; i < len; ++i)
        printf("%c", getIndex('d', line[i], shift));
    printf("\n");
    return;
}

void bruteforceString(char *line) {
    for (int i = 1; i < 26; ++i) {
        printf("%2d: ", i);
        decryptString(line, i);
    }
    return;
}

int getShift(char **argv, int *shift) {
    if (argv[2][0] >= 'a' && argv[2][0] <= 'z')
        *shift = argv[2][0] - 97;
    else if (argv[2][0] >= 'A' && argv[2][0] <= 'Z')
        *shift = argv[2][0] - 65;
    else if (!sscanf(argv[2], " %d", shift) || *shift < 0)
        return 0;
    return 1;
}

int main(int argc, char **argv) {

    int shift = 0, opt = 0;

    while ((opt = getopt(argc, argv, ":bde")) != -1) {
        switch (opt) {
            case 'b':
                if (argc < 3) {
                    printUsage("Missing argument.\0");
                    return 1;
                }
                bruteforceString(argv[2]);
                return 0;

            case 'e':
                if (argc < 4) {
                    printUsage("Missing argument.\0");
                    return 1;
                }
                if (!getShift(argv, &shift)) {
                    printUsage("Invalid shift or key.\0");
                    return 1;
                }
                encryptString(argv[3], shift);
                break;

            case 'd':
                if (argc < 4) {
                    printUsage("Missing argument.\0");
                    return 1;
                }
                if (!getShift(argv, &shift)) {
                    printUsage("Invalid shift or key.\0");
                    return 1;
                }
                decryptString(argv[3], shift);
                break;

            case '?':
                printUsage("Unknown option.\0");
                break;
        }
    }

    return 0;
}