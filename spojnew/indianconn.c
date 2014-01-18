#include<stdio.h>
int main()
 {
   int t,g,ch;
   long long int power[50];
   power[0]=1LL;
   int i;
   for(i=1;i<=50;i++)
     power[i]=power[i-1]*2LL;
   long long int n,start,mid,end; 
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %lld",&g,&n);
      start=1LL;
      for(i=0;;i++)
        if(power[i]>=n)
          break;
      end=power[i];
      ch=0;
      printf("\nstart = %lld\nend = %lld i = %d\n",start,end,i);
      while(1)
       {
         printf("\nstart = %lld\nend = %lld\nch = %d\n",start,end,ch);
         if(start==end)
           break;
         mid=(start+end)/2LL;
         if(n<=mid)
            end=mid;
         else
           {
            ch=1-ch;
            start=mid+1LL;
           }
       }
      if(ch==0)
        printf("Male\n");
      else
        printf("Female\n");
    }
   return 0;
 }      
          
         
