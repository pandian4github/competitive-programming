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
int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int gcount = 0;
int noofdigs(int n)
{
	int count = 0;
	while(n != 0)
	{
		count++;
		n = n / 10;
	}
	return count;
}
int recurse(int a, int b)
{
	int rem1, rem2, n11, n22;
	if(a == 0 && b == 0)
		return 1;
	if(a == 0)
	{
		gcount++;
		a = 1;
	}
	int n1 = noofdigs(a);
	int n2 = noofdigs(b);
	//printf("recurse a : %d b : %d n1 : %d n2 : %d\n",a , b, n1, n2);
	int ans = 0, i, f1, f2;
	if(n1 == n2)
	{
		if(n1 == 1)
		{
			ans = 0;
			for(i = a; i <= b; i++)
				if(i % 2 == 0)
					ans++;
	//		printf("ans : %d\n", ans);
			return ans;
		}
		f1 = a / pow10[n1-1];
		f2 = b / pow10[n2-1];
		if(f1 == f2)
		{
			if(f1 % 2 == 0)
				ans =  b - a + 1;
			else
			{
				ans = 0;
				rem1 = a % pow10[n1-1];
				rem2 = b % pow10[n2-1];
				n11 = noofdigs(rem1);
				n22 = noofdigs(rem2);
				if(n22 < n2 - 1)
					ans = ans + rem2 - rem1 + 1;
				else
					if(n11 < n1 - 1)
					{
						ans = ans + pow10[n22-1] - rem1;
	//					printf("intermediate ans : %d\n",ans);
						ans = ans + recurse(pow10[n22-1], rem2);
					}
					else
						ans = ans + recurse(rem1, rem2);
			}
	//		printf("f1==f2 ans : %d\n", ans);
			return ans;
		}
		else
		{
			ans = 0;
			for(i = f1+1; i < f2; i++)
			{
				if(i % 2 == 0)
					ans = ans + pow10[n2-1];
				else
					ans = ans + recurse(pow10[n1-2], pow10[n1-1]-1) + pow10[n1-2];
			}
	//		printf("after for loop ans : %d\n",ans);
			if(f1 % 2 == 0)
				ans = ans + pow10[n1-1] - (a % pow10[n1-1]);
			else
			{
	//			ans = 0;
				rem1 = a % pow10[n1-1];
				//rem2 = b % pow10[n2-1];
				n11 = noofdigs(rem1);
				//n22 = noofdigs(rem2);
				if(n11 < n1 - 1)
				{
					ans = ans + pow10[n2-2] - rem1;
					//printf("intermediate ans : %d\n",ans);
					ans = ans + recurse(pow10[n2-2], pow10[n2-1]-1);
				}
				else
					ans = ans + recurse(a % pow10[n1-1], pow10[n2-1]-1);
				//printf("f1==f2 ans : %d\n", ans);
				
			}
			//	ans = ans + recurse(a % pow10[n1-1], pow10[n1-1] - 1);
	//		printf("after f1 ans : %d\n",ans);
			if(f2 % 2 == 0)
				ans = ans + (b % pow10[n1-1]) + 1;
			else
			{
				rem2 = b % pow10[n1-1];
				//rem2 = b % pow10[n2-1];
				n22 = noofdigs(rem2);
				//n22 = noofdigs(rem2);
				if(n22 < n2 - 1)
					ans = ans + rem1 + 1;
				else
					ans = ans + recurse(pow10[n22-1], rem2) + pow10[n22-1];
			}
			//	ans = ans + recurse(0, b % pow10[n1-1]);
	//		printf("after f2 ans : %d\n", ans);
			return ans;	
		}
	}
	else
	{
		ans = 0;
		for(i = n1 + 1; i < n2; i++)
			ans = ans + recurse(pow10[i-1], pow10[i]-1);
	//	printf("after for loop out ans : %d\n",ans);
		ans = ans + recurse(a, pow10[n1]-1) + recurse(pow10[n2-1], b);
	//	printf("ans : %d\n", ans);
		return ans;
	}
}
int main()
{
	int t, a, b;
	scani(t)
	while(t--)
	{
		scani(a)
		scani(b)
		gcount = 0;
		printf("%d\n",gcount + recurse(a, b));
	}
	return 0;
}
// {200, 242, 250, 299, 321, 342, 381, 394}, {200, 204, 242, 244, 394}}
