#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
bool sort_by_dist(pair<int,int> lhs, pair<int,int> rhs)
{
     return lhs.first > rhs.first;
}
int main()
{
    int t,n,i,currFuel,remDist,max,maxp,count,l,p,a,b,margin;
    pair<int,int> pr;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&n);
      vector<pair<int,int> > info(n);
      info.clear();
      count=0;
      for(i=0;i<n;i++)
        {
         scanf("%d %d",&a,&b);
         pr=make_pair(a,b);
         info.push_back(pr);
        }
      scanf("%d %d",&l,&p);
      sort(info.begin(),info.end(),sort_by_dist);
//      for(i=0;i<n;i++)
 //       printf("%d %d\n",info[i].first,info[i].second);
      int arr[n];
      for(i=0;i<n;i++)
        arr[i]=info[i].second-info[i].first;
  //    printf("arr[] : \n");
      for(i=0;i<n;i++)
  //      printf("%d  ",arr[i]);
      currFuel=p;
      remDist=l;
      i=0;
      while(1)
      {
      //     printf("\ncurrFuel : %d \nremDist= %d\n",currFuel,remDist);
           if(currFuel>=remDist)
             break;
           max=-10000000;
           maxp=0;
           margin=remDist-currFuel;
          // i=0;
           while(info[i].first>=margin && i<n)
           {
             if(info[i].second>max)
             {
               max=info[i].second;
               maxp=i;
             }            
             i++;
           }
      //     printf("\nmax : %d \nmaxp : %d\n",max,maxp);
           count++;
           
           if(i==n)
            {
             count=-1;
             break;
            }
           currFuel=currFuel-(remDist-info[maxp].first)+info[maxp].second;
           remDist=info[maxp].first;
      }
      printf("%d\n",count);
    }
    return 0;
}
      
