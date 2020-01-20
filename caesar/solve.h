#ifndef SOLVE_H
#define SOLVE_H

int getStrLen(char *str);

char encryptChar(char c, int shift, char size);
char decryptChar(char c, int shift, char size);

char getIndex(char mode, char c, int shift);

void solve(char mode, char *line, int shift);

#endif