#include<iostream>
using namespace std;
int main()
 {
   long int s1,s2,s3,a1,a2,a3,tot,temp;
   int no,c=0;
   while((scanf("%ld%ld%ld%ld%ld%ld",&s1,&s2,&s3,&a1,&a2,&a3))!=EOF)
    {
      c++;
      no=0;
      tot=0;
      if(s1!=0)
       {
        no++;
        temp=(a1-1)*20*60;
        tot+=(temp+s1);
       } 
      if(s2!=0)
       {
        no++;
        temp=(a2-1)*20*60;
        tot+=(temp+s2);
       } 
      if(s3!=0)
       {
        no++;
        temp=(a3-1)*20*60;
        tot+=(temp+s3);
       } 
      cout<<"team "<<c<<": "<<no<<", "<<tot<<endl;
    }
   return 0;
 }     
      
      
