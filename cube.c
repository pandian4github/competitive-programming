#include<stdio.h>
int main()
 {
   int a,b,c,d,s,t1[5]={0,0,0,0,0},t2[5]={0,0,0,0,0},t3[5]={0,0,0,0,0},i;
   for(a=2;a<=100;a++)
    {
      i=0; 
   //  q=0;
     for(b=2;b<a;b++)
        {
            for(c=2;c<a;c++)
             {                                 
                for(d=2;d<a;d++)
                 {
                   s=(b*b*b)+(c*c*c)+(d*d*d);
                   if((a*a*a)==s)
                    {
                      if( ((t1[0]==b)&&(t2[0]==c)&&(t3[0]==d))||((t1[0]==b)&&(t2[0]==d)&&(t3[0]==c))||((t1[0]==c)&&(t2[0]==b)&&(t3[0]==d))||((t1[0]==c)&&(t2[0]==d)&&(t3[0]==b))||((t1[0]==d)&&(t2[0]==c)&&(t3[0]==b))||((t1[0]==d)&&(t2[0]==b)&&(t3[0]==c))||((t1[1]==b)&&(t2[1]==c)&&(t3[1]==d))||((t1[1]==b)&&(t2[1]==d)&&(t3[1]==c))||((t1[1]==c)&&(t2[1]==b)&&(t3[1]==d))||((t1[1]==c)&&(t2[1]==d)&&(t3[1]==b))||((t1[1]==d)&&(t2[1]==c)&&(t3[1]==b))||((t1[1]==d)&&(t2[1]==b)&&(t3[1]==c))||((t1[2]==b)&&(t2[2]==c)&&(t3[2]==d))||((t1[2]==b)&&(t2[2]==d)&&(t3[2]==c))||((t1[2]==c)&&(t2[2]==b)&&(t3[2]==d))||((t1[2]==c)&&(t2[2]==d)&&(t3[2]==b))||((t1[2]==d)&&(t2[2]==c)&&(t3[2]==b))||((t1[2]==d)&&(t2[2]==b)&&(t3[2]==c))||((t1[3]==b)&&(t2[3]==c)&&(t3[3]==d))||((t1[3]==b)&&(t2[3]==d)&&(t3[3]==c))||((t1[3]==c)&&(t2[3]==b)&&(t3[3]==d))||((t1[3]==c)&&(t2[3]==d)&&(t3[3]==b))||((t1[3]==d)&&(t2[3]==c)&&(t3[3]==b))||((t1[3]==d)&&(t2[3]==b)&&(t3[3]==c))||((t1[4]==b)&&(t2[4]==c)&&(t3[4]==d))||((t1[4]==b)&&(t2[4]==d)&&(t3[4]==c))||((t1[4]==c)&&(t2[4]==b)&&(t3[4]==d))||((t1[4]==c)&&(t2[4]==d)&&(t3[4]==b))||((t1[4]==d)&&(t2[4]==c)&&(t3[4]==b))||((t1[4]==d)&&(t2[4]==b)&&(t3[4]==c)) )
                         break;
                      else
                       { 
                         printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                         t1[i]=b;
                         t2[i]=c;
                         t3[i]=d;
                         i++;
      //                   q=1;
                         break;
                       } 
                   }
                 }  
             }         
        }         
      }
      return 0;
    }          