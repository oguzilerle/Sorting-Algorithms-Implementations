#include "the1.h"


//You can add your own helper functions

int sillySort(int* arr, long &comparison, long & swap, int size) 
{

    int num_of_calls=1;
	int i, j, temp, k, l;
	
	int q12[size/2];
	int q23[size/2];
	int q34[size/2];
	
	
	//Your code here
	if (size < 4)
	{
	    if (arr[0] > arr[1])
	    {
	        temp = arr[0];
	        arr[0] = arr[1];
	        arr[1] = temp;
	        swap += 1;
	    }
        comparison += 1;
	}
	else
	    {
	        num_of_calls += sillySort(arr, comparison, swap, size/2);
	        num_of_calls += sillySort(arr+(size/4), comparison, swap, size/2);
	        num_of_calls += sillySort(arr+(size/2), comparison, swap, size/2);
	        num_of_calls += sillySort(arr, comparison, swap, size/2);
	        num_of_calls += sillySort(arr+(size/4), comparison, swap, size/2);
	        num_of_calls += sillySort(arr+(size/2), comparison, swap, size/2);
	    }
	return num_of_calls;
}

int merge(int* A, int p, int q, int r)
{
    int n, m, i, j, k, comparison;
    
    n = q - p + 1;
    m = r - q;
    comparison = 0;
    int L[n+1];
    int R[m+1];
    
    for (i = 0; i < n; i++)
    {
        L[i] = A[p+i-1];
    }
    
    for (j = 0; j < m; j++)
    {
        R[j] = A[q+j];
    }
    
    L[n] = 10000000;
    R[m] = 10000000;
    i = 1;
    j = 1;
    for (k = p; k < r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i += 1;
            comparison += 1;
        }
        else
        {
            A[k] = R[j];
            j += 1;
            comparison += 1;
        }
    }
    
    return comparison;
}

int mergeSort(int* arr, int l, int r, long &comparison, int size)
{
    int m;
    int num_of_calls=1;
	int temp;
	if (size == 2)
	{
	    if (arr[0] > arr[1])
	    {
	        temp = arr[1];
	        arr[1] = arr[0];
	        arr[0] = temp;
	    }
	    comparison += 1;
	}
	
	else if (size > 2)
	{

	return num_of_calls;
    m = l + (r-l)/2;
    
    mergeSort(arr, l, m, comparison, size/2);
    mergeSort(arr, m, r, comparison, size/2);
    merge(arr, l, m, r);
    
	}
	
	return num_of_calls;
}

int crossMergeSort(int *arr, long &comparison, int size)
{
	
	int num_of_calls=1;
    
	// Your code here
	num_of_calls = mergeSort(arr, 0, size, comparison, size);
	
	return num_of_calls;
	
}