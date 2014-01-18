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
	int t, i, j, k, n;
	long long int sum;
	scani(t)
	while(t--)
	{
		scani(n)
		long long int arr[n];
		fori(0, n-1)
			scanlli(arr[i])
		sort(arr, arr+n);
		sum = 0LL;
		fori(0, n-1)
			sum = sum + arr[i];
		//printf("%lld\n", sum);
		for(i = n-1; i >= 1; i--)
		{
			if(arr[i] < sum - arr[i])
			{
				break;
			}
			sum = sum - arr[i];
		}
		if(i >= 2)
			printf("%d\n", i+1);
		else
			printf("-1\n");
	}
	return 0;
}


