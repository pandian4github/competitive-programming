//EQBOX
#include<stdio.h>
int main()
 {
   int t;
   scanf("%d",&t);
   int arr[t];
   int i;
   long int a,b,x,y,min1,min2,max1,max2;
   for(i=0;i<t;i++)
    {
     scanf("%ld%ld%ld%ld",&a,&b,&x,&y);
     min1=(a<b)?a:b;
     min2=(x<y)?x:y;
     max1=(a>b)?a:b;
     max2=(x>y)?x:y;
     if(min1<min2||max1<max2)
      {
        arr[i]=0;
        continue;
      }
     arr[i]=1;
    }
   for(i=0;i<t;i++)
    if(arr[i])
     puts("Escape is possible.");
    else
     puts("Box cannot be dropped.");
   return 0;
 }      
        
