#include<stdio.h>
#include<math.h>
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
	int t, i, j, k, ans, a, b, count1, count2, take, rem;
	scani(t)
	sieve();
	ofstream inp;
	ofstream oup;
	inp.open("convertnuminput3.txt");
	oup.open("convertnumoutput3.txt");
	inp << t << "\n";
	while(t--)
	{
		//scani(a)
		//scani(b)
		a = rand() % 998788534;
		b = rand() % 987352746;
		inp << a << " " << b << "\n";
		ans = 0;
		vector<int> diff;
		for(k = 0; primes[k] <= sqrt(a) || primes[k] <= sqrt(b); k++)
		{
			//printf("inside");
			j = primes[k];
			count1 = count2 = 0;
			if(a % j == 0)
			{
				count1 = 0;
				while(a % j == 0)
				{
					count1++;
					a = a / j;
				}
			}
			if(b % j == 0)
			{
				count2 = 0;
				while(b % j == 0)
				{
					count2++;
					b = b / j;
				}
			}
			//printf("j : %d count1 : %d count2 : %d\n", j, count1, count2);
			diff.push_back(count2 - count1);	
		}
		if(a != 1 && a != b)
			diff.push_back(-1);
		if(b != 1 && a != b)
			diff.push_back(1);
		sort(diff.begin(), diff.end());
		
		//fori(0, diff.size()-1)
		//	printf("%d ", diff[i]);
		
		fori(0, diff.size()-1)
		{
			if(diff[i] <= 0)
			{
				ans += abs(diff[i]);
				continue;
			}
			take = diff[i] / 2;
			rem = diff[i] % 2;
			if(take == 0)
			{
				ans += rem;
				diff[i] = 0;
				continue;
			}
			else
			{
				ans += rem + 1;
				diff[i] = 0;
				forj(i+1, diff.size()-1)
					diff[j] -= 2*take;	
			}
		}		
		oup << ans << "\n";
		//printf("%d\n", ans);
	}
	return 0;
}



