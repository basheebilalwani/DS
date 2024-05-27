#include<stdio.h>
#include<stdlib.h>
void swap(int*p1, int*p2)
{
	int temp;
	temp= *p1;
	*p1=*p2;
	*p2=temp;
}

void heapify(int arr[], int n, int i )
{
	int largest=i;
	int left= 2*i+1;
	int right= 2*i+2;
	
	if(left<n && arr[left]>arr[largest])
	{
		largest= left;
	}	
	
	if(right<n && arr[right]>arr[largest])
	{
		largest=right;
	}
	
	if(largest!=i)
	{
		swap(&arr[i],&arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[], int n)
{
	for(int i= n/2-1; i>=0; i--)
		heapify(arr, n, i);
	for(int i= n-1; i>=0; i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr, i, 0);
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
	heapsort(arr,n);
	printf("Sorted Array: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}