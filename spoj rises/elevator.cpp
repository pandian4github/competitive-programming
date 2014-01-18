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
int Map[1000001] = {0};
int main()
{
	int t, i, j, k, f, s, g, u, d, cur, cursteps, ans;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	queue<int> index;
	queue<int> steps;
	//map<int, int> Map;
	index.push(s);
	steps.push(0);
	ans = -1;
	Map[s] = 1;
	while(!index.empty())
	{
		cur = index.front();
		cursteps = steps.front();
		//printf("cur : %d cursteps : %d\n", cur, cursteps);
		if(cur == g)
		{
			ans = cursteps;
			break;
		}
		if(cur + u <= f && Map[cur + u] == 0)
		{
			index.push(cur + u);
			steps.push(cursteps + 1);
			Map[cur + u] = 1;
		}
		if(cur - d > 0 && Map[cur - d] == 0)
		{
			index.push(cur - d);
			steps.push(cursteps + 1);
			Map[cur - d] = 1;
		}
		index.pop();
		steps.pop();
	}
	if(ans == -1)
		printf("use the stairs\n");
	else
		printf("%d\n", ans);
	return 0;
}

// 1 3 5 2 7 4 

