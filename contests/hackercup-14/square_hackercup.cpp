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

int main()
{
	int t, i, j, k, n, count, i1, i2, j1, j2, flag;
	scani(t)
	fork(1, t)
	{
		scani(n)
		char mat[n][n];
		fori(0, n-1)
			scans(mat[i])
		printf("Case #%d: ", k);
		count = 0;
		fori(0, n-1)
			forj(0, n-1)
				if(mat[i][j] == '#')
					count++;
		flag = 0;
		fori(0, n-1)
			if(flag == 0)
				forj(0, n-1)
					if(mat[i][j] == '#')
					{
						i1 = i;
						j1 = j;
						flag = 1;
						break;
					}
		flag = 0;
		for(i = n-1; i >= 0; i--)
			if(flag == 0)
				for(j = n-1; j >= 0; j--)
					if(mat[i][j] == '#')
					{
						i2 = i;
						j2 = j;
						flag = 1;
						break;
					}
		//printf("i1 : %d j1 : %d i2 : %d j2 : %d count : %d\n", i1, j1, i2, j2, count);
		if(j1 > j2)
		{
			printf("NO\n");
			continue;
		}
		if(i2-i1 != j2-j1)
		{
			printf("NO\n");
			continue;
		}
		flag = 0;
		fori(i1, i2)
			forj(j1, j2)
				if(mat[i][j] == '.')
				{
					flag = 1;
					break;
				}
		if(flag)
		{
			printf("NO\n");
			continue;
		}
		if((i2-i1+1)*(j2-j1+1) != count)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}
