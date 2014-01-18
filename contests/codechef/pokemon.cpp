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
#define scanc(c) scanf("%c",&c);
#define println printf("\n");

int min(int a, int b)
{
	if(a < b)
		return a;
	return b;
}
int main()
{
	int t, n, i;
	scani(t)
	while(t--)
	{
		scani(n)
		int A[n], B[n], C[n];
		fori(0, n-1)
		{
			scani(A[i])
			scani(B[i])
			scani(C[i])
		}
		int dp1[n], dp2[n], dp3[n];
		dp1[0] = A[0];
		dp2[0] = B[0];
		dp3[0] = C[0];
		fori(1, n-1)
		{
			dp1[i] = min(dp2[i-1], dp3[i-1]) + A[i]; 
			dp2[i] = min(dp1[i-1], dp3[i-1]) + B[i]; 
			dp3[i] = min(dp2[i-1], dp1[i-1]) + C[i]; 
		}
		printf("%d\n", min(dp1[n-1], min(dp2[n-1], dp3[n-1])));
	}
	return 0;
}
