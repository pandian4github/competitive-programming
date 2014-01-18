#include<stdio.h>
#include<conio.h>
#define SIZE 64
main()
{
        long long a,b,i,t,nop,check,cnt,ans;
        long long s[SIZE];
        scanf("%lld %lld",&a,&b);
        for(i=0,t=2;t<=b;i++,t*=2)
                s[i]=t;
        nop=i-1;
        check=0;
        ans=0;
        long long x;
        for(i=nop;i>=0;i--)
        {
                x=s[i];
                cnt=(b/x)-((a-1)/x);
                cnt-=check;
                check+=cnt;
                ans+=cnt*x;
        }
        ans+=b-a+1-check;
        printf("%lld\n",ans);
        getch();
        return 0;
}
