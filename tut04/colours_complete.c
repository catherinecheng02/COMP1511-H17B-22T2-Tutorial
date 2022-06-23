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
    OTHER
};

enum main_colours get_main_colour(struct colour c) {
    if (c.red > c.green && c.red > c.blue) {
        return RED;
    } else if (c.green > c.red && c.green > c.blue) {
        return GREEN;
    } else if (c.blue > c.red && c.blue > c.green) {
        return BLUE;
    } else {
        return OTHER;
    }
}

double brightness(struct colour colour) {
    return sqrt(colour.red) + sqrt(colour.green) + sqrt(colour.blue);
}

double average_brightness(struct colour colours[100], int size) {
    double avg = 0;

    int i = 0;
    while (i < size) {
        avg += brightness(colours[i]);
        i++;
    }

    return avg / size;
}
