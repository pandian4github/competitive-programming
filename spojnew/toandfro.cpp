#include<iostream>
using namespace std;
int main()
 {
   int col,t,len,row;
   cin>>col;
   char str[200];
   int i,j;
   while(col!=0)
    {
      t=0;
      cin>>str;
//      strcpy(str,"ttyohhieneesiaabss");
      len=strlen(str);
      row=len/col;
      char mat[row][col];
      for(i=0;i<row;i++)
       {
         if(i%2==0)
            for(j=0;j<col;j++)
              mat[i][j]=str[t++];
         else
            for(j=col-1;j>=0;j--)
              mat[i][j]=str[t++];
       }
      for(i=0;i<col;i++)
        for(j=0;j<row;j++)
          cout<<mat[j][i];
      cin>>col;
    }
   return 0;
 }                         
