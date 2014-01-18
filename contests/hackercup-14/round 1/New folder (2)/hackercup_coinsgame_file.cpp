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
	int t, i, j, k, minn, eq, rem, tot, n, c, count, flag, tempc, flagadd;
	ifstream inp;
	ofstream oup;
	inp.open("coingameinput.txt");
	oup.open("coingameoutput.txt");
	inp >> t;
	forj(1, t)
	{
		inp >> n >> k >> c;
		minn = 1000000000;
		fori(1, n)
		{
			tempc = c;
			count = 0;
			eq = k / i;
			if(eq == 0)
				break;
			rem = k % i;
			if(rem == 0)
			{
				count = count + n - i + c;
				if(count < minn)
					minn = count;
				c = tempc;
				continue;
			}
			if(i == n && rem != 0)
				break;
			tot = i + 1;
			flagadd = 1;
			
			count = count + n - tot;
		//	printf("i : %d eq : %d rem : %d tot : %d count : %d\n", i, eq, rem, tot, count);
			if(c <= tot)
			{
				count = count + c;
				if(count < minn)
					minn = count;
				c = tempc;
				continue;
			}
			count += tot;
			eq--;
			rem--;
			c = c - tot;
			flag = 0;
			while(eq > 0 && rem > 0)
			{
				if(c > tot)
				{
					eq--;
					rem--;
					c = c - tot;
					count += tot;
				}
				else
				{
					count+=c;
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				if(count < minn)
					minn = count;
				c = tempc;
				continue;
			}
			if(eq == 0)
				count = count + i + c;
			else
				count = count + flagadd + c;
			if(count < minn)
				minn = count;
			c = tempc;
		}
		oup << "Case #" << j << ": " << minn << endl;
	}
	return 0;
}



