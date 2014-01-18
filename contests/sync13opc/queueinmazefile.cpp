#include<stdio.h>
//#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
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
#define max(a,b) ((a > b) ? a : b)
#define min(a,b) (a < b) ? a : b
#define ll(a) (long long int)(a)

int main()
{
	int t, i, j, k, mx, n, m;
	char ch[] = "...###....##...##..#..##....#.";
	ofstream inp;
	ofstream oup;
	inp.open("queueinmazeinput5.txt");
	oup.open("queueinmazeoutput5.txt");
	scani(t)
	inp << t << "\n";
	//char chc = getchar();
	while(t--)
	{
		//scani(n)
		//scani(m) 
		n = rand() % 500;
		m = rand() % 500;
		//printf("%d %d\n", n, m);
		//chc = getchar();
		inp << n << " " << m << "\n";
		char mat[n][m];
		fori(0, n-1)
		{
			forj(0, m-1)
			{
				int temp = rand() % 30;
				//printf("temp : %d\n", temp);
				//chc = getchar();
				mat[i][j] = ch[temp];
				inp << mat[i][j];
			}
			inp << "\n";
		}
		//printf("over");
		int dp[n][m];
		mx = 0;
		
		//from top left
		fori(0, n-1)
			forj(0, m-1)
				dp[i][j] = 0;
		if(mat[0][0] == '.')
			dp[0][0] = 1;
		else
			dp[0][0] = -1;
		mx = max(mx, dp[0][0]);
		fori(0, n-1)
			forj(0, m-1)
			{
				if(i == 0 && j == 0)
					continue;
				if(i == 0)
				{
					if(mat[i][j] == '#' || dp[i][j-1] == -1)
						dp[i][j] = -1;
					else
						dp[i][j] = dp[i][j-1] + 1;
				}
				else
					if(j == 0)
					{
						if(mat[i][j] == '#' || dp[i-1][j] == -1)
							dp[i][j] = -1;
						else
							dp[i][j] = dp[i-1][j] + 1;					
					}
					else
					{
						if(mat[i][j] == '#' || (dp[i-1][j] == -1 && dp[i][j-1] == -1))
							dp[i][j] = -1;
						else
							dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + 1;			
					}
				mx = max(mx, dp[i][j]);
			}
		
		//from top right
		fori(0, n-1)
			forj(0, m-1)
				dp[i][j] = 0;
		if(mat[0][m-1] == '.')
			dp[0][m-1] = 1;
		else
			dp[0][m-1] = -1;
		mx = max(mx, dp[0][m-1]);
		fori(0, n-1)
			for(j = m-1; j >= 0; j--)
			{
				if(i == 0 && j == m-1)
					continue;
				if(i == 0)
				{
					if(mat[i][j] == '#' || dp[i][j+1] == -1)
						dp[i][j] = -1;
					else
						dp[i][j] = dp[i][j+1] + 1;
				}
				else
					if(j == m-1)
					{
						if(mat[i][j] == '#' || dp[i-1][j] == -1)
							dp[i][j] = -1;
						else
							dp[i][j] = dp[i-1][j] + 1;					
					}
					else
					{
						if(mat[i][j] == '#' || (dp[i-1][j] == -1 && dp[i][j+1] == -1))
							dp[i][j] = -1;
						else
							dp[i][j] = max(dp[i][j+1], dp[i-1][j]) + 1;			
					}
				mx = max(mx, dp[i][j]);
			}
		
		
		//from bottom right
		fori(0, n-1)
			forj(0, m-1)
				dp[i][j] = 0;
		if(mat[n-1][m-1] == '.')
			dp[n-1][m-1] = 1;
		else
			dp[n-1][m-1] = -1;
		mx = max(mx, dp[n-1][m-1]);
		for(i = n-1; i >= 0; i--)
			for(j = m-1; j >= 0; j--)
			{
				if(i == n-1 && j == m-1)
					continue;
				if(i == n-1)
				{
					if(mat[i][j] == '#' || dp[i][j+1] == -1)
						dp[i][j] = -1;
					else
						dp[i][j] = dp[i][j+1] + 1;
				}
				else
					if(j == m-1)
					{
						if(mat[i][j] == '#' || dp[i+1][j] == -1)
							dp[i][j] = -1;
						else
							dp[i][j] = dp[i+1][j] + 1;					
					}
					else
					{
						if(mat[i][j] == '#' || (dp[i+1][j] == -1 && dp[i][j+1] == -1))
							dp[i][j] = -1;
						else
							dp[i][j] = max(dp[i][j+1], dp[i+1][j]) + 1;			
					}
				mx = max(mx, dp[i][j]);
			}		
		
		//from bottom left
		fori(0, n-1)
			forj(0, m-1)
				dp[i][j] = 0;
		if(mat[n-1][0] == '.')
			dp[n-1][0] = 1;
		else
			dp[n-1][0] = -1;
		mx = max(mx, dp[n-1][0]);
		for(i = n-1; i >= 0; i--)
			forj(0, m-1)
			{
				if(i == n-1 && j == 0)
					continue;
				if(i == n-1)
				{
					if(mat[i][j] == '#' || dp[i][j-1] == -1)
						dp[i][j] = -1;
					else
						dp[i][j] = dp[i][j-1] + 1;
				}
				else
					if(j == 0)
					{
						if(mat[i][j] == '#' || dp[i+1][j] == -1)
							dp[i][j] = -1;
						else
							dp[i][j] = dp[i+1][j] + 1;					
					}
					else
					{
						if(mat[i][j] == '#' || (dp[i+1][j] == -1 && dp[i][j-1] == -1))
							dp[i][j] = -1;
						else
							dp[i][j] = max(dp[i][j-1], dp[i+1][j]) + 1;			
					}
				mx = max(mx, dp[i][j]);
			}
		
		oup << mx << "\n";
		
//		printf("%d\n", mx);			
	}
	return 0;
}



