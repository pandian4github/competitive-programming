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
	int t, i, j, k, n, bas, ind;
	int base[102], tax[102];
	double total[102], max;
	string sbase, stax;
	string carname[102];
	scani(t)
	while(t--)
	{
		scani(n)
		fori(0, n-1)
		{
			cin >> carname[i];
			cin >> sbase;
			cin >> stax;
			base[i] = 0;
			forj(1, sbase.length()-1)
				base[i] = base[i] * 10 + sbase[j] - 48;
			tax[i] = 0;
			forj(0, stax.length()-2)
				tax[i] = tax[i] * 10 + stax[j] - 48;			
			total[i] = (double)base[i] + (double)base[i] * (double)tax[i] / 100.0;
		}
		ind = 0;
		bas = base[0];
		max = total[0];
		fori(1, n-1)
		{
			if(total[i] > max)
			{
				max = total[i];
				ind = i;
				bas = base[i];
			}
			else
				if(total[i] == max)
				{
					if(base[i] > bas)
					{
						ind = i;
						bas = base[i];
					}
				}
		}
	//	fori(0, n-1)
	//		printf("%lf ", total[i]);
		cout<<carname[ind]<<"\n";
	}
	return 0;
}



