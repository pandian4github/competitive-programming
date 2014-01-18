#include<stdio.h>
#include<math.h>
char ch;
int Digits(long long int n)
 {
   int c=0;
   while(n!=0)
    {
      c++;
      n=n/10;
    } 
//   printf("%d\n",c);
//   scanf("%d",&w);
   return c;
 }    
long long int presum(int a)
 {
    switch(a)
      {
       case 0 : return 0;
       case 1 : return 5;
       case 2 : return -40;
       case 3 : return 410;
       case 4 : return -4090;
       case 5 : return 40910;
       case 6 : return -409090;
       case 7 : return 4090910;
       case 8 : return -40909090;
       case 9 : return 409090910;
       case 10 : return 4090909090;
       case 11 : return 40909090910;
       case 12 : return -409090909090;
       case 13 : return 4090909090910;
       case 14 : return -40909090909090;
       case 15 : return 409090909090910;
      }
       
 } 
long long int Spsum(long long int a,long long int b,int se)
 {
     long long int s=0;
     int i,o,p,f1,f2,d=0,l2;
     d=Digits(b);
     f1=a/pow(10,d-1);
     f2=b/pow(10,d-1);
     l2=b%10;
     if(a==0&&b==0)
      return 0;
     if(se==1)
      {
        s=0;
  l:     p=1;
       for(i=1;i<=b;i++)
        {
         s=s+p*i;
         p=p*-1;
        }
       return s;
     }    
        
     if(se%2==0)
      {
        if(d==1)
          {
            s=b*(b+1)/2; 
            return s;
          } 
        if((se-d)%2==0)
          {
            if(a==0)
             {
              s=s+45*pow(10,d-2)*f2;
              s=s-f2*(f2-1)/2*pow(10,d-1);
              s=s+Spsum(f2*pow(10,d-1),b,se);
             } 
            else
              if(f1!=f2)
               {
                s=s-(f2*(f2-1)/2-f1*(f1-1)/2)*pow(10,d-1);
                s=s+(d-1)%2*45*pow(10,d-2)*(f2-f1);
                s=s+Spsum(f2*pow(10,d-1),b,se);
               }
              else
               {
                s=s-f2*(b-a+1);
                s=s+Spsum(0,b-f2*pow(10,d-1),se);  
               } 
            }   
      
       else
         {
            if(a==0||f1!=f2)
             {
               s=s+(f2*(f2-1)/2-f1*(f1-1)/2)*pow(10,d-1);
               s=s+Spsum(f2*pow(10,d-1),b,se);
             }
            else
             {
                s=s+f1*(b-a+1);
                s=s+Spsum(0,b-f2*pow(10,d-1),se);
             }   
        } 
      }      

     else
      {  
         if(d==1)
           goto l;   
         if(l2%2==1)
          {
           if(a==0)
            {
             s=s+5*pow(10,d-2)*f2;
             s=s+Spsum(f2*pow(10,d-1),b,se);
            }
           else    
            if(f1!=f2)
            {
             s=s+5*pow(10,d-2)*(f2-f1);             
             s=s+Spsum(f2*pow(10,d-1),b,se);
            }
           else
              s=s+Spsum(0,b-f2*pow(10,d-1),se);
         }         
        
        else
         { 
           p=((se-d)%2==0)?-1:1;                         
           if(a==0)
            {
             s=s+5*pow(10,d-2)*f2;
             s=s+Spsum(f2*pow(10,d-1),b,se);
            }
           else  
           if(f1!=f2)
            {
             s=s+5*pow(10,d-2)*(f2-f1);
             s=s+Spsum(f2*pow(10,d-1),b,se);
            }
           else
            {
              s=s+p*f2;
              s=s+Spsum(0,b-f2*pow(10,d-1),se);
            }    
      }
  }  
    return s;      
  }          

int main()
 {
   long long int arr[40];
   int t,i;
   int d;
   long long int s=0,a;
   for(t=0;;t++)
    {
      scanf("%lld",&arr[t]);
      if(arr[t]==0)
       break;
    }    
   for(i=0;i<t;i++)
    {
      s=0;
      a=arr[i];
      d=Digits(a); 
      s=s+presum(d-1);
      if(d==11)
       s=s*-1;
/* printf("Calling Spsum func. . .\n");
printf("Spsum(%lld,%lld,%d). . .\n",(long long int)pow(10,d-1),(long long int)a,d);
ch=getchar(); */

      s=s+Spsum(pow(10,d-1),a,d);

      printf("%lld\n",s);
    }
   return 0;
 }      
 
 
