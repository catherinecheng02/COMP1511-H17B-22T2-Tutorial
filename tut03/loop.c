// While loop demo
// Written by Catherine Cheng 
// 16-06-2022

#include <stdio.h>
#define SIZE 4
int main(void) {
    /*
    // initialise a counter
    int i = 0;
    // condition
    while (i < SIZE) {
        // body 
        printf("%d\n", i);
        // increment
        i = i + 1;
        // i++;
    } */
    
    // print a 4x4 grid of Xs
    int row = 0; 
    while (row < SIZE) {
        // prints out 1 row
        int col = 0;
        while (col < SIZE) {
            printf("X");
            col++;
        }
        printf("\n");
        row++;
    }
        
    return 0;
}

