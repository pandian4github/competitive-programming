#include<stdio.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;

#define scani(a) scanf("%d",&a);

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t;
	scani(t)
	while(t--)
	{
		int n,coinTaken,amount;
		scani(n)
		vector<long long int> dp(n+2,0LL);
		dp[0] = 1LL; 
		for(coinTaken = 1; coinTaken < n; coinTaken++)
			for( amount = coinTaken; amount <= n; amount++ )
			{
				dp[ amount ] += dp[ amount - coinTaken];
				dp[ amount ] = dp[ amount ] % 1000000007;
			}
  
		dp[0] = 0LL;
		printf("%lld\n", dp[n]);
		dp.clear();
	}
	return 0;
}
