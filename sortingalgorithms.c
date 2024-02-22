#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
//added
#include <stdlib.h> // for merge sort dynamic memory allocation
#include "record.c"

/* FOR CHECKING: prints the current array state into a file sorted.txt */
void printRecord(Record *currentRecord, int n) {
    FILE *fp = fopen("sorted.txt", "a+"); 
    
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s\n", currentRecord[i].idNumber, currentRecord[i].name);
    }
    fprintf(fp, "\n");

    fclose(fp);
}




/*
 * You may declare additional variables and helper functions
 * as needed by the sorting algorithms here.
 */

void insertionSort(Record *arr, int n)
{
    //printRecord(arr, n);

    int step;    // 1
    for (step = 1; step < n; step++)    // (n-1+1)
    {
        Record key = arr[step];    //1*(n-1)
        int j = step - 1;    //1*(n-1)
        while (j >= 0 && key.idNumber < arr[j].idNumber)    //
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;    //1*(n-1)
    }
    
    //printRecord(arr, n);
    return;
}




void selectionSort(Record *arr, int n)
{
    //printRecord(arr, n);

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

    //printRecord(arr, n);
    return;
}



// converted to iterative merge sort vs recursive merge sort because recursive merge sort apparently has problems dealing with larger lists which lead to stack overflow
// Helper function to initialize the two temporary arrays and then merge the two arrays back into the main array

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


void mergeSort(Record *arr, int n) {
    // Create a temporary array to hold the merged results
    //printRecord(arr, n); // unsorted
    Record *temp = (Record *)malloc(n * sizeof(Record));

    for (int current_size = 1; current_size <= n - 1; current_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * current_size) {
            int mid = (left_start + current_size - 1) < (n - 1) ? (left_start + current_size - 1) : (n - 1);
            int right_end = (left_start + 2 * current_size - 1) < (n - 1) ? (left_start + 2 * current_size - 1) : (n - 1);
            
            // Merge the two sub-arrays
            merge(arr, left_start, mid, right_end, temp);
        }
    }
    //printRecord(arr, n); // sorted
    free(temp);  // Free the temporary array
}




/*
 * Define AT LEAST ONE more sorting algorithm here, apart from the
 * ones given above. Make sure that the method accepts an array of
 * record structures.
 */

/* This is a helper function that shrinks the gap by 1.3 or (gap*10)/13 */
void combSortShrink(int *gap, float shrink)
{
    // shrink the gap by the shrink factor until it reaches 1
    *gap /= shrink;

    if (*gap < 1)
        *gap = 1;

    // printf("Gap: %d\n", *gap);
}

void combSort(Record *arr, int n)
{
    //printRecord(arr, n);

    /* combSort is a modification of bubble sort but the gap between elements is increased compared to bubbleSort
    which reduces the number of swaps and comparisons. During every iteration, the gap is reduced by a factor of 1.3
    until it reaches 1. */

    // set initial gap size where gap is number of elements or size of the array
    int gap = n;
    // set the shrink factor to 1.3
    float shrink = 1.3;
    // set swapped flag to true so it runs
    int swapped = 1;

    // while the gap is more than 1 or swapped flag is true,
    // check if the current record element's idNumber is greater than the element at the gap
    // when the gap is 1 or nothing has been swapped anymore, the array is sorted
    // the sorting may stop even before the gap reaches 1
    while (gap > 1 || swapped == 1)
    {
        // shrink the gap every time the for loop is done
        combSortShrink(&gap, shrink);
        // set swapped flag to false, once a check has been done and all elements are in order, it will never be set to true again
        swapped = 0;

        // do comparison here
        for (int i = 0; i < (n - gap); i++) // n - gap because we don't want to go out of bounds
        {
            Record temp; // temp variable to store the struct set to be swapped

            if (arr[i].idNumber > arr[i + gap].idNumber)
            {
                // swap the entire record
                temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                // set swapped flag to true because the condition for swapping was met
                swapped = 1;
            }
        }
    }

    //printRecord(arr, n);
}


