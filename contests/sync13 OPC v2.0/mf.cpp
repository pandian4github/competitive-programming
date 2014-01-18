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
#define scand(a) scanf("%lf",&a);
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

int main()
{
	int t, i, j, k, x, y, prev, now;
	double val;
	scani(t)
	while(t--)
	{
		stack<int> st;
		scani(x)
		scani(y)
		scand(val)
		prev = x;
		while(x > 1)
		{
			now = x / 2;
			if(now % 2 == 0)
				val = val * 2;
			else
				if(prev % 2 == 0)
					val = val * 2;
				else
					val = val * 4;
			x = x / 2;
			prev = now;
		}
		//cout << val;
		st.push(y);
		while(y > 1)
		{
			y = y / 2;
			st.push(y);
		}
		
		prev = 1;
		st.pop();
		while(!st.empty())
		{
			now = st.top();
			st.pop();
			if(prev % 2 == 0)
				val = val / 2;
			else
				if(now % 2 == 0)
					val = val / 2;
				else
					val = val / 4;
			prev = now;
		}
		printf("%lf\n", val);
	}
	return 0;
}



