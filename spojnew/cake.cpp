#include<iostream>
//#include<conio.h>
using namespace std;
int max(int q[],int r[])
 {
  int m1,i;
  m1=q[0];
  for(i=1;i<4;i++)
    if(q[i]>m1)
      m1=q[i];    
  for(i=0;i<4;i++)
   if(q[i]==m1)
     if(r[i]>0)
       {
        m1++;;
        break;
       } 
  return m1;           
 }     
int main()
 {
   int act[4],req[4],quo[4],rem[4],out[4],m,i,res[10000][4],j=0;
   int k;   
   while(1)
    {
      for(i=0;i<4;i++)
        cin>>act[i];
      for(i=0;i<4;i++)
        cin>>req[i];
      if(act[0]==-1)
        break;  
      for(i=0;i<4;i++)
       {
         quo[i]=act[i]/req[i];
         rem[i]=act[i]%req[i];
       }
      if(quo[0]+quo[1]+quo[2]+quo[3]==0)
         m=1;
      else  
         m=max(quo,rem);      
      if(act[0]+act[1]+act[2]+act[3]==0)
        for(i=0;i<4;i++)
          res[j][i]=0;
      else    
        for(i=0;i<4;i++)
         res[j][i]=m*req[i]-act[i];
      
      j++;
    }
   
   for(i=0;i<j;i++)
   {
     for(k=0;k<4;k++)
       cout<<res[i][k]<<" ";
     cout<<endl;   
   } 
//   getch();
   return 0;
 }
    
                 
                    
