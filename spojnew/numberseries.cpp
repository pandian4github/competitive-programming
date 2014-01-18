#include<stdio.h>
int main()
{
    long long int t[120];
    t[0]=1;
    t[1]=2;
    t[2]=3;
    t[3]=4;
    t[4]=5;
    t[5]=9;
    for(i=6;i<100;i++)
      t[i]=t[i-1]+t[i-3];
    for(i=0;i<100;i++)
      printf("%lld\n",t[i]);
    return 0;
}  
