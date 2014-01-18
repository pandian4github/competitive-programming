#include<stdio.h>
int main()
 {
   int t;
   char str[101];
   int minarr[101],maxarr[101];
   scanf("%d",&t);
   while(t--)
   {
    // maxcount=mincount=0;
     vect<bool> flag1(101,true);
     vect<bool> flag2(101,true);
     scanf("%s",str);
     len=strlen(str);
     index1=index2=0;

     if(str[0]=='0')
       if(str[1]=='*')
       {
         for(i=1;i<len;i+=2)
          {
           minstr[i]='+';
           minstr[i+1]='0';
          }
         for(i=1;i<len;i+=2)
         {
          if(str[i]=='+')
           break;
          maxstr[i]='+';
          maxstr[i+1]='0';
         }                
       }

     for(i=1;i<len-1;i+=2)
       if(str[i]=='0')
        {
          if(str[i+1]=='*')
           { 
            for(j=i+1;j<len;j+=2)
            {
              minstr[j]='+';
              minstr[j+1]='0';
            }
            for(j=i+1;j<len;j+=2)
            {
              if(str[j]=='+')
                break;
              maxstr[j]='+';
              maxstr[j+1]='0'; 
            }
           }
          if(str[i-1]=='*')
           {
            for(j=i-1;j>=0;j-=2)
             {
               minstr[j]='+';
               minstr[j-1]='0';
             }
            for(j=i-1;j>=0;j-=2)
             {
              if(str[j]=='+')
                break;
              maxstr[j]='+';
              maxstr[j-1]='0';
             }
           }               
        }
     if(str[len-1]=='0')
       if(str[len-2]=='*')
        {
          for(i=0;i<len-1;i+=2)
           {
             minstr[i]='0';
             minstr[i+1]='+';
           }
          for(i=len-1;i>=0;i--)
           {
             if(str[i]=='+')
               break;
             maxstr[i]='+';
             maxstr[i-1]='0';
           }
        }
     flag=1;   
     for(i=0;i<len;i++)
      {
        if(minstr[i]=='0')
         {
          flag=0;
          continue;
         }
        if(minstr[i]>48&&minstr[i]<58)
          flag=1;
        if(flag)
          minstr2[minindex++]=minstr[i];
      }
     flag=1;   
     for(i=0;i<len;i++)
      {
        if(maxstr[i]=='0')
         {
          flag=0;
          continue;
         }
        if(maxstr[i]>48&&maxstr[i]<58)
          flag=1;
        if(flag)
          maxstr2[maxindex++]=maxstr[i];
      }
     
 
   }
   return 0;
 } 
