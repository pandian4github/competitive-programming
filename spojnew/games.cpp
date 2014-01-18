#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
    if(b==0)
      return a;
    return gcd(b,a%b);
}
int main()
{
   int intt,flag,cur,curr,i,dig,t,rem,pos,nume;
   char str[20];
   scanf("%d",&t);
   while(t--)
   {
     scanf("%s",str);
     pos=strlen(str);
     for(i=0;i<strlen(str);i++)
       if(str[i]=='.')
         {
          pos=i+1;
          break;
         }
     rem=0;
     nume=1;   
     for(i=pos;i<strlen(str);i++,nume=nume*10)
       rem=rem*10+str[i]-48;
     int g=gcd(rem,nume);
     printf("%d\n",nume/g);      
/*     for(i=1;i<=10000;i++)
     {
       intt=rem*i;
       if(intt%nume==0)
       {
         printf("%d\n",i);
         break;
       }
     }*/
   }
   return 0;
} 
