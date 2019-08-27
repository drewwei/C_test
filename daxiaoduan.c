/* 判断大小端*/

#include <stdio.h>


union myunion{
	int a;
	char b;
};

int main(void)
{
	union myunion u;
	u.a=0x1000;
	if(u.b==1)
	{
		printf("daduan.\n");
	}else
	{
		printf("xiaoduan.\n");
	}
	
	return 0;
}