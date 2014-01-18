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
	int x, y, sum;
	int primes[] ={  2,      3 ,     5   ,   7   ,  11 ,    13 ,    17  ,   19   ,  23 ,    29, 
     31  ,   37  ,   41  ,   43  ,   47   ,  53 ,    59    , 61 ,    67 ,    71 ,
     73,     79 ,    83   ,  89  ,   97  ,  101  ,  103 ,   107  ,  109 ,   113 ,
    127  ,  131  ,  137  ,  139  ,  149  ,  151 ,   157  ,  163   , 167  ,  173 ,
	179  ,  181  ,  191 ,   193,    197  ,  199  ,  211  ,  223 ,   227 ,   229 ,
    233,    239   , 241 ,   251 ,   257 ,   263 ,   269  ,  271,    277  ,  281 ,
    283 ,   293 ,   307 ,   311  ,  313 ,   317  ,  331  ,  337 ,   347 ,   349 ,   
	353 ,   359 ,   367,    373,    379   , 383  ,  389 ,   397,    401  ,  409 ,    
	419 ,   421 ,   431,    433  ,  439 ,   443 ,   449 ,   457 ,   461 ,   463 ,
    467 ,   479  ,  487 ,   491 ,   499,    503   , 509  ,  521  ,  523  ,  541};
	//int hash[12][12];
	scani(T)
	while(T--)
	{
		scani(n)
		scani(m)
		map<pair<int, int>, int> Hash;
		Hash.clear();
		Max = 0;
		fori(0, n-1)
			scanf("%s", mat[i]);
		fori(0, n-1)
			forj(0, m-1)
				fork(i, n-1)
					forl(j, m-1)
					{
						count = 0;
						sum = 0;
						fora(i, k)
							forb(j, l)
								sum = sum + primes[count++] * primes[mat[a][b]-97];
						Hash[mp(i*m + j, k*m + l)] = sum;
					}
		fori(0, n-1)
			forj(0, m-1)
				fork(i, n-1)
					forl(j, m-1)
					{
						r = k - i + 1;
						c = l - j + 1;
						fora(i, n-1)
							forb(j, m-1)
							{
								if(i == a && j == b)
									continue;
								if(a + r > n || b + c > m)
									break;
								C = a + r - 1;
								D = b + c - 1;
								x = Hash[mp(i*m + j, k*m + l)];
								y = Hash[mp(a*m + b, C*m + D)];
								if(x == y)
								{
									if(Max < r * c)
										Max = r * c;
									break;
								}
							}
					}
		printf("%d\n", Max);		
	}
	return 0;
}


