#include<iostream>
//#include<conio.h>
using namespace std;
/*long long int maxsum(long long int arr[],int x,int y)
 {
   long int i,pos;
   long long int ma,ma2;
   i=x+1;
   ma=arr[x];
   pos=x;
   for(;i<=y;i++)
     if(arr[i]>ma)
      {
       ma=arr[i];
       pos=i;
      } 
    if(x==pos)
      ma2=arr[x+1];
    else
      ma2=arr[x];  
    for(i=x+1;i<=y;i++)
      if(arr[i]>ma2&&i!=pos)
        ma2=arr[i];
    return (ma+ma2);      
 }*/  
       
int main()
 {
   long int n,x,y,j;
   cin>>n;
   long long int arr[n+1],i;
   for(i=1;i<=n;i++)
     cin>>arr[i];
   long int q;
   cin>>q;
   char str[15];
   for(i=0;i<q;i++)
    {
       cin>>str;
       cin>>x>>y;
       if(str[0]=='U')
         arr[x]=y;
       else
        {
          long int i,pos;
          long long int ma,ma2;
          i=x+1;
          ma=arr[x];
          pos=x;
          for(;i<=y;i++)
            if(arr[i]>ma)
              {
                 ma=arr[i];
                 pos=i;
              } 
          if(x==pos)
             ma2=arr[x+1];
          else
             ma2=arr[x];  
          for(i=x+1;i<=y;i++)
             if(arr[i]>ma2&&i!=pos)
                ma2=arr[i];
         cout<<(ma+ma2)<<"\n";
        }        

   //      cout<<maxsum(arr,x,y)<<endl;
//       cout<<"\n";
//       for(j=1;j<=n;j++)
//         cout<<"   "<<arr[j];
//       cout<<"\n";    
    }
//   getch();
   return 0;
 }                     
   
