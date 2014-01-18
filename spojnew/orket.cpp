//#include<stdlib.h>
#include<iostream>
using namespace std;
//#include<stdio.h>
int main()
 {
   char *s,c,te;
   long int i=0,a,b,j,k,t,l;
   s=(char*)malloc(sizeof(char));
   while(1)
    {
   //   scanf("%c",&c);
      cin>>c;
      if((int)c>=97&&(int)c<=122)
       {
      //  s+i=(char*)malloc(sizeof(char));
        s[i]=c;
        i++;
       }
      else
       break;
    }
    s[i]='\0'; 
 //  c=getchar();*/
  // scanf("%s",s);
   scanf("%ld",&t);
   for(i=0;i<t;i++)
    {
    //  fflush(0);
   //   scanf("%ld %ld",&a,&b);
      cin>>a;
      cin>>b;
      if((b-a)%2==0)
        for(l=0,j=a-1,k=b-1;l<=(b-a)/2;l++,j++,k--)
         {
          te=s[j];
          s[j]=s[k];
          s[k]=te;
         }
      else
        for(l=0,j=a-1,k=b-1;l<=(b-a)/2+1;l++,j++,k--)
         {
          te=s[j];
          s[j]=s[k];
          s[k]=te;
         }
   //     printf("%s\n",s); 
          
    }   
    printf("%s\n",s);
    cin>>t;
    return 0;
  }  
         
       
