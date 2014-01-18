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
#define fora(x,y) for(a = x; a <= y; a++)
#define forb(x,y) for(b = x; b <= y; b++)
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
	int T, t, i, j, k, l, a, b, c, d, n, m, r, ans, Max, C, D, count;
	char mat[12][12];
	map<pair<int, int>, long long int> Hash;
	long long int x, y, sum;
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
	long long int hash[12][12];
	scani(T)
	while(T--)
	{
		scani(n)
		scani(m)
		Hash.clear();
		Max = 0;
		fori(0, n-1)
			scanf("%s", mat[i]);
		fori(0, n-1)
		{
			forj(0, m-1)
			{
				fork(0, n-1)
				{
					forl(0, m-1)
					{
						count = 0;
						sum = 0LL;
						fora(i, k)
						{
							forb(j, l)
							{
								count++;
								sum = sum + count * (long long int)primes[mat[i][j]-26];
								//count++;
							}
						}
						Hash[mp(i*n + j, k*n + l)] = sum;
					}
				}
			}
		}
/*		fori(0, n-1)
		{
			forj(0, m-1)
			{
				if(i == 0 && j == 0)
					hash[i][j] = primes[mat[i][j] - 97];
				else
				{
					if(i == 0)
						hash[i][j] = hash[i][j-1] + (i*n + j + 1) * primes[mat[i][j] - 97];
					else
						if(j == 0)
							hash[i][j] = hash[i-1][j] + (i*n + j + 1) * primes[mat[i][j] - 97];
						else
							hash[i][j] = hash[i][j-1] + hash[i-1][j] - hash[i-1][j-1] + (i*n + j + 1) * primes[mat[i][j] - 97];
					
				}
			}
		}
		fori(0, n-1)
		{
			forj(0, m-1)
				printf("%lld  ", hash[i][j]);
			printf("\n");
		}
*/		fori(0, n-1)
		{
			printf("Start point row %d\n", i);
			forj(0, m-1)
			{
				printf("Start point column %d\n", j);
				fork(i, n-1)
				{
					printf("End point row %d\n", k);
					forl(j, m-1)
					{
						printf("End point column %d\n", l);
						r = l - i + 1;
						c = k - j + 1;
						fora(i, n-1)
						{
							//printf("Checking start row %d\n", a);
							forb(j, m-1)
							{
								//printf("Checking start column %d\n", b);
								if(i == a && j == b)
									continue;
								if(a + r > n || b + c > m)
									break;
								C = a + r - 1;
								D = b + c - 1;
								x = Hash[mp(i*n + j, k*n + l)];
								y = Hash[mp(a*n + b, C*n + D)];
								
/*								if(i == 0 && j == 0)
									x = hash[k][l];
								else
									if(i == 0)
										x = hash[k][l] - hash[k][j-1];
									else
										if(j == 0)
											x = hash[k][l] - hash[i-1][l];
										else
											x = hash[k][l] + hash[i-1][j-1] - hash[k][j-1] - hash[i-1][l];
								if(a == 0 && b == 0)
									y = hash[C][D];
								else
									if(a == 0)
										y = hash[C][D] - hash[C][b-1];
									else
										if(b == 0)
											y = hash[C][D] - hash[a-1][D];
										else
											y = hash[C][D] + hash[a-1][b-1] - hash[C][b-1] - hash[a-1][D];
							*/	if(i == 0 && j == 0 && k == 1 && l == 2 && a == 0 && b == 2)
								{
									printf("x : %lld y : %lld\n", x, y);
								}
								if(x == y)
								{
									if(Max > r * c)
										Max = r * c;
									break;
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", Max);
		
	}
	return 0;
}


