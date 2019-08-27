#include <stdio.h>
/* 应该说明的是，枚举类型是一种基本数据类型，而不是一种构造类型，因为它不能再分解为任何基本类型。枚举元素是常量，又叫枚举常量，不可对枚举元素赋值，只可对枚举变量赋值，且只能用枚举元素对它赋值，如果一定要用数字赋值需要强制类型转换。
*/
enum mouth{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	Aguest,
	Sepember,
	October,
	November,
	December,
};
int main()
{
	enum mouth a,b;
	a = July;
	b = (enum mouth)4;
	printf("a:%d.b:%d\n",a,b);
}