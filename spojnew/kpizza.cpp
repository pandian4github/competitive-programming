#include<iostream>
using namespace std;
int main()
{
    int n,i,count1=0,count2=0,count3=0,count=0;
    char a[10003],x[10];
    cin>>n;
    cin>>x;
    strcmp(x,"1/2")
    cout<<"1/2";
    for(i=0;i<n;i++)
    {
                    cin>>a[i];
                    if(a[i]=='1/4')
                    count1++;
                    else if(a[i]=='1/2')
                    count2++;
                    else if(a[i]=='3/4')
                    count3++;
                    if(count3>count1)
                    count=(count3-count)+count;
                    else if(count1>=count3)
                    count=(count-count3)+count3;
                    if(count2%2==0)
                    count=count+(count2/2);
                    else 
                    count=count+(count2/2)+1;
    }
    count++;
    cout<<count;
    cin>>n;
    return 0;
}
