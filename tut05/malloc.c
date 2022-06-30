// Demo of malloc, free and realloc
#include <stdio.h>
#include <stdlib.h>
void dynamic_memory(int size);
int main(void) {
    dynamic_memory(8);

}
// Write a function called "dynamic_memory", 
// which takes an integer called size.
// Create a dynamic array of integers, that is 
// exactly size integers long.
// Set all the integers in that array to 0.
// Make that array twice as long.
// Set all the integers you just added to 1.
// Free the array.
void dynamic_memory(int size) {
    int *array = malloc(sizeof(int)*size);
    int i = 0;
    while (i < size) {
        array[i] = 0;
        i++;
    }
    array = realloc(array,sizeof(int)*size*2);
    int j = size;
    while (j < size*2) {
        array[j] = 1;
        j++;
    }
    
    j = 0;
    while (j < size*2) {
        printf("%d\n", array[j]);
        j++;
    }
    free(array);
}

    
