#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
int last(int a,long long int b)
 {if(!b)return 1;if(a==0||a==1||a==5||a==6)
    return a;
   else
    if(a==2||a==3||a==8||a==7){
      switch(b%4){
         case 1 : return (a==2)?2:(a==3)?3:(a==8)?8:7;
         case 2 : return (a==2)?4:(a==3)?9:(a==8)?4:9;
         case 3 : return (a==2)?8:(a==3)?7:(a==8)?2:3;
         case 0 : return (a==2)?6:(a==3)?1:(a==8)?6:1;}}
     else  return (b%2==0)?(a==4)?6:1:(a==4)?4:9;}    
int main()
{
   int t,i,d,l;
   int a;
   char c;
//   a=(char*)malloc(sizeof(char));
   long long int b;
   scanf("%d",&t);
   int arr[t];
   for(i=0;i<t;i++)
   {
 //   l=0;
 //   fflush(0);
 //   while(1)
 //    {
 //      scanf("%c",&c);
 //      if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
 //       {
 //        printf("Entered\n\n");
 //        a[l++]=c;
 //       }
 //      else
 //       break;
   //   }
   //   fflush(0);
     scanf("%d",&a);
     scanf("%lld",&b);
 //    a[l]='\0'; 
 //    c=a[l-1];
 //    printf("\n\n%s\n\n",a);
     d=a%10;;



      arr[i]=last(d,b);
    }
   for(i=0;i<t;i++)
    printf("%d\n",arr[i]);
   getch();
   return 0;}      
      
