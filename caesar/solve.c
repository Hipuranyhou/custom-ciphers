#include <stdio.h>

int getStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
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
    /*
     * Gets ascii decimal value of encrypted/decrypted lowercase/uppercase character
     * All other characters returns the same
    */
    switch(mode) {
        case 'e':
            if (c >= 'a' && c <= 'z')
                return encryptLower(c, shift);
            if (c >= 'A' && c <= 'Z')
                return encryptUpper(c, shift);
            break;
        case 'd':
            if (c >= 'a' && c <= 'z')
                return decryptLower(c, shift);
            if (c >= 'A' && c <= 'Z')
                return decryptUpper(c, shift);
            break;
    }
    return c;
}

void solve(char mode, char *line, int shift) {
    // Encrypt or decrypt text with given shift
    int len = getStrLen(line);
    for (int i = 0; i < len; ++i)
        printf("%c", getIndex(mode, line[i], shift));
    printf("\n");
    return;
}