#include<iostream>
using namespace std;
struct list
 {
   int ii;
   int jj;
   struct list *next;
 };  
struct list* insert(struct list* n,int i,int j)
 {
   struct list *temp,*newn;
   if(n==NULL)
    {
      n=new list;
      n->ii=i;
      n->jj=j;
      n->next=NULL;
    }   
   else
    {
     temp=n;
     while(temp->next!=NULL)
      temp=temp->next;
     newn=new list;
     newn->ii=i;
     newn->jj=j;
     newn->next=NULL;
     temp->next=newn;
    }
   return n;  
 }          
void deletenodes(struct list* data[])
 {
   int i;
   struct list* temp,*temp1;
   for(i=0;i<26;i++)
    {
      temp=data[i];
      while(temp!=NULL)
       {
         temp1=temp;
         temp=temp->next;
         delete temp1;
       }
    }
 }             
void constructtable(int arr[][50],int r,int c,struct list* data[],int dp[][50])
 {
   int i,j,k,j1,j2,j3,k1,k2,k3;
   struct list* temp;
   for(i=25;i>=0;i--)
     if(data[i]!=NULL)
      {
        temp=data[i];
        while(temp!=NULL)
         {
           dp[temp->ii][temp->jj]=1;
           temp=temp->next;
         }  
        i--; 
        break;        
      }  
   for(;i>=0;i--)
    {
      temp=data[i];
      while(temp!=NULL)
       {
         j=temp->ii;
         k=temp->jj;
         if(j==0)
           j1=0;
         else
           j1=j-1;
         if(k==0)
           k1=0;
         else
           k1=k-1;
         if(j==r-1)
           j2=r-1;
         else
           j2=j+1;
         if(k==c-1)
           k2=c-1;
         else
           k2=k+1;             
         int mm=0;   
         for(j3=j1;j3<=j2;j3++)
           for(k3=k1;k3<=k2;k3++)
             {
              if(arr[j3][k3]==i+1)  
                if(dp[j3][k3]>mm)
                  mm=dp[j3][k3];
             }
         if(mm==0)
          dp[j][k]=1;
         else
          dp[j][k]=mm+1; 
         temp=temp->next;
       }
     }
 }
int main()
 {
   int r,c,i,j,t,k,arr[50][50]={0},dp[50][50]={0};
   char ch;
   for(i=1;;i++)
    {
      struct list* data[26];
      struct list* temp;
      for(j=0;j<26;j++)
        data[j]=NULL;
      cin>>r>>c;
      if(r==0&&c==0)
        break;
      for(j=0;j<r;j++)
        for(k=0;k<c;k++)
          {
            cin>>ch;
            t=arr[j][k]=(int)ch-65;
            data[t]=insert(data[t],j,k);
          }
      if(data[0]==NULL)
       {
         cout<<"Case "<<i<<": 0\n";
         continue;
       }                       
      constructtable(arr,r,c,data,dp);
      int max=0;
      temp=data[0];
      while(temp!=NULL)
       {
         j=temp->ii;
         k=temp->jj;
         if(dp[j][k]>max)
           max=dp[j][k];
         temp=temp->next;
       }
      cout<<"Case "<<i<<": "<<max<<"\n";
      deletenodes(data);
    }
   return 0;
 }         
      
          
          
