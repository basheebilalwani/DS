#include<stdio.h>
#include<stdlib.h>
 void insertsort(int arr[], int n)
 {
 	int i, j, temp;
 	for(i=1; i<n; i++)
 	{
 		temp=arr[i];
 		j=i-1;
 		while(j>=0 && arr[j]>temp)
 		{
 			arr[j+1]= arr[j];
 			j--;
		}
		 arr[j+1]= temp;
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
	insertsort(arr,n);
	printf("Sorted Array: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}