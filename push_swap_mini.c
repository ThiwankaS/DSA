#include <stdio.h>
#include <stdlib.h>

void print(int *arr)
{
	for(int i = 0;i < 3;i++)
		printf("arr[%d] : %d \n", i, arr[i]);
	printf("..............................\n");
}

void rotate(int *arr)
{
	int temp = arr[2];
	arr[2] = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	printf("ra\n");
}

void reverse_rotate(int *arr)
{
	int temp = arr[0];
	arr[0] = arr[2];
	arr[2] = arr[1];
	arr[1] = temp;
	printf("rra\n");
}

void swap(int *arr)
{
	int temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
	printf("sa\n");
}

int isSorted(int *arr)
{
	return(arr[2] > arr[1] && arr[1] > arr[0]);
}

void sort(int *arr)
{
	int count = 0;
	while(!isSorted(arr))
	{
		if(arr[0] > arr[2])
			rotate(arr);
		else if(arr[0] > arr[1])
			swap(arr);
		else if(arr[1] > arr[2])
			reverse_rotate(arr);
		count++;
	}
	print(arr);
	printf("stack sorted in (%d) steps.....\n", count);
}

int main(int argc, char *argv[])
{
	int arr[3];

	if(argc == 4)
	{
		arr[0] = atoi(argv[1]);
		arr[1] = atoi(argv[2]);
		arr[2] = atoi(argv[3]);
		printf("Stack before sorting....\n");
		print(arr);
		sort(arr);
		printf("Stack after sorting....\n");
	}
}
