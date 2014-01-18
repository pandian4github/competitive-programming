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
	int b1,b2,b3;
	int i;
	int *ptr;
	b1 = b2 = b3 = 0;
	int count = 0, out = 0;
	ptr = &b1;
	char ch;
	int outb = -1, strike = 1;
	while(count < 6)
	{
		scanc(ch)
	//	printf("strike : %d outb : %d count : %d b1 : %d b2 : %d b3 : %d\n",strike, outb, count, b1, b2, b3);
	//	printf("%c",ch);
		if(ch == 'W' || ch == 'N' || ch == ' ')
			continue;
		if(ch == 'O')
		{
			count++;
			out++;
			if(out == 2)
				break;
			if(strike == 1)
				outb = 1;
			else
				outb = 2;
			ptr = &b3;
			strike = 3;
			continue;
		}
		count++;
		*ptr = *ptr + ch - 48;
		if(out == 0 && ch % 2 != 0)
		{
			if(strike == 1)
			{
				ptr = &b2;
				strike = 2;				
			}
			else
			{
				ptr = &b1;
				strike = 1;
			}
		}
		else
		{	if(ch % 2 != 0)
			{
				if(outb == 1)
				{
					if(strike == 2)
					{
						ptr = &b3;
						strike = 3;
					}
					else
					{
						ptr = &b2;
						strike = 2;
					}
				}
				else
				{
					if(strike == 1)
					{
						ptr = &b3;
						strike = 3;
					}
					else
					{
						ptr = &b1;
						strike = 1;
					}
				}

			}
		}
		
	}
	printf("%d %d %d\n",b1,b2,b3);
	return 0;
}
