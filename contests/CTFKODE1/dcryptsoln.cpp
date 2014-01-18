#include<stdio.h>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

#define scani(a) scanf("%d",&a);
#define fori(a,b) for(i=a;i<=b;i++)
#define fork(a,b) for(k=a;k<=b;k++)
#define forj(a,b) for(j=a;j<=b;j++)

int main()
{
	int t, n, key, ne, i, pos;
	scani(t)
	char input[100001], output[100001];
	while(t--)
	{
		scani(key)
		scanf("%s", input);
		n = strlen(input);
		if(key <= 25)
		{
			fori(0, n-1)
			{
				if(input[i] == '.')
					output[i] = ' ';
				else
				{
					if(input[i] >= 65 && input[i] <= 90)
					{
						ne = input[i] + key;
						if(ne > 90)
							ne = ne % 90 + 64;
					}
					else
					{
						ne = input[i] + key;
						if(ne > 122)
							ne = ne % 122 + 96;
					}
					output[i] = ne;					
				}
			}
		}
		else
		{
			key = key % 26;
			fori(0, n-1)
			{
				if(input[i] == '.')
					output[i] = ' ';
				else
				{
					if(input[i] >= 65 && input[i] <= 90)
					{
						ne = input[i] + key;
						if(ne > 90)
							ne = ne % 90 + 64;
						ne += 32;
					}
					else
					{
						ne = input[i] + key;
						if(ne > 122)
							ne = ne % 122 + 96;
						ne -= 32;
					}
					output[i] = ne;					
				}
			}
		}
		output[n] = '\0';
		printf("%s\n", output);
	}
	return 0;
}
