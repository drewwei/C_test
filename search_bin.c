#include <stdio.h>

int search_bin(int *q, int len, int val)
{
	int low = 0, high = len - 1;
	int mid;
	while(low <= high)
	{
		mid = (high+low)/2;
		if(q[mid] == val)
			return mid;
		
		else if(q[mid] > val)
			high = mid - 1;
		else 
			low = mid + 1;
	}
	
	return -1;
}
int Partition(int *q, int low, int high)
{
	int key = q[low];
	while(low < high)
	{
		while((low < high)&&(q[high] >= key))
			high--;
		q[low] = q[high];
		while((low < high)&&(q[low] <= key))
			low++;
		q[high] = q[low];	
	}
	q[low] = key;
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

int arry[] = {20,10,66,3,6,25,30,24,65,95,66,44,13,8,6};

int main()
{
	int i, ret, a;
	int len = sizeof(arry)/sizeof(int);
	QuickSort(arry, len);
	for(i = 0; i < len; i++)
	{
		printf("%d\t",arry[i]);
	}
	printf("\n");
	scanf("%d",&a);
	ret = search_bin(arry, len, a);
	if(ret == -1)
	{
		printf("can not find !\n");
	}
	else{
		printf("find  the number is %d\n", ret);
	}
	
	return 0;
}
























