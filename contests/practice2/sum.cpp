#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanlli(a) scanf("%lld",&a);
#define scanc(c) scanf("%c",&c);
#define println printf("\n");

int main()
{
	int t, n, q, i, l, r;
	scani(t)
	while(t--)
	{
		scani(n)
		long long int arr[n+1], sum[n+1];
		scani(q)
		fori(1, n)
			scanlli(arr[i])
		sum[0] = 0LL;
		sum[1] = arr[1];
		fori(1, n)
			sum[i] = arr[i] + sum[i-1];
		fori(1, q)
		{
			scani(l)
			scani(r)
			printf("%lld\n", sum[r+1] - sum[l]);
		}		
	}
	return 0;
}
