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

int stac[1000001];
bool flag;
vi vec[1000001];
void print(int j)
{
	int i;
	for(i = 0; i < j; i++)
		printf("%d ", stac[i]);
	printf("\n");
	flag = true;
}
void print(vi v)
{
	int i;
	fori(0, v.size()-1)
		printf("%d ", v[i]);
	printf("\n");
}
void dfs(int index, int over, int q, int level, int n, int j, vi ve, int st)
{
	if(flag)
		return;
	printf("dfs :: index : %d over : %d level : %d j : %d st : %d\n", index, over, level ,j, st);
	print(ve);
	char ch = getchar();
	int i;
	if(over == q)
		print(j);
	if(over + n - level < q)
	{
		dfs(ve[st], over+n-level, q, level, n, j, ve, st+1);
	}
	else
	{
		stac[j] = index;
		int temp = 0;
		for(i = 0; i < vec[index].size(); i++)
		{
			if(vec[index].at(i) == index)
				continue;
			
			dfs(vec[index].at(i), over + temp + 1, q, level+1, n, j+1, vec[vec[index].at(i)], 0);
			temp = temp + n - level;
			if(flag)
				break;
		}
	}
}
int main()
{
	int t, i, j, k, n,q, a, b;
	scani(t)
	while(t--)
	{
		scani(n)
		scani(q)
		//vi vec(n+1);
		fori(0, n)
            vec[i].clear();
		flag = false;
		fori(1, n-1)
		{
			scani(a)
			scani(b)
			printf("%d %d\n", a, b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		fori(1, n)
		{
			sort(vec[i].begin(), vec[i].end());
		}
		vi v;
		fori(1, n)
			v.push_back(i);
		dfs(1, 0, q, 0, n, 0, v, 1);

	}
	return 0;
}



