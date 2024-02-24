#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"


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

 //Temp Array
    Record *temp = (Record *)malloc(n * sizeof(Record));
    int current_size; 
    for (current_size = 1; current_size <= n - 1; current_size *= 2) {
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


// BubbleSort
void bubbleSort(Record *arr, int n) {
    int i, j;
    Record temp;
    for (i = 1; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].idNumber > arr[j + 1].idNumber) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



/*
=========================
Empirical Frequency Count
=========================
*/

void InsertionSortWithSteps(Record *arr, int n)
{
    int count = 0;

    int step; count++;   
    for (count++, step = 1; count++, step < n; count++, step++)
    {
        Record key = arr[step]; count++; 
        int j = step - 1;  count++;
        while (count++, j >= 0 && key.idNumber < arr[j].idNumber)   
        {
            arr[j + 1] = arr[j]; count++;
            j = j - 1; count++;
        }
        arr[j + 1] = key;  count++;
    } count++;
    printf("Number of Steps: %d", count);
}

void SelectionSortWithCount(Record *arr, int n)
{
    int count;

    int i, j, min; count += 3;
    Record temp; count++;

    for (count++, i = 0; count++, i < (n - 1); count++, i++)
    {
        min = i; count++;
        for (count++, j = i + 1; count++, j < n; count++, j++)
        {
            if (arr[j].idNumber < arr[min].idNumber, count++)
                min = j; count++;
        } count++;
        if (count++, min != i) 
        {
            temp = arr[i]; count++;
            arr[i] = arr[min]; count++;
            arr[min] = temp; count++;
        }
    } count++;

}

void MergeSortWithCount(Record *arr, int n)
{
    int count = 0;

    //Temp Array
    Record *temp = (Record *)malloc(n * sizeof(Record)); count++;
    int current_size; count++;
    int left_start; count++;

    for (count++, current_size = 1; count++, current_size <= n - 1; count++, current_size *= 2) {
        for (count++, left_start = 0; left_start < n - 1, count++; left_start += 2 * current_size, count++) {
            int mid = (left_start + current_size - 1) < (n - 1) ? (left_start + current_size - 1) : (n - 1); count++;
            int right_end = (left_start + 2 * current_size - 1) < (n - 1) ? (left_start + 2 * current_size - 1) : (n - 1); count++;
            
            // Merge the two sub-arrays
            merge(arr, left_start, mid, right_end, temp); count++;
        } count++;
    } count++;
    
    free(temp);  /*Free the temporary array*/ count++;
}

void BubbleSortWithCount(Record *arr, int n){
    int count = 0;

    int i, j; count +=2;
    Record temp; count++;
     for (count++, i = 1; count++, i < n - 1; count++, i++) {
        for (count++, j = 1; count++, j < n - i - 1; count++, j++) {
            if (arr[j].idNumber > arr[j + 1].idNumber, count++) {
                temp = arr[j], count++;
                arr[j] = arr[j + 1], count++;
                arr[j + 1] = temp, count++;
            }
        }
    } count++;
    printf("Number of Steps: %d", count);
}



#endif