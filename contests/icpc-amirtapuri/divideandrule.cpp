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
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define println printf("\n");
#define sz(v) v.size()
#define len(s) s.length()
#define max(a,b) (a > b) ? a : b
#define min(a,b) (a < b) ? a : b
#define ll(a) (long long int)(a)

int main()
{
	int t, i, j, k, a, b, x, y, n;
	long long int ans;
	scani(t)
	while(t--)
	{
		scani(n)
		map<int, int> xc;
		map<int, int> yc;
		x = 0;
		y = 0;
		while(n--)
		{
			scani(a)
			scani(b)
			if(xc[a] == 0)
			{
				x++;
				xc[a] = 1;
			}
			if(yc[b] == 0)
			{
				y++;
				yc[b] = 1;
			}
		}
		ans = ll(x + 1) * ll(y + 1);
		printf("%lld\n", ans);
	}
	return 0;
}



