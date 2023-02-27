#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *arr , int size , int *count)
{
    
    for(int i = 0 ; i < size - 1 ; i++)
    {
        for(int j = i + 1 ; j > 0 ; j--)
        {
            if(arr[j - 1] > arr[j])
            {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
			   *count  = *count + 1;
            }
        }
    }
    
}

void quickSort(int arr[], int s, int e , int *count) 
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
    (*count) = (*count) + 1;


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
			(*count) = (*count) + 1;
        }

    }
  
    quickSort(arr, s, pivotIndex - 1 , count);
   
    quickSort(arr, pivotIndex + 1, e , count);

}

void merge(int *arr , int s , int e , int *count)
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
		(*count) = (*count) + 1;
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
void mergeSort(int *arr , int s , int e , int *count)
{
	if(s >= e) return;

	int mid = s + (e - s) / 2;
	
	mergeSort(arr , s , mid , count);
	mergeSort(arr , mid + 1 , e , count);
	
	merge(arr , s , e , count);	

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
	int size = 100000 , r , k = 0;
	int block = 100;
	FILE *fptr1 = fopen("Sorted3.txt" , "w");
	int *comp = (int *)malloc(sizeof(int) * 1000);
	for(int i = block ; i <= size ; i = i + 100)
	{
		int count = 0;
		//printf("\nSorting Block number :%d\n",(i/block));
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
		//quickSort(arr, 0 , i - 1 , &count);
		mergeSort(arr , 0 , i - 1 , &count);
		//insertionSort(arr , i ,&count);
		end = clock();
		printf("%f\n", ((double)(end - start)/CLOCKS_PER_SEC));

		//printf("\n");
		fprintf(fptr1 , "\nSorting Block number :%d\n",(i/block));
		for(int j = 0 ; j < i ; j++)
		{
			//printf("%d\t",arr[j]);
			fprintf(fptr1 , "%d\t" , arr[j]);	
		}
		fprintf(fptr1 , "\nTime taken:%f\nNumber of Comparisons made : %d\n",((double)(end - start)/CLOCKS_PER_SEC),count);
		comp[k++] = count;
		//printf("\n");
		free(arr);
		fclose(fptr);
	}
	//fclose(fptr1);	
	for(int i = 0 ; i < 1000 ; i++)
	{
		printf("%d\n",comp[i]);
	}
	free(comp);
}
	
