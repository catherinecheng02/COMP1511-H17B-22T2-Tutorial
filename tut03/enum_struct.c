// Enum and struct demo
// Written by Catherine Cheng 
// 16-06-2022

#include <stdio.h>

enum position {
    laying_down,
    sitting,
    tummy_up
};

struct pet {
    double age;
    enum position body_position;
    int height_above_ground;
};


int main (void) {
    struct pet dog;
    dog.age = 3;
    dog.height_above_ground = 5;
    // dog.body_position = laying_down;
    dog.body_position = 0;
    if (dog.body_position == laying_down) {
        printf("dog sleeping zzz\n");
    }
    
    return 0;
}
