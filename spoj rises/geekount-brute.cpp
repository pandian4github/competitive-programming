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
int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int gcount = 0;
int noofdigs(int n)
{
	int count = 0;
	while(n != 0)
	{
		count++;
		n = n / 10;
	}
	return count;
}
int recurse(int a, int b)
{
	if(a == 0 && b == 0)
		return 1;
	if(a == 0)
	{
		gcount++;
		a = 1;
	}
	int n1 = noofdigs(a);
	int n2 = noofdigs(b);
//	printf("recurse a : %d b : %d n1 : %d n2 : %d\n",a , b, n1, n2);
	int ans = 0, i, f1, f2;
	if(n1 == n2)
	{
		if(n1 == 1)
		{
			ans = 0;
			for(i = a; i <= b; i++)
				if(i % 2 == 0)
					ans++;
			return ans;
		}
		f1 = a / pow10[n1-1];
		f2 = b / pow10[n2-1];
		if(f1 == f2)
		{
			if(f1 % 2 == 0)
				return b - a + 1;
			return recurse(a % pow10[n1-1], b % pow10[n2-1]);
		}
		else
		{
			ans = 0;
			for(i = f1+1; i < f2; i++)
			{
				if(i % 2 == 0)
					ans = ans + pow10[n2-1];
				else
					ans = ans + recurse(1, pow10[n1-1]-1) + 1;
			}
			if(f1 % 2 == 0)
				ans = ans + pow10[n1-1] - (a % pow10[n1-1]) + 1;
			else
				ans = ans + recurse(a % pow10[n1-1], pow10[n1-1] - 1);
			if(f2 % 2 == 0)
				ans = ans + (b % pow10[n1-1]) + 1;
			else
				ans = ans + recurse(1, b % pow10[n1-1]) + 1;
			return ans;	
		}
	}
	else
	{
		ans = 0;
		for(i = n1 + 1; i < n2; i++)
			ans = ans + recurse(pow10[i-1], pow10[i]-1);
		ans = ans + recurse(a, pow10[n1]-1) + recurse(pow10[n2-1], b);
		return ans;
	}
}
int answer(int a, int b)
{
	int i, count = 0, d, temp;
	fori(a, b)
	{
		temp = i;
		while(temp != 0)
		{
			d = temp % 10;
			if(d % 2 == 0)
			{
				count ++;
				break;
			}
			temp = temp / 10;
		}
	}
	return count;
}
int main()
{
	int t, a, b;
	scani(t)
	while(t--)
	{
		scani(a)
		scani(b)
		gcount = 0;
		printf("%d\n",answer(a, b));
	}
	return 0;
}
//234 179
//345 280
//000 845
// 1002300 9870540 8793241
//997558595
// 198465 198987 523
