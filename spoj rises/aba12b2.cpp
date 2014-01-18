#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <ctime>
#include <cassert>
#include<string.h>
using namespace std;
 
#define GI ({int t;scanf("%d",&t);t;})
#define GL ({LL t;scanf("%lld",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(int i=a;i>b;i--)
#define SET(x,a) memset(x,a,sizeof(x));
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tr(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define pb push_back
#define sz(a) (int)(a.size())
#define INF (int)1e9
#define EPS (double)1e-9
#define is istringstream
#define os ostringstream
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
 
typedef long long LL;
typedef pair< int,int > ii;
typedef vector< ii > vii;
typedef vector < vii > vvii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< string > vs;
char inp[1000110];
int ret;
int p[1000110];
 
int findLength(char *in)
{
p[1] = 0;
int k = 0, len = strlen(in);
for(int i = 2;i <= len;i ++)
{
while(k > 0 && in[k] != in[i-1])
k = p[k];
if(in[k] == in[i-1])
k ++;
p[i] = k;
if(!(i & 1) && p[i] == (i >> 1)) return i;
}
}
 
int main()
{
int t=GI;
int ret;
while(t--)
{
ret = 0; scanf("%s", inp);
int l = strlen(inp), c = 0;
for(;c<l;)
{
c += findLength(inp + c);
ret += 2;
}
printf("%d\n", ret);
}
return 0;
}
