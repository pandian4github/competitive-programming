#include<stdio.h>
#include<string.h>
//#include<conio.h>
int main()
 {
  int t,count,len,i,j;
  char s[2000];
  scanf("%d",&t);
  while(t>0)
   {
     t--;
     count=0;
     scanf("%s",s);
     len=strlen(s);
     for(i=0;i<len;i++)
      {
       if(s[i]=='B')
        for(j=i+1;j<len;j++)
         {
          if(s[j]=='R')
           {
            count=count+j-i;
            s[j]='a';
            break;
           }      
         } 
       else
        if(s[i]=='R')
         for(j=i+1;j<len;j++)
          if(s[j]=='B')
           {
            count=count+j-i;
            s[j]='a';
            break;
           }
       }           
     printf("%d\n",count);      
   }
 // getch();
  return 0;
 }          
            
