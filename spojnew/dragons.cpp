#include<iostream>
//#include<conio.h>
#include<string.h>
using namespace std;
int main()
 {
   int t,i,flag;
   char str[52];
   scanf("%d",&t);
   while(t>0)
    {
      t--;
      scanf("%s",str);
      flag=0;
      for(i=0;i<strlen(str);i++)
        if(str[i]=='D')
         {
           flag=1;
           break;
         }
      if(flag)
        printf("You shall not pass!\n");
      else
        printf("Possible\n");
    }
//   getch(); 
   return 0;
 }              
