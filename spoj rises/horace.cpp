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

int isprime[1000001] = {0};
int primes[1001] = {0};
int numsteps[1000001] = {0};
int actualcount[1000001][13];
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
		for(j = i*i; j <= 1000001; j+=i)
			isprime[j] = 0;
	}
	//fori(0, 20)
	//	printf("%d ",primes[i]);
	
}

int main()
{
	int t, n, i, j, sum, a, b, K, max = 0;
	int numcount[13] = {0};
	scani(t)
	primesieve();
	//printf("sieve over !");
	primes[0] = 2;
	fori(0, 12)
		actualcount[1][i] = 0;
	fori(2, 1000000)
	{
	//	printf("i : %d\n",i);
		n = i;
		if(isprime[n])
			numsteps[n] = 1;
		else
		{
			sum = 0;
			for(j = 0; j < k; j++)
			{
//				if(i == 90)
//					printf("isprime[%d] : %d\n",n , isprime[n]);
				if(isprime[n])
				{
					sum = sum + n;
					break;
				}
				if(primes[j] > sqrt(n))
					break;
				if(n % primes[j] == 0)
				{
					sum += primes[j];
					while(n % primes[j] == 0)
						n = n / primes[j];
				}
//				if(i == 90)
//				{
//					printf("end of %d \n",primes[j]);
//					printf("n : %d\n",n);
//				}
				
			}
//			if(i == 90)
//				printf("sum : %d\n",sum);
			numsteps[i] = numsteps[sum] + 1;
	//		numcount[numsteps[i]]++;
	//		if(numsteps[i] > max)
	//			max = numsteps[i];
		}	
		forj(1, 12)
			actualcount[i][j] = actualcount[i-1][j];
		actualcount[i][numsteps[i]]++;
	}
	//fori(2, 20)
	//	printf("%d ",numsteps[i]);
	//printf("\nmax = %d\n",max);
	//fori(0,12)
	//	printf("%d ",numcount[i]);
	//fori(1, 10)
	//{
	//	forj(1, 12)
	//		printf("%d ",actualcount[i][j]);
	//	printf("\n");
	//}
	while(t--)
	{
		scani(a)
		scani(b)
		scani(K)
		if(K > 12)
			printf("0\n");
		else
			printf("%d\n",actualcount[b][K] - actualcount[a-1][K]);
	}
	return 0;
}
