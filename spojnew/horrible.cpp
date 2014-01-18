#include<stdio.h>
#include<vector>
using namespace std;
//#include<conio.h>
int main()
 {
   int t;
   int i,j,k;
   //cin>>t;
   scanf("%d",&t);
   int c,v,p,q,n;
   long long int var,sum;
   int ch;
   while(t--)
    {
 //     cin>>n>>c;
      scanf("%d %d",&n,&c);
      long long int arr[n+2];
      int index[n+2];
      vector<bool> vec(n+2);
      int indexcount=0;
      for(j=0;j<n+2;j++)
        {
         arr[j]=index[j]=0;
         vec[j]=false;
        }
      for(j=0;j<c;j++)
       {
         //cin>>ch;
         scanf("%d",&ch);
         if(ch==0)
          {
            scanf("%d %d %ld",&p,&q,&v);
            if(!vec[p])
              {
               index[indexcount++]=p;
               vec[p]=true;
              }
            arr[p]+=v;
            if(!vec[q+1])
             {
               index[indexcount++]=q+1;
               vec[q+1]=true;
             }
            arr[q+1]-=v;
        /*    printf("\nstart arr[] :\n");
            for(i=1;i<=n+1;i++)
              printf("%lld  ",start[i]);
            printf("\nend arr[] :\n");
            for(i=1;i<=n+1;i++)
              printf("%lld  ",end[i]);              
            printf("\nstartarr arr[] :\n");
            for(i=0;i<startcount;i++)
              printf("%lld  ",start[i]);
            printf("\nendarr arr[] :\n");
            for(i=0;i<endcount;i++)
              printf("%lld  ",end[i]);
          */    
          }
         else
          {
            sum=var=0;
            scanf("%d %d",&p,&q);
        /*    printf("\n\n");
            for(i=1;i<=n+1;i++)
              printf("%lld  ",arr[i]);
            printf("\n\n");
            for(i=0;i<indexcount;i++)
              printf("%d  ",index[i]);
            printf("\n\n");*/     
            for(i=0;i<indexcount;i++)
              if(index[i]<p)
                var=var+arr[index[i]];
       /*     for(i=0;i<endcount;i++)
              if(end[i]<=p)
                var=var+arr[start[i]];*/
         //   printf("var = %lld\n\n",var);    
            for(i=p;i<=q;i++)
              {
                var=var+arr[i];
                sum=sum+var;
           //     printf("\nvar = %lld\nsum = %lld\n\n",var,sum);
              }             
            printf("%ld\n",sum);  
          }
       }
    }
 //  getch();
   return 0;
 }               
