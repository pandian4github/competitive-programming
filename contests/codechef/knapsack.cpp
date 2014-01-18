#include<stdio.h>
//#include<math.h>
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
int matrix[102][102];
int c[102], p[102], t[102];
int max(int a, int b)
{
	if(a > b)
		return a;
	return b;
}
int knapsack(int n, int w)
{
	int i, j;
	fori(0, 102)
		matrix[0][i] = matrix[i][0] = 0;
	fori(1, n)
	{
		forj(1, w)
		{
			int k = i-1;
        	if(j >= t[k])
            	matrix[i][j] = max(p[k]*c[k] + matrix[i-1][j-t[k]], matrix[i-1][j]);
          	else
            	matrix[i][j] = matrix[i-1][j];       
		}
	}
/*	fori(0, n)
	{
		forj(0, w)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
*/	return matrix[n][w];
}
int main()
{
	int T, n, w, i;
	scani(T)
	while(T--)
	{
		scani(n)
		scani(w)
		fori(0, n-1)
		{
			scani(c[i])
			scani(p[i])
			scani(t[i])
		}
		printf("%d\n", knapsack(n, w));
	}
	return 0;
}
