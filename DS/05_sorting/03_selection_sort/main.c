#include<stdio.h>
#include<stdlib.h>

void selectionsort(int arr[], int n)
{
	int i, j, min,temp;
	for(i=0; i<n-1; i++)
	{
		int min=i;
		for(j=i+1; j<n; j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		if(min!=i)
		{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
	}
}

int main()
{
	int arr[]= {64, 25, 12, 22, 11};
	int n= sizeof(arr)/sizeof(arr[0]);
	int i;
	printf("Original Array: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	selectionsort(arr,n);
	printf("Sorted Array: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}