#include<iostream>
using namespace std;
#include<conio.h>
#include<map>
struct ListRecord
 {
   int row;
   int col;
   struct ListRecord* next;
 }; 
typedef struct ListRecord* list; 
----------------------------------------------------------------------------------------
list insert(int i,int j,list l)
 {
   if(l==NULL)
    {
      l=new ListRecord;
      l->row=i;
      l->col=j;
      l->next=NULL;
      return l;
    }
   list temp=l;
   while(temp->next!=NULL)
     temp=temp->next;
   list newn=new ListRecord;
   newn->row=i;
   newn->col=j;
   newn->next=NULL;
   temp->next=newn;
   return l;
 } 
----------------------------------------------------------------------------------------
void print(list l)
 {
   list temp=l;
   printf("\n");
   while(temp!=NULL)
    {
      printf("i = %d j = %d\n",temp->row,temp->col);
      temp=temp->next;
    }
   printf("\n"); 
 }     
----------------------------------------------------------------------------------------
void bounds(int curi,int curj,int &i1,int &i2,int &j1,int &j2,int r,int c)
 {
   if(curi==0)
     i1=0;
   else
     i1=curi-1;
   if(curi==r-1)
     i2=r-1;
   else
     i2=curi+1;
   if(curj==0)
     j1=0;
   else
     j1=curj-1;
   if(curj==c-1)
     j2=c-1;
   else
     j2=curj+1;
 }    
