#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanc(c) scanf("%c",&c);
#define println printf("\n");

int main()
{
	int t, s, i;
	long long int ans;
	char ch;
	scani(t)
	while(t--)
	{
		scani(s)
		string str;
		cin >> str;
		stack<int> index;
		stack<char> value;
		while(index.size() > 0)
			index.pop();
		while(value.size() > 0)
			value.pop();
		ans = 0LL;
		fori(1, s)
		{
			ch = str[i-1];
			if(ch == '7')
			{
				if(!value.empty() && value.top() == '4')
				{
					ans = ans + (long long int)(index.top());
			//		printf("adding %d\n", index.top());
					value.pop();
					index.pop();
				}
				else
				{
					value.push(ch);
					index.push(i);
				}
			}
			else
			{
				value.push(ch);
				index.push(i);				
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
