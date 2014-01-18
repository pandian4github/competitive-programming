#include<iostream>
#include<string.h>
using namespace std;
int dir[101][101]={0},val[101][101]={0};
void lcs(char x[],char y[],int l1,int l2) 
 {
   int i,j;
   for(i=0;i<101;i++)
    {
      dir[0][i]=0;
      val[0][i]=0;
      dir[i][0]=0;
      val[i][0]=0;
    }
   for(i=0;i<l1;i++)
     for(j=0;j<l2;j++)
       if(x[i]==y[j])
        {
          dir[i+1][j+1]=11;
          val[i+1][j+1]=val[i][j]+1;
        }
       else
        if(val[i][j+1]>=val[i+1][j])
         {
          dir[i+1][j+1]=22;
          val[i+1][j+1]=val[i][j+1];
         }
        else
         {
          dir[i+1][j+1]=33;
          val[i+1][j+1]=val[i+1][j];
         }
 }               
int returnpos(int i,int j)
 {
   if(i==0||j==0)
     return 0;
   if(dir[i][j]==11)
     return val[i][j];
   else
    if(dir[i][j]==22)
      return returnpos(i-1,j);
    else
      return returnpos(i,j-1);
 }      
void storelcs(int arr1[],int arr2[],int i,int j,int pos,int l1,int l2)
 {
   if(i==0||j==0||pos==-1)
      return;
   if(dir[i][j]==11)
    {
      arr1[pos]=i-1;
      arr2[pos]=j-1;
      storelcs(arr1,arr2,i-1,j-1,pos-1,l1,l2);
    }
   else
    if(dir[i][j]==22)
      storelcs(arr1,arr2,i-1,j,pos,l1,l2);
    else
      storelcs(arr1,arr2,i,j-1,pos,l1,l2);
 }       
         
      
int main()
 {
   char str1[100],str2[100];
   int p,i,j,k,l1,l2;
   int veci[101],vecj[101];
   while((scanf("%s%s",str1,str2))!=EOF)
    {
      l1=strlen(str1);
      l2=strlen(str2);
      lcs(str1,str2,l1,l2);
      p=returnpos(l1,l2);
      if(p==0)
      {
        printf("%s%s\n",str1,str2);
        continue;
      }  
      veci[p]=-1;
      vecj[p]=-1;
      storelcs(veci,vecj,l1,l2,p-1,l1,l2);
      i=j=k=0;
      while(1)
       {
         if(veci[k]==-1)
          {
            for(i=veci[k-1]+1;i<l1;i++)
              printf("%c",str1[i]);
            for(j=vecj[k-1]+1;j<l2;j++)
              printf("%c",str2[j]);
            break;
          }      
         for(;i<veci[k];i++)
           printf("%c",str1[i]);
         i=veci[k]+1;
         for(;j<vecj[k];j++)
           printf("%c",str2[j]);
           printf("%c",str1[veci[k]]);  
         j=vecj[k]+1;
         k++;
       }
      cout<<"\n";
    }
   return 0;
 }   
      
