#include<iostream>
using namespace std;
int last(int a,long long int b){if(b==0)return 1;if(a==0||a==1||a==5||a==6)return a;
else
if(a==2||a==3||a==8||a==7){switch(b%4){case 1 : return (a==2)?2:(a==3)?3:(a==8)?8:7;
case 2 : return (a==2)?4:(a==3)?9:(a==8)?4:9;
case 3 : return (a==2)?8:(a==3)?7:(a==8)?2:3;
case 0 : return (a==2)?6:(a==3)?1:(a==8)?6:1;}}else  
return (b%2==0)?(a==4)?6:1:(a==4)?4:9;}    
int main()
  {
   int t,i,len,aa;
   char a[1001];
   long long int b;
   cin>>t;
   for(i=0;i<t;i++)
    {
      cin>>a;
      len=strlen(a);
      aa=(int)(a[len-1])-48;
      cin>>b;
      cout<<last(aa,b)<<"\n";
    }
   return 0;
  }      
      

