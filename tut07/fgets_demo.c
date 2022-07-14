#include <stdio.h>

#define MAX_LINE_SIZE 10

void print_string_elements(char *str);
void single_line_demo(void);
void loop_demo(void);


#include <stdio.h>



int main (void) {

    single_line_demo();
    // loop_demo()

    return 0;
}


void single_line_demo() {

    char buffer[MAX_LINE_SIZE];
    printf("Input line: ");
    char *fgets_return_value = fgets(buffer, MAX_LINE_SIZE, stdin);

    if (fgets_return_value == buffer) {
        printf("return value: address of buffer (%p)\n", fgets_return_value);
        printf("buffer: ");
        print_string_elements(buffer);
    } else if (fgets_return_value == NULL) {
        printf("return value: NULL\n");
    }

    // might crash program
    // printf("buffer: ");
    // print_string_elements(buffer);



}


void loop_demo(void) {

    char buffer[MAX_LINE_SIZE];
    printf("Input line: ");
    while (fgets(buffer, MAX_LINE_SIZE, stdin) != NULL) {
        printf("buffer: ");
        print_string_elements(buffer);
        printf("Input line: ");
    }

    // might crash program.
    // printf("\nbuffer after CTRL-D: ");
    // print_string_elements(buffer);

}


void print_string_elements(char *str) {

    printf("{");
    int i = 0;

    int end_of_string = 0;
    while (!end_of_string) {

        if (str[i] == '\n') {
            printf("'\\n', ");
        } else if (str[i] == '\0') {
            printf("'\\0'");
            end_of_string = 1;
        } else  {
            printf("'%c', ", str[i]);
        }
        i++;
    }

    printf("}\n");
}
