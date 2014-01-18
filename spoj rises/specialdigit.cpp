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
	int t, n, count, i, sq, temp, d;
	scani(t)
	while(t--)
	{
		scani(n)
		int sq = sqrt(n);
		count = 0;
		fori(1, sq-1)
		{
			if(n % i != 0)
				continue;
			temp = i;
			while(temp != 0)
			{
				d = temp % 10;
				if(d == 3 || d == 5 || d == 6)
				{
					//printf("%d ", i);
					count++;
					break;
				}
				temp = temp / 10;
			}
			temp = n / i;
			while(temp != 0)
			{
				d = temp % 10;
				if(d == 3 || d == 5 || d == 6)
				{
					//printf("%d ", n/i);
					count++;
					break;
				}
				temp = temp / 10;
			}
		}
		if(n % sq == 0)
		{
			i = sq;
			temp = i;
			while(temp != 0)
			{
				d = temp % 10;
				if(d == 3 || d == 5 || d == 6)
				{
					count++;
					break;
				}
				temp = temp / 10;
			}
			if(sq * sq != n)
			{
				temp = n / sq;
				while(temp != 0)
				{
					d = temp % 10;
					if(d == 3 || d == 5 || d == 6)
					{
						count++;
						break;
					}
					temp = temp / 10;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