---------------------------------------------------------------------------------------
void recursion(int **dp,int rpos,int cpos,int r,int c,int n,int **status)
 {
    int i1,i2,j1,j2;
    bounds(rpos,cpos,i1,i2,j1,j2);
    int i,j;
    for(i=i1;i<=i2;i++)
      for(j=j1;j<=j2;j++)
       {
        status[i][j]=0;
        if(dp[i][j]==n-1)
         {
          status[i][j]=1;
          recursion(dp,i,j,r,c,n-1);
         }  
       } 
       
         
int main()
 {
   int r,c,t,i,j,k,rpos,cpos,i1,i2,j1,j2,max,c1,flag;
   map<char,int> m;
   m['A']=0;
   m['L']=1;
   m['I']=2;
   m['Z']=3;
   m['W']=4;
   m['E']=5;   
   scanf("%d",&t);
   char key[11]="ALLIZZWELL";
   while(t>0)
    {
      t--;
      list li[6];
      list temp;
      for(i=0;i<6;i++)
        li[i]=NULL;
      fflush(stdin);
      scanf("%d%d",&r,&c);
      char arr[r][c];
      int dp[r][c];
      int dp1[r][c];
      int status[r][c];
      for(i=0;i<r;i++)
       {
         scanf("%s",arr[i]);
         for(j=0;j<c;j++)
           if(arr[i][j]=='A'||arr[i][j]=='L'||arr[i][j]=='I'||arr[i][j]=='Z'||arr[i][j]=='W'||arr[i][j]=='E')
              li[m[arr[i][j]]]=insert(i,j,li[m[arr[i][j]]]);
       }
//      for(i=0;i<6;i++)
//        print(li[i]);    
      for(i=0;i<r;i++)
        for(j=0;j<c;j++)
          dp[i][j]=dp1[i][j]=0;
   -------------------------------------------------------------------------------------------
      for(k=6;k>=0;k--)
       {
         temp=li[m[key[k]]];         
         flag=0;
         while(temp!=NULL)
          {
            rpos=temp->row;
            cpos=temp->col;
            bounds(rpos,cpos,i1,i2,j1,j2,r,c);
            max=dp[rpos][cpos];
            for(i=i1;i<=i2;i++)
              for(j=j1;j<=j2;j++)
               if(i!=rpos||j!=cpos)
                if(arr[i][j]==key[k+1])
                 {
                   flag=1;
                   if(dp[i][j]+1>=max)
                     max=dp[i][j]+1;
                   if(max>(7-k))
                     max=7-k;  
                   dp[rpos][cpos]=max;
                 }
            temp=temp->next;     
          }
         if(flag==0)
          {
           printf("NO\n");
           break;
          }
       }
   -------------------------------------------------------------------------------------------
/*      for(k=1;k<=7;k--)
       {
  //       cout<<m[key[k]]<<"   ";
         temp=li[m[key[k]]];         
         flag=0;
         while(temp!=NULL)
          {
            rpos=temp->row;
            cpos=temp->col;
 //           printf("rpos = %d cpos = %d \n\n",rpos,cpos);

            if(rpos==0) i1=0;else i1=rpos-1;
            if(rpos==r-1) i2=r-1;else i2=rpos+1;
            if(cpos==0) j1=0;else j1=cpos-1;
            if(cpos==c-1) j2=c-1;else j2=cpos+1;

  //          printf("i1 = %d i2 = %d j1 = %d j2 = %d\n\n",i1,i2,j1,j2);  
            max=dp[rpos][cpos];
            for(i=i1;i<=i2;i++)
              for(j=j1;j<=j2;j++)
               if(i!=rpos||j!=cpos)
                if(arr[i][j]==key[k-1])
                 {
                   flag=1;
                   if(dp[i][j]+1>=max)
                     max=dp[i][j]+1;
                   if(max>k)
                     max=k;  
                   dp[rpos][cpos]=max;
                 }
            temp=temp->next;     
          }
         if(flag==0)
          {
           printf("NO\n");
           break;
          }
       }*/
   --------------------------------------------------------------------------------------------
 
       
/*      for(i=0;i<r;i++)
       {
         for(j=0;j<c;j++)
  
          printf("%d  ",dp[i][j]);
         printf("\n");
       }   */
       
      if(flag==0)
       continue;
      temp=li[0];
      while(temp!=NULL)
       {
         for(i=0;i<r;i++)
           for(j=0;j<r;j++)
             status[i][j]=0;
         rpos=temp->row;
         cpos=temp->col;
         status[rpos][cpos]=1;
         temp=temp->next;
         if(dp[rpos][cpos]!=7)
           continue;
         recursion(dp,rpos,cpos,r,c,7,status);
       }    
         
       
   /*   c1=0;
      temp=li[0];
      while(temp!=NULL)
       {
         rpos=temp->row;
         cpos=temp->col;
         if(dp[rpos][cpos]==6)
          {
            rpos=temp->row;
            cpos=temp->col;
 //           printf("rpos = %d cpos = %d \n\n",rpos,cpos);
            if(rpos==0)
              i1=0;
            else
              i1=rpos-1;
            if(rpos==r-1)
              i2=r-1;
            else
              i2=rpos+1;
            if(cpos==0)
              j1=0;
            else
              j1=cpos-1;
            if(cpos==c-1)
              j2=c-1;
            else
              j2=cpos+1;
            for(i=i1;i<=i2;i++)
              for(j=j1;j<=j2;j++)
                if(i!=rpos||j!=cpos)
                 {
                   if(dp[i][j]==5)
                    {
                      rpos1=i;
                      cpos1=j;
                      if(rpos1==0)
                        i3-0;
                      else
                        i3=rpos1-1;
                      if(rpos1==r-1)
                        i4=r-1;
                      else
                        i4=rpos1+1;
                      if(cpos1==0)
                        j3=0;
                      else
                        j3=cpos1-1;
                      if(cpos1==c-1)
                        j4=c-1;
                      else
                        j4=cpos1+1;
                      for(l=i3;l<=i4;l++)
                        for(n=j3;n<=j4;n++)
                          if(l!=rpos1||n!=cpos1)
                             if(dp[l][n]==4)
                               splist=insert(splist,rpos,cpos,rpos1,cpos1);
                    }
                 }           
          }*/
//       }                      
                                       
      for(i=0;i<r;i++)
       {
         for(j=0;j<c;j++)
          if(dp[i][j]==9)
           {
            printf("YES\n");
            c1=1;
            break;
           }
         if(c1)
           break;
       }
      if(c1==0)
        printf("NO\n");
    }
   getch();
   return 0;
 }
            
            
                            
               
                 
                  
              
                    
         
    
