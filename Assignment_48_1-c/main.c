#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int s, int e) 
{
    if(s >= e) return ;

  
	int pivot = arr[s];

    int cnt = 0 , i = s, j = e;
    for(int i = s+1; i<=e; i++) 
	{
        if(arr[i] <=pivot) cnt++;
    }

    int pivotIndex = s + cnt;
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[s];
    arr[s] = temp;


    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex) {
            
			int temp = arr[i];
    			arr[i++] = arr[j];
    			arr[j--] = temp;
        }

    }
  
    quickSort(arr, s, pivotIndex - 1);
   
    quickSort(arr, pivotIndex + 1, e);

}

void merge(int *arr , int s , int e)
{
	int mid = s + (e - s) / 2;

	int l1 = mid - s + 1;
	int l2 = e - mid;
	
	int *arr1 = (int *)malloc(sizeof(int) * l1);
	int *arr2 = (int *)malloc(sizeof(int) * l2);

	int k = s;
	for(int i = 0 ; i < l1 ; i++)
	{
		arr1[i] = arr[k++];
	}
	for(int i = 0 ; i < l2 ; i++)
	{
		arr2[i] = arr[k++];
	}

	int ptr1 = 0 , ptr2 = 0;
	k = s;
	while(ptr1 < l1 && ptr2 < l2)
	{
		if(arr1[ptr1] < arr2[ptr2])
		{
			arr[k++] = arr1[ptr1++];
		}
		else arr[k++] = arr2[ptr2++];
	}
	while(ptr1 < l1)
	{
		arr[k++] = arr1[ptr1++];
	}
	while(ptr2 < l2)
	{
		arr[k++] = arr2[ptr2++];
	}
	free(arr1);
	free(arr2);

}
void mergeSort(int *arr , int s , int e)
{
	if(s >= e) return;

	int mid = s + (e - s) / 2;
	
	mergeSort(arr , s , mid);
	mergeSort(arr , mid + 1 , e);
	
	merge(arr , s , e);	

}

int main()
{
	//Generating random numbers in "Random_No.txt"

	FILE *fptr = fopen("Random_No1.txt" , "w");
	
	for(int i = 0 ; i < size ; i++) {
		r = rand()%100000 + 1;
		fprintf(fptr , "%d\n" , r);
	}
	fclose(fptr);

	//Reading random numbers from "Random_No.txt"
	int size = 100000 , r;
	int block = 100;
	//Storing sorted numbers in "Sorted.txt"
	FILE *fptr1 = fopen("Sorted.txt" , "w");
	for(int i = block ; i <= size ; i = i + 100)
	{
		printf("\nSorting Block number :%d\n",(i/block));
		
		FILE *fptr = fopen("Random_No1.txt" , "r");
		int *arr = (int *)malloc(sizeof(int) * i);
		
		for(int j = 0 ; j < i ; j++)
		{
			fscanf(fptr , "%d" , &r);
			arr[j] = r;
			//printf("%d\t",arr[j]);
			
		}
		clock_t start , end;
		start = clock();
		quickSort(arr, 0 , i - 1);
		//mergeSort(arr , 0 , i - 1);
		end = clock();
		printf("%f\n", ((double)(end - start)/CLOCKS_PER_SEC));
		
		printf("\n");
		for(int j = 0 ; j < i ; j++)
		{
			
			//printf("%d\t",arr[j]);
			fprintf(fptr , "%d\n" , arr[j]);
			
		}
		printf("\n");
		free(arr);
		fclose(fptr);
	}
	fclose(fptr1);
}
	
