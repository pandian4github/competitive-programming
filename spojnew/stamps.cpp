#include<stdio.h>
int main()
 {
   int t,i,j,a,count,n;
   long int req;
   scanf("%d",&t);
   for(i=1;i<=t;i++)
    {
      scanf("%ld %d",&req,&n);
      int arr[10001];
      for(j=0;j<10001;j++)
        arr[j]=0;
      for(j=0;j<n;j++)
       {
         scanf("%d",&a);
         arr[a]++;
       }
      if(req==0)
       {
         printf("Scenario #%d:\n0\n\n",i);
         continue;
       }
      count=0; 
      for(j=10000;j>0;)
       {
         if(arr[j]==0)
           j--;
         else
          {  
           req=req-j;
           count++;
           arr[j]--;
           if(req<=0)
             break;
          }
       }
      if(req>0)
       printf("Scenario #%d:\nimpossible\n\n",i);
      else
       printf("Scenario #%d:\n%d\n\n",i,count);
    }
   return 0;
 }          
           
