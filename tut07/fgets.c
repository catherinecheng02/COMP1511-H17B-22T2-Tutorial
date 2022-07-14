#include <stdio.h>


char *my_fgets(char *str, int size) {

    // handling invalid size
    if (size < 1) {
        return NULL;

    } else if (size == 1) {
        // poorly defined behaviour
        str[0] = '\0';
        return str;
    }

    char c;
    int values_scanned = scanf("%c", &c);
    if (values_scanned != 1) {
        return NULL;
    }

    int end_of_line = 0;
    int i = 0;
    while (i < size - 1 && !end_of_line && values_scanned == 1) {
        str[i] = c;

        if (c == '\n') {
            // ending loop after inserting newline
            end_of_line = 1;
        } else {
            // only scanning character if not at the end of the line.
            values_scanned = scanf("%c", &c);
        }

        i++;
    }

    str[i] = '\0';

    return str;
}
