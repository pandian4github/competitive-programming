#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
#include<stdio.h>

#define scani(a) scanf("%d",&a);

int main()
{
//	std::ios_base::sync_with_stdio(false);
	int t;
	scani(t)
//	ofstream inp;
//	ofstream oup;
//	inp.open("splitnuminp.txt");
//	oup.open("splitnumoup.txt");	
//	inp<<t<<"\n";
	while(t--)
	{
		int n,coinTaken,amount;
		//cin>>n;
//	 	n = rand() % 1000;
		scani(n)
	 	inp<<n<<"\n";
		/* Similar to Coin Change Problem */
		vector<long long int> dp(n+2,0LL);
		dp[0] = 1LL;
 
 		
		for(coinTaken = 1; coinTaken < n; coinTaken++)
			for( amount = coinTaken; amount <= n; amount++ )
			{
				dp[ amount ] += dp[ amount - coinTaken];
				dp[ amount ] = dp[ amount ] % 1000000007;
			}
 
		dp[0] = 0LL;
	//	cout<<dp[n]<<endl;
 		oup<<dp[n]<<"\n";
		dp.clear();
	}
	return 0;
}
