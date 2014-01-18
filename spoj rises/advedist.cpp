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
#define min(a,b) ((a < b) ? a : b)
#define ll(a) (long long int)(a)

int dp[1003][1003];
int main()
{
	int t, i, j, k, a;
	char str1[1002], str2[1002];
	scani(t)
	while(true)
	{
		scanf("%s", str1);
		scanf("%s", str2);
		if(strcmp(str1, "*") == 0 && strcmp(str2, "*") == 0)
			break;
		fori(0, 1002)
			dp[0][i] = dp[i][0] = i;
		fori(1, strlen(str1))
		{
			forj(1, strlen(str2))
			{
				if(str1[i-1] == str2[j-1])
					a = dp[i-1][j-1];
				else
					a = dp[i-1][j-1] + 1;	
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
				dp[i][j] = min(dp[i][j], a);
			}
		}
		fori(0, strlen(str1))
		{
			forj(0, strlen(str2))
				printf("%d ", dp[i][j]);
			printf("\n");
		}
		printf("%d\n", dp[strlen(str1)][strlen(str2)]);
	}
	return 0;
}



