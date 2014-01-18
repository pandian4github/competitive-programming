#include<stdio.h>
#include<string.h>
int main()
 {
   char str[101];
   int java,c,len,i,e;
   while((scanf("%s",str))!=EOF)
    {
      java=c=e=0;
      len=strlen(str);
      for(i=0;i<len;i++)
        if(str[i]=='_')
          {
            c=1;
            if(i<len-1)
              if(str[i+1]=='_')
                e=1;
          }      
        else
          if(str[i]>=65&&str[i]<=90)
            java=1;
    // To check two continuous underscores
      if(e==1)
       {
         printf("Error!\n");
         continue;
       }
    //To check both _ and caps
      if(c==1&&java==1)
       {
         printf("Error!\n");
         continue;
       }
      if(c==0&&java==0)
       {
         printf("%s\n",str);
         continue;
       }
    //If c word
      if(c==1)
       {
         if(str[0]=='_'||str[len-1]=='_')
          {
            printf("Error!\n");
            continue;
          }
         for(i=0;i<len-1;i++)
          {
            if(str[i]!='_')
              printf("%c",str[i]);
            else
              {
               str[i+1]=str[i+1]-32;
               continue;
              }
          }
         printf("%c\n",str[len-1]); 
       }
    //If java word
      if(java==1)
       {
         if(str[0]>=65&&str[0]<=90)
          {
            printf("Error!\n");
            continue;
          }
         else
           printf("%c",str[0]); 
         for(i=1;i<len;i++)
           if(str[i]>=65&&str[i]<=90)
            {
             printf("_");
             printf("%c",str[i]+32);
            }
           else
            printf("%c",str[i]);
         printf("\n");   
       }
    }
   return 0; 
 }                    
