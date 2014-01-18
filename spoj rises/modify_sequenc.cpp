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
	int t, flag, n, prev, now;
	scani(t)
	while(t--)
	{
		scani(n)
		flag = 0;
		n--;
		scani(prev)
		while(n--)
		{
			scani(now)
			if(prev > now)
			{
				flag = 1;
				break;
			}
			prev = now - prev;
		}
		if(prev != 0)
			flag = 1;
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	
	return 0;
}
