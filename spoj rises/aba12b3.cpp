    #include<iostream>
    #include<vector>
    #include<string>
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<map>
    #define vi vector<int>
    using namespace std;
    string st;
    void makePi(vector<int> &pi)
    {
    int length=st.length()-1;
    pi[0]=pi[1]=0;
    int k=0;
    for(int q=2;q<=length;q++)
    {
    while(k>0 && st[k+1]!=st[q])
    k=pi[k];
    if(st[k+1]==st[q])
    k=k+1;
    pi[q]=k;
    }
    }
    int main()
    {
    int t;
    scanf("%d",&t);
    while(t--)
    {
    string st1;
    cin>>st1;
    st=" "+st1;
    int ans=0;
    while(st.length()>1)
    {
    //cout<<"KMP for "<<st<<"\n";
    int length=st.length()-1;
    vi pi(length+1);
    int i;
    for(i = 0; i < length; i++)
    	printf("%d ",pi[i]);
    makePi(pi);
    int stop,ind=-1;
    for(int i=length;i>=1;i--)
    {
    if(pi[i]==0)continue;
    if((i%(i-pi[i]))==0)
    stop=i/(i-pi[i]),ind=i;
    }
    //cout<<stop<<"\n";
    ans+=stop;
    //if(ind==-1)
    //cout<<"over\n";
    //else
    st=" "+st.substr(ind+1);
    }
    cout<<ans<<"\n";
    }
    } 
