#include<stdio.h>
#include<conio.h>
int main()
 {
  long long int n,m,q;
  int t=0,u=0,c=0,i;
  printf("Enter a number...");
  scanf("%lld",&n);
  m=n;
  q=n;
  printf("\n");
   while(n!=0)
     {
      n/=10;
      c++;
     }
  int d[c];
  for(i=c-1;i>=0;i--)
     { 
      d[i]=m%10;
      m=m/10;
     }
  int x,y,z,r;
  x=c/2+1;
  y=c/2;
  z=c/2+2;
  if(c==1)
   {
    if(q!=9)
     printf("%lld",q+1);
    else
     printf("11");
   }
  else
   if(c%2==0)
    {
    l: if(d[x-1]<d[y-1])
         r=1;
       else
        if(d[x-1]>d[y-1])
          {
            if(t==0)
              r=2;
            else
              r=7;
          }
        else
          r=3;
     }
   else
    {
     m:if(d[z-1]<d[y-1])
         r=4;
       else
         if(d[z-1]>d[y-1])
           if(u==0)
            r=5;
           else
            r=8;
         else
          r=6;
    }
 n:switch(r)
  {
   case 1: {
            for(i=0;i<y;i++)
              printf("%d",d[i]);
            for(i=y-1;i>=0;i--)
              printf("%d",d[i]);
            break;
           }
   case 2: {
            d[y-1]++;
            for(i=0;i<y;i++)
              printf("%d",d[i]);
            for(i=y-1;i>=0;i--)
              printf("%d",d[i]);
            break;
           }
   case 3: {
            t++;
            x++;
            y--;
            goto l;
            if(t==c/2)
             {
              r=7;
              goto n;
             }
           }
   case 4: {
            for(i=0;i<x;i++)
              printf("%d",d[i]);
            for(i=y-1;i>=0;i--)
              printf("%d",d[i]);
            break;
           }
   case 5: {
            d[x-1]++;
            for(i=0;i<y+1;i++)
              printf("%d",d[i]);
            for(i=y-1;i>=0;i--)
              printf("%d",d[i]);
            break;
           }
   case 6: {
            u++;
            z++;
            y--;
            goto m;
            if(u==c/2)
             {
              r=8;
              goto n;
             }
           }
   case 7: {
            d[c/2-1]++;
            for(i=0;i<c/2;i++)
              printf("%d",d[i]);
            for(i=c/2-1;i>=0;i--)
              printf("%d",d[i]);
            break;
           }
   case 8: {
            d[c/2]++;
            for(i=0;i<=c/2;i++)
              printf("%d",d[i]);
            for(i=c/2-1;i>=0;i--)
              printf("%d",d[i]);
            break;
           }
                         
   }  
  printf("\n\n");
  getch();
  return 0;   
}










































