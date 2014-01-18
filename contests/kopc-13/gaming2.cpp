#include<stdio.h>
int main()
{
    int t,n,k,l,w,sum,min,i,pos,rem;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d %d %d %d",&n,&k,&l,&w);
      min=1000000000;
      sum=0;
      pos=-1;
      for(i=0;i<=n/2;i++)
      {
        if(i==0)
          rem=0;
        if(i==1)
          rem=k;
        if(i>1)
          rem=2*(k-1)+(i-2)*(k-2);
        if(n-i*2>rem)
          continue;
      //  printf("rem : %d\n",rem);
        if(i*k>n)
          sum=w*i+(i-1)*l;
        else
          sum=w*i+(n-i*k+i-1)*l;
     //   printf("sum : %d\n",sum);
        if(sum<min)
          {
            min=sum;
            pos=i;
          }
      }
      if(min==1000000000)
        min=0;
  //    printf("pos : %d\n",pos);
      printf("%d\n",min);
    }
    return 0;
}
      
        
      
