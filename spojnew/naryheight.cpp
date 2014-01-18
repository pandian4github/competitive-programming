#include<stdio.h>
long int pow(long int n,int i)
 {
   long int ans=1;
   for(int j=1;j<=i;j++)
     ans=ans*n;
   return ans; 
 }  
int main()
 {
   int i,t;
   scanf("%d",&t);
   long int m,n;
   while(t--)
    {
      scanf("%ld %ld",&m,&n);
      if(m==0)
       {
         printf("0\n");
         continue;
       }
      if(n==1)
       {
         printf("%ld\n",m);
         continue;
       }
     // printf(" m = %ld\n n = %ld\n\n",m,n); 
      for(i=0;;i++)
       {
       //  printf("%ld   %ld \n",m,pow(n,i));
         if(m<=pow(n,i))
          {
            printf("%d\n",i+1);
            break;
          }
         m=m-pow(n,i);
       }
    }
   return 0;
 }      
