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
#define scand(a) scanf("%lf",&a);
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
#define max(a,b) ((a > b) ? a : b)
#define min(a,b) ((a < b) ? a : b)
#define ll(a) (long long int)(a)

int main()
{
	int te, i, j, k;
	double t1, a, l, b, t2, r, h, h1, asquare, arectangle, acircle, atriangle, temp;
	scani(te)
	while(te--)
	{	
		scand(t1)
		scand(a)
		scand(l)
		scand(b)
		scand(t2)
		scand(r)
		
		h = sqrt(3) / 2.0 * t1;
//		cout << h;
		asquare = max(a, t1) * (a + h);
		
		if(l < b)
		{
			temp = l;
			l = b;
			b = temp;
		}
		arectangle = min(max(t1, l) * (b + h), max(t1, b) * (l + h));
		
		acircle = (h + 2*r) * max(2*r, t1);
		
		h1 = sqrt(3) / 2.0 * t2;
		if(h > h1)
			atriangle = h * (t1 / 2.0 + max(t1 / 2.0, t2));
		else
			atriangle = h1 * (t2 / 2.0 + max(t2 / 2.0, t1));
		
		printf("%0.4lf %0.4lf %0.4lf %0.4lf\n", asquare, arectangle, acircle, atriangle);
	}

	return 0;
}



