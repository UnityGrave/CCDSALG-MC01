#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include "insert.c"
#include "heap.c"
#include "selection.c"
#include "merge.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
	int n = 0;
    double startTime = 0.0, endTime = 0.0, executionTime = 0.0;
    long long int InCnt = 0, OutCnt = 0;
    Record *arr = 0;
	insertAlgo(n, &OutCnt, &InCnt, arr, startTime, endTime, executionTime);

	selectionAlgo(n, &OutCnt, &InCnt, arr, startTime, endTime, executionTime);
	
	mergeAlgo(n, &OutCnt, &InCnt, arr, startTime, endTime, executionTime);

	heapAlgo(n, &OutCnt, &InCnt, arr, startTime, endTime, executionTime);
    
    return 0;
}
