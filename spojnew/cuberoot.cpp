#include<stdio.h>
#include<math.h>
int main()
{
   int t,n,j,i;
   double temp,low,high,mid;
   char str[100];
   scanf("%d",&t);
   while(t--)
   {
     scanf("%d",&n);
     low=0.0;
     high=(double)n;
     for(i=0;i<500;i++)
     {
       mid=(low+high)/2;  
       temp=mid*mid*mid;
       if(fabs(temp-n)<0.0000000000001)
         break;
       else
        if((temp-n)>0)
          high=mid;
        else
          low=mid;          
     }
     sprintf(str,"%0.12lf",mid);
     for(i=0;str[i]!='.';i++)
       printf("%c",str[i]);
     for(j=1;j<=5;j++,i++)
        printf("%c",str[i]);
     printf("\n");

   }
   return 0;
}



