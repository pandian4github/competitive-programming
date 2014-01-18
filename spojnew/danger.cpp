#include<stdio.h>
long long int power(int a,int b)
 {
   long long int p=1;
   for(int i=1;i<=b;i++)
     p=p*a;
   return p;
 }
int main()
 {
   char str[5];
   int a,b,c,i;
   long long int num;
   while(1)
    {
      scanf("%s",str);
    //  puts(str);
      a=str[0]-48;
      b=str[1]-48;
      c=str[3]-48;
      if(a==0&&b==0&&c==0)
        break;
  //    printf("%d %d %d\n",a,b,c);  
      num=(a*10+b)*power(10,c);
  //    printf("%lld\n",num);
      for(i=0;;i++)
        if(power(2,i)>num)
          break;
      num=num-power(2,i-1);
      printf("%lld\n",2*num+1);
    }
   return 0;
 }     
