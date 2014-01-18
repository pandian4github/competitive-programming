#include<stdlib.h>
#include<stdio.h>
struct post
 {
   char c[500];
   int top;
 };
typedef struct post* Stack;      
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
   int x,i,j,k,t;
   Stack S;
   S=(Stack)malloc(sizeof(struct post));
   S->top=-1;   
   scanf("%d",&t);
   char str[t][400];
   for(i=0;i<t;i++)
      scanf("%s",str[i]);
   for(i=0;i<t;i++)
    {  
     for(j=0;str[i][j]!='\0';j++)
       {
         if(str[i][j]=='('||str[i][j]=='+'||str[i][j]=='-'||str[i][j]=='*'||str[i][j]=='/'||str[i][j]=='^')
          Push(str[i][j],S);
         if(str[i][j]==')')
          {
           while(Top(S)!='(')
             printf("%c",Topandpop(S));
           Pop(S);
          }  
      if((int)str[i][j]>=97&&(int)str[i][j]<=122)
           printf("%c",str[i][j]);
       }
      printf("\n"); 
     }     
    return 0;
   }     
            
           
                   
          
               
