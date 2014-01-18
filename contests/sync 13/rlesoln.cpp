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
string tostring(int num)
{
	string ret = "";
	int d;
	while(num > 0)
	{
		d = num % 10;
		ret = (char)(d + 48) + ret;
		num = num / 10;
	}
	return ret;
}
int main()
{
	int t = 1, i, j, k, len, count;
	string ans, str;	
	ifstream inp;
	ofstream oup;
	//inp.open("input.txt");
	//oup.open("output.txt");
	//scani(t)
	//inp >> t;
	while(t)
	{
		cin >> str;
		//inp >> str;
		ans = "";
		len = str.length();
		cout << "len" << len << "\n";
		count = 1;
		fori(1, len - 1)
		{
			if(str[i] == str[i-1])
			{
				count++;
				continue;
			}
			if(count <= 3)
				forj(1, count)
					ans = ans + str[i-1];
			else	
				ans = ans + tostring(count) + "!" + str[i-1];
			count = 1;
		}
		if(count <= 2)
			forj(1, count)
				ans = ans + str[len-1];
		else	
			ans = ans + tostring(count) + "!" + str[len-1];
		//oup << ans << "\n";
		cout << ans << "\n";
		//char chc = getchar();
	}
	return 0;
}



