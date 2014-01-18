#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
  int col,i,j,k,t,colcount,row,max,t2;
  string s;
  int size[105],colarr[105],colmax[105];
  vector<string> vec;
  vector<string>::iterator it;
  while((scanf("%d",&t))!=EOF)
  {
    vec.clear();
    for(i=0;i<t;i++)
     { 
      cin>>s;
      vec.push_back(s);
     }
    for(i=0;i<t;i++)
      for(j=i+1;j<t;j++)
        if(vec[i]>vec[j])
        {
          s=vec[i];
          vec[i]=vec[j];
          vec[j]=s;
        }
    max=0;
    for(i=0;i<t;i++)
      {
       size[i]=vec[i].size();
       if(size[i]>max)
         max=size[i];
      }
    colcount=1;
    col=60-max;
    col=col-max-2;
    while(col>=0)
    {
      colcount++;
      col=col-max-2;
    }
    row=t/colcount;
    double temp=((double)(t))/colcount;
    if((temp-row)>0)
      row++; 
    for(i=0;i<colcount;i++)
      colmax[i]=0;
    for(i=1;i<=t;i++)
      if(size[i-1]>colmax[(i-1)/row])
        colmax[(i-1)/row]=size[i-1];  
    for(i=0;i<60;i++)
      printf("-");
    printf("\n");
    for(j=1;j<=row;j++)
    {
      for(i=1;i<=colcount;i++)
      {
        int temp=row*(i-1)+(j-1);
        if(temp<t)
        {
         cout<<vec[temp];
         t2=size[temp];
        }
        else
          t2=0;
        if(i!=colcount)
          for(k=0;k<colmax[i-1]-t2+2;k++)
            printf(" ");
        else
          for(k=0;k<colmax[i-1]-t2;k++)
            printf(" ");             
        
      }
      printf("\n");
    }    
  }    
  return 0;
}
