#include<stdio.h>
#include<deque>
using namespace std;
//#include<conio.h>
int main()
 {
   long int n,k;
   scanf("%ld",&n);
   long int arr[n];
   long int i;
   for(i=0;i<n;i++)
     scanf("%ld",&arr[i]);
   scanf("%ld",&k);  
   deque<long int> d;
   for(i=0;i<k;i++)
    {
      while(!d.empty()&&arr[d.back()]<arr[i])
        d.pop_back();
      d.push_back(i);
    }
   printf("%ld",arr[d.front()]);
   for(i=k;i<n;i++)
    {
      if(i+1-d.front()>k)
        d.pop_front();
      while(!d.empty()&&arr[d.back()]<arr[i])
        d.pop_back();
      d.push_back(i);
      printf("% ld",arr[d.front()]);
    }
  // getch(); 
   return 0;
 }               
