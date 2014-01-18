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
	int t, n, m, r, a, b, turn, pos1, pos2, win, i, roll, j, temp;
	bool finish;
	scani(t)
	while(t--)
	{
		int mp[102] = {0};
		scani(n)
		scani(m)
		scani(r)
		fori(0, m-1)
		{
			scani(a)
			scani(b)
			mp[a] = b;
		}
		turn = 1;
		pos1 = pos2 = 1;
		finish = false;
		win = 0;
		fori(0, r-1)
		{
			scani(roll)
			//printf("roll : %d turn : %d pos1 : %d pos2 : %d\n", roll, turn, pos1, pos2);
			if(finish)
				continue;
			if(turn == 1)
			{
				turn = 2;
				if(pos1 + roll <= n)
				{
					pos1 = pos1 + roll;
					while(mp[pos1] != 0)
					{
						pos1 = mp[pos1];
						turn = 1;
					}	
				}
				if(roll == 6)
					turn = 1;
				if(pos1 == pos2)
				{
					turn = 1;
					pos2 = 1;
				}
				if(pos1 == n)
				{
					win = 1;
					finish = true;
				}
			}	
			else
			{
				turn = 1;
				if(pos2 + roll <= n)
				{
					pos2 = pos2 + roll;
					while(mp[pos2] != 0)
					{
						pos2 = mp[pos2];
						turn = 2;
					}	
				}
				if(roll == 6)
					turn = 2;
				if(pos1 == pos2)
				{
					turn = 2;
					pos1 = 1;
				}
				if(pos2 == n)
				{
					win = 2;
					finish = true;
				}
				
			}
		}
		printf("%d %d %d\n", win, pos1, pos2);
	}
	return 0;
}
