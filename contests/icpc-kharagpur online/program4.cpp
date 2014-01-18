#include<stdio.h>
//#include<math.h>
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

int noofdigs(int n)
{
	int count = 0;
	while(n != 0)
	{
		count++;
		n = n/10;
	}
	return count;
}
int findnumber(int n, int k)
{
	int i;
	int ans = 0;
	fori(1, n)
	{
		int temp = i;
		while(temp != 0)
		{
			if(temp%10 == k)
				ans++;
			temp = temp/10;
		}
	}
	return ans;
}
int bruteforce(int n, int k)
{
	
}
int main()
{
	int t, i, j, k, n;
	scani(t)
	while(t--)
	{
		scani(n)
		scani(k)
		int dig = noofdigs(k);
		if(dig == 1)
			printf("%d\n", findnumber(n, k));
		else
		{
			int d = noofdigs(n);
			for(j = d-1; j >= 1; j--)
			{
				x = n / po[j];
				y = n % po[j];
				
			}
		}
		
	}
	return 0;
}



