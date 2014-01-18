#include<stdio.h>
#include<string.h>
int space=0;
long int power(int a,int b)
 {
   long int p=1;
   int i;
   for(i=1;i<=b;i++)
     p=p*a;
   return p;
 }
long int convertoten(char str[],int a)
 {
   int i,j,d;
   long int n=0;
//   printf("in conv10 : \n");
//   printf("%s %d ",str,a);
   for(j=0,i=strlen(str)-1;i>=0;i--,j++)
    {
      if(str[i]>=48&&str[i]<=57)
        d=str[i]-48;
      else
        d=str[i]-55;
//      printf("%c %d\n",str[i],d);
      n=n+d*power(a,j);
    }
   return n;
 }   
void convertob(long int n,int b,char ans[])
 {
   int d,j=6,i;
   char ans2[10];
 //  printf("n : %ld b : %d\n",n,b);
   while(n!=0)
   {
     if(j<0)
      {
        space=2;
        strcpy(ans,"ERROR");
        break;
      }
     d=n%b;
     n=n/b;
     if(d<=9)
       d=d+48;
     else
       d=d+55;
     ans2[j--]=d;
   }
   if(n==0)
     {
      space=j+1;
      for(i=0;i+space<7;i++)
        ans[i]=ans2[i+space];
      ans[i]='\0';
     }
 } 
       
int main()
 {
   char str[10],ans[10];
   int a,b,i;
   while((scanf("%s %d %d",str,&a,&b))!=EOF)
    {
   //   printf("in");
  //    printf("str : %s  a : %d  b : %d  toten : %ld\n",str,a,b,convertoten(str,a));
      space=0;
      convertob(convertoten(str,a),b,ans);
      for(i=1;i<=space;i++)
        printf(" ");
      printf("%s\n",ans);
    }
   return 0;
 } 
