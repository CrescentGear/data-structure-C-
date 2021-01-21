//未写完
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max_number 1001

void input()
{

}

int check()
{

}

int final_check()
{

}

int main()
{
	char a;
	int n1, n2;
	int number1[max_number];
	int result;
	result = 0;
	scanf("%c %d %d", &a, &n1, &n2);
	while (a != 'S')
	{ 
	switch (a)
	{
	case 'I':input(); break;
	case 'C':
		result=check();
		if (result == 1)
			printf("yes\n");
		else
			printf("no\n");
		break;	
	case 'S':result=final_check();
		if (result == 1)
			printf("The network is connected.\n");
		else
			printf("There are %d components.\n",result);
		break;
	}
	}
	return 0;
}


