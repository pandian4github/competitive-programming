#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct struc
{
   char name[20];
   int acc;
   int speed;
   int stup;
};
bool mycompare(struct struc x,struct struc y)
{
     return (x.acc>y.acc)||(x.acc==y.acc && x.speed>y.speed)||(x.acc==y.acc && x.speed==y.speed && x.stup<y.stup)||(x.acc==y.acc && x.speed==y.speed && x.stup==y.stup && strcmp(x.name,y.name)<0);
}
int main()
{
    int i,n;
    scanf("%d",&n);
    struct struc st;
    vector<struct struc> v;
    vector<struct struc>::iterator it;
    for(i=0;i<n;i++)
    {
      scanf("%s %d %d %d",st.name,&st.acc,&st.speed,&st.stup);
      v.push_back(st);
    }
    sort(v.begin(),v.end(),mycompare);
    for(it=v.begin();it!=v.end();it++)
      printf("%s\n",(*it).name);
//    cin>>n;  
    return 0;  
}      
