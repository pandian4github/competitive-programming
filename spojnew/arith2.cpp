#include<stdio.h>
#include<string.h>
int main()
 {
   int t,i;
   long long int prev1,prev2;
   char str[500];
   char presentop,ch;
   scanf("%d",&t);
   ch=getchar();
   while(t--)
    {
      ch=getchar();
      gets(str);
      presentop='+';
      prev1=prev2=0;
      for(i=0;i<strlen(str);i++)
       {
         if(str[i]==' ')
           continue;
         if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='=')
           {
             switch(presentop)
              {
                case '+' : prev1=prev1+prev2;
                           break;
                case '-' : prev1=prev1-prev2;
                           break;
                case '*' : prev1=prev1*prev2;
                           break;
                case '/' : prev1=prev1/prev2;
                           break;
              }                           
             presentop=str[i];
             prev2=0;
           }
         else
          prev2=prev2*10+str[i]-48; 
       }
      printf("%lld\n",prev1);
   }
  return 0;
 }  
        
            
            
