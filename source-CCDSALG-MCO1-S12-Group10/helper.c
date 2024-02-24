//contains the names of all the original data set file names
char txtNames[8][50] = 
    {
        "random100.txt",
        "random25000.txt",
        "random50000.txt",
        "random75000.txt",
        "random100000.txt",
        "fullysorted.txt",
        "almostsorted.txt",
        "totallyreversed.txt"
    };

//array of strings to name the insert-sorted data sets
char insertSortedNames[8][50] = 
    {
        "insertionsorted_random100.txt",
        "insertionsorted_random25000.txt",
        "insertionsorted_random50000.txt",
        "insertionsorted_random75000.txt",
        "insertionsorted_random100000.txt",
        "insertionsorted_fullysorted.txt",
        "insertionsorted_almostsorted.txt",
        "insertionsorted_totallyreversed.txt"
    };
    
//array of strings to name the selection-sorted data sets
char selectionSortedNames[8][50] = 
    {
        "selectionsorted_random100.txt",
        "selectionsorted_random25000.txt",
        "selectionsorted_random50000.txt",
        "selectionsorted_random75000.txt",
        "selectionsorted_random100000.txt",
        "selectionsorted_fullysorted.txt",        
        "selectionsorted_almostsorted.txt",
        "selectionsorted_totallyreversed.txt"
    };


//array of strings to name the mergesorted data sets
char mergeSortedNames[8][50] = 
    {
        "mergesorted_random100.txt",
        "mergesorted_random25000.txt",
        "mergesorted_random50000.txt",
        "mergesorted_random75000.txt",
        "mergesorted_random100000.txt",
        "mergesorted_fullysorted.txt",        
        "mergesorted_almostsorted.txt",
        "mergesorted_totallyreversed.txt"
    };

//array of strings to name the heap-sorted data sets
char heapSortedNames[8][50] = 
    {
        "heapsorted_random100.txt",
        "heapsorted_random25000.txt",
        "heapsorted_random50000.txt",
        "heapsorted_random75000.txt",
        "heapsorted_random100000.txt",
        "heapsorted_fullysorted.txt",
        "heapsorted_almostsorted.txt",
        "heapsorted_totallyreversed.txt"
    };

void printToFile(Record *arr, int n, char *var) //prints the arranged data sets into a file
{
	FILE *fp;
	
	fp = fopen(var, "w");
	
	int i;
	
	for(i = 0; i < n; i++)
		fprintf(fp, "%d %s\n", arr[i].idNumber, arr[i].name);
	
	fclose(fp);
}