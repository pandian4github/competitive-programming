#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int flag=1,ones=0,twos=0,fours=0;
		for(int i=s.size()-1;i>=0;i--)
		{
			if(flag==1)
			{
				if(s[i]=='1')				
					ones++;
				flag=2;
			}
			else if(flag==2)
			{
				if(s[i]=='1')				
					twos++;
				flag=0;
			}
			else
			{
				if(s[i]=='1')				
					fours++;
				flag=1;
			}
		}
		int ans=fours*4+twos*2+ones;
		if(ans%7==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
