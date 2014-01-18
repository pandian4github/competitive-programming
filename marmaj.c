#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
struct s
 {
  int no;
  struct s *link;
 };
void traverse(struct s* rider)
 {
  do
  {
   if(rider->no==0)
    printf("Maryam Win!!!\n");
   else
    if(rider->no==1)
      printf("Majid Win!!!\n");
   rider=rider->link;
  }
  while(rider!='\0');
 }  
    
struct s* add(struct s *m,int t)
 {
   struct s *ptr1;
   ptr1=(struct s*)malloc(sizeof(struct s));
   ptr1->no=t;
   m->link=ptr1;
   ptr1->link='\0';
   return ptr1;
 }  
int main()
 {
  int a[3],c=0;
  struct s *start,*ptr,*end;
  
  while(1)
   {
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    if(a[0]==0&&a[1]==0&&a[2]==0)
     break;
    else
     {
      c++;
      if(c==1)
        {
         ptr=(struct s *)malloc(sizeof(struct s));
         start=ptr;
         end=ptr;
        }
      if(a[0]+a[1]==a[2])
        end=add(end,0);
      else
       if(a[0]-a[1]==a[2]||a[1]-a[0]==a[2])
        end=add(end,1);
     }
    }
   traverse(start);
   return 0;
  }
     
           












