#include<iostream>
using namespace std;
//#include<conio.h>
//------------------------------------------------------------------------------------------
long int power(int x)
 {
   long int p=1;
   for(int i=1;i<=x;i++)
     p=p*10;
   return p;
 }   
//------------------------------------------------------------------------------------------
//void print(int arr[])
// {
//   cout<<"\n";
//   for(int i=0;i<10;i++)
//     cout<<arr[i]<<"  ";
//   cout<<"\n";
 //}   
//------------------------------------------------------------------------------------------
int nodig(long int x)
 {
  int cou=0;
  if(x==0)
    return 0;
  while(x>0)
   {
     cou++;
     x=x/10;
   } 
  return cou;
 }
//------------------------------------------------------------------------------------------
void zerocalc(int d,int arr[])
 {
   int p=1;
//   cout<<"\nEntered into zerocalc(). . .\n";
//   print(arr);
 //  getch();
// d--;
   while(d>0)
    {
     arr[0]+=p;
     p=p*10;
     d--;
    }
 }
//------------------------------------------------------------------------------------------
void zerocplx2(int d,int d1,long int a1,int arr[])
 {
   int i;
   long int p=1;
  // cout<<"\nEntered into zerocplx2(). . .\n";
  // print(arr);
   for(i=0;i<d1;i++)
   {
     arr[0]-=p;
     p=p*10;
   }
   arr[0]-=((a1+1)*(d-1-d1));
 }   
//------------------------------------------------------------------------------------------
void zerocplx1(int d,int d1,long int a1,int arr[])
 {
   int i;
   long int p=1;
  // cout<<"\nEntered into zerocplx1(). . .\n";
  // print(arr);
 //  getch();
   for(i=0;i<d1;i++)
   {
     arr[0]+=p;
     p=p*10;
   }
   arr[0]+=((a1+1)*(d-1-d1));
 }   
//------------------------------------------------------------------------------------------
void actualsum(int d,int arr[])
 {
 //   cout<<"\nEntered into actual sum. . . \n\n  d = "<<d<<"\n";
 //   print(arr);
    //getch();
    int i;
    switch(d)
     {
      case 1 : arr[0]+=0;
               for(i=1;i<=9;i++)
                 arr[i]+=1;
               break;
      case 2 : arr[0]+=9;
               for(i=1;i<=9;i++)
                 arr[i]+=19;
               break;  
      case 3 : arr[0]+=180;
               for(i=1;i<=9;i++)
                 arr[i]+=280;
               break;  
      case 4 : arr[0]+=2700;
               for(i=1;i<=9;i++)
                 arr[i]+=3700;
               break;  
      case 5 : arr[0]+=36000;
               for(i=1;i<=9;i++)
                 arr[i]+=46000;
               break;  
      case 6 : arr[0]+=450000;
               for(i=1;i<=9;i++)
                 arr[i]+=550000;
               break;  
      case 7 : arr[0]+=5400000;
               for(i=1;i<=9;i++)
                 arr[i]+=6400000;
               break;   
      case 8 : arr[0]+=63000000;
               for(i=1;i<=9;i++)
                 arr[i]+=73000000;
               break;  
     }
 }                 
