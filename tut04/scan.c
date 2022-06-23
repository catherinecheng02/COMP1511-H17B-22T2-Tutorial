// Program that scans values into an array.

#include <stdio.h>
#define SIZE 100

int main(void) {
    // scan until end of input (ctrl + d)
    int array[SIZE] = {0};
    int i = 0;
    while (scanf("%d", &array[i]) == 1) {
        i++; 
    }
    
    int j = 0;
    while (j < SIZE) {
        printf("%d\n", array[j]);
        j++;
    
    }

    

    return 0;
}

