#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
string tostring(int num)
{
	string ret = "";
	int d;
	while(num > 0)
	{
		d = num % 10;
		ret = (char)(d + 48) + ret;
		num = num / 10;
	}
	return ret;
}
int main()
{
	//char s[100008];
	char ch;
	string str, output;
	while((scanf("%c",&ch))!=EOF)
	{
		output = "";
		int i,j;
		i=0;
		cin >> str;
		str = ch + str;
		int len = str.length();
		printf("len : %d\n", len);
		while(i < len)
		{
			j=i;
			while(str[j]==str[j+1])
				j++;
			int temp=j-i+1;
			
			switch (temp)
			{
				case 1: output = output + str[j];
						break;
				case 2: output = output + str[j] + str[j];
						break;
				case 3: output = output + str[j] + str[j] + str[j];
						break;
				default:output = output + tostring(temp) + "!" + str[j];
			}
			j++;
			i=j;
		
		}
		cout << output << "\n";
		//printf("\n");
	}
	return 0;
	
}



