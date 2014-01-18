#include<stdio.h>
#include<math.h>
int main()
 {
   int t;
   long int num;
   scanf("%d",&t);
   while(t--)
    {
      scanf("%ld",&num);
      printf("%ld\n",(num+1L)/2L);
    }
   return 0;
 } 
