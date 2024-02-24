#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

void swap(Record *a, Record *b) 
{
	Record temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(Record *arr, int n, long long int *OutCnt, long long int *InCnt) //main insertion sort program
{
    int i;
    int key;
    int j;
    char sav[50];
    Record plhd;
    *OutCnt = 0;  //outer loop counter
    *InCnt = 0;   //inner loop counter
    
    
    for(i = 1; i < n; i++)  //starts from the second element and goes through the entire array
    {
        key = arr[i].idNumber;
        strcpy(sav, arr[i].name);
        plhd = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j].idNumber > key)  //runs until arr[j] is the first element or arr[j].idNumber 
        {
            arr[j+1].idNumber = arr[j].idNumber;   //shifts the values to the right to make space for the inserted value
            strcpy(arr[j+1].name, arr[j].name);

            j = j - 1;
            *InCnt = *InCnt + 1;
        }
        arr[j+1] = plhd;    //the insertion of the value in the array
        *OutCnt = *OutCnt + 1;
    }
}

void selectionSort(Record *arr, int n, long long int *OutCnt, long long int *InCnt)
{
    int i, j, minIndex;
    *OutCnt = 0;  //outer loop counter
    *InCnt = 0;   //inner loop counter
    
    for (i = 0; i < n-1; i++){
    	minIndex = i;
    	for (j = i+1; j < n; j++){
    		if (arr[j].idNumber < arr[minIndex].idNumber)
    			minIndex = j;
    			
            *InCnt = *InCnt + 1;
		}
		
		if (minIndex != i)
			swap(&arr[minIndex], &arr[i]);
			
        *OutCnt = *OutCnt + 1;
	}
}

void merge(Record* arr, int p, int q, int r, long long int *InCnt)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    Record *L = (Record *)malloc(n1 * sizeof(Record));
    Record *R = (Record *)malloc(n2 * sizeof(Record));

    int i, j, k;
    *InCnt = 0; // inner loop counter

    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i].idNumber <= R[j].idNumber)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        *InCnt = *InCnt + 1;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        *InCnt = *InCnt + 1;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        *InCnt = *InCnt + 1;
    }

    free(L);
    free(R);
}

void mergeSortHelper(Record* arr, int p, int r, long long int *OutCnt, long long int *InCnt)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        mergeSortHelper(arr, p, q, OutCnt, InCnt);
        *OutCnt = *OutCnt + 1;
        mergeSortHelper(arr, q + 1, r, OutCnt, InCnt);
        *OutCnt = *OutCnt + 1;
        merge(arr, p, q, r, InCnt);
        *OutCnt = *OutCnt + 1;
    }
    else
    {
        *OutCnt = *OutCnt + 1;
        *InCnt = *InCnt + 1;
    }
}

void mergeSort(Record *arr, int n, long long int *OutCnt, long long int *InCnt)
{
    *OutCnt = 0;
    *InCnt = 0;
    mergeSortHelper(arr, 0, n - 1, OutCnt, InCnt);
}

// function to build the max heap
void heapify(Record arr[], int n, int root, long long int *InCnt) 
{
    int largest = root;
    int left_child = 2 * root + 1;
    int right_child = 2 * root + 2;
    
    if (left_child < n && arr[left_child].idNumber > arr[largest].idNumber)
        largest = left_child;
    
    if (right_child < n && arr[right_child].idNumber > arr[largest].idNumber)
        largest = right_child;
    
    if (largest != root) {
        swap(&arr[root], &arr[largest]);
        heapify(arr, n, largest, InCnt);
    }
    *InCnt = *InCnt + 1;
}

void heapSort(Record *arr, int n, long long int *OutCnt, long long int *InCnt) 
{
    int i;
	
	*OutCnt = 0;
    *InCnt = 0;
    for (i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i, InCnt);
        *OutCnt = *OutCnt + 1;
    }

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, InCnt);
        *OutCnt = *OutCnt + 1;
    }
}

#endif
