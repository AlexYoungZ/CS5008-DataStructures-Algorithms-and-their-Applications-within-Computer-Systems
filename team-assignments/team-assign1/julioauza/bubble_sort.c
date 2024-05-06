#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int * bubble_sort(int things[], int n) {
    int new_array[n];
    bool swapped = true;
    while ( swapped == true) {
        swapped = false;
        for (int i = 0; i < n; i++) {
            if ( things[i] > things[i + 1] ) {
                things[i] = things [i + 1];
                things[i + 1] = things[i];
                swapped = true;
            }
        }
    }
    return new_array;
}

// method to shuffle existing array. Equivalent to random.shuffle(my_list) in Python
// taken from https://stackoverflow.com/questions/6127503/shuffle-array-in-c
void shuffle(int aArray[], int cnt){
    int temp, randomNumber;
    time_t t;
    srand((unsigned)time(&t));
    for (int i=cnt-1; i>0; i--) {
        temp = aArray[i];
        randomNumber = (rand() % (i+1));
        aArray[i] = aArray[randomNumber];
        aArray[randomNumber] = temp;
    }
}

int main() {
    //create array of 100 items
    int my_list[100];
    for (int i = 0; i < 100; i++) {
        my_list[i] = i+1;
    }
    //shuffle array
    shuffle(my_list, 100);

    //print shuffled array
    for (int i = 0; i < 100; i++) {
        printf("%d\n", my_list[i]);
    }
    printf("\n");

    //sort shuffled array
    bubble_sort(my_list, 100);

    //print sorted array
    for (int j = 0; j < 100; j++) {
        my_list[j] = j+1;
        printf("%d ", my_list[j]);
        printf("\n");
    }

    return 0;
}

