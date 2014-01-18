#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    float t1,t2,t3,t4,t5,t6,t7,t8,r1,r2,r3,r4,maxr;
    int s1,s2,s3,s4;
    while(1)
    {
        cin>>t1>>t2>>t3>>t4>>t5>>t6>>t7>>t8;
        if(t1==-1&&t2==-1&&t3==-1&&t4==-1&&t5==-1&&t6==-1&&t7==-1&&t8==-1)
            return 0;
        if(t1==0&&t2==0&&t3==0&&t4==0)
         {
           s1=s2=s3=s4=0;
         }
        else
         {
          r1=t1/t5;
          r2=t2/t6;
          r3=t3/t7;
          r4=t4/t8;
          maxr=r1;
          if(r2>maxr) maxr=r2;
          if(r3>maxr) maxr=r3;
          if(r4>maxr) maxr=r4;
          maxr=ceil(maxr);
          s1=maxr*t5-t1;
          s2=maxr*t6-t2;
          s3=maxr*t7-t3;
          s4=maxr*t8-t4;
         }
         
        cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
    }
    
}
