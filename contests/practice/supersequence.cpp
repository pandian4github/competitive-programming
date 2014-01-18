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
char str[1002];
bool flag;
int count;
void print(int index)
{
	int i;
	fori(0, index)
		printf("%c", str[i]);
	printf("\n");
}
void recurse(string s1, string s2, int i, int j, int n, int index)
{
	//int ind;
	//printf("recurse :: i : %d j : %d index : %d\n", i, j, index);
	if(flag == true)
		return;
	if(i == s1.length() && j == s2.length())
	{
		count++;
		if(count == n)
		{	
			print(index);
			flag = true;
		}
	}
	else
		if(i == s1.length())
		{	
			str[index] = s2[j];
			recurse(s1, s2, i, j+1, n, index+1);
		}
		else
			if(j == s2.length())
			{
				str[index] = s1[i];
				recurse(s1, s2, i+1, j, n, index+1);
			}
			else
				if(s1[i] == s2[j])
				{
					str[index] = s1[i];
					recurse(s1, s2, i+1, j+1, n, index+1);
				}
				else
				{
					if(s1[i] < s2[j])
					{
						str[index] = s1[i];
						recurse(s1, s2, i+1, j, n, index+1);
						str[index] = s2[j];
						recurse(s1, s2, i, j+1, n, index+1);
					}
				}
	return;
}
int main()
{
	int t, n;
	string s1, s2;
	scani(t)
	while(t--)
	{
		cin >> s1;
		cin >> s2;
		scani(n)
		flag = false;
		count = 0;
		recurse(s1, s2, 0, 0, n, 0);
		if(count != n)
			printf("NO ANSWER\n");
	}
	return 0;
}
