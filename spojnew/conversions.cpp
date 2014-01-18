#include<iostream>
using namespace std;
//#include<conio.h>
int main()
 {
   int i,n;
   cin>>n;
   double fin,fout;
   char str[2],strout[2];
   for(i=1;i<=n;i++)
    {
      cin>>fin;
      cin>>str;
      if(str[0]=='k')
       {
        fout=2.2046*fin;
        strcpy(strout,"lb");
       }
      else
       if(str[0]=='g')
        {
         fout=3.7854*fin;
         strcpy(strout,"l");
        } 
       else
        if(str[1]=='\0')
         {
           fout=0.2642*fin;
           strcpy(strout,"g");
         }
        else
         {
           fout=0.4536*fin;
           strcpy(strout,"kg");
         }
      printf("%d %0.4lf %s\n",i,fout,strout);
    }
//   getch();
   return 0;
 }           
           
         
