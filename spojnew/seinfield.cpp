#include<stdio.h>
#include<string.h>
int main() 
 {
   char str[2001];
   int a,b,i,j=0,count;
   while(1)
    {
      j++;
      scanf("%s",str);
      if(str[0]=='-')
        break;
      a=b=count=0;
      for(i=0;i<strlen(str);i++)
       {
        if(str[i]=='{')
         a++;
        else
         b++;
        if(b>a)
         {
           count++;
           a++;
           b--;
         }
       }
      count=count+(a-b)/2;
      printf("%d. %d\n",j,count);
    }
   return 0;
 }     
      
