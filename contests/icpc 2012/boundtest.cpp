  #include<stdio.h>
  #include<string.h>
  #include<iostream>
  #include<vector>
  #include<map>
  #include<list>
  #include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
  int arr[]={2,5,7,10,15},e;
  vector<int> v (arr,arr+5);
  vector<int>::iterator l,u;
  while(1)
  {
    scanf("%d",&e);
    l=lower_bound(v.begin(),v.end(),e);
    u=upper_bound(v.begin(),v.end(),e);
    printf("l : %d u : %d\n",(int)(l-v.begin()),(int)(u-v.begin()));
  }
  return 0;
}
