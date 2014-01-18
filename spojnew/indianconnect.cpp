#include<stdio.h>
long long int power(int n)
 {
   long long int p=1LL;
   int i;
   for(i=1;i<=n;i++)
     p=p*2LL;
   return p;
 }
int main()
 {
   int t,g,ch;
   long long int n,start,mid,end; 
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %lld",&g,&n);
      start=1LL;
      end=power(g-1);
      ch=0;
    //  printf("\nstart = %lld\nend = %lld\n",start,end);
      while(true)
       {
         if(start==end)
           break;
         mid=(start+end)/2LL;
         if(n<=mid)
           {
         //   ch=0;
            end=mid;
           }
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
          
         
