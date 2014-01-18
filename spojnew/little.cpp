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
#define wait { char ccc=getchar(); }
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
int main()
{
  int t,i;
  char str[50];
  int count[26]={0};
  scans(str)
  fori(0,strlen(str)-1)
    count[str[i]-97]++;
  fori(0,25)
    printf("%c  %d\n",i+97,count[i]);
  wait
  wait  
  return 0;
}
