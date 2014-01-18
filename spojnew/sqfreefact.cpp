#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;
vector<bool> sqfree(1000001);
void sqfreefunc()
 {
   int i,j,sq;
   for(i=0;i<1000001;i++)
     sqfree[i]=true;
  // for(i=0;i<=50;i++)
  //   cout<<sqfree[i]<<"   ";     
   for(i=2;i<=1000;i++)
    {
      sq=i*i;
    //  cout<<sq<<"   ";
      for(j=sq;j<=1000000;j=j+sq)
        {
       //   cout<<j<<"    ";
          sqfree[j]=false;
        }
    //  cout<<"\n";  
    }
 }      
int find(int n,int &count)
 {
   int i,j;
   if(sqfree[n])
    {
      count++;
   //   printf("%d  ",n);
      return 1;
    }
   for(i=2;i<=sqrt(n);i++)
    {
      if(n%i==0)
       {
         j=n/i;
         if(sqfree[j])
          {
            while(n%j==0)
             {
               count++;
     //          printf("%d  ",j);
               n=n/j;
             }
            return n; 
          }          
       }
    } 
   for(i=sqrt(n);i>=2;i--)
    {
      if(n%i==0)
       {
         if(sqfree[i])
          {
            while(n%i==0)
             {
               count++;
       //        printf("%d  ",i);
               n=n/i;
             }
            return n; 
          }          
       }
    } 
   return 1;
 } 
    
int main()
 {
   int t,n,j,i,temp,count;
   scanf("%d",&t);
   sqfreefunc();
 //  printf("\n");
 //  for(i=130;i<=150;i++)
 //    cout<<sqfree[i]<<"   ";
     //printf("%d  ",sqfree[i]);
   while(t--)
    {
      scanf("%d",&n);
      if(sqfree[n])
       {
         printf("1\n");
         continue;
       }
      count=0;
      while(1)
       {
         n=find(n,count);
     //    printf("n : %d\ncount : %d\n\n",n,count);
         if(n==1)
          break;
       }
      printf("%d\n",count);
    }
   return 0;
 }      
