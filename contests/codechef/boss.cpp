#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
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
bool compare(pair<int, int> a, pair<int, int> b)
{
	if(a.second > b.second)
		return true;
	if(a.second == b.second)
		if(a.first > b.first)
			return true;
	return false;
}
int main()
{
	int t, n, i, count, s, e, end;
	scani(t)
	while(t--)
	{
		scani(n)
		vector<pair<int, int> > vec(n+1);
		fori(0, n-1)
		{
			scani(s)
			scani(e)
			vec.push_back(make_pair(s,e));
		}
		sort(vec.begin(), vec.end(), compare);
		//fori(0, n-1)
		//	printf("%d %d\n", vec[i].first, vec[i].second);
		count = 1;
		end = vec[n-1].second;
		for(i = n-2; i >= 0; i--)
		{
			pair<int, int> p = vec[i];
			if(p.first >= end)
			{
				count++;
				end = p.second;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
