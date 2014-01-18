#include<stdio.h>
#include<string.h>
#include<conio.h>
#include "E:\Dev-Cpp\include\BigIntegerLibrary.hh"
int main()
 {
   char str1[20],str2[20];
   int arr[20],p,i;
   scanf("%s%s",str1,str2);
   BigInteger a=0,b=0,a1=1,b1=1,c1;
   for(i=strlen(str1)-1;i>=0;i--)
    {
      a=a+((str1[i]-48)*a1);
      a1=a1*10;
    }
   for(i=strlen(str2)-1;i>=0;i--)
    {
      b=b+((str2[i]-48)*b1);
      b1=b1*10;
    }
   c1=a+b;
   while(c1>0)
    {
     arr[p++]=c1%10;
     c1=c1/10;
    }
   for(i=p-1;i>=0;i--)
     printf("%d\n",arr[i]);
   getch();
   return 0;
 }      
      
