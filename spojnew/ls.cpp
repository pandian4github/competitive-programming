#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
/*void print(vector<string> v,int t)
{
  int i;
  for(i=0;i<t;i++)
    cout<<v[i]<<"\n";
}
void prints(int arr[],int t)
{
  int i;
  printf("\n");
  for(i=0;i<t;i++)
    printf("%d  ",arr[i]);
  printf("\n");
}*/
bool mycomp(string str1,string str2)
{
  if(str1<=str2)
    return true;
  return false;
}
int col;
void calrow(int size[],int r,int t)
{
  int i,j,max;
  printf("r : %d\n",r);
  for(i=0;i<t;)
  {
    max=0;
    for(j=0;j<r;j++,i++)
      if(size[i]>max)
        max=size[i];
    col=col-max-2;
    printf("col : %d\n",col);
    if(col<-3)
      return;
  }
  col=col+2;  
}
      
int main()
{
  int i,j,k,t,colcount,row,max;
  char filename[105][70];
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
//    sort(vec.begin(),vec.end(),mycomp);
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
  //  prints(size,t);
    for(row=1;row<=t;row++)
    {
      col=60;
      calrow(size,row,t);
      if(col>=0)
        break;
    }
  /*  colcount=1;
    col=60;
    col=col-max;
    col=col-max-2;
    while(col>=0)
    {
      colcount++;
      col=col-max-2;
    }*/
    colcount=t/row;
    double temp=((double)(t))/row;
    if((temp-colcount)>0)
      colcount++; 
    for(i=0;i<colcount;i++)
      colmax[i]=0;
    for(i=1;i<=t;i++)
      if(size[i-1]>colmax[(i-1)/row])
        colmax[(i-1)/row]=size[i-1];  
  //  printf("row : %d\n",row);
    for(i=0;i<60;i++)
      printf("-");
    printf("\n");
    for(j=1;j<=row;j++)
    {
      for(i=1;i<=colcount;i++)
      {
        int temp=row*(i-1)+(j-1);
  //      printf("temp : %d  size[temp] : %d ",temp,size[temp]);
        if(temp<t)
        {
         cout<<vec[temp];
         if(i!=colcount)
           for(k=0;k<colmax[i-1]-size[temp]+2;k++)
             printf(" ");
        }
      }
      printf("\n");
    }    
  }    
  return 0;
}
