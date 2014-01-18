#include<stdio.h>
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
#define scanlli(a) scanf("%lld",&a);
#define scanc(c) scanf("%c",&c);
#define println printf("\n");

long long int pow10[] = { 1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL, 10000000LL, 100000000LL, 1000000000LL, 10000000000LL};
int noofdigs(long long int x)
{
	int count = 0;
	while(x != 0LL)
	{
		count++;
		x = x / 10LL;
	}
	return count;
}
long long int sum(long long int a, long long int b)
{
//	printf("sum func : a : %lld b : %lld\n", a, b);
	a = a - 1LL;
	long long int x; 
	long long int y;
	if(a % 2 == 0)
		x = (a / 2LL)*(a + 1LL);
	else
		x = a *((a + 1LL) / 2LL);
	if(b % 2 == 0)
		y = (b / 2LL)*(b + 1LL);
	else
		y = b *((b + 1LL) / 2LL);
	long long int ans = (y - x) % 1000000007LL;
	//printf("in func ans : %lld\n", ans);
	return ans;
}
int main()
{
	int t, d1, d2, i;
	long long int l, r, ans;
	scani(t)
	while(t--)
	{
		scanlli(l)
		scanlli(r)
		d1 = noofdigs(l);
		d2 = noofdigs(r);
		if(d1 == d2)
			ans = d1 * sum(l, r);
		else
		{
			ans = d1 * sum(l, pow10[d1]-1LL);
			ans = ans % 1000000007LL;
	//		printf("ans : %lld\n", ans);
			fori(d1+1, d2-1)
			{
				ans = ans + i * sum(pow10[i-1], pow10[i]-1LL);
				ans = ans % 1000000007LL;
			}
	//		printf("ans : %lld\n", ans);
			ans = ans + d2 * sum(pow10[d2-1], r);
			ans = ans % 1000000007LL;
	//		printf("ans : %lld\n", ans);
		}
		ans = ans % 1000000007LL;
		printf("%lld\n", ans);
	}
	return 0;
}
