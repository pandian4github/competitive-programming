//#include<iostream>
#include<stdio.h>
//using namespace std;
//#include<conio.h>
int main()
 {
   int i,t,j;
   scanf("%d",&t);
   long int n;
   for(i=0;i<t;i++)
    {
      scanf("%ld",&n);
      int arr[n];
      int count[6001]={0};
      for(j=0;j<n;j++)
      {
       scanf("%d",&arr[j]);
       count[(arr[j]+3000)]++;
      } 
      int c=0;
      for(j=0;j<6001;j++)
       if(count[j]>n/2)
        {
          printf("YES %d\n",j-3000);
          c=1;
          break;
        }    
      if(!c)
        printf("NO\n");
    }
//   getch();
   return 0;
 }        
          
