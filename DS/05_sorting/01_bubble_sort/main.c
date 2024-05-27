#include<stdio.h>
#include<stdlib.h>

void bubblesort(int arr[], int n)
{
	int i, j, temp, flag;
	for(i=0; i< n-1; i++)
	{		
		for(j=0; j<n-1-i; j++)
		{
			flag=0;
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
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
	bubblesort(arr,n);
	printf("Sorted Array: ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}