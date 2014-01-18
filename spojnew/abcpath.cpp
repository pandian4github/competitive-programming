//      cout<<"\nDP table  :\n\n";
/*      for(j=0;j<r;j++)
       {
        for(k=0;k<c;k++)
          cout<<dp[j][k]<<"  ";
        cout<<"\n";
       } */   


#include<iostream>
//#include<conio.h>
using namespace std;
int computeabc(int i,int j,int arr[][50],int r,int c,int val,int count)
 {
   int veci[10],vecj[10];
//   cout<<i<<"   "<<j<<"\n";
   int c1=0;
   int k1,k2,k3,l1,l2,l3;
   k1=i-1;
   k2=i+1;
   l1=j-1;
   l2=j+1;
   if(i==0)
     k1=0;
   if(j==0)
     l1=0;
   if(i==r-1)
     k2=r-1;
   if(j==c-1)
     l2=c-1;      
   for(k3=k1;k3<=k2;k3++)
     for(l3=l1;l3<=l2;l3++)
       if(arr[k3][l3]==val+1)
          {
            veci[c1]=k3;
            vecj[c1]=l3;
            c1++;
          }
   if(c1==0)
     return count;
   if(val==26)
     return 26;       
   int m,max=0;
   for(k3=0;k3<c1;k3++)
     for(l3=0;l3<c1;l3++)
       {
        m=computeabc(veci[k3],vecj[l3],arr,r,c,val+1,count+1);
 //       getch();
        if(m>max)
          max=m;
       }
    return max;   
 }     
          
   
int main()
 {
   int r,c,i,j,max,an,co=0;
   char ch;
   while(1)
    {
      co++;
      fflush(0);
//      scanf("%d%d",&r,&c);
      cin>>r>>c;
      if(r==0&&c==0)
        break;
      int arr[50][50];
      for(i=0;i<r;i++)
        for(j=0;j<c;j++)
          {
         //  scanf("%c",&c);
           cin>>c;        
           arr[i][j]=(int)ch-65;
          } 
      max=0;
      for(i=0;i<r;i++)
        for(j=0;j<c;j++)
          if(arr[i][j]==0)
            {
             an=computeabc(i,j,arr,r,c,0,1);
             if(an>max)
               max=an;
            }
      printf("Case %d: %d\n",co,max);
      //cout<<"Case "<<co<<": "<<max<<"\n";
    }
   return 0;
 }                         
