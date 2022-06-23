// Function, struct, enum demo
// Written by Catherine Cheng 
// 23-06-2022
#include <stdio.h>

struct colour {
    int red;
    int green;
    int blue;
};

enum main_colours {
    RED,
    GREEN,
    BLUE,
};

struct colour make_colour(int r, int b, int g);
int main (void) {
    // function call
    struct colour purple = make_colour(191, 64, 191  );
    
    return 0;
}


// Write a function called make_color which takes three integers and returns a struct colour
struct colour make_colour(int r, int b, int g) {
    struct colour c;
    c.red = r;
    c.blue = b;
    c.green = g;
    return c;
}



// In the kahoot we will write:
// - a function that determines the dominating/main colour component in a colour
// - a function that calculates brightness of a colour
// - a function that calculates average brightness of 100 colours






