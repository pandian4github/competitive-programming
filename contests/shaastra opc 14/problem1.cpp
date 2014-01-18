#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanlli(a) scanf("%lld", &a);
#define scanc(c) scanf("%c",&c);
#define scans(s) scanf("%s", s);
#define mp(a,b) make_pair(a, b)
#define ll long long int
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define println printf("\n");
#define sz(v) v.size()
#define len(s) s.length()
#define max(a,b) (a > b) ? a : b
#define min(a,b) (a < b) ? a : b
#define ll(a) (long long int)(a)

long long int power(long long int a, long long int b, long long int high)
{
	if(b == 0LL)
		return 1LL;
	long long int c = power(a, b/2LL, high);
	double c1 = (double)c * 1.0;
	double sqr = sqrt(high);
	if(b % 2 == 0)
	{
		if(c1 > sqr)
			return 0;
		return c * c;		
	}
	else
	{
		sqr = sqrt(high*1.0 / a*1.0);
		if(c1 > sqr)
			return 0;
		return c * c * a;		
	}
}
bool isPerfectPower(long long int b, long long int low, long long int high)
{
	long long int l = low, h = high;
	long long int p, mid;
	while(l <= h)
	{
		mid = (l + h)/2;
		p = power(mid, b, high); 
		//printf("l : %lld h : %lld mid : %lld p : %lld\n", l, h, mid, p);
		//char ch = getchar();
		if(p == high)
			return true;
		if(p < high && p > 0)
		{
			if(l == mid)
				l = mid + 1;
			else
				l = mid;
		}
		else
		{
			if(h == mid)
				h = mid - 1;
			else
				h = mid;
		}
	}
	return false;
}
int main()
{
	int t, i, j, k, flag;
	long long int n, b;
	scani(t)
	while(t--)
	{
		scanlli(n)	
		b = (long long int)(log(n)/log(2));
		flag = 0;
		while(b > 1LL)
		{
			//cout << b << "::\n";
			bool bo = isPerfectPower(b, 2, n);
			if(bo)
			{
				flag = 1;
				break;
			}
			b--;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}



