#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   int t,m,n,d,i;
   scanf("%d",&t);
   while(t>0)
    {
      scanf("%d%d%d",&n,&m,&d);
      int arr,count=0;
      for(i=0;i<n;i++)
       {
         scanf("%d",&arr);
         count+=(arr-1)/d;
       }
      if(count>=m)
        printf("YES\n");
      else
        printf("NO\n");
      t--;  
    }
//   getch();
   return 0;
 }        
       
         
