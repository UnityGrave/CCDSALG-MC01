#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

typedef char String[101]; //In order to use strings 

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

#include <stdlib.h>
#include <string.h>


void swap(Record *a, Record *b){
    Record temp = *a;
    *a = *b;
    *b = temp;

}

void insertionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.

    int step;   
    for (step = 1; step < n; step++)
    {
        Record key = arr[step];   
        int j = step - 1;  
        while (j >= 0 && key.idNumber < arr[j].idNumber)   
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;  
    }

}

void selectionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.

    int i, j, min;
    Record temp;

    for (i = 0; i < (n - 1); i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j].idNumber < arr[min].idNumber)
                min = j;
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void merge(Record *arr, int left, int mid, int right, Record *temp) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i].idNumber <= arr[j].idNumber) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.

    // Create a temporary array to hold the merged results
    Record *temp = (Record *)malloc(n * sizeof(Record));

    for (int current_size = 1; current_size <= n - 1; current_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * current_size) {
            int mid = (left_start + current_size - 1) < (n - 1) ? (left_start + current_size - 1) : (n - 1);
            int right_end = (left_start + 2 * current_size - 1) < (n - 1) ? (left_start + 2 * current_size - 1) : (n - 1);
            
            // Merge the two sub-arrays
            merge(arr, left_start, mid, right_end, temp);
        }
    }
    
    free(temp);  // Free the temporary array
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/


// Function to read data from the file into an array of structs
int readDataFromFile(const char *filename, Record dataArray[], int maxEntries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%d %s", &dataArray[count].idNumber, dataArray[count].name) == 2 && count < maxEntries) {
        count++;
    }

    fclose(file);
    return count;
}

// Function to write data from an array of structs to the file
void writeDataToFile(const char *filename, Record dataArray[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s\n", dataArray[i].idNumber, dataArray[i].name);
    }

    fclose(file);
}

// BubbleSort
void bubbleSort(Record array[], int n) {
    int i, j;
    Record temp;
    for (i = 1; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j].idNumber > array[j + 1].idNumber) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}












#endif