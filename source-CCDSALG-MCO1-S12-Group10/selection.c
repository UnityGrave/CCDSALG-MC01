#include "sortingalgorithms.c"
#include "record.c"
#include "timer.c"
#include "filereader.c"
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
extern char txtNames[8][50];
extern char selectionSortedNames[8][50];

void selectionAlgo(int n, long long int *OutCnt, long long int *InCnt, Record *arr, double startTime, double endTime, double executionTime) //the "body" of the selection program
{   
	FILE *fp, *wp;  //*fp is used repeatedly to read the files' length, *wp is used repeatedly across multiple files to generate data files

    int i;

    printf("\nSELECTION SORTING ALGORITHM\n\n\n");

    wp = fopen("SelectionSortData.txt", "w");

    //loops the number of text files
    for(i = 0; i < 8; i++)
    {
        //reads the length for each file in preparation for the use of malloc
        fp = fopen(txtNames[i], "r");
        fscanf(fp, "%d", &n);
        fclose(fp);
        
        arr = (Record*)malloc(n * sizeof(Record));

        readFile(arr, txtNames[i]);
        startTime = currentTimeMillis();
        selectionSort(arr, n, OutCnt, InCnt);   //the "heart" of the selection sort algorithm
        endTime = currentTimeMillis();
        executionTime = (endTime - startTime) / 1000;   //converts the execution time into seconds

        //printToFile(arr, n, selectionSortedNames[i]);   //prints the sorted data set into a file, disabled by default

        //set of print statements, for terminal and files
        printf("%s execution time: 		%.3lf seconds\n", txtNames[i], executionTime);
        printf("Outer loop executed %lld times, inner loop executed %lld times.\n", *OutCnt, *InCnt);  //displays the iterations of the inner and outer loop on the terminal
        printf("%s file generated...\n\n", selectionSortedNames[i]);
        fprintf(wp, "%s:\nExecution time in seconds: %.3lf\n", txtNames[i], executionTime);
        fprintf(wp, "Outer loop executed %lld times\nInner loop executed %lld times.\n\n", *OutCnt, *InCnt);  //writes the iterations of the inner and outer loop on a data results file
    }
    
    printf("SelectionSortData.txt file generated...\n\n");
    fclose(wp);
}
