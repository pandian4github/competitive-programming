#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct struc
{
  int v;
  int w;
  double ratio;
};
bool mycomp(struct struc x,struct struc y)
{
  return (x.ratio<=y.ratio);
}
void printv(vector<struct struc> ve,int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("v : %d  w : %d  ratio : %lf  \n",ve[i].v,ve[i].w,ve[i].ratio);
}
int main()
{
  struct struc st;
  vector<struct struc> vec;
  int t,f,e,W,wi,vi,n,i,ans;
  scanf("%d",&t);
  while(t--)
  {
    vec.clear();
    scanf("%d %d",&e,&f);
    W=f-e;
    ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d %d",&st.v,&st.w);
      st.ratio=(double)(st.v)/st.w;
      vec.push_back(st);
    }
 //   printv(vec,n);
    sort(vec.begin(),vec.end(),mycomp);
 //   printv(vec,n);
    for(i=0;i<n;i++)
    {
      wi=vec[i].w;
      vi=vec[i].v;
      if(wi<=W)
      {
        ans+=(W/wi)*vi;
        W=W%wi;
      }
    }
    if(W==0)
      printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
    else
      printf("This is impossible.\n"); 
  }
  return 0;
}
