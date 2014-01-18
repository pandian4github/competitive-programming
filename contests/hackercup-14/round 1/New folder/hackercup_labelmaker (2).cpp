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
#define lll(a) (long long int)(a)

int main()
{
	int t, i, j, k, noofletters, len, rem;
	char str[30];
	unsigned long long int no, prod, base, y, temp;
	long double x;
	ifstream inp;
	ofstream oup;
	inp.open("input.txt");
	oup.open("output.txt");
	inp >> t;
	//scani(t)
	forj(1, t)
	{
		//scanf("%s ", str);
		//scanf("%llu", &no);
		inp >> str;
		inp >> no;
		//printf("fadsfdas");
		len = strlen(str);
		base = (unsigned long long int)len;
		prod = (unsigned long long int)len;
		noofletters = 1;
		
		while(base < no)
		{
			prod = prod * len;
			base = base + prod;
			noofletters++;
		}
		//printf("noofletters : %d\n", noofletters);
		base = 0LL;
		prod = (unsigned long long int)len;
		fori(1, noofletters - 1)
		{
			base = base + prod;
		//	printf("base : %lld \n", base);
			prod = prod * (unsigned long long)len;
		//	printf("Adding prod : %lld\n", prod);
		}
		//printf("%llu \n", base);
		no = no - base;
		//printf("%llu \n", no);
		char output[noofletters];
		output[noofletters] = '\0';
		prod = 1LL;
		for(i = noofletters - 1; i >= 0; i--)
		{
			x = no * 1.0L / prod;
		//	printf("x : %llu\n", (unsigned long long)x);
			temp = (unsigned long long int)x;
			if(temp * prod == no)
				y = temp;
			else
				y = temp + (unsigned long long int)1;
			//y = (unsigned long long int)ceil(x);
		//	printf("y : %llu\n", y);
			rem = y % (unsigned long long int)len;
		//	printf("rem : %d\n", rem);
			if(rem == 0)
				rem = len;
			rem--;
			output[i] = str[rem];
			prod = prod * (unsigned long long int)len;
		}
		oup << "Case #" << j << ": " << output << endl;
		//printf("Case #%d: ", j);
		//printf("%s\n", output);
	}
	return 0;
}



