#include <stdio.h>
#include <ctype.h>

int getStrLen(char *str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

char encryptChar(char c, int shift, char size) {
    return (((c - size) + shift) % 26) + size;
}

char decryptChar(char c, int shift, char size) {
    return ((((c - size) - shift) + 26) % 26) + size;
}

char getIndex(char mode, char c, int shift) {
    /*
     * Gets ascii decimal value of encrypted/decrypted lowercase/uppercase character
     * All other characters returns the same
    */
    switch(mode) {
        case 'e':
            if (islower(c))
                return encryptChar(c, shift, 'a');
            if (isupper(c))
                return encryptChar(c, shift, 'A');
            break;
        case 'd':
            if (islower(c))
                return decryptChar(c, shift, 'a');
            if (isupper(c))
                return decryptChar(c, shift, 'A');
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