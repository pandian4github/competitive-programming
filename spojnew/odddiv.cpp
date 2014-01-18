#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;
vector<vector<int> > vec(100000);
int primes[1000]={0},cou;
int sieve[10001];
void printvec()
 {
   int i,j;
   for(i=1;i<10;i++)
    {
      printf("i : %d\n",vec[i].size());
    }
 //  getch(); 
   for(i=1;i<=15;i++)
    {
      printf("i : %d\n",i);
      for(j=0;j<vec[i].size();j++)
       { 
        printf("%d  ",vec[i].at(j));
      //getch();
  }  
    }
 }     
void sievefunc()
 {
   int i,p,j=0;
   for(i=2;i<=1000;i++)
     sieve[i]=1;
   sieve[1]=0;
   for(p=2;p<=317;p++)
     {
      if(sieve[p]==1)
       {
        primes[j++]=p;
        for(i=p*p;i<=1000;i=i+p)
          sieve[i]=0;
       }
     }
   
   cou=j;  
 }         
   
void bin_search1(int n,int k,int i,int j,int &temp)
{
  int mid=(i+j)/2;
  if(i>j)
    return;
 // printf("i : %d j : %d mid : %d temp : %d\n",i,j,mid,temp);
 // getch();
  if(vec[k].at(mid)==n)
    {
     temp=mid;
     return;
    }
  if(vec[k].at(mid)<n)
    bin_search1(n,k,mid+1,j,temp);
//  if((vec[k].at(mid)-n)<temp)
  else
   {
    temp=mid;
    bin_search1(n,k,i,mid-1,temp);
    return;
   }
}  
void bin_search2(int n,int k,int i,int j,int &temp)
{
  int mid=(i+j)/2;
  if(i>j)
    return;
//  printf("i : %d j : %d mid : %d temp : %d\n",i,j,mid,temp);
//  getch();
  if(vec[k].at(mid)==n)
    {
     temp=mid;
     return;
    }
  if(vec[k].at(mid)>n)
    bin_search2(n,k,i,mid-1,temp);
//  if((vec[k].at(mid)-n)<temp)
  else
   {
    temp=mid;
    bin_search2(n,k,mid+1,j,temp);
    return;
   }
}  
int main()

 {
   int j,t,min,max,k,x,y,count,te,c1,c2;
   long long int m,n,num,te3;
   scanf("%d",&t);
   int i;
   sievefunc();
 //  for(i=0;i<cou;i++)
 //    printf("%d   ",primes[i]);
  // getch();
   vec[1].push_back(1);
   for(i=2;i<=100;i++)
   {
    // count=1;
     int flag=0;
     count=0;
     c2=1;
     te=i;
     for(j=0;j<cou&&primes[j]<=sqrt(i);j++)
     {
      c1=0;
      if(i%primes[j]!=0)
        continue;
   //   printf("\n\n...\n\n");
      flag++;
      while(1)
       {
         if(i%primes[j]==0)
          {
           count++;
           c1++;
          }
         else
           break;  
         i=i/primes[j];
       }
      c2=c2*c1*2;
     } 
     if(i!=1)
       {
         flag++;
         count++;
         c2=c2*2;
       }
   //  printf("count : %d c2 : %d\n",count,c2);  
     if(flag==1)
       c2+=1;
     else
       c2+=count*2+1;  
     i=te;  
     vec[c2].push_back(i);  
   //  printf("i : %d count : %d\n",i,c2);
    // getch(); 
   }
 //  printvec();
 //  getch();
   while(t--)
    {
      scanf("%d %lld %lld",&k,&m,&n);
      min=ceil(sqrt(m));
      max=floor(sqrt(n));
  //    printf("min : %d max : %d\n",min,max);
      x=y=100000;
      bin_search1(min,k,0,vec[k].size()-1,x);
      bin_search2(max,k,0,vec[k].size()-1,y);
  //    printf("x : %d y : %d\n",x,y);
      printf("%d\n",y-x+1);
    }
   return 0;
 } 
            
