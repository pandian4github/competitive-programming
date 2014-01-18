#include<stdio.h>
#include<vector>
using namespace std;
vector<bool> vec(1000001);
int cubefree[1000001];
void sievefunc()
 {
   int i,j,index=2,cube,last;
   for(i=0;i<1000001;i++)
    vec[i]=true;
   cubefree[1]=1;
   last=1;
   for(i=2;i<=1000000;i++)
    {
      if(vec[i])
       {
         cubefree[index++]=++last;
         if(i<=100)
          {
           cube=i*i*i;
           for(j=cube;j<=1000000;j=j+cube)
             vec[j]=false;
          } 
       }
      else
       index++; 
    }
 }     
      
int main()
 {
   int t,i,n;
   scanf("%d",&t);
   sievefunc();
 //  for(i=1;i<=20;i++)
 //    printf("%d  ",cubefree[i]);
   for(i=1;i<=t;i++)
    {
      scanf("%d",&n);
      if(vec[n])
        printf("Case %d: %d\n",i,cubefree[n]);
      else 
        printf("Case %d: Not Cube Free\n",i);
    }
   return 0; 
 } 
