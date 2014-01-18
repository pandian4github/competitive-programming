#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
/*bool mycomp(string str1,string str2)
{
  if(str1<=str2)
    return true;
  return false;
}*/
int main()
{
  int col,i,j,k,t,colcount,row,max,temp;
  double temp1;
  string s;
  while((scanf("%d",&t))!=EOF)
  {
    int size[t];
    vector<string> vec(t);
    vector<string>::iterator it;
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
    temp1=((double)(t))/colcount;
    if((temp1-row)>0)
      row++; 
    for(i=0;i<60;i++)
      printf("-");
    printf("\n");
    for(j=1;j<=row;j++)
    {
      for(i=1;i<=colcount;i++)
      {
        temp=row*(i-1)+(j-1);
        if(temp<t)
        {
          cout<<vec.at(temp);
          if(i!=colcount)
            for(k=0;k<max-size[temp]+2;k++)
              printf(" ");
        }
      }
      printf("\n");
    }    
  }    
  return 0;
}
