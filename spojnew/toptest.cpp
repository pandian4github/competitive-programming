#include<vector>
#include<iostream>
#include<conio.h>
using namespace std;
#include<vector>
#include<iostream>
using namespace std;
class BinaryCode
 {
   public : 
    vector<string> decode(string message)
    {
      int i,flag,len=message.length();
      cout<<"\nEntere function : message : "<<message<<"\n";
      vector<string> vec(2);
      string str1,str2,str3;
      str1=message;
      str2=message;
      str2[0]=48;
      flag=0;
      vec[0]=str1;
      cout<<"mess : "<<message<<"\n";
      cout<<"str1 : "<<str1<<"\n";
      cout<<"vec[0] : "<<vec[0]<<"\n";
      cout<<"0   "<<str2[0]<<"\n";
      for(i=1;i<message.length()-1;i++)
        {
          str2[i]=str1[i-1];
          str1[i]=(str1[i]-str2[i])+48;
          str1[i+1]=(str1[i+1]-str2[i])+48;
          cout<<i<<"   "<<str2[i]<<"\n";
          if(str2[i]>49)
           {
            flag=1;
            break;
           }
        }
      if(flag==0)
      {
        printf("falg is 0\n");
        str2[i]=str1[i];  
        if(str2[i]>49)
          flag=1;
      }    
      cout<<i<<"   "<<str2[i]<<"\n";
      cout<<"str2 : "<<str2<<"\n";
      str2[i+1]='\0'; 
      cout<<"flag : "<<flag<<"\n";       
      if(flag==1)
        vec[0]="NONE";
      else
        vec[0]=str2;
     // str2.resize(len);
      vec[0].assign(str2);  
      cout<<"vec[0] : "<<vec[0]<<"\n";
      cout<<"str2 lenght : "<<str2.length()<<"\n";
      for(i=0;i<len;i++)
        cout<<str2[i]<<"\n";
        //vec[0][i]=str2[i];
      cout<<"vec[0] : "<<vec[0]<<"\n";
      flag=0;      
      str1=message; 
      str3[0]=1;
      str1[0]-=str3[0];
      str1[1]-=str3[0];
      for(i=1;i<message.length()-1;i++)
        {
          str3[i]=str1[i-1];
          str1[i]=str1[i]-str3[i];
          str1[i+1]=str1[i+1]-str3[i];
          if(str3[i]>49)
           {
            flag=1;
            break;
           }
        }
      str3[i]=str1[i];  
      if(str3[i]>49)
        flag=1;            
      if(flag==1)
        vec[1]="NONE";
      else
        vec[1]=str3;
      cout<<"rsdgw";  
      cout<<"\n"<<vec[0]<<"\n"<<vec[1]<<"\n";  
      return vec;
    }
  };      
int main()
 {
    vector<string> vec;
    BinaryCode bc;
    string str;
    cin>>str;
    vec=bc.decode(str);
    cout<<vec.at(0)<<"\n"<<vec.at(1);
    getch();
    return 0;
 }         
          
          
