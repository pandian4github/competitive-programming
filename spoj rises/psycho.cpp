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

//int prec[1000000];
int isprime[10000];
int primes[10000];
int k;
void primesieve()
{
	int i,j;
	k = 0;
	memset(isprime, 1, sizeof(isprime));
	isprime[1]=0;
	fori(2,10000)
	{
		if(isprime[i] == 0)
			continue;
		//printf("i : %d\n",i);
		primes[k++] = i;
		//printf("primes[0] : %d\n",primes[0]);
		for(j = i*i; j <= 10000; j+=i)
			isprime[j] = 0;
	}
	//fori(0, 20)
	//	printf("%d ",primes[i]);
	
}
int main()
{
	int t, n, sqt, i, count, ecount, ocount;
	primesieve();
//	printf("k : %d\n",k);
//	fori(0, 20)
//		printf("%d ",primes[i]);
	primes[0] = 2;
	scani(t)
	while(t--)
	{
		scani(n)
		ecount = ocount = 0;
		for(i = 0; i < k; i++)
		{
			sqt = sqrt(n);
		//	printf("sqt : %d primes[i] : %d\n",sqt, primes[1]);
		//	printf("..i : %d primes[i] : %d n : %d ecount : %d ocount : %d\n", i, primes[i], n, ecount, ocount);
			if(n == 1)
				break;
			if(primes[i] > sqt)
			{
				ocount++;
				break;
			}
			count = 0;
			while(n % primes[i] == 0)
			{
				count++;
				n = n / primes[i];
			}	
			if(count != 0)
			{
				if(count % 2 == 0)
					ecount++;
				else
					ocount++;
			}
		//	printf("i : %d primes[i] : %d n : %d ecount : %d ocount : %d\n", i, primes[i], n, ecount, ocount);
		}
		if(ecount > ocount)
			printf("Psycho Number\n");
		else
			printf("Ordinary Number\n");
		
	}
	return 0;
}
