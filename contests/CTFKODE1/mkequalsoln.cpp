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
	int t, n, num, i, sum;
	scani(t)
	while(t--)
	{
		sum = 0;
		scani(n)
		fori(0, n-1)
		{
			scani(num)
			sum = sum + num;
		}
		if(sum % n == 0)
			printf("%d\n",n);
		else
			printf("%d\n",n-1);
	}
	return 0;
}
