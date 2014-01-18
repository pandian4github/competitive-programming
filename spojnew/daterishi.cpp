#include<stdio.h>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int t,n,val,pos,i,flag1,flag2,pos1,pos2;
    long int temp,max,temp1,temp2;
    pair<int,int> p;
    priority_queue< pair<int,int> > pq;
    int arr[100000];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              for(i=0;i<n;i++)
               {
                scanf("%d",&arr[i]);
                pq.push(make_pair(-1*arr[i],i));
               }
              max=0; 
              while(!pq.empty())
              {
                  p=pq.top();
                  pq.pop();
                  val=-p.first;
                  pos=p.second;
              //    printf("\n");
              //    printf("val : %d\npos : %d\n",val,pos);
                  flag1=flag2=0;
                  for(pos1=0;pos1<pos;pos1++)
                    if(arr[pos1]>=val)
                      break;
                  if(pos1==pos)
                    flag1=1;   
              //    printf("pos1 : %d\nflag1 : %d\n",pos1,flag1);   
                  for(pos2=n-1;pos2>pos;pos2--)
                    if(arr[pos2]>=val)
                      break;
                   if(pos2==pos)
                     flag2=1;   
              //    printf("pos2 : %d\nflag2 : %d\n",pos2,flag2);   
                  if(flag1)
                    temp1=0;
                  else
                    temp1=(pos-pos1)*val;
                  if(flag2)
                    temp2=0;
                  else
                    temp2=(pos2-pos)*val;
              //    printf("temp1 : %d\ntemp2 : %d\n",temp1,temp2);
              //    printf("\n");  
                  temp=temp1>temp2?temp1:temp2;
                  max=(max>temp)?max:temp;
              }
              printf("%ld\n",max);
    }
    return 0;
}   
              
