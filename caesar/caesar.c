#include <stdio.h>
#include <unistd.h>
#include "helper.h"
#include "solve.h"
//#include "distribution.h"

void printUsage(const char *error) {
    printf("%s\n", error);
    printf("Usage: caesar -d NUMBER/KEY STRING\n");
    printf("       caesar -e NUMBER/KEY STRING\n");
    printf("       caesar -b STRING\n");
    return;
}

void bruteforceString(char *line) {
    // Decrypt string with every of the 25 possible keys
    for (int i = 1; i < 26; ++i) {
        printf("%2d: ", i);
        solve('d', line, i);
    }
    return;
}

int getShift(char **argv, int *shift) {
    // Get shift from lowercase character
    if (isLower(argv[2][0]))
        *shift = argv[2][0] - 97;
    // Get shift from uppercase character
    else if (isUpper(argv[2][0]))
        *shift = argv[2][0] - 65;
    // Get shift from number
    else if (!sscanf(argv[2], " %d", shift) || *shift < 0)
        // Error extracting shift
        return 0;
    *shift = (*shift > 25) ? (*shift % 26) : *shift;
    return 1;
}

int main(int argc, char **argv) {

    int shift = 0, opt = 0;

    while ((opt = getopt(argc, argv, ":bde")) != -1) {
        switch (opt) {
            // Bruteforce string
            case 'b':
                if (argc < 3) {
                    printUsage("Missing argument.\0");
                    return 1;
                }
                bruteforceString(argv[2]);
                return 0;
            // Encrypt or decrypt string
            case 'e':
            case 'd':
                if (argc < 4) {
                    printUsage("Missing argument.\0");
                    return 1;
                }
                if (!getShift(argv, &shift)) {
                    printUsage("Invalid shift or key.\0");
                    return 1;
                }
                solve(opt, argv[3], shift);
                break;
            // Unknown option
            case '?':
                printUsage("Unknown option.\0");
                break;
        }
    }

    return 0;
}