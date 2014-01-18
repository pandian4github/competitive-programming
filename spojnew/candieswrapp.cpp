#include<stdio.h>
#include<fstream>
using namespace std;
int main()
 {
   int i,j,t,r,c,count;
   ofstream oupfile;
   oupfile.open("output.txt");
   scanf("%d",&t);
   while(t--)
    {
      count=0;
      scanf("%d %d",&r,&c);
      char arr[r][c];
      for(i=0;i<r;i++)
        scanf("%s",arr[i]);
      for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(arr[i][j]=='<')
               {
                if(j>=2)
                 if(arr[i][j-1]=='o'&&arr[i][j-2]=='>')
                   count++;
                }
             else
               if(arr[i][j]=='^')
                {
                  if(i>=2)
                    if(arr[i-1][j]=='o'&&arr[i-2][j]=='v')
                      count++;
                }
       oupfile<<count<<"\n";
       //printf("%d\n",count);
    }
   return 0;
 }            
