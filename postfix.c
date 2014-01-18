#include<stdlib.h>
#include<stdio.h>
struct post
 {
   char *c;
   int top;
 };
typedef struct post* Stack;      
void Makeempty(Stack S)
 {
   S->top=-1;
 }
void Push(char x,Stack S)
 {
     S->c[++S->top]=x;
 }
char Top(Stack S)
 {
   return S->c[S->top];
 }
char Topandpop(Stack S)
 {
   return S->c[S->top--];
 }
void Pop(Stack S)
 {
  S->top--;
 }
 
 
  
      
int main()
 {
   int i,j,k,t;
   char s[500];
   Stack S;
   S=(Stack)malloc(sizeof(struct post));
   Makeempty(S);
   scanf("%d",&t);
   char str[t][400];
   for(i=0;i<t;i++)
    {
      k=0;
      scanf("%s",s);
      for(j=0;s[j]!='\0';j++)
       {
 
         if(s[j]=='(')
          Push('(',S);
         while(s[j]=='+'||s[j]=='-')
          {
            str[i][k]=Topandpop(S);
            k++;
            if(S->top==-1)
             break;
          }                            

         while(s[j]=='*'||s[j]=='/')
            if(Top(S)=='*'||Top(S)=='/'||Top(S)=='^')
             {
               str[i][k]=Topandpop(S);
               k++;
             }
            else
              Push(s[j],S);           
         if(s[j]==')')
          {
           while(Top(S)!='(')
            {
             str[i][k]=Topandpop(S);
             k++;
            } 
           Pop(S);
          }  
          
         if(s[j]=='^')
           Push(s[j],S);
  // scanf("%d",&i);

         if((int)s[j]>=97&&(int)s[j]<=122)
          {
   //       scanf("%d",&i);
     scanf("%d",&i);
   
            str[i][k]=s[j];
            
            k++;
          }    
       }
    
       while(S->top!=-1)
        {
          str[i][k]=Topandpop(S);
          k++;
     
         }
        str[i][k]='\0';
     }
       
     for(i=0;i<t;i++)
        puts(str[i]);
   
      return 0;
   }     
            
           
                   
          
               
