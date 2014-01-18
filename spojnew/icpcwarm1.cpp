#include<stdio.h>
#include<math.h>
int main()
{
    long int t,x1,y1,x2,y2,X,Y,i,count,min,max;
    long int m,intt;
    scanf("%ld",&t);
    while(t--)
    {
              count=0;
              scanf("%ld %ld %ld %ld",&x1,&y1,&x2,&y2);
              X=(x2-x1);
              Y=(y2-y1);
              if(X==0)
               {
                intt=y2-y1;
                if(intt<0)
                  intt*=-1;
                printf("%ld\n",intt+1);
                continue;
               }
              if(Y==0)
               {
                intt=x2-x1;
                if(intt<0)
                  intt*=-1;
                printf("%ld\n",intt+1);  
                continue;
               }
              m=(X*y1-Y*x1);
              max=(x1>=x2)?x1:x2;
              min=(x1<=x2)?x1:x2;
              for(i=min;i<=max;i++)
                {
                 intt=Y*i+m;
                 if(intt<0)
                   intt=intt*(-1);
                 if(X<0)
                   X=X*(-1);
                 if(intt%X==0)
                  count++;
                 }
              printf("%d\n",count);
    }
    return 0;
}
