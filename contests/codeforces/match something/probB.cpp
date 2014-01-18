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
long long int p10[] = { 1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL, 10000000LL, 100000000LL, 1000000000LL, 10000000000LL, 100000000000LL, 1000000000000LL, 10000000000000LL, 100000000000000LL, 1000000000000000LL, 10000000000000000LL, 100000000000000000LL, 1000000000000000000LL};
int noofdigs(long long int n)
{
	int count = 0;
	while(n > 0)
	{
		count++;
		n = n / 10;
	}
	return count;
}
int main()
{
	int t, i, j;
	long long int w, m, ans = 0LL, k;
	cin >> w >> m >> k;
	int curdig = noofdigs(m);
	long long int cur = m, rem = w;
	while(true)
	{
//		cout << cur << curdig << rem << "\n";
		if((p10[curdig] - cur) * curdig * k <= rem)
		{
			rem = rem - (p10[curdig] - cur) * ll(curdig) * k;
//			cout << p10[curdig] << cur << curdig << "\n\n";
			ans += (p10[curdig] - cur) * ll(curdig);
			cur = p10[curdig];
			curdig++;
		}
		else
		{
			ans +=	rem / (ll(curdig) * k);
			break;
		}
	}
	cout << ans;
	return 0;
}



