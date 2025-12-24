#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mergeSort(int array[], int length);
void merge(int new_array[], int new_array_2[], int new_array_length, int new_array_length_2, int final_array[]);

int main() {
    unsigned int seed = 42;
    srand(seed);   
    int size = 10000000;
    int list[size];

    for(int i = 0 ; i < size; i++){
        list[i] = rand()% 20;
    }
    int length = sizeof(list) / sizeof(list[0]);

    mergeSort(list, length);

    return 0;

}

void mergeSort(int array[], int length){
    if (length <= 1) return;

    int half_length = length/2;

    int new_array[half_length];

    int new_array_2[length-half_length];

    for(int i = 0; i < half_length; i++){
        new_array[i] = array[i];
    }
    int j = 0;
    for(int i = half_length; i < length; i++){
        new_array_2[j] = array[i];
        j++;
    }
    int new_array_length = sizeof(new_array) / sizeof(new_array[0]);
    
    int new_array_length_2 = sizeof(new_array_2) / sizeof(new_array_2[0]);

    mergeSort(new_array, new_array_length);

    mergeSort(new_array_2, new_array_length_2);

    merge(new_array, new_array_2, new_array_length, new_array_length_2,array);


}

void merge(int new_array[], int new_array_2[], int new_array_length, int new_array_length_2, int final_array[]){

    int i = 0;
    int j = 0;
    int total = 0;

    while(i < new_array_length && j < new_array_length_2){
        if(new_array[i] < new_array_2[j]){
            final_array[total] = new_array[i];
            total = total + 1;
            i++;
        }

        else{
            final_array[total] = new_array_2[j];
            total = total + 1;
            j++;
        }
       
    }
    while(i < new_array_length){
        final_array[total] = new_array[i];
        total = total + 1;
        i++;
    }
    while(j < new_array_length_2){
        final_array[total] = new_array_2[j];
        total = total + 1;
        j++;
    }


}