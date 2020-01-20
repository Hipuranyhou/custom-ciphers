#ifndef SOLVE_H
#define SOLVE_H

int getStrLen(char *str);

char encryptLower(char c, int shift);
char encryptUpper(char c, int shift);
char decryptLower(char c, int shift);
char decryptUpper(char c, int shift);

char getIndex(char mode, char c, int shift);

void solve(char mode, char *line, int shift);

#endif