#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
 {
   if(b==0)
     return a;
   return gcd(b,a%b);
 }
int modulus(char str[],int a)
 {
   int len=strlen(str);
   int rem=0,i;
   for(i=0;i<len;i++)
    {
      rem=rem*10+str[i]-48;
      rem=rem%a;
    }
   return rem;
 }      
int main()
 {
   int a,mod,t;
   char str[252];
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d",&a);
      scanf("%s",str);
      if(a==0)
       {
         printf("%s\n",str);
         continue;
       } 
      mod=modulus(str,a);
      printf("%d\n",gcd(a,mod));
    }
   return 0;
 } 
    
