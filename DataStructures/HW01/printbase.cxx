#include <stdio.h> // for printf
#include <stdlib.h> // for malloc, EXIT_SUCCESS

const int MAX_BASE = 36;

char* integer2char(unsigned int number, unsigned int base) {
    char *ptr;

    ptr = (char *) malloc(1 * sizeof(char));

    /* check to see if malloc failed or not */
    if (ptr == 0) {
       perror("malloc failed");
    }

    ptr[0] = '\0';
    return ptr;
}

int main(int argc, char **argv) {
    char *str[MAX_BASE+1];

    char format[] = "%12s|%12s|%12s|%12s|%12s|%12s\n";
    char numformat[] = "%12i|%12s|%12s|%12s|%12s|%12s\n";

    printf(format, "number", "2", "8", "10", "16", "36");
    printf(format, "============", "============", "============", "============", "============", "============");

    for (int num = 0; num < 1024; num++) {
        for (int base = 2; base <= MAX_BASE; base++) {
            str[base] = integer2char(num,base);
        }

        /* print line of conversions */
        printf(numformat, num, str[2], str[8], str[10], str[16], str[36]);

        /* free all of the gotton pointers */
        for (int base = 2; base <= MAX_BASE; base++) {
            free(str[base]);
        }
    }
    return EXIT_SUCCESS;
}
