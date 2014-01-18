#include<iostream>
#include<stdlib.h>
using namespace std;
void swap(int *a,int *b)
 {
   int t=*a;
   *a=*b;
   *b=t;
 }  
int randpartition(int a[],int p,int r)
 {
   int q=p+(rand()%(r-p+1));
   swap(&a[q],&a[r]);
   int i=p,j=p,par=a[r];;
   while(i<r)
    {
      if(a[i]<par)
        {
         swap(&a[i],&a[j]); 
         j++;
        }
      i++;
    } 
   swap(&a[j],&a[r]);
   return j;
 }       
   
void randomqsort(int a[],int p,int r)
 {
   int q;
   if(p<r)
    {
      q=randpartition(a,p,r);
      randomqsort(a,p,q-1);
      randomqsort(a,q+1,r);
    }
 }    
int findpos(int a[],int n,int key)
 {
  int i;
  for(i=0;i<n;i++)
    if(a[i]==key)
      return i;
 }     
int sillysort(int act[],int sort[],int stat[],int n,int i)
 {
   char x;
   int t1;
   int temp=sort[i],pos,l;
   int count1=0,count2=0,var;
   int k,c=0;
   int tmpstat[n],tmpact[n];
   for(var=0;var<n;var++)
    {
      tmpstat[var]=stat[var];
      tmpact[var]=act[var];
    }  
   for(var=0;var<n;var++)
     {
      tmpact[var]=act[var];
      tmpstat[var]=stat[var];
     }  
   for(var=0;var<n;var++)
    if(stat[var]==0)
      {
       c=1;
       break;
      }
   if(c==0)
     return 0;   
   k=findpos(act,n,temp);  
   if(stat[k]==0)
    {
      pos=findpos(act,n,sort[k]);
      swap(&act[k],&act[pos]);
      stat[k]=1;
      if(act[pos]==sort[pos])
        stat[pos]=1;
      return act[k]+act[pos]+sillysort(act,sort,stat,n,i);
    }
   else
    {
      for(l=i+1;l<n;l++)
        if(stat[l]==0)
          break;
      count1=sillysort(act,sort,stat,n,l);
      for(var=0;var<n;var++)
       {
         stat[var]=tmpstat[var];
         act[var]=tmpact[var];
       }     
      t1=findpos(act,n,sort[l]);
      swap(&act[i],&act[t1]);
      stat[i]=0;
      count2=act[i]+act[t1]+sillysort(act,sort,stat,n,i);
      if(count1<count2)
        return count1;
      else
        return count2;
    }      
  }  
                   
int main()
 {
   int n,count=0,j=0;
   int *arr,*arr2,*status;
   cin>>n;
   int i;
   while(n!=0)
    {

      arr=new int[n];
      arr2=new int[n];
      status=new int[n];
      for(i=0;i<n;i++)
        {
         //cin>>arr[i];
         scanf("%d",&arr[i]);
         arr2[i]=arr[i];
        }
      randomqsort(arr2,0,n-1);
      for(i=0;i<n;i++)
       if(arr[i]==arr2[i])
        status[i]=1;
       else
        status[i]=0; 
      count=sillysort(arr,arr2,status,n,0);
      //cout<<"Case "<<++j<<": "<<count<<endl<<endl;
      printf("Case %d: %d\n\n",++j,count); 
      delete[] arr;
      delete[] arr2;
      delete[] status;
      scanf("%d",&n);
//      cin>>n;
    }
   return 0;
 }             
          
        
   

