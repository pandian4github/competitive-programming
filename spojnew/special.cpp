#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int combination(int n,int r)
 {
   int p=1,p1=1;
   int i;
   for(i=n;i>r;i--)  
     p=p*i;
   for(i=n-r;i>1;i--)
     p1=p1*i;
   return p/p1;    
 }
void powerof(char str[],int *p)
 {
   int len=strlen(str);
   int i,j,c,check,flag;
   if(len==1)
     {
       switch(str[0])
        {
          case '2': (*p)++;
                    break;
          case '4': (*p)+=2;
                    break;
          case '8': (*p)+=3;
                    break;
        }
       return;                                
     }
   (*p)++;    
   check=0;  
   char str1[len];
   for(i=0,j=0;i<len;i++)
    {
      c=str[i];
      if(check==0)
       switch(c)
       {
         case '1': str1[j++]='0';
                   check=1;
                   break;
         case '2': str1[j++]='1';
                   check=0;
                   break; 
         case '3': str1[j++]='1';
                   check=1;
                   break;
         case '4': str1[j++]='2';
                   check=0;
                   break;
         case '5': str1[j++]='2';
                   check=1;
                   break;
         case '6': str1[j++]='3';
                   check=0;
                   break; 
         case '7': str1[j++]='3';
                   check=1;
                   break;
         case '8': str1[j++]='4';
                   check=0;
                   break; 
         case '9': str1[j++]='4';
                   check=1;
                   break;
         case '0': str1[j++]='0';
                   check=0;
                   break;                               
       }
      else
       switch(c)
       {
         case '1': str1[j++]='5';
                   check=1;
                   break;
         case '2': str1[j++]='6';
                   check=0;
                   break; 
         case '3': str1[j++]='6';
                   check=1;
                   break;
         case '4': str1[j++]='7';
                   check=0;
                   break;
         case '5': str1[j++]='7';
                   check=1;
                   break;
         case '6': str1[j++]='8';
                   check=0;
                   break; 
         case '7': str1[j++]='8';
                   check=1;
                   break;
         case '8': str1[j++]='9';
                   check=0;
                   break; 
         case '9': str1[j++]='9';
                   check=1;
                   break;
         case '0': str1[j++]='5';
                   check=0;
                   break;                               
       }
    }   
   flag=0;
   for(i=0,j=0;i<len;i++)
    {
      if(str1[i]=='0')
       {
        if(flag)
         str[j++]='0';
       }
      else
       {
        str[j++]=str1[i];
        flag=1;
       }
    }
   str[j]='\0';     
   powerof(str,p);     
 }  

int total(int a)
 {
   if(a==0)
     return 0;
   return combination(a-1,a/2-1)+total(a-2);      
 }  
int main()
 {
   int act,n;
   cin>>n;
   int res[n];
   char str[20];
   int i;
   int po;
   for(i=0;i<n;i++)
    {
      po=0;
      cin>>str;
      powerof(str,&po);
      if(po%2==1)
        act=po-1;
      else
        act=po;
      res[i]=total(act);      
    }
   for(i=0;i<n;i++)
     cout<<res[i]<<"\n"; 
   getch();
   return 0; 
   
 }
 