//------------------------------------------------------------------------------------------
void recursum(long long int a,long long int b,int d,int arr[])
 {
   int i,j,d1,d2,f1,f2;
   int c1=0,c2=0;
   long int a1,b1;
 //  cout<<"\nEntered into recursum. . . \na = "<<a<<"  b = "<<b<<"  d = "<<d<<"\n";
 //  print(arr);
  // getch();
   if(d==1)
    {
     if(a==0)
      a++;
     for(i=a;i<=b;i++)
       arr[i]++;
     return;  
    }  
   a1=a%power(d-1);
   b1=b%power(d-1);
   f2=b/power(d-1);
   if(a==b)
    {
     while(a!=0)
      {
        arr[a%10]++;
        a=a/10;
      }    
     return ;
    }  
   if(b1==0)
    {
      arr[f2]++;
      arr[0]+=(d-1);
      b--;
      b1=b%power(d-1);
    } 
   f1=a/power(d-1);
   f2=b/power(d-1);
   d1=nodig(a1);
   d2=nodig(b1);
/*   if(a==0&&b==0)
    {
      arr[0]++;
      return ;
    }*/  
//---------------------------------------------------------------------------------
   if(a1==power(d1-1))
      c1=1;
   if(b1==power(d2)-1)
      c2=1;
//---------------------------------------------------------------------------------
//   cout<<"\n f1 = "<<f1<<" f2 = "<<f2<<" a1 = "<<a1<<" b1 = "<<b1<<" d1 = "<<d1<<" d2 = "<<d2<<" c1 = "<<c1<<" c2 = "<<c2<<"\n";
//---------------------------------------------------------------------------------
   if(f1==f2)
    {
        arr[f1]=arr[f1]+b-a+1;
        if(d1==d-1)
          recursum(a1,b1,d1,arr);
        else
         {
           if(a1==0)
             if(d2==d-1)
               zerocalc(d-1,arr);
             else  
               zerocplx1(d,d2,b1,arr);
           else
             if(d2==d-1)
              {
               zerocalc(d-1,arr);
               zerocplx2(d,d1,a1-1,arr);
              }
             else
              {
               zerocplx1(d,d2,b1,arr);
               zerocplx2(d,d1,a1-1,arr);
              } 
           if(d!=0)
            if(c1)
           {
             if(c2)
               for(i=d1;i<=d2;i++)
                 actualsum(i,arr);
             else
               if(d1==d2)
                 recursum(a1,b1,d1,arr);
               else
                {  
                  for(i=d1;i<d2;i++)
                    actualsum(i,arr);
                  recursum(power(d2-1),b1,d2,arr);
                } 
           }
           else
             if(c2)
                if(d1==d2)
                   recursum(a1,b1,d1,arr);
                else
                 {   
                   for(i=d1+1;i<=d2;i++)
                     actualsum(i,arr);
                   recursum(a1,power(d1)-1,d1,arr);
                 }
             else
              {
                for(i=d1+1;i<d2;i++)
                  actualsum(i,arr);
                if(d1==d2)
                  recursum(a1,b1,d1,arr);
                else
                 {  
                  recursum(a1,power(d1)-1,d1,arr);
                  recursum(power(d2-1),b1,d2,arr);
                 } 
              }
       }
    }
   else
    {
     for(i=f1+1;i<f2;i++)
      arr[i]+=power(d-1);
   //  cout<<"---------------------------------------------------------------------\n";
     for(i=1;i<f2-f1;i++)
     {
      zerocalc(d-1,arr);
      for(j=d-1;j>=1;j--)
        actualsum(j,arr);
     }
  //   cout<<"---------------------------------------------------------------------\n";
     if(a1==0)
      {
        arr[f1]+=power(d-1);
        zerocalc(d-1,arr);
        for(i=d-1;i>=1;i--)
          actualsum(i,arr);
        if(c2)
         {
          arr[f2]+=power(d-1);
          zerocalc(d-1,arr);
          for(i=d-1;i>=1;i--)
            actualsum(i,arr);
         }
        else
           if(d2==d-1)
           {
            arr[f2]+=b1+1;
            zerocalc(d-1,arr);
            for(i=1;i<d2;i++)
              actualsum(i,arr);
            recursum(power(d2-1),b1,d2,arr);
           }     
          else
           {
            arr[f2]+=b1+1;
            zerocplx1(d,d2,b1,arr);
            for(i=1;i<d2;i++)
              actualsum(i,arr);
            recursum(power(d2-1),b1,d2,arr);
           }    
      }
     else     
      if(d1==d-1)                                     
      {
        if(c1)
         {
           zerocalc(d-1,arr);
           zerocplx2(d,d1,a1-1,arr);
           arr[f1]+=power(d1)-a1;
           for(j=d1;j>=1;j--)
             actualsum(j,arr);
         }
        else
         {
           arr[f1]+=power(d1)-a1;
           recursum(a1,power(d1)-1,d1,arr);
         }  
        if(c2)
         {
           zerocalc(d-1,arr);
           arr[f2]+=power(d-1);
           for(j=1;j<=d2;j++)
             actualsum(j,arr);
         }
        else
         {
           arr[f2]+=b1+1;
           if(d2==d-1)
            {
              zerocalc(d2,arr);
              for(i=d2-1;i>=1;i--)
                actualsum(i,arr);
              recursum(power(d2-1),b1,d2,arr);
            }
           else
            {
              zerocplx1(d,d2,b1,arr);
              for(i=d2-1;i>=1;i--)
                actualsum(i,arr);                  
              recursum(power(d2-1),b1,d2,arr);
            } 
         } 
      }
     else
      {
         if(d2==d-1)
          {
           zerocalc(d-1,arr);
           zerocplx2(d,d1,a1-1,arr);
           zerocalc(d2,arr);
          }
         else
          {
           zerocalc(d-1,arr);
           zerocplx2(d,d1,a1-1,arr);
           zerocplx1(d,d2,b1,arr);
//           arr[0]+=b1-a1+1;
          }
        arr[f1]+=(f1+1)*power(d-1)-a;
        arr[f2]+=b1+1;
        if(c1)
          if(c2)
           {  
            for(i=d1;i<d;i++)
              actualsum(i,arr);
            for(i=1;i<=d2;i++)
              actualsum(i,arr);      
           }
          else
           {
             for(i=d1;i<d;i++)
               actualsum(i,arr);
             for(i=1;i<d2;i++)
               actualsum(i,arr);  
             recursum(power(d2-1),b1,d2,arr);
           }
        else
           if(c2)
            {
               for(i=1;i<=d2;i++)
                 actualsum(i,arr);      
               for(i=d1+1;i<d;i++)
                 actualsum(i,arr);
               recursum(a1,power(d1)-1,d1,arr);
            }
           else
            {
               for(i=d1+1;i<d;i++)
                 actualsum(i,arr);
               for(i=1;i<d2;i++)
                 actualsum(i,arr);
               recursum(power(d2-1),b1,d2,arr);                 
               recursum(a1,power(d1)-1,d1,arr);
            }
      }                                 
   }
  return ; 
 }             
