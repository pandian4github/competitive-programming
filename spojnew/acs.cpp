#include<iostream>
//#include<conio.h>
using namespace std;
#include<stdio.h>
struct roww
 {
   int ind;
 }srow[1234];
struct coll
 {
   int ind;
 }scol[5678]; 
int recur(int z[],int pre,int key)
 {
   if(z[pre]==key)
     return pre;
   return recur(z,z[pre]-1,key);
 }          
int row[1235],col[5679];
int main()
 {
   int i,j,x,y,quo,rem,x1,y1,cc,rr;
   char str[10];
   for(i=0;i<1234;i++)
    {
     row[i]=i+1;
     srow[i].ind=i+1;
    } 
   for(i=0;i<5678;i++)
    {
     col[i]=i+1;  
     scol[i].ind=i+1;
    } 

   long int k=1,t,num;
   while((scanf("%s",str))!=EOF)
    {
//      cin>>str; 
      switch(str[0])
       {
         case 'R' : cin>>x>>y;
                    t=row[x-1];
                    row[x-1]=row[y-1];
                    row[y-1]=t;
  //                  t=srow[srow[x-1].ind-1].ind;
  //                  srow[srow[x-1].ind-1].ind=srow[srow[y-1].ind-1].ind;
  //                  srow[srow[y-1].ind-1].ind=t;                   
                    break; 
         case 'C' : cin>>x>>y;
                    t=col[x-1];
                    col[x-1]=col[y-1];
                    col[y-1]=t;
  //                  t=scol[scol[x-1].ind-1].ind;
  //                  scol[scol[x-1].ind-1].ind=scol[scol[y-1].ind-1].ind;
  //                  scol[scol[y-1].ind-1].ind=t;
                    break;
         case 'Q' : cin>>x>>y;
                    x1=row[x-1];
                    y1=col[y-1];
                    cout<<(x1-1)*5678+y1<<"\n";
                    break;
         case 'W' : cin>>num;                        
                    quo=(num-1)/5678;
    //                rr=srow[quo].ind;
                    rr=recur(row,quo,quo+1);
                    rem=(num-1)%5678;
    //                cc=scol[rem].ind;
                    cc=recur(col,rem,rem+1);
                    cout<<rr+1<<" "<<cc+1<<endl;
                    break;                            
       }
    }
//   getch();
   return 0; 
 }               
              
