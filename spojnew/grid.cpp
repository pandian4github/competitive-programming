#include<stdio.h>
int main()
{
    int t,max,min,d1,d2,x1,y1,x2,y2,a,ans;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d %d %d %d %d",&a,&x1,&y1,&x2,&y2);
              if(y1==0)
                d1=x1;
              else
                if(x1==a)
                  d1=a+y1;
                else
                  if(y1==a)
                    d1=a+a+a-x1;
                  else
                    d1=a+a+a+a-y1;
              if(y2==0)
                d2=x2;
              else
                if(x2==a)
                  d2=a+y2;
                else
                  if(y2==a)
                    d2=a+a+a-x2;
                  else
                    d2=a+a+a+a-y2;
              max=(d1>d2)?d1:d2;
              min=(d1<d2)?d1:d2;
              ans=max-min;
              ans=(ans<(4*a-max+min))?ans:(4*a-max+min);
              printf("%d\n",ans);
    }
    return 0;
}
                    
                    
/*                      
              if(x1==0||x1==a)
                p1='x';
              else
                p1='y';
              if(x2==0||x2==a)
                p2='x';
              else
                p2='y';
              switch(p1)
              {
                        case 'x' :  if(x1==0)
                                       pos1=0;
                                    else
                                       pos1=1;
                        case 'y' :  if(y1==0)
                                       pos1=0;
                                    else
                                       pos1=1;
              }                                       
              switch(p2)
              {
                        case 'x' :  if(x2==0)
                                       pos2=0;
                                    else
                                       pos2=1;
                        case 'y' :  if(y2==0)
                                       pos2=0;
                                    else
                                       pos2=1;
              }                                       
              
*/
