#include<stdio.h>
int main()
{
	//二维数组
	int a[2][3] = {1};
	printf("*a[0] = %d\n",*a[0]);
	printf("a[0][0] = %d\n",a[0][0]);
	
	int(*p1)[3] = &a[0];
	int(*p2)[3] = a;
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	//三维数组
	int b[3][2][2] = {{{1,0},{0,0}}, {{0,0},{0,0}}, {{0,0},{0,0}}};
	int(*p3)[2][2] = &b[0];
	int(*p4)[2][2] = b;
	printf("p1 = %p\n",p3);
	printf("p2 = %p\n",p4);
	
	return 0;
	
}