/*******************************/
/* Below are the modified functions that allow us to track the steps taken for each file and get the empirical frequency count. */

/* Step counting variable was renamed to count due to step already being used as a variable name */
void insertionSortWithStepsAsCount(Record *arr, int n)
{
    long long int count; //added
    int step; count++;
    for (count++, step = 1;count++, step < n;count++, step++)
    {
        Record key = arr[step]; count++;
        int j = step - 1; count++;
        while (count+=2, j >= 0 && key.idNumber < arr[j].idNumber) 
        {
            arr[j + 1] = arr[j]; count++;
            j = j - 1; count++;
        }
        arr[j + 1] = key; count++;
    }
    
    count++; //for return
    printf("Insertion Sort Steps: %lld\n", count); //added
    return;
}


void selectionSortWithStep(Record *arr, int n)
{
    long long int step; //added
    int i, j, min; step+=3;
    Record temp; step++;

    for (step++, i = 0; step++, i < (n - 1);step++, i++)
    {
        min = i; step++;
        for (step++, j = i + 1;step++, j < n;step++, j++)
        {
            if (step++, arr[j].idNumber < arr[min].idNumber)
                min = j; step++;
        }
        if (step++, min != i)
        {
            temp = arr[i]; step++;
            arr[i] = arr[min]; step++;
            arr[min] = temp; step++;
        }
    }
    step++; //for return
    printf("Selection Sort Steps: %lld\n", step); //added
    return; 
}

/* mergeSortWithStep helper function */
 void mergeWithStep(Record *arr, int left, int mid, int right, Record *temp, long long int *step) {
    int i = left, j = mid + 1, k = left; step+=3;

    while (step++, i <= mid && j <= right) {
        if (step++, arr[i].idNumber <= arr[j].idNumber) {
            temp[k++] = arr[i++]; step++;
        } else {
            temp[k++] = arr[j++]; step++;
        }
    }

    while (step++, i <= mid) {
        temp[k++] = arr[i++]; step++;
    }

    while (step++, j <= right) {
        temp[k++] = arr[j++]; step++;
    }

    for (step++, i = left;step++, i <= right;step++, i++) {
        arr[i] = temp[i]; step++;
    }
}

void mergeSortWithStep(Record *arr, int n) {

    long long int step; //added
    Record *temp = (Record *)malloc(n * sizeof(Record)); step++;
    int current_size, left_start; step++; //added

    for (step++, current_size = 1;step++, current_size <= n - 1; step++, current_size *= 2) {
        for (step++, left_start = 0;step++, left_start < n - 1;step++, left_start += 2 * current_size) {
            int mid = (left_start + current_size - 1) < (n - 1) ? (left_start + current_size - 1) : (n - 1); step++;
            int right_end = (left_start + 2 * current_size - 1) < (n - 1) ? (left_start + 2 * current_size - 1) : (n - 1); step++;
            
            mergeWithStep(arr, left_start, mid, right_end, temp, &step); step++;
        }
    }
    free(temp); step++;
    printf("Merge Sort Steps: %lld\n", step); //added
}

/* combSortWithStep helper function */
void combSortShrinkWithStep(int *gap, float shrink, long long int *step)
{
    *gap /= shrink; step++;

    if (step++, *gap < 1)
        *gap = 1; step++;

}

void combSortWithStep(Record *arr, int n)
{
    long long int step; //added
    int gap = n; step++;
    int i; step++;
    float shrink = 1.3; step++;
    int swapped = 1; step++;

    while (step++, gap > 1 || swapped == 1)
    {
        combSortShrinkWithStep(&gap, shrink, &step); step++;
        swapped = 0; step++;

        for (step++, i = 0;step++, i < (n - gap); step++, i++) 
        {
            Record temp; step++;

            if (step++, arr[i].idNumber > arr[i + gap].idNumber)
            {
                temp = arr[i]; step++;
                arr[i] = arr[i + gap]; step++;
                arr[i + gap] = temp; step++;
                swapped = 1; step++;
            }
        }
    }
    printf("Comb Sort Steps: %lld\n", step); //added
}

#endif
