#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanc(c) scanf("%c",&c);
#define println printf("\n");

int main()
{
	int t, n, i, j;
	long long int ans;
	scani(t)
	while(t--)
	{
		scani(n)
		long long int arr[n+1];
		long long int Xor[n+1];
		fori(0, n-1)
			scanlli(arr[i])
		Xor[0] = arr[0];
		ans = Xor[0];
		fori(1, n-1)
		{
			Xor[i] = Xor[i-1] ^ arr[i];
			ans += Xor[i];
		}	
		fori(1, n-1)
		{
			ans += arr[i];
			forj(i+1, n-1)
			{
				Xor[j] = Xor[j] ^ arr[i-1];
				ans += (long long int)Xor[j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
