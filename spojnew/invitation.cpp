#include<iostream>
//#include<conio.h>
using namespace std;
int max(int a,int b)
 {
   return (a>b)? a:b;
 }  
int c[22][20002]; 
int sum=0;
void knapsack(int v[],int w[],int n,int W)
 {
   int i,j;
   for(i=0;i<=W;i++)
     c[0][i]=0;
   for(i=1;i<=n;i++)
    {
      c[i][0]=0;
      for(j=1;j<=W;j++)
        {
          if(j>=w[i])
            c[i][j]=max(v[i]+c[i-1][j-w[i]],c[i-1][j]);
          else
            c[i][j]=c[i-1][j];       
        }
    }
 }
void calculate(int i,int j,int w[],int v[])
 {
   if(i==0||j==0)
     return ;
   if(c[i-1][j]==c[i][j])
     calculate(i-1,j,w,v);
   else
    {     
      calculate(i-1,j-w[i],w,v);
      sum+=v[i];
    }
 }
int main()
 {
   int i,t,n,j,x,y;
   scanf("%d",&t);
   int v[21],w[21],W;
   while(t--)
   {
     sum=0;
     scanf("%d %d",&n,&W);
     v[0]=0;
     w[0]=0;
     for(i=1,j=1;i<=n;i++)
       {
        scanf("%d %d",&x,&y);
        if(x==0)
          sum+=y;
        else
          {
           w[j]=x;
           v[j++]=y;
          }
        }
     n=j-1;
     if(W==0)
     {
    //   for(i=1;i<=n;i++)
    //     if(w[i]==0)
    //       sum+=v[i];
       printf("%d\n",sum);
       continue;
     }
     knapsack(v,w,n,W);
    // sum=0;
     calculate(n,W,w,v);
     printf("%d\n",sum);
   }
//   getch();
   return 0;
 }      
                 
