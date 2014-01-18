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

char mat[100][100];
bool test(int i, int j, int n, int m, int no)
{
	int dx, dy, i1, i2, j1, j2, count = 0;
//	printf("test func i : %d j : %d no : %d", i, j, no);
	if(i == 0)
		i1 = 0;
	else
		i1 = i-1;
	if(i == n-1)
		i2 = n-1;
	else
		i2 = i+1;
	if(j == 0)
		j1 = 0;
	else
		j1 = j-1;
	if(j == m-1)
		j2 = m-1;
	else
		j2 = j+1;
	for(dx = i1; dx <= i2; dx++)
	{
		for(dy = j1; dy <= j2; dy++)
		{
			if(mat[dx][dy] == 'F')
				count++;
		}
	}
	//printf("count : %d\n", count);
	if(count == no)
		return false;
	return true;
	
}
int main()
{
	int t, n, m, i, j;
	bool flag;
	scani(t)
	while(t--)
	{
		scani(n)
		scani(m)
		//char mat[n][m];
		fori(0, n-1)
			scanf("%s", mat[i]);
		flag = false;
		fori(0, n-1)
		{
			if(flag)
				break;
			forj(0, m-1)
			{
				if(mat[i][j] >= '0' && mat[i][j] <= '8')
					if(test(i, j, n, m, mat[i][j]-48))
					{
						//printf(")
						flag = true;
						false;
					}
			}
		}
		if(flag)
			printf("Please sweep the mine again!\n");
		else
			printf("Well done Clark!\n");
	}
	return 0;
}
