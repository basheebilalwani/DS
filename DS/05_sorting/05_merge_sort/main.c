#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int lb, int mid, int ub)
{
	int i=lb;
	int j= mid+1;
	int k = lb; 
	int b[ub];
	while(i<=mid && j<=ub)
{
	if(arr[i]<= arr[j])
{
	b[k]=arr[i];
	i++;
}
else
{
 b[k]=arr[j];
 j++;
}
	k++;
}
if(i>mid)
{
	while(j>=ub)
{
	b[k]=arr[j];
	j++; k++;
}
}
if(j>ub)
{
	while(i<=mid)
{
	b[k]=arr[i];
	k++; i++;
}
}
for(k=lb; k<=ub;k++)
{
	arr[k]=b[k];
}	
}
void mergesort(int arr[], int lb, int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mergesort(arr, lb, mid);
		mergesort(arr, mid+1, ub);
		merge(arr, lb, mid, ub);
	}
}
int main()
{
	int arr[]= {64, 25, 12, 22, 11};
	int n= sizeof(arr)/sizeof(arr[0]);
	int i;
	int lb=0;
	int ub= n-1;
	printf("Original Array: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	mergesort(arr,lb,ub);
	printf("Sorted Array: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}