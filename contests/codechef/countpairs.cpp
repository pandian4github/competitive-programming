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
	int t, n, k, a, i, ans;
	map<int, int> mp;
	map<int, int>::iterator it;
	scani(n)
	scani(k)
	int arr[n];
	fori(0, n-1)
	{
		scani(arr[i])
		mp[arr[i]]++;
	}
	sort(arr, arr + n);
	ans = 0;
	fori(0, n-1)
	{
		ans = ans + mp[arr[i]] * mp[arr[i] + k];
		mp[arr[i]] = 0;
	}
	/*ans = 0;
	for(it = mp.begin(); it != mp.end(); ++it)
		ans = ans + (*it).second * mp[(*it).first + k];*/
	printf("%d\n", ans);
	return 0;
}
