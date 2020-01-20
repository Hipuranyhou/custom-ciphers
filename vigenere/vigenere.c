#include <stdio.h>
#include <unistd.h>

void printUsage(const char *error) {
    printf("%s\n", error);
    printf("Usage: vigenere -d KEY STRING\n");
    printf("Usage: vigenere -e KEY STRING\n");
    return;
}

char getLower(char c) {
    return c + 32;
}

int getStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

char encrypt(char key, char text) {
    return (((text - 97) + (key - 97)) % 26) + 97;
}

char decrypt(char key, char text) {
    return (((text - 97) - (key - 97) + 26) % 26) + 97;
}

char getIndex(char mode, char key, char text) {
    if (!(text >= 'a' && text <= 'z')) return text;
    switch(mode) {
        case 'e':
            return encrypt(key, text);
        case 'd':
            return decrypt(key, text);
    }
    return '?';
}

void solve(char mode, char *key, char *text) {
    int lenKey = getStrLen(key);
    int lenText = getStrLen(text);
    int index = 0, upper = 0;
    for (int i = 0; i < lenText; ++i) {
        if (index == lenKey) index = 0;
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = getLower(text[i]);
            upper = 32;
        }
        if (key[index] >= 'A' && key[index] <= 'Z') key[index] = getLower(key[index]);
        printf("%c", getIndex(mode, key[index], text[i]) - upper);
        index++;
        upper = 0;
    }
    printf("\n");
    return;
}

int main(int argc, char **argv) {

    int opt = 0;

    if (argc < 4) {
        // Missing argument
        printUsage("Missing argument.\0");
        return 1;
    }

    while ((opt = getopt(argc, argv, ":ed")) != -1) {
        switch (opt) {
            case 'e':
            case 'd':
                solve(opt, argv[2], argv[3]);
                break;
            case '?':
                printUsage("Unknown option.\0");
                return 1;
        }
    }

    return 0;
}
