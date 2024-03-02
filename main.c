#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
//added
#include <stdlib.h>

// defining file relative paths, to be switched out per test
#define almostSortedFilePath "data\\almostsorted.txt"       // unable to run (100000) update: able to run
#define random100FilePath "data\\random100.txt"             // able to run (100)
#define random25000FilePath "data\\random25000.txt"         // unable to run (25000) update: able to run
#define random50000FilePath "data\\random50000.txt"         // unable to run (50000) update: able to run
#define random75000FilePath "data\\random75000.txt"         // unable to run (75000) update: able to run
#define random100000FilePath "data\\random100000.txt"       // unable to run (100000) update: able to run
#define totallyReversedFilePath "data\\totallyreversed.txt" // unable to run (100000) update: able to run
// custom test files
#define extremelySmall10FilePath "custom\\extremelysmall10.txt"       // able to run (10)
#define custom500duplicatesFilePath "custom\\custom500duplicates.txt" // able to run (500)
#define limitationscheckFilePath "custom\\limitationscheck.txt"       // able to run any amount of lines 

//CURRENT FILE PATH - CHANGE THIS LINE TO CHANGE FILES
#define currentFilePath random25000FilePath

long runMergeSortTest(Record *records, int n)
{
    long averageExecutionTime = 0;
    long start, end, executionTime;

    // benchmark algorithm at least 5 times and average the results
    for (int i = 0; i < 5; i++)
    {
        start = 0;
        end = 0;
        executionTime = 0;
        printf("MERGE SORT ITERATION %d\n", i);
        start = currentTimeMillis(); // store the current time
        printf("Start Time: %ld\n", start);
        mergeSort(records, n); // Pass the correct arguments // updated parameters
        end = currentTimeMillis(); // store the current time
        printf("End Time: %ld\n", end);
        executionTime = end - start;
        printf("Merge Sort took %ld milliseconds to execute.\n", executionTime);
        averageExecutionTime += executionTime; // add to overall average
        printf("Current Total Average Execution Time: %ld\n\n", averageExecutionTime);
        readFile(records, currentFilePath);
    }
    return averageExecutionTime / 5.0;
}

long runSelectionSortTest(Record *records, int n)
{
    long averageExecutionTime = 0;
    long start, end, executionTime;

    // benchmark algorithm at least 5 times and average the results
    for (int i = 0; i < 5; i++)
    {
        start = 0;
        end = 0;
        executionTime = 0;
        printf("SELECTION SORT ITERATION %d\n", i);
        start = currentTimeMillis(); // store the current time
        printf("Start Time: %ld\n", start);
        selectionSort(records, n); // run sorting alg
        end = currentTimeMillis(); // store the current time
        printf("End Time: %ld\n", end);
        executionTime = end - start;
        printf("Selection Sort took %ld milliseconds to execute.\n", executionTime);
        averageExecutionTime += executionTime; // add to overall average
        printf("Current Total Average Execution Time: %ld\n\n", averageExecutionTime);
        readFile(records, currentFilePath);
    }
    return averageExecutionTime / 5.0;
}

long runInsertionSortTest(Record *records, int n)
{
    long averageExecutionTime = 0;
    long start, end, executionTime;

    // benchmark algorithm at least 5 times and average the results
    for (int i = 0; i < 5; i++)
    {
        start = 0;
        end = 0;
        executionTime = 0;
        printf("INSERTION SORT ITERATION %d\n", i);
        start = currentTimeMillis(); // store the current time
        printf("Start Time: %ld\n", start);
        insertionSort(records, n); // run sorting alg
        end = currentTimeMillis(); // store the current time
        printf("End Time: %ld\n", end);
        executionTime = end - start;
        printf("Insertion Sort took %ld milliseconds to execute.\n", executionTime);
        averageExecutionTime += executionTime; // add to overall average
        printf("Current Total Average Execution Time: %ld\n\n", averageExecutionTime);
        readFile(records, currentFilePath);
    }
    return averageExecutionTime / 5.0;
}

/*
    This function returns the number of lines in a file.
    It is used to determine the size of the array to be passed into the sorting algorithms.
*/
int getFileLineNumber(char path[])
{
    FILE *fp;
    int n = 0;
    fp = fopen(path, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s", path);
        return 0;
    }

    fscanf(fp, "%d", &n); // N is the first line in the notepad file which denotes the amount of lines.
    fclose(fp);
    return n;
}

/*
    This main function will not be checked for grading.
    1. Declares a dynamic array currentRecord containing Record structs to be passed into the sorting algorithms.
    2. Gets the number of lines in the file to be passed into sorting algorithms (See getFileLineNumber() function above).
    3. The address of the record struct (passing an array without & gives the address anyway) and the number of lines n in the file are passed into the sorting algorithms.
    4. Individual sorting algorithms are called 5 times (see above) and the average time is printed to the console in main.

    Notes before running, printRecord function in sortingalgorithms.c is called twice in each sorting algorithm and has "a+" which means it will append to the file. 
*/
int main()
{
    int n = getFileLineNumber(currentFilePath);
    /* For checking if file can be read and if it actually gets the first number in line */
    //printf("Current File Total line Number: %d\n", n);

    /* Replaced Record currentRecord[n]; with below*/
    Record *currentRecord = malloc(n * sizeof(Record)); //pointer is declared, stores the address of a dynamically allocated memory block.
    if (currentRecord == NULL) {
        printf("Error: failed to allocate memory for currentRecord\n");
        return 1;
    }

    readFile(currentRecord, currentFilePath);

    /* For checking if it actually reads the file and stores it into the array */
    //printf("FIRST LINE OF RECORD ARRAY: %d%s\n", currentRecord[0].idNumber, currentRecord[0].name);
    //printf("LAST LINE OF RECORD ARRAY: %d%s\n", currentRecord[n - 1].idNumber, currentRecord[n - 1].name);

    /* Uncomment depending on which should run */
    printf("Average execution time for Insertion Sort %ld milliseconds\n\n", runInsertionSortTest(currentRecord, n));
    printf("Average execution time for Selection Sort %ld milliseconds\n\n", runSelectionSortTest(currentRecord, n));
    printf("Average execution time for Merge Sort %ld milliseconds\n\n", runMergeSortTest(currentRecord, n));

    /* For counting empirical frequency, uncomment depending on which should run */
    //insertionSortWithStepsAsCount(currentRecord, n);
    //readFile(currentRecord, currentFilePath);

    //selectionSortWithStep(currentRecord, n);
    //readFile(currentRecord, currentFilePath);

    //mergeSortWithStep(currentRecord, n);
    //readFile(currentRecord, currentFilePath);

    //combSortWithStep(currentRecord, n);

    free(currentRecord);
    return 0;
}
