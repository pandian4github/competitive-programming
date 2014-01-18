#include<stdio.h>
int main()
 {
   int i,j,t,rangea,rangeb;
   long long int count;
   long long int n,maxa,maxb,maxc,mina,minb,minc,r1,r2,x,y,a,b;
   scanf("%d",&t);
   while(t--)
    {
      count=0LL;
      scanf("%lld",&n);
      scanf("%lld %lld",&mina,&maxa);
      scanf("%lld %lld",&minb,&maxb);
      scanf("%lld %lld",&minc,&maxc);
      maxa-=mina;
      maxb-=minb;
      maxc-=minc;
      n=n-mina-minb-minc;
  //    printf("\n%lld\n%lld\n%lld\n",maxa,maxb,maxc);
      if(n<0LL || maxa+maxb+maxc<n)
       {
         printf("0\n");
         continue;
       }
      if(n==0LL || maxa+maxb+maxc==n)
       {
         printf("1\n");
         continue;
       }
      b=n;
 //     printf("\n\nb %lld\n");
      a=n-maxc;
      if(a<0LL)
        a=0LL;   
      y=(maxa>=maxb)?maxa:maxb;
      x=(maxa<=maxb)?maxa:maxb;
      r1=x-1LL;
      r2=y+1LL;
      if(a<=r1)
        rangea=1;
      else
        if(a<r2)
          rangea=2;
        else
          rangea=3;
      if(b<=r1)
        rangeb=1;
      else
        if(b<r2)
          rangeb=2;
        else
          rangeb=3;
 //     printf("\nVariable values\n\n:");
 //     printf("\nn = %lld\na = %lld\nb = %lld\nx = %lld\ny = %lld\nr1 = %lld\nr2 = %lld\nrangea = %d\nrangeb = %d\n",n,a,b,x,y,r1,r2,rangea,rangeb)    ;
      if(rangea==1)
       {
         switch(rangeb)
          {
            case 1 : count=count+(((b+1LL)*(b+2LL)-(a+1LL)*(a))/2LL)%1000000007;
                     count=count%1000000007;
                     break;
            case 2 : count=count+(((x*(x+1LL))-(a+1LL)*(a))/2LL)%1000000007;
                     count=count%1000000007;
                     count=count+((b-r1)*(x+1LL))%1000000007;
                     count=count%1000000007;
                     break;
            case 3 : count=count+(((x*(x+1LL))-(a+1LL)*(a))/2LL)%1000000007;
                     count=count%1000000007;
                     count=count+((r2-r1-1LL)*(x+1LL))%1000000007;
                     count=count%1000000007;
                     count=count+(((x*(x+1LL))-(x+y-b)*(x+y-b+1LL))/2LL)%1000000007;
                     count=count%1000000007;
                     break;
          }
       }
      else
        if(rangea==2)
         {
           if(rangeb==2)
             {
               count=count+((b-a+1LL)*(x+1LL))%1000000007;
               count=count%1000000007;
             }
           else
            {
              count=count+((r2-a)*(x+1LL))%1000000007;
              count=count%1000000007;
              count=count+(((x*(x+1LL))-(x+y-b)*(x+y-b+1LL))/2LL)%1000000007;
              count=count%1000000007;
            }
         }
        else
         {
              count=count+(((x+y-a+1LL)*(x+y-a+2LL)-(x+y-b+1LL)*(x+y-b+2LL))/2LL)%1000000007;
              count=count%1000000007;
         }
      printf("%lld\n",count);    
     }          
    return 0;
  } 
