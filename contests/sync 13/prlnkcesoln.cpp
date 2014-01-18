#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    std::ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        long long int ans=0LL;
        int i,j=0,cnt[3]={0},inc=0;
        for(i=0;i<s.size();i++)
        {
            cnt[s[i]-'r']++;
            while( cnt[0] !=0 & cnt[1] != 0 & cnt[2] != 0 )
            {
                cnt[s[j]-'r']--;
                inc--;
                j++;
            }
            ans += inc+1;
            inc++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

