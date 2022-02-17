#include "the2.h"

//You may write your own helper functions here
void swap_help(unsigned short* first, unsigned short* sec)
{
    int temp = *first;
    *first = *sec;
    *sec = temp;
}

int absolute(int x)
{
    if (x < 0)
    {
        x = (-1)*x;
    }
    
    return x;
}

int partition(unsigned short* arr, int size, long &swap, double &avg_dist, double &max_dist)
{
    unsigned short x = arr[size-1];
    int i = -1;
    int j, k;
    
    for (j = 0; j < size-1; j++)
    {
        if (arr[j] >= x)
        {
            i += 1;
            swap_help(&arr[i], &arr[j]);
            swap += 1;
            k = absolute(i-j);
            avg_dist += k;
            
            if (max_dist < k)
            {
                max_dist = k;
            }
            
        }
    }
    swap_help(&arr[i+1], &arr[size-1]);
    return i+1;
}


void quickSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size)
{
    int p;
    //Your code here
    if (!hoare)
    {
        if (size > 1)
        {
            p = partition(arr, size, swap, avg_dist, max_dist);
            quickSort(arr, swap, avg_dist, max_dist, false, p);
            quickSort(arr+p+1, swap, avg_dist, max_dist, false, (size-p)-1);
        }
    }
    
    avg_dist = avg_dist / size;
	
}

void quickSort3(unsigned short *arr, long &swap, long &comparison, int size) {
	
    //Your code here
	
}