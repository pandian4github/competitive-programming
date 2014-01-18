#include<stdlib.h>
#include<stdio.h>
int main()
 {
   int t,j,max,i,l,c1=0,c2=0,cou=0;
   scanf("%d",&t);
   int a[t];
   char *str,c;
   
   str=(char*)malloc(sizeof(char));
   for(i=0;i<t;i++)
    {
      l=0;
      scanf("%c",(str+l));
  // printf("no pro\n");
  // scanf("%c",&c);
      while(1)
       {
         if((int)(str[l])>=97&&(int)c<=122||(int)c==32)
          {
            str[l]=c;
            l++;
          }
         else
          break;

         scanf("%c",(str+l));
       }
      str[l]='\0';
      cou=0;
      c1=0;
      c1=0;
      max=0;
      j=0;
      while(1)
       {
        c1=0;
        for(;str[j]!=' '||str[j]!='\0';j++)
         c1++;
        if(str[j]=='\0')
         break;
        for(j++;str[j]!=' '||str[j]!='\0';j++)
         c2++;
        if(str[j]=='\0')
         break;
        if(c1==c2)
         cou+=2;
        else
         {  
          if(cou>max)
            max=cou;
          cou=1;
         }   
        if(str[j]==' ')
         j++; 
       }   
     a[i]=max;
    }
    for(i=0;i<t;i++)
     printf("%d\n",a[i]);
    return 0;
   }       
        
       
       
       
       
       
             
