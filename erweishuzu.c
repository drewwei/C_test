#include<stdio.h>
void main()
{
int i,j;
int A[3][4]=
{
{1,2,3,4},
{5,6,7,8},
{9,10,11,12}
};
int (*p)[4]=A;
for(i=0;i<3;i++)
{
	for(j=0;j<4;j++)
	{
		printf("%d.\n",*(*(p+i)+j));
	}
}
return;
}