#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int retrieve(char str[])
 {
  int i;
  int num=0,asc;
  for(i=0;str[i]!='\0';i++)
   {
     asc=(int)str[i];
     if(asc>=48&&asc<=57)
      num=num*10+asc-48;
     else
      break;
   }
  return num;
 }
int ismachula(char str[])
 {
   int i;
   for(i=0;str[i]!='\0';i++)
     if(str[i]=='m')
       return 1;
   return 0;
 }      
int main()
 {
   int n;
   cin>>n;
   int j;
   char str1[100],str2[5],str3[100],str4[5],str5[100];
   int n1,n2,n3;
   for(j =1;j<=n;j++)
   {
     cin>>str1;
     cin>>str2;
     cin>>str3;
     cin>>str4;
     cin>>str5;
     if(ismachula(str1))
      {
        n2=retrieve(str3);
        n3=retrieve(str5);
        n1=n3-n2;
      }
     else
       if(ismachula(str3))
        {
         n1=retrieve(str1);
         n3=retrieve(str5);
         n2=n3-n1;
        }
       else
        {
         n1=retrieve(str1);
         n2=retrieve(str3);
         n3=n1+n2;
        }      
   cout<<n1<<" + "<<n2<<" = "<<n3<<"\n";

   }
   return 0;
 }



