#include<stdio.h>
#include<conio.h>
long long pow(int b)
 {
   long long p=1;
   int i;
   for(i=0;i<b;i++)
     p=p*2;
   return p;
 }    
void nobits(long long x,int &y)
 {
   y++;
   if(x==0)
    {
     y=0;
     return;
    } 
   if(x==1)
     return ;
   nobits(x/2,y);
 }   
long long whriglig(long long x,long long y,int d,long long arr[])
 {
  // cout<<"\nStart\nx = "<<x<<"\ny = "<<y<<"\n"<<"d = "<<d<<"\n";
   int c1=0,c2=0,d1=0,d2=0,i;
   long long x1,y1,sum=0;
   x1=x-pow(d-1);
   y1=y-pow(d-1);
   if(d==1)
     return 1;
//   if(x1==0)     
   nobits(x1,d1);
   nobits(y1,d2);
   for(i=d1+1;i<d2;i++)
     sum+=arr[i];
   if(x1==pow(d1-1))
     c1=1;
   if(y1==pow(d2)-1)
     c2=1;  
  // cout<<"After changing\nx1 = "<<x1<<"\nby1 = "<<y1<<"\nc1 = "<<c1<<"\nc2 = "<<c2<<"\nd1 = "<<d1<<"\nd2 = "<<d2;
   if(x1==0)
    {
      if(c2)
        sum+=pow(d-1)+arr[d2];
      else
        sum+=pow(d-1)+whriglig(pow(d2-1),y1,d2,arr);
     }      
   else
    if(c1)
     {
      if(c2)
       {
        if(d1!=d2)
         sum+=arr[d1]+arr[d2];
        else
         sum+=arr[d1];  
       } 
      else
       {
        if(d1==d2)
         sum+=whriglig(x1,y1,d1,arr);
        else
         sum+=arr[d1]+whriglig(pow(d2-1),y1,d2,arr);
       } 
     }  
    else
     {
      if(c2)
       {
        if(d1==d2)
         sum+=whriglig(x1,y1,d1,arr);
        else
         sum+=arr[d2]+whriglig(x1,pow(d1)-1,d1,arr);
       } 
      else
       {
        if(d1==d2)
         sum+=whriglig(x1,y1,d1,arr);
        else
         sum=whriglig(x1,pow(d1)-1,d1,arr)+whriglig(pow(d2-1),y1,d2,arr);
       } 
      }
   return sum;
 }    
       
int main()
 {
   long long a,b,sum=0,arr[51]={0};
   int i,j,d1=0,d2=0,c1=0,c2=0;
   scanf("%lld %lld",&a,&b);
   nobits(a,d1);
   nobits(b,d2);
   arr[0]=0;
   arr[1]=1;
   for(i=2;i<51;i++)
    {
     for(j=i-1;j>0;j--)
        arr[i]+=arr[j];
     arr[i]+=pow(i-1);      
    }  
   for(i=d1+1;i<d2;i++)
     sum+=arr[i];
   if(a==pow(d1-1))
     c1=1;
   if(b==pow(d2)-1)
     c2=1;  
   if(c1)
     {
      if(c2)
        {
         if(d1==d2)
           sum+=arr[d1];
         else
           sum+=arr[d1]+arr[d2];
        } 
      else
        {
         if(d1==d2)
           sum+=whriglig(a,b,d1,arr);
         else
           sum+=arr[d1]+whriglig(pow(d2-1),b,d2,arr);
        }  
     }  
   else
     {
      if(c2)
        {
         if(d1==d2)
          sum+=whriglig(a,b,d1,arr);
         else
          sum+=arr[d2]+whriglig(a,pow(d1)-1,d1,arr);
        } 
      else
        {
         if(d1==d2)
          sum+=whriglig(a,b,d1,arr);
         else
          sum+=whriglig(a,pow(d1)-1,d1,arr)+whriglig(pow(d2-1),b,d2,arr);
        } 
      }
   printf("%lld",sum);
   getch();
   return 0;
 }             
   
