#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;                    //数组元素个数
	scanf("%d", &n);
	int i = 0;
	int first = 0;
	int last = n-1;
	int final_first = 0;
	int final_last = n - 1;
	int number[10000];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &number[i]);
	}
	int sum,result,ne_flag;
	sum = 0;
	result = 0;
	ne_flag = 0;
	for (i = 0; i < n; i++)
	{

		if (number[i]>0)
		{
			ne_flag = 1;
		}
		if (ne_flag == 0 && number[i]==0)
		{
			ne_flag = 2;
		}
		if (sum + number[i] < 0)
		{
			first = i+1;
			sum = 0;
		}
		else
		{
			last = i;
			sum += number[i];
		}
		if (result < sum)
		{
			final_first = first;
			final_last = last;
			result = sum;
		}
	}
	if (result<0)
	{
		result = 0;
		final_first = 0;
		final_last = n-1;
	}
	if (ne_flag==2)
	{
		printf("0 0 0");
	}
	else
	{
		printf("%d %d %d", result, number[final_first], number[final_last]);
	}
	return 0;
}
/*
   判定点负数和0的意思是所有序列中只有负数与0，并且输出的结果为0 0 0.
   我这里的方法算是一个比较勉强的算法，比较好的算法应该是在final_first和final_last的赋值这块进行优化。
   下面的网址是别人用不一样的赋值思路解决问题的代码，感兴趣的朋友可以看一下。
   http://www.bubuko.com/infodetail-3055362.html
 */
