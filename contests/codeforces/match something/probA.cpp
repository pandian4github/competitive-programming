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
#define forl(a,b) for(l = a; l <= b; l++)
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
	int t, i, j, k, l, flag;
	char str[5];
	scani(k)
		int count[11] = {0};
		forj(0, 3)
		{
			scanf("%s", str);
			forl(0, 3)
				if(str[l] != '.')
					count[str[l] - 48]++;
		}			
		flag = 0;
		forj(0, 9)
			if(count[j] > 2*k)
			{
				printf("NO\n");
				flag = 1;
				break;
			}
		if(flag == 0)
			printf("YES\n");
	return 0;
}



