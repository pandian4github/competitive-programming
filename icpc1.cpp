#include<stdio.h>
//include<conio.h>
int main()
 {
   long long int a,b,count,j,temp;
   int dig[10];
   int t,k,c;
   int i,d;
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
     scanf("%lld%lld",&a,&b);
     count=0;
     for(j=a;j<=b;j++)
      {
        c=1;               
        for(k=0;k<10;k++)
          dig[k]=0;
        temp=j;  
        while(temp!=0)
         {
           d=temp%10;
           switch(d)
            {
              case 0 : dig[0]++;
                       break;  
              case 1 : dig[1]++;
                       break;
              case 2 : dig[2]++;
                       break;
              case 3 : dig[3]++;
                       break;
              case 4 : dig[4]++;
                       break;
              case 5 : dig[5]++;
                       break;
              case 6 : dig[6]++;
                       break;
              case 7 : dig[7]++;
                       break;
              case 8 : dig[8]++;
                       break;
              case 9 : dig[9]++;
                       break;
            }
           temp=temp/10; 
         }  
           for(k=0;k<10;k++)
             if(dig[k]>2)
              {
               c=0; 
               break;
              }
           if(c)
             count++;
        }
       printf("%d\n",count);
      }                       
              
                                                                                                    
   
  // getch();
   return 0;
 } 
