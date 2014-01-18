#include<iostream>
#include<fstream>
using namespace std;
int main()
 {
   ofstream oupfile;
   oupfile.open("input.txt");
   for(int i=1;i<=1000000;i++)
     oupfile<<i<<"\n";
   oupfile.close();
   return 0;
}
