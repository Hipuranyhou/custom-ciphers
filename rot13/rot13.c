#include <stdio.h>
#include <stdlib.h>

char decryptLower(char c) {
    if(c <= 109) return c + 13;
    if(c > 109) return 97 + (12 - (122 - c));
    return '-';
}

char decryptUpper(char c) {
    if(c <= 77) return c + 13;
    if(c > 77) return 65 + (12 - (90 - c));
    return '-';
}

char decryptIndex(char c) {
    if(c == ' ') return c;
    if(c >= 'a' && c <= 'z') return decryptLower(c);
    if(c >= 'A' && c <= 'Z') return decryptUpper(c);
    return 'c';
}

void unRot13(char *line) {
    int len = 0;
    while(line[len] != '\0') len++;
    char *decrypted = (char*)malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; ++i) {
        decrypted[i] = decryptIndex(line[i]);
    }
    decrypted[len] = '\0';
    printf("%s\n", decrypted);
    free(decrypted);
    return;
}

int main(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        unRot13(argv[i]);
    }
    return 0;
}