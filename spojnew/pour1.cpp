#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   int t,a,b,c,ans,max,min,f1,f2,flag,ans1,ans2,cnt,f3,ans3;
   cin>>t;
   while(t>0)
    {
      t--;
      flag=0;
      f1=f2=f3=0;
      ans1=ans2=ans3=0;
      cin>>a>>b>>c;
      max=(a>=b)?a:b;
      min=(a+b)-max;
      if(c==a||c==b)
       ans=1;
      else
       if(c>max)
         flag=1;
       else      
        if(c>min&&c<max)
         {
          if(c%min!=0)
            f1=1;
          else            
            ans1=2*c/min;  
          if((max-c)%min!=0)
            f2=1;
          else             
           {
            cnt=max;
            ans2++;
            while(1)
             {
              cnt=cnt-min;
              ans2++;
              if(cnt==c)
                break;
              ans2++;
             }   
           }
          if(f1&&f2)
            flag=1;
          else
            ans=(ans1>=ans2)?ans1:ans2;      
         }
        else
         {
          if((max-c)%min!=0)
           f3=1;
          else
          {
           cnt=max;
           ans3++;
           while(1)
           {
            cnt=cnt-min;
            ans3++;
            if(cnt==c)
              break;
            ans3++;
           }   
          }
          if(max%c!=0)
            f1=1;
          else
            ans1=2*(max/c);
          if(min%c!=0)
            f2=1;
          else
            ans2=2*(min/c);
          ans=(ans1>=ans2)?ans1:ans2;
          ans=(ans>=ans3)?ans:ans3;        
         }          
      if(flag)
        cout<<"-1\n";
      else  
        cout<<ans<<"\n";
     }
 //  getch();
   return 0;
 }           
      
            
        
   
