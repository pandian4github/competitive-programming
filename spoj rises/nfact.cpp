#include<stdio.h>
#include<math.h>
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
int primes[10000], Count[1000000][11];
int primecount;
void sieve()
{
	int i, j, k = 0;
	bool visited[10000] = {false};
	for(i = 2; i <= 10000; i++)
		if(visited[i] == false)
		{
			primes[k++] = i;
			for(j = i; j <= 10000; j+=i)
				visited[j] = true;
		}
	primecount = k;
}
int main()
{
	int t, i, j, k, a, b, n, n1, ans = 0, count, temp;
	scani(t)
	sieve();
	fori(0, 10)
		Count[0][i] = 0;
	fori(1, 1000000)
	{
		count = 0;
		temp = i;
		if(i != 1)
		{
			for(k = 0; primes[k] <= sqrt(i); k++)
			{
				j = primes[k];
				if(i % j == 0)
				{
					count++;
					while(i % j == 0)
						i = i / j;
				}
			}
			if(i != 1)
				count++;
		}
		i = temp;
		if(count > 10)
			continue;
		Count[i][0] = Count[i-1][0];
		Count[i][1] = Count[i-1][1];
		Count[i][2] = Count[i-1][2];
		Count[i][3] = Count[i-1][3];
		Count[i][4] = Count[i-1][4];
		Count[i][5] = Count[i-1][5];
		Count[i][6] = Count[i-1][6];
		Count[i][7] = Count[i-1][7];
		Count[i][8] = Count[i-1][8];
		Count[i][9] = Count[i-1][9];
		Count[i][10] = Count[i-1][10];
		Count[i][count]++;
	}
	while(t--)
	{
		scani(a)
		scani(b)
		scani(n)
		ans = 0;
		ans = Count[b][n] - Count[a-1][n];
		printf("%d\n", ans);
	}
	return 0;
}



