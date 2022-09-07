#include <stdio.h>

// Q1a
int best_speed(int start, int end, int max_speed) {
    // Your answer here
    int block = end - start; 

    while (block % max_speed != 0)
    {
        max_speed--; 
    }
    return max_speed; 
}


// Q1b
int stopping_distance(int speed) {
    // Your answer here
    int sum = 0; 

    while (speed > 0) 
    {
        sum += speed; 
        printf("%d\n", sum); 
        speed--; 
    }
    return sum; 
}


// Q1c
// void travel(int start, int end, int max_speed) {
//     // Your answer here
// }


int main(void) {
    // printf("%d\n", best_speed(44, 89, 4));
    // printf("%d\n", best_speed(44, 89, 5));
    // printf("%d\n", best_speed(44, 89, 10));

    printf("%d\n", stopping_distance(4));
    printf("%d\n", stopping_distance(5));

    // travel(44, 89, 5);
    // travel(44, 89, 10);
    // travel(44, 89, 4);
}