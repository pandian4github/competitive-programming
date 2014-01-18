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
int primes[100000];
int primecount;
void sieve()
{
	int i, j, k = 0;
	bool visited[100000] = {false};
	for(i = 2; i <= 100000; i++)
		if(visited[i] == false)
		{
			primes[k++] = i;
			for(j = i; j <= 100000; j+=i)
				visited[j] = true;
		}
	primecount = k;
}
int main()
{
	int t, i, j, k, a, b, n, n1, ans = 0, count, temp;
	scani(a)
	scani(b)
	scani(n)
	sieve();
	fori(a, b)
	{
		temp = i;
		if(i == 1)
			n1 = 1;
		else
		{
			n1 = 1;
			for(k = 0; primes[k] <= sqrt(i); k++)
			{
				j = primes[k];
				if(i % j == 0)
				{
					count = 0;
					while(i % j == 0)
					{
						count++;
						i = i / j;
					}
					n1 *= (count + 1);
					if(n1 > n)
						break;
				}
			}
			if(i != 1)
				n1 *= 2;
		}
		if(n1 == n)
			ans++;
		i = temp;
	}
	printf("%d", ans);
	return 0;
}



