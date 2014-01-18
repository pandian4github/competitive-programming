#include<iostream>
#include<string.h>
using namespace std;
//#include<conio.h>
int main()
 {
   char a[1001];
   cin>>a;
   int str[26];
   int i;
   for(i=0;i<26;i++)
     str[i]=0;
   for(i=0;i<strlen(a);i++)
    {
      switch(a[i])
       {
         case 'a' : str[0]++;
                    break;
         case 'b' : str[1]++;
                    break;
         case 'c' : str[2]++;
                    break;
         case 'd' : str[3]++;
                    break;
         case 'e' : str[4]++;
                    break;
         case 'f' : str[5]++;
                    break;
         case 'g' : str[6]++;
                    break;
         case 'h' : str[7]++;
                    break;
         case 'i' : str[8]++;
                    break;
         case 'j' : str[9]++;
                    break;
         case 'k' : str[10]++;
                    break;
         case 'l' : str[11]++;
                    break;
         case 'm' : str[12]++;
                    break;
         case 'n' : str[13]++;
                    break;
         case 'o' : str[14]++;
                    break;
         case 'p' : str[15]++;
                    break;
         case 'q' : str[16]++;
                    break;
         case 'r' : str[17]++;
                    break;
         case 's' : str[18]++;
                    break;
         case 't' : str[19]++;
                    break;
         case 'u' : str[20]++;
                    break;
         case 'v' : str[21]++;
                    break;
         case 'w' : str[22]++;
                    break;
         case 'x' : str[23]++;
                    break;
         case 'y' : str[24]++;
                    break;
         case 'z' : str[25]++;
                    break;
       }
    }
    for(i=0;i<26;i++)
      if(str[i])
       cout<<(char)(i+97)<<" "<<str[i]<<endl;
 //  getch();
   return 0;
 } 
