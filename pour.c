#include<stdio.h>
void print(int a,int b,int c)
 {
   int cou=0;
   int flag=0;
   int max,min;
   max=(a>b)?a:b;
   min=(a<b)?a:b;
   while(max>c)
    {
      max=max-min;
      cou+=2;
      if(max==c)
       {
        printf("%d\n",cou+1);
        flag=1;
        break;
       } 
    }
   if(!flag)
    printf("-1\n");
 }      
   
int main()
 {
   int t;
   scanf("%d",&t);
   int A[t],B[t],C[t],i;
   int max,min,a,b,c;
   for(i=0;i<t;i++)
     scanf("%d%d%d",&A[i],&B[i],&C[i]);
   for(i=0;i<t;i++)
    {
      a=A[i];
      b=B[i];
      c=C[i];
      max=(a>b)?a:b;
      min=(a<b)?a:b;
      if(c>a&&c>b)
       {
        printf("-1\n");  
        continue;
       }
      else
       if(c==a||c==b)
        {
          printf("1\n");
          continue;
        }
       else
         if(max-min==c)
          {
           printf("3\n");
           continue;
          }
         else
          if((max-min-c)%2==0&&(max-min)>c)
           {
            print(max,min,c);
            continue;
           }
          else
           {
            printf("-1\n");
            continue;
           }
       }
      return 0;
    }       
                           
         
     
