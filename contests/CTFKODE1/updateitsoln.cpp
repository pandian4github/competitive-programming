#include<stdio.h>
#include<fstream>
#include<math.h>
#include<stdlib.h>
using namespace std;

#define scani(a) scanf("%d",&a);
#define fori(a,b) for(i=a;i<=b;i++)
#define fork(a,b) for(k=a;k<=b;k++)
#define forj(a,b) for(j=a;j<=b;j++)

int main()
{
	int t, n, q, l, r, val, i, temp, u;
	scani(t)
	while(t--)
	{
		scani(n)
		int arr[n+1];
		fori(0, n)
			arr[i] = 0;
		scani(u)
		while(u--)
		{
			scani(l)
			scani(r)
			if(l>r)
			{
				temp = l;
				l = r;
				r = temp;
			}
			scani(val)
			arr[l] += val;
			arr[r+1] -= val;
		}
		fori(1, n)
			arr[i] += arr[i-1];
		scani(q)
		while(q--)
		{
			scani(l)
			printf("%d\n",arr[l]);
		}		
	}
	return 0;
}
