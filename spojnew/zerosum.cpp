#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;
#define wait char ccc=getchar();
#define fori(a,b) for(i=a;i<=b;i++)
#define rfori(a,b) for(i=a;i>=b;i--)
#define forj(a,b) for(j=a;j<=b;j++)
#define rforj(a,b) for(j=a;j>=b;j--)
#define fork(a,b) for(k=a;k<=b;k++)
#define rfork(a,b) for(k=a;k>=b;k--)
#define forl(a,b) for(l=a;l<=b;l++)
#define rforl(a,b) for(l=a;l>=b;l--)
#define scani(a) scanf("%d",&a);
#define scanii(a,b) scanf("%d %d",&a,&b);
#define scaniii(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define scans(s) scanf("%s",s);
#define printi(a) printf("%d ",a);
#define printiln(a) printf("%d\n",aa);
int p1[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void recurse(int a,int p,int *cnt,int flag)
{
     int first=a/p1[p];
     if(first==0)
       (*cnt)+=a+1;
     if(first>0 && flag==0)
       (*cnt)+=p1[p];
     if(p==0)
       return;
     (*cnt)+=first*p*p1[p-1];
     if(flag==1)
       (*cnt)-=(p1[p]-1)/9;
     recurse(a%p1[p],p-1,cnt,0);
     return;
}
int main()
{
  int t,a,b,cnt1,cnt2,p;
  scani(t)
  while(t--)
  {
    scanii(a,b)
    cnt1=cnt2=0;
    a--;
    if(a!=0)
      {
       p=(int)floor(log10(a));
       recurse(a,p,&cnt1,1);
      }
    p=(int)floor(log10(b));
    recurse(b,p,&cnt2,1);
  //  printf("cnt1 : %d\ncnt2 : %d\n",cnt1,cnt2);
    printf("%d\n",cnt2-cnt1);
  }  
  return 0;
}
