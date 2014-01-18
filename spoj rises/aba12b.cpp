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
#define m_p(x, y) make_pair(x, y)

string str;
/*bool isFine(int j, int k)
{
	//printf("comparing %d and %d\n",j,k);
	int diff = k - j;
	int avg = ( j + k ) / 2;
	string str1, str2;
	if(j == k)
	{
		if(str[2*j] == str[2*j+1])
			return true;
		else
			return false;
	}
	if(diff % 2 == 0)
	{
		str1 = str.substr(j*2, diff+1);
		str2 = str.substr(2*avg+1, diff+1);
	}	
	else
	{
		str1 = str.substr(j*2, diff+1);
		str2 = str.substr(2*(avg+1), diff+1);
	}
	if(str1.compare(str2) == 0)
		return true;
	return false;
}*/
int main()
{
	int t, len, i, j, k, x, y, z;
	scani(t)
	while(t--)
	{
		cin >> str;
		vector<vector<int> > vec(256);
		map<pair<int, int>, bool> mp;
		int count[256] = {0}, length[256] = {0};
		len = str.length();
		for(i = 0; i < len; i++)
			vec[str[i]].push_back(i);
		//printf("over");
		fori(0, 255)
			length[i] = vec[i].size();
		//fori(0, 255)
		//	printf("%d ", length[i]);
		for(i = 0; i < len; i+=2)
		{
			//count[str[i]]++;
			for(j = 0; j < length[str[i]]; j++)
			{
				if(vec[str[i]].at(j) <= i)
					continue;
				x = i;
				y = z = vec[str[i]].at(j);
				if(len - y < y - i)
					break;
				while(str[x] == str[y] && x < z)
				{
					x++;
					y++;
				}
				if(x == z)
				{	
					mp[m_p(i/2, (y-2)/2)] = true;
				//	printf("mp[%d, %d]\n",i/2,  (y-2)/2);
				}
			}	
		}
		int dp[100001] = {0};
		if(str[0] == str[1])
			dp[0] = 2;
		fori(1, len/2-1)
		{
			j = k = i;
			if(dp[j-1] == 0)
			{
				while(--j >= 0)
				{
					if((j == 0 || dp[j-1] > 0) && mp[m_p(j,k)])
					{
						if(j == 0)
							j = 1;
						dp[k] = dp[j-1] + 2;
						break;
					}
				}
				
			}
			else
			{
				if(str[2*k] == str[2*k+1])
					dp[k] = dp[k-1] + 2;
				else
				{
					while(--j >= 0)
					{
						if((j == 0 || dp[j-1] > 0) && mp[m_p(j,k)])
						{
							if(j == 0)
								j = 1;
							dp[k] = dp[j-1] + 2;
							break;
						}
					}
				}
			}
			
		}
		//fori(0, len/2-1)
		//	printf("%d ",dp[i]);
		printf("%d\n",dp[len/2-1]);
	}
	return 0;
}
