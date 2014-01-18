#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanc(c) scanf("%c",&c);
#define println printf("\n");

int main()
{
	char str[52];
	while(scanf("%s",str) != EOF)
	{
		int min = 1000, i, j, count;
		int len = strlen(str);
		//printf("len : %d\n",len);
		for(i = 0; i <= len; i++)
		{
			count = 0;
			for(j = 0; j < i; j++)
				if(str[j] == 'G')
					count++;
			for(j = i; j < len; j++)
				if(str[j] == 'R')
					count++;
		//	printf("i : %d count : %d\n", i, count);
			if(count < min)
				min = count;
		}
		printf("%d\n",min);
	}
	return 0;
}
