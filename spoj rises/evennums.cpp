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
	int n, t, d, ans;
	scani(t)
	while(t--)
	{
		scani(n)
		if(n%2 == 1)
			printf("%d\n",n);
		else
		{
			ans = 0;
			while(n != 0)
			{
				d = n % 2;
				n = n / 2;
				ans = ans * 2 + d;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
