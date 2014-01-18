#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanc(c) scanf("%c",&c);
#define println printf("\n");

int main()
{
	int r, i;
	string str;
	while(1)
	{
		scani(r)
		if(r == -1)
			break;
		cin >> str;
		int len = str.length();
		vector<string> vec(len);
		fori(0, len-1)
		{
			vec[i] = str;
			str = str.substr(1, len-1) + str.substr(0, 1);
		}
		sort(vec.begin(), vec.end());
		cout<<vec[r-1]<<"\n";
/*		fori(0, len-1)
			vec[i] = str[i];
		sort(vec.begin(), vec.end());
		fori(1, r-1)
			next_permutation(vec.begin(), vec.end());
		fori(0, len-1)
			printf("%c", vec[i]);
		printf("\n");*/
	}
	return 0;
}
