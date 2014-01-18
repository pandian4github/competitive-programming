#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<utility>
using namespace std;
#define fori(a,b) for(i=a;i<=b;i++)
#define forj(a,b) for(j=a;j<=b;j++)
#define scani(a) scanf("%d",&a);
int main()
{
    int t,n,i,j,m,key,x,y;
    int b[51],r[51];
    pair<int,int> p;
    scani(t)
    while(t--)
    {
      scani(m)
      scani(n)
      map<int,vector<pair<int,int> > > mp; 
      vector<pair<int,int> > vec;
      int a;
      fori(0,m-1)
        forj(0,n-1)
        {
          //printf("i  :%d j : %d\n",i,j);
          p=make_pair(i,j);
          scani(a)
          mp[a].push_back(p);
        }
      scani(key)
      if(mp.count(key)==0)
        {
          printf("-1\n");
          continue;
        }
      vec=mp[key];
      int rmin=m,cmin=n;
      vector<pair<int,int> >::iterator it;
      for(it=vec.begin();it!=vec.end();++it)
      {
        x=(*it).first;
        y=(*it).second;
      //  printf("x : %d y : %d\n",x,y);
        if(x<rmin)
          rmin=x;
        if(m-x<rmin)
          rmin=m-x;
        if(y<cmin)
          cmin=y;
        if(n-y<cmin)
          cmin=n-y;          
      }
      printf("%d\n",rmin+cmin);
    }
    return 0;
}
