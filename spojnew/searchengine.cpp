#include<iostream>
using namespace std;
#include<conio.h>
#define FILES 4
//#include<fstream.h>
class hash
 {
   public :
     class listrecord
      {
       public :
       int doc;
       listrecord* next;
       listrecord(int d)
        {
         doc=d;
        } 
      }*l; 
   hash* h[26];
   hash();
   void display();
   void Insert(int d);    
 };     
hash::hash()
 {
   l=NULL;
   int i;
   for(i=0;i<26;i++)
     h[i]=NULL;
 }    
void hash::display()
 {
   listrecord* temp=l;
   cout<<"\n\n";
   while(temp!=NULL)
     {
      cout<<"  "<<temp->doc;
      temp=temp->next;
     } 
   cout<<"\n\n";
 }     
void hash::Insert(int d)
 {
   listrecord* temp=l;
   listrecord* newnode;
   if(l==NULL)
    {
     l=new listrecord(d);
     l->next=NULL;
    }
   else 
    {
     while(1)
     {
      if(temp->next==NULL)
       break;
      temp=temp->next;
     } 
     newnode=new listrecord(d);
     temp->next=newnode;
     newnode->next=NULL;
    } 
 }    
int main()
 {
   FILE * pfile;
   char arr[50][20];
   int k;
   for(k=0;k<50;k++)
    {
      
   pfile=fopen("file1.txt","w");
   hash* head;
   head=new hash;
   char c,str[30];
   int i,len,ic,ic1,j;
//   fstream myfile;
//   myfile.open("abc.txt");
//   cout<<"Enter a string. . ";
//   cin>>str;
//   len=strlen(str);
   hash* temp=head;
   hash* temp1;
//   myfile.close();
   char files[FILES][500];
   cout<<"\nEnter the values of the files. . .\n\n";
   for(j=0;j<FILES;j++)
    {
      cout<<" File  "<<j+1<<"  :  ";
      gets(files[j]);
    }  
   
//   for(i=0;i<FILES;i++)
//      cout<<"\n"<<files[i]<<"\n";
   for(j=0;j<FILES;j++)
    {
     temp=head;
     len=strlen(files[j]);
//     cout<<"\nlen = "<<len<<"\n";
     for(i=0;i<len;i++)
      {
        c=files[j][i];
        ic=(int)c;
        if(!((ic>=65&&ic<=90)||(ic>=97&&ic<=122)))
         {
//           cout<<"Entered ! !\n";
           temp->Insert(j+1);
           temp=head;
           continue;
         }  
        if(ic>=65&&ic<=90)
          ic=ic-65;
        else  
          ic=ic-97;  
        if(temp->h[ic]==NULL)
          {
           temp->h[ic]=new hash;
           temp=temp->h[ic];
          }
        else
          temp=temp->h[ic];    
      }
     ic1=(int)files[j][len-1]; 
     if((ic1>=65&&ic1<=90)||(ic1>=97&&ic1<=122)) 
       temp->Insert(j+1);
    }    
//   temp->Insert("doc1");
   cout<<"\nEnter a string to search. . .";
   cin>>str;
   len=strlen(str);
   temp1=temp;
   temp=head;
      
   for(i=0;i<len;i++)
    {
      c=str[i];
      if((int)c>=65&&(int)c<=90)
        ic=(int)c-65;
      else
        ic=(int)c-97;
      temp=temp->h[ic];
    }
   temp->display();        
   getch(); 
   return 0; 
 }   

       
