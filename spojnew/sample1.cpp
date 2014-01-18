#include<stdio.h>
#include<conio.h>
int main()
 {
   int m,n,i,j;
   while(1)
    {
     int count[100]={0};
     scanf("%d%d",&m,&n);
     if(m==0&&n==0)
       break;
     for(i=0;i<=m;i++)
       for(j=0;j<=n;j++)
         count[i+j]++;
     for(i=0;i<=m+n;i++)
       printf("%d  ",count[i]);
     printf("\n\n");  
    }
 //  getch();
   return 0;
 }
