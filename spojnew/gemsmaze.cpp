#include<stdio.h>
#include<conio.h>
#include<vector>
#include<fstream>
using namespace std;
vector<bool> vec(17000000);
long int arr[17000000],dp[17000000];
void func(long int i,long int arr[],long int n,long int dp[],long int *c)
 {
  // printf("i = %d\n",i);
   if(vec[i])
     return;
   vec[i]=true;  
   (*c)++;  
   func(arr[i],arr,n,dp,c);
   dp[i]=(*c);
 }   
int main()
 {
   int t,a,b,c;
   long int max,i,j,n,count;
   ofstream oupfile;
   oupfile.open("outputgems.txt");
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %d %d %ld",&a,&b,&c,&n);
    //  long int arr[n],dp[n];
      for(i=0;i<n;i++)
        {
         vec[i]=false;
         arr[i]=(a*i*i+b*i+c)%n;
        }
  //    for(i=0;i<n;i++)
  //      printf("%ld ",arr[i]);  
      max=0;
      count=0;
      for(i=0;i<n;i++)
        {
         for(j=0;j<n;j++)
           vec[j]=false;
         //if(vec[i])
         //  continue;
         if(count>max)
           max=count;
         count=0;
         func(i,arr,n,dp,&count);
      //   printf("\ncount = %ld\n",count);
      //   getch();
        }
 //     printf("%ld\n",max);  
      oupfile<<max<<"\n";  
    }
   oupfile.close(); 
   return 0;
 }       
