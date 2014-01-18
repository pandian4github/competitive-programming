#include<stdio.h>
//#include<math.h>
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
	int t, n, min, max, num;
	scani(t)
	while(t--)
	{
		scani(n)
		max = -1;
		min = 100000000;
		while(n--)
		{
			scani(num)
			if(num > max)
				max = num;		
			if(num < min)
				min = num;
		}
		printf("%d %d\n", min, max);
	}
	return 0;
}
