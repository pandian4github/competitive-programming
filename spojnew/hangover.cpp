#include<iostream>
using namespace std;
int main()
 {
   double c;
   double ans,i;
   while(1)
    {
      ans=0;
      scanf("%lf",&c);
      if(100*c==0)
        break;
      for(i=2;ans<c;i++)
         ans=ans+(1.0/i);
      printf("%0.0lf card(s)\n",i-2);
    }
   return 0;
 }         
