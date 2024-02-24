#define SORTINGALGORITHMS1_C

#include <stdio.h>
#include "record.c"



#include <stdlib.h>
#include <string.h>

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
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j].idNumber > array[j + 1].idNumber) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}