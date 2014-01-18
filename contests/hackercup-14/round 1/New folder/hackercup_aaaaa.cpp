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
//#define ll(a) (long long int)(a)

int Max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}
int main()
{
	int t, i, j, k, i1, j1, i2, j2, n, m, maxx, a, b;
	ifstream inp;
	ofstream oup;
	inp.open("aaainput.txt");
	oup.open("aaaoutput.txt");
	inp >> t;
	fork(1, t)
	{
		inp >> n >> m;
		char mat[n][m];
		int dp1[n][m], dp2[n][m];
		fori(0, n-1)
			inp >> mat[i];

		maxx = 0;
		//dp1
		if(mat[0][0] == '.')
		{
			dp1[0][0] = 1;
			maxx = 1;
		}
		else
		{
			dp1[0][0] = -1;
			maxx = 0;
			oup << "Case #" << k << ": " << maxx << endl;
			continue;
		}
		fori(0, n-1)
		{
			forj(0, m-1)
			{
				if(i == 0 && j == 0)
					continue;
				if(i == 0)
				{
					if(dp1[i][j-1] == -1 || mat[i][j] == '#')
						dp1[i][j] = -1;
					else
						dp1[i][j] = dp1[i][j-1] + 1;
				}
				else
					if(j == 0)
					{
						if(dp1[i-1][j] == -1 || mat[i][j] == '#')
							dp1[i][j] = -1;
						else
							dp1[i][j] = dp1[i-1][j] + 1;
					}
					else
					{
						if(mat[i][j] == '#')
							dp1[i][j] = -1;
						else
							dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + 1;
					}
				if(dp1[i][j] > maxx)
					maxx = dp1[i][j];
			}
		}

		//dp2
		if(mat[n-1][m-1] == '.')
			dp2[n-1][m-1] = 1;
		else
			dp2[n-1][m-1] = 0;
		for(i = n-1; i >= 0; i--)
		{
			for(j = m-1; j >= 0; j--)
			{
				if(i == n-1 && j == m-1)
					continue;
				if(i == n-1)
				{
					if(mat[i][j] == '#')
						dp2[i][j] = 0;
					else
						dp2[i][j] = dp2[i][j+1] + 1;
				}
				else
					if(j == m-1)
					{
						if(mat[i][j] == '#')
							dp2[i][j] = 0;
						else
							dp2[i][j] = dp2[i+1][j] + 1;
					}
					else
					{
						if(mat[i][j] == '#')
							dp2[i][j] = 0;
						else
							dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]) + 1;
					}
			}
		}


		//printing dp1
		printf("dp1 : \n");
		fori(0, n-1)
		{
			forj(0, m-1)
				printf("%d ", dp1[i][j]);
			printf("\n");
		}

		//printing dp2
		printf("dp2 : \n");
		fori(0, n-1)
		{
			forj(0, m-1)
				printf("%d ", dp2[i][j]);
			printf("\n");
		}

		for(j = 2; j < m-1; j++)
		{
			for(i1 = n-1; i1 >= 0; i1--)
			{
				if(mat[i1][j] == '#' || dp1[i1][j-1] == -1)
					continue;
				for(i2 = i1-1; i2 >= 0; i2--)
				{
					if(mat[i2][j] == '#')
					{
						i1 = i2;
						break;
					}
					a = dp1[i1][j-1];
					b = dp2[i2][j+1];
					if(a+b+i1-i2+1 > maxx)
						maxx = a + b + i1 - i2 + 1;
				}
			}
		}

		for(i = 2; i < n-1; i++)
		{
			for(j1 = m-1; j1 >= 0; j1--)
			{
				if(mat[i][j1] == '#' || dp1[i-1][j1] == -1)
					continue;
				for(j2 = j1-1; j2 >= 0; j2--)
				{
					if(mat[i][j2] == '#')
					{
						j1 = j2;
						break;
					}
					a = dp1[i-1][j1];
					b = dp2[i+1][j2];
					if(a+b+j1-j2+1 > maxx)
						maxx = a + b + j1 - j2 + 1;
				}
			}
		}

		oup << "Case #" << k << ": " << maxx << endl;
	}
	return 0;
}



