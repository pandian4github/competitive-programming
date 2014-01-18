#include<stdio.h>
#include<conio.h>
void print(int a,int b)
 {
   int h1,m1,h2,m2;
   if(a==1440)
     a=0;
   if(b==1440)
     b=0;
   h1=a/60;
   m1=a%60;
   h2=b/60;
   m2=b%60;
   if(h1<=9)
     printf("0");
   printf("%d ",h1);
   if(m1<=9)
     printf("0");
   printf("%d ",m1);
   if(h2<=9)
     printf("0");
   printf("%d ",h2);
   if(m2<=9)
     printf("0");
   printf("%d\n",m2);
 }     
int main()
 {
   int arr[1500]={0};
   int m,k,count,prev,i,h1,m1,h2,m2,t1,t2;
   scanf("%d %d",&m,&k);
   for(i=0;i<m;i++)
    {
      scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
      t1=h1*60+m1;
      t2=h2*60+m2;
      if(t2==0)
        if(t1!=0)
          {
//           printf("fdgad");
           t2=1440;
          }
      arr[t1]++;
      arr[t2+1]--;
    }
   for(i=1;i<=1440;i++)
     arr[i]=arr[i]+arr[i-1];
   count=0;
   prev=0;
   for(i=0;i<=1440;i++)
   {
     if(arr[i]==0)
       {
        count++;
        continue;
       }
     if(count>=k-1)
       print(prev,i);
     count=0;
     prev=i;
   }
   if(count>=k-1)
     print(prev,1440);
   getch();
   return 0;
 }              
   
