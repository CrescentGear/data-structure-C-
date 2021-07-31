#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

struct Node  //结点
{
	char alpha;
	char number[5];
};

int main()
{
	int N;
	struct Node in[100];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)             //输入序列
	{
		scanf(" %c %s", &in[i].alpha, &in[i].number);
	}
	return 0;
}

