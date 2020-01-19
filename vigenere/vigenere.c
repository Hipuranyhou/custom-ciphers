#include <stdio.h>

static const char lower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
static const char upper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void printUsage(void) {
    printf("Usage: vigenere -d KEY STRING\n");
    printf("Usage: vigenere -e KEY STRING\n");
    return;
}

int getStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

void getDecryptIndex(char key, char text) {
    return;
}

void decrypt(char *key, char *text) {
    int lenKey = getStrLen(key);
    int lenText = getStrLen(text);
    int index = 0;
    for (int i = 0; i < lenText; ++i) {
        if (index == lenKey) index = 0;
        printf("%c", getDecryptIndex(key, text[i]));
    }
    printf("\n");
    return;
}

void getEncryptIndex(char key, char text) {
    return;
}

void encrypt(char *key, char *text) {
    int lenKey = getStrLen(key);
    int lenText = getStrLen(text);
    int index = 0;
    for (int i = 0; i < lenText; ++i) {
        if (index == lenKey) index = 0;
        printf("%c", getEncryptIndex(key[index], text[i]));
    }
    printf("\n");
    return;
}

int main(int argc, char **argv) {

    if (argc < 4) {
        // Missing argument
        printf("Missing parameter.\n");
        printUsage();
        return 1;
    }

    if (argv[1][0] == '-') {
        switch(argv[1][1]) {
            case 'd':
                decrypt(argv[2], argv[3]);
                break;
            case 'e':
                encrypt(argv[2], argv[3]);
                break;
            default:
                printf("Invalid option.\n");
                printUsage();
                return 1;
        }
    } else {
        // Second parameter is not a option
        printf("Second parameter is not a option.\n");
        printUsage();
        return 1;
    }

    return 0;
}