#include<iostream>
using namespace std;
int main()
{
    int var=0,m,n,i,z,y,count1=0,count2=0,count3=0,count=0;
    char a[10],x[10];
    //cin>>t;
    //while(t--)
    //{
    cin>>n;
    //cin>>x;
    //cout<<x;
    //y=strcmp(x,"1/2");
    //cout<<y;
    //if(!strcmp(x,"1/2"))
    //cout<<"1/2";
   // cout<<"\n";
    for(i=0;i<n;i++)
    {
                    cout<<"\n";
                    cin>>a;
                    //cout<<"\n";
                    if(!strcmp(a,"1/4"))
                    count1++;
                    else if(!strcmp(a,"1/2"))
                    count2++;
                    else if(!strcmp(a,"3/4"))
                    count3++;
                    
                    //cout<<"0count"<<count1<<count2<<count3;
   }
   
                    if(count2%2==0)
                    count=count2/2;
                    else 
                    {
                    count=(count2/2)+1;
                    var++;
                    }
   
                    //cout<<"\n count & var "<<count<<var;
   
                    if(count3>count1)
                    {
                     count=count+(count3-count1)+count1;
                     //cout<<"akhka"<<count;
                    }
   
                    else if(count1>=count3)
                    {
                    //count=(count1-count3)+count3;
                    count1=count1-count3;
                    //cout<<"z..."<<z<<"\n";
                    y=count1/4;
                    m=count1%4;
                    //cout<<"y...."<<y<<"\n";
                    if(count1%4==0)
                    count=count+count3+y;
                    else
                    count=count+count3+y+1;
                    
                    if((m<=2)&&var==1)
                    count--;
                    }
                    
    
    /*cout<<"Count1....."<<count1<<"\n";
    cout<<"Count2....."<<count2<<"\n";
    cout<<"Count3....."<<count3<<"\n";*/
    count++;
    cout<<count;
//    }
 //  cin>>n;
    return 0;
}
