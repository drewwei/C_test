#include <stdio.h>
void Swap(int *q, int a, int b)
{
	/*
	q[a] = q[a] + q[b];
	q[b] = q[a] - q[b];
	q[a] = q[a] - q[b];
	*/
	int temp;
	temp = q[a];
	q[a] = q[b];
	q[b] = temp;
}

int Partition(int *q, int low, int high)
{
	int key = q[low];
	while(low < high)
	{
		while((low < high)&&(q[high] >= key))
			high--;
		Swap(q, low, high);
		while((low < high)&&(q[low] <= key))
			low++;
		Swap(q, low, high);	
	}
	return low;
}
void _QuickSort(int *q, int low, int high)
{
	int off;
	if(low < high)
	{
		off = Partition(q,low, high);
		_QuickSort(q, low, off-1);
		_QuickSort(q, off+1, high);
	}
}

void QuickSort(int *q, int length)
{
	_QuickSort(q, 0, length-1);
}

int main()
{
	int i;
	int a[] = {20,10,66,3,6,25,30,24,65,95,66,44,13,8,6};
	int len = sizeof(a)/sizeof(int);
	QuickSort(a, len);
	for(i = 0; i < len; i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
























