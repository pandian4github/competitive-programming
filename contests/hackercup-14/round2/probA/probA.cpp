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
#define max(a,b) (a > b) ? a : b
#define min(a,b) (a < b) ? a : b
#define ll(a) (long long int)(a)

int main()
{
	int t, i, j, k, n, m, x1, x2, a1, a2, b1, b2, c1, c2, r1, r2;
	ifstream inp;
	ofstream oup;
	inp.open("input.txt");
	oup.open("output.txt");
	inp >> t;
	fork(1, t)
	{
		inp >> n >> m;
		inp >> x1 >> a1 >> b1 >> c1 >> r1;
		inp >> x2 >> a2 >> b2 >> c2 >> r2;
		int bb1[n], bb2[m];
		bb1[0] = x1;
		bb2[0] = x2;
		fori(1, n-1)
			bb1[i] = (a1 * bb1[(i-1)%n] + b1 * bb2[(i-1)%m] + c1) % r1;
		fori(1, m-1)
			bb2[i] = (a2 * bb1[(i-1)%n] + b2 * bb2[(i-1)%m] + c2) % r2;
		
		fori(0, n-1)
			printf("%d ", bb1[i]);
		printf("\n");
		fori(0, m-1)
			printf("%d ", bb2[i]);
		printf("\n");
		
		ans = 0;
		map<int, int> mp1;
		map<int, int> mp2;
		mp1[bb1[0]] = 1;
		i = j = 0;
		turn = 1;

		map<int, int> toget1;
		map<int, int> toget2;

		toget1[bb1[0]] = mp1[bb1[0]] = 1;
		count1 = 1;
		i = 1;
		while(i < n && j < m)
		{
			if(turn == 1)
			{
				if(count1 == 0)
				{
					mp1
				}
				for(l = j; l < m && count1 > 0; l++)
				{
					if(toget1[bb2[l]] == 1)
					{
						toget1[bb2[l]] = 0;
						count1--;
					}
					else
					{
						if(mp1[bb2[l]] == 0)
						{
							toget2[bb2[l]] = 1;
							count2++;
						}
					}
				}
				if(count2 == 0)
					ans++;
				turn = 2;
			}
			else
			{
				for(l = i; l < n && count2 > 0; l++)
				{
					if(toget2[bb1[l]] == 1)
					{
						toget2[bb1[l]] = 0;
						count2--;
					}
					else
					{
						if(mp2[bb1[l]] == 0)
						{
							toget1[bb1[l]] = 1;
							count1++;
						}
					}
				}
				if(count1 == 0)
					ans++;
				turn = 1;
				
			}
		}
		
		if(bb1[0] == bb2[0])
			ans = 1;
			
		oup << "Case #" << k << ":" ;
	}
	return 0;
}



