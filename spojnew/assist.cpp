#include<iostream>
#include<list>
//#include<conio.h>
using namespace std;
int main()
 {
   list<int> l;
   int ans[3001];
   int ind=1,n,t;
   list<int>::iterator it;
   int i,val,curpos,flag=1;
   for(i=5;i<34000;)
    {
     l.push_back(i);
     if(flag)
      i+=2;
     else 
      i+=4;
     flag=flag^1;
    }
/*   printf("\n"); 
   for(i=0,it=l.begin();i<15;++it,i++)
     printf("%d  ",*it); 
   printf("\n");*/ 
   ans[ind++]=2;
   ans[ind++]=3;
   while(!l.empty())
    {
      it=l.begin();
      curpos=0;
      ans[ind++]=*it;
      val=*it;
      it=l.erase(it);
     // printf("size : %d ans : %d\n",l.size(),val);
      if(l.size()<val)
       {
        // printf("enterd!");
         it=l.end();
        // printf("end : %d\n",*it);
         for(it=l.begin();it!=l.end();advance(it,1))
          {
         //  printf("%d\n",*it);
           if(*it==34633)
             break;
          // getch();
           ans[ind++]=*it;
           if(ind==3001)
             break;
          }
         break;  
       }
 //     getch();
      while(1)
       {
   //     printf("curpsos : %d size : %d\n",curpos,l.size());
//        getch();
        if(l.size()-curpos<val)
          break;
        advance(it,val-1);
   //     printf("removed : %d\n\n",*it);
        it=l.erase(it);
        curpos=curpos+val-1;
       }
    }
   while(1)
    {
     scanf("%d",&n);
     if(n==0)
       break;
     printf("%d\n",ans[n]);
    }
   return 0;
 }    

//5 7   11 13   17 19    23 25    29 31    35 37 
