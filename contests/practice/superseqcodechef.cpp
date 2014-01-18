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
int dp[1001][1001];
int ls[1001][1001];
int lcs1[1001], lcs2[1001], arr1[1001], arr2[1001];
char dir[1001][1001];
string s1, s2;
/*void preprocess()
{
	int i, j;
	forj(1, 1000)
		dp[0][j] = 1;
	forj(1, 1000)
		dp[1][j] = j + 1;
	fori(2, 1000)
		forj(i, 1000)
			dp[i][j] = dp[i-1][j] + j * (j + 1) / 2;
}
void lcs(string s1, string s2)
{
	int i, j;
	fori(0, 1000)
		ls[0][i] = ls[i][0] = 0;
	fori(1, s1.length())
	{
		forj(1, s2.length())
		{
			if(s1[i-1] == s2[i-1])
			{
				ls[i][j] = ls[i-1][j-1] + 1;
				dir[i][j] = 'd';
			}
			else
				if(ls[i-1][j] > ls[i][j-1])
				{
					ls[i][j] = ls[i-1][j];
					dir = 'l';
				}
				else
				{
					ls[i][j] = ls[i-1][j];
					dir = 'u';
					
				}
		}
	}
}
void findlcs(int i, int j)
{
	if(i == 0 || j == 0)
		return;
	if(dir[i][j] == 'd')
	{
		lcs1[i-1] = true;
		lcs2[j-1] = true;
		findlcs(i-1, j-1);
	}
	else
		if(dir[i][j] == 'l')
			findlcs(i, j-1);
		else
			findlcs(i-1, j);
}*/
int func(int i, int j, int l1, int l2)
{
	if(i == l1 || j == l2)
		return 1;
	if(s1[i] == s2[j])
		return func(i+1, j+1, l1, l2);
	return func(i+1, j, l1, l2) + func(i, j+1, l1, l2);
}
void create_answer(int n, int i, int j) 
{
	if(i >= s1.length())
	{
		while(j < s2.length())
			printf("%c", s2[j++]);
		return;
	}
	if(j >= s2.length())
	{
		while(i < s1.length())
			printf("%c", s1[i++]);
		return;
	}
	
	if(n > dp[0][0])
	{
		printf("NO ANSWER");
		return;
	}
    if(s1[i] == s2[j]) 
	{
		printf("%c", s1[i]);
		create_answer(n,i+1,j+1);
	}
    else 
		if(s1[i]<s2[j]) 
		{
        	if(n <= dp[i+1][j]) 
			{
				printf("%c",s1[i]);
				create_answer(n, i+1, j);
			}
        	else 
			{
				printf("%c", s2[j]);
				create_answer(n-dp[i+1][j], i, j+1);
			}
    	}
    	else 
		{
        	if(n <= dp[i][j+1]) 
			{
				printf("%c", s2[j]);
				create_answer(n, i, j+1);
			}
        	else 
			{
				printf("%c", s1[i]);
				create_answer(n-dp[i][j+1], i+1, j);
			}
    	}
}
int main()
{
	int t, n, ind;
	int i, j;
	scani(t)
	while(t--)
	{
		cin >> s1;
		cin >> s2;
		scani(n)
		int l1 = s1.length(), l2 = s2.length();
		for(i = l1; i >= 0; i--)
			for(j = l2; j >= 0; j--)
				dp[i][j] = func(i, j, l1, l2);
		//printf("dsd");
		create_answer(n, 0, 0);
    	printf("\n");
				
/*		lcs(s1, s2);
		findlcs(l1, l2);
		ind = 0;
		left1 = left2 = 0;
		while(left1 < l1 && lcs1[left1] == true)
			left1++;
		while(left2 < l2 && lcs2[left2] == true)
			left2++;
		while(left1 < l1 && left2 < l2)
		{
			count1 = 0;
			startarr1[ind] = left1;
			fori(left1, l1-1)
			{
				if(lcs1[i] == true)
				{
					while(i < l1 && lcs[i] == true)
						i++;
					break;
				}	
				count1++;
			}
			left1 = i;
			count2 = 0;
			startarr2[ind] = left2;
			forj(left2, l2-1)
			{
				if(lcs2[j] == true)
				{
					while(j < l2 && lcs2[j] == true)
						j++;
					break;
				}
				count2++;
			}
			left2 = j;
			arr1[ind] = count1;
			arr2[ind++] = count2;
		}
		fori(ind-1, ind-1)
		{
			if(dp[arr1[i]][arr2[i]] >= n)
				break;
			n = n - dp[arr1[i]][arr2[i]];
		}
		
		
		flag = false;
		count = 0;
		recurse(s1, s2, 0, 0, n, 0);
		if(count != n)
			printf("NO ANSWER\n");*/
	}
	return 0;
	
}
