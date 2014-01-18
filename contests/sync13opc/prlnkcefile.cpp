#include<stdlib.h>
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

#define fori(a, b) for(i=a; i<=b; i++)
#define ll(a) (long long int)(a)

int main()
{
    int t, len, i;
    char ch[] = "rssrsrsrtrttsrtrtttsrsrtsrrrtt";
    ofstream inp;
    ofstream oup;
    inp.open("prlnkceinput3.txt");
    oup.open("prlnkceoutput3.txt");
    std::ios_base::sync_with_stdio(false);
    cin>>t;
    inp << t << "\n";
	while(t--)
    {
        len = rand() % 987654;
        printf("%d\n", len);
        char s[len];
        fori(0, len-1)
        {
        	s[i] = ch[rand() % 30];
        	inp << s[i];
    	}
        s[len] = '\0';
        
		inp << "\n";
      
	    long long int ans=0LL;
        int i,j=0,cnt[3]={0},inc=0;
        for(i=0;i<len;i++)
        {
            cnt[s[i]-'r']++;
            while( cnt[0] !=0 & cnt[1] != 0 & cnt[2] != 0 )
            {
                cnt[s[j]-'r']--;
                inc--;
                j++;
            }
            ans += ll(inc+1);
            inc++;
        }
        oup << ans << "\n";
        //cout<<ans<<endl;
    }
    return 0;
}

