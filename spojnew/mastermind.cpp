#include<stdio.h>
int myarr[4],reply[4],vec[4];
void setandprint(int val)
 {
   int i;
   for(i=0;i<4;i++)
     {
      if(vec[i]==0)
        myarr[i]=val;
      printf("%d ",myarr[i]);
     }
   printf("\n");
 }
void read()
 {
   int i;
   for(i=0;i<4;i++)
     {
      scanf("%d",&reply[i]);
      if(reply[i]==1)
        vec[i]=1;
     }
 } 
bool check()
 {
   int i;
   for(i=0;i<4;i++)
     if(vec[i]==0)
      return false;
   return true;
 }
int main()
 {
   int i;
   for(i=0;i<4;i++)
     vec[i]=0;
   for(i=1;i<=6;i++)
    {
      if(check())
        break;
      setandprint(i);
      read();
    }
   return 0;
 }   
