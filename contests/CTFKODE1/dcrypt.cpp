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
	char data[53];
	for(i = 0; i < 26; i++)
		data[i] = i + 97;
	for(i = 27; i < 53; i++)
		data[i] = i + 38;
	data[26] = '.';
	ofstream inp;
	ofstream oup;
	inp.open("dcryptinp.txt");
	oup.open("dcryptoup.txt");
	scani(t)
	inp<<t<<"\n";
	char input[100001], output[100001];
	while(t--)
	{
		n = 100000;
	//	scani(n)
		key = rand() % 52;
	//	scani(key)
		inp<<key<<"\n";
		fori(0, n-1)
		{
			pos = rand() % 53;
			input[i] = data[pos];
		}
		input[i] = '\0';
		inp<<input<<"\n";
	//	scanf("%s", input);
	//	printf("%s\n",input);
	//	n = strlen(input);
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
		oup<<output<<"\n";
//		printf("%s\n", output);
	}
	return 0;
}
