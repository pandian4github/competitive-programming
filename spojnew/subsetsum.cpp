#include<stdio.h>
#include<string.h>
void print(int count[])
{
     int i;
     for(i=0;i<10;i++)
       printf("   %d",count[i]);
     printf("\n");
}
int main()
{
    int t,n,i,ans;
    long long int power[55];
    power[0]=1LL;
    power[1]=2LL;
    for(i=2;i<55;i++)
      power[i]=2LL*power[i-1];
    char str[53];
    int count[60]={0};
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",str);
              n=strlen(str);
           //   for(i=0;i<10;i++)
           //     count[i]=0;
              for(i=0;i<n;i++)
                count[i]=str[i]-48;
             // for(i=0;i<n;i++)
             //   count[i]=i*count[i];
              ans=0;
//               print(count);
              for(i=0;i<n;i++)
                ans=(ans+(count[i]*power[n-1])%9)%9;  
              printf("%d\n",ans);
    }
    return 0;
}    
