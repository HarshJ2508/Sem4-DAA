#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *arr , int size)
{
    time_t begin = time(NULL);
    for(int i = 0 ; i < size - 1 ; i++)
    {
        for(int j = i + 1 ; j > 0 ; j--)
        {
            if(arr[j - 1] > arr[j])
            {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
            }
        }
    }
    time_t end = time(NULL);
    printf("%d\n",(end - begin) );
}

void selectionSort(int *arr , int size)
{
	time_t begin = time(NULL);
	
	// One by one move boundary of unsorted subarray
	for (int i = 0; i < size; i++)
	{
        // Find the minimum element in unsorted array
		int min = i;
		for (int j = i+1; j < size; j++) 
		{
			if (arr[j] < arr[min]) min = j;
		}
 
        // Swap the found minimum element with the first element
		if(min != i) 
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}	
	time_t end = time(NULL);
    	printf("%d\n", (end - begin));
}
int main()
{
	//Generating random numbers in "Random_No.txt"

	FILE *fptr = fopen("Random_No.txt" , "w");
	int size = 100000 , r;
	for(int i = 0 ; i < size ; i++) {
		r = rand()%100000 + 1;
		fprintf(fptr , "%d\n" , r);
	}
	fclose(fptr);

	//Reading random numbers from "Random_No.txt"
	int block = 100;
	for(int i = block ; i <= size ; i = i + 100)
	{
		
		fptr = fopen("Random_No.txt" , "r");
		int *arr = (int *)malloc(sizeof(int) * i);
		int *arr_copy = (int *)malloc(sizeof(int) * i);
		for(int j = 0 ; j < i ; j++)
		{
			fscanf(fptr , "%d" , &r);
			//printf("%d\t",r);
			arr[j] = r;
			arr_copy[j] = arr[j];
		}
		//Calculating time taken by each block for Insertion Sort.
		
		insertionSort(arr , i);
		selectionSort(arr_copy , i);
		
		free(arr);
		free(arr_copy);
		fclose(fptr);
	}
	
}
	