int main()
 {
   long long int a,b,t;
   int d1,d2,i,c1,c2;
   int arr[10]={0};
   while(1)
    {
     for(i=0;i<10;i++)
       arr[i]=0;
     scanf("%lld%lld",&a,&b);
     if(a==0&&b==0)
       break;
     if(a==0)
      arr[a++]++;
     if(b==0)
      arr[b++]++;
     if(a>b)
      {
       t=a;
       a=b;
       b=t;
      }  
     c1=c2=0;  
     d1=nodig(a);
     d2=nodig(b);  
     if(a==power(d1-1))
       c1=1;
     if(b==power(d2)-1)
       c2=1;
     if(d1==d2)
       recursum(a,b,d1,arr);
     else  
      if(c1)
       if(c2)
         for(i=d1;i<=d2;i++)
           actualsum(i,arr);
       else
        {
         for(i=d1;i<d2;i++)
           actualsum(i,arr);
         recursum(power(d2-1),b,d2,arr);
        }
     else
       if(c2)
        {
         for(i=d1+1;i<=d2;i++)
           actualsum(i,arr);
         recursum(a,power(d1)-1,d1,arr);
        }
       else
        {
         for(i=d1+1;i<d2;i++)
           actualsum(i,arr);
         recursum(a,power(d1)-1,d1,arr);
         recursum(power(d2-1),b,d2,arr);
        }
     for(i=0;i<9;i++)
       printf("%d ",arr[i]);
     printf("%d\n",arr[9]);
    }
   return 0;
 }                    
