#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int cnt[5] = {0},n,ans=1;
		char x;
		cin>>n;
		while(n--)
		{
			cin>>x;
			if( x == 'G' )
				cnt[0]++;
			else if( x == 'S' )
				cnt[1]++;
			else if( x == 'R' )
				cnt[2]++;
			else if( x == 'H' )
				cnt[3]++;
			else
				cnt[4]++;
		}

		for(int i=0;i<4;i++)
			ans = ans * ( (1<<cnt[i]) -1 );

		ans = ans * ( 1<<cnt[4] );
		if( ans == 0 )
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
}
