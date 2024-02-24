#include <stdio.h>

// Selection sort
void SelectionSort(int A[], int n) {
	
int i, j, min, temp;

	for (i = 0; i < n - 1; i++) {
		min = i; // min is the index of the lowest element
		
	for (j = i + 1; j < n; j++)
		if (A[min] > A[j])
		min = j;
		// swap A[i] with A[min]

	if (i != min) {
	temp = A[i];
		A[i] = A[min];
			A[min] = temp;
		}
	}
}

