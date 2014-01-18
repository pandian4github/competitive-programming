#include<stdio.h>
#include<string.h>
int count=0;
int start1[]={0,1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};
int end9[]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999};
int power5[]={1,5,25,125,625,3125,15625,78125,390625,1953125,9765625};
int power10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void samelen(int l,int r,int len)
{
     int f1,f2,i,j;
 //    printf("samelen  :%d %d len:%d \n",l,r,len);
     if(len==1)
     {
       for(i=l;i<=r;i+=2)
         count++;
       return;
     }
     f1=l/power10[len-1];
     f2=r/power10[len-1];
     if(f1==f2)
       samelen(l%power10[len-1],r%power10[len-1],len-1);
     else
     {
         for(j=f1+2;j<f2;j+=2)
           count+=power5[len-1];
         samelen(l%power10[len-1],end9[len-1],len-1);
         samelen(start1[len-1],r%power10[len-1],len-1);
     }       
     return;
}
void func1(int l,int r,int len1,int len2)
{
     int i;
//     printf("Inside func1 : \nlen1 = %d len2 = %d\n",len1,len2);
     if(len1!=len2)
       {
         for(i=len1+1;i<len2;i++)
          count+=power5[i];
         samelen(l,power10[len1]-1,len1);
         samelen(start1[len2],r,len2);
       }
     else
       samelen(l,r,len1);
     return;
}
     
int main()
{
    int t,i,temp,len1,len2;
    char l[10],r[10];
    int l1,r1,l2,r2,flag;
    scanf("%d",&t);
    while(t--)
    {
      count=0;
      scanf("%d %d",&l2,&r2);
      flag=0;
      temp=l2;
      i=0;
      while(temp!=0)
        {
          l[i++]=temp%10;
          temp=temp/10;
        }
      len1=i;
      i--;
      for(;i>=0;i--)
       if(l[i]%2==0)
        {
          l[i]=l[i]+1;
          flag=1;
          i--;
          break;
        }
      if(flag==1)
        for(;i>=0;i--)
          l[i]=1;
          
      flag=0;
      temp=r2;
      i=0;
      while(temp!=0)
        {
          r[i++]=temp%10;
          temp=temp/10;
        }
      len2=i;
      i--;
      for(;i>=0;i--)
       if(r[i]%2==0)
        {
          r[i]=r[i]+1;
          flag=1;
          i--;
          break;
        }
      if(flag==1)
        for(;i>=0;i--)
          r[i]=1;
        
      l1=r1=0;
      for(i=len1-1;i>=0;i--)
        l1=l1*10+l[i];
      for(i=len2-1;i>=0;i--)
        r1=r1*10+r[i];
        
  //    printf("%d %d\n",l1,r1);
      func1(l1,r1,len1,len2);
      if(r2==r1)
        r2--;
  //    printf("count : %d\n",count);
      printf("%d\n",r2-l2-count+2);
    }
    return 0;
} 
      
