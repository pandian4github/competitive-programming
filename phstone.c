#include<stdio.h>
int maxpos(int a[],int w)
 {
   int i,p=0,max;
//   for(i=0;i<w;i++)
//    printf("%d\n\n",a[i]);
   max=a[0];
   for(i=1;i<w;i++)
     if(a[i]>max)
      {
       max=a[i];
       p=i;
     }
    return p;
  }    
   
int main()
 {
   int t,p,l;
   int h,w,i=0,j,k,s;
   scanf("%d",&t);
   int arr[t];
   int b[100][100];
   for(k=0;k<t;k++)
    {
      s=0;
      scanf("%d%d",&h,&w);
      for(l=0;l<h;l++)
       for(j=0;j<w;j++)
        scanf("%d",&b[l][j]);
//      printf("\n\n%d\n\n",s);
      p=maxpos(b[0],w);
      s=s+b[0][p];

//      printf("%d",b[0][p]);
//      printf("\n\nno problem\n\n");
      while(1)
      {
 //     printf("%d\n\n%d",s,i);
      i++;
      if(i>=h)
       break;
      else
        if(p==w-1)
         s=s+b[i][--p];
        else
         if(p==0)
          s=s+b[i][1];
          else 
          if(b[i][--p]>b[i][++p])
            {
              s=s+b[i][--p];
 //             printf("\n\n.\n\n");
            }         
           else
            {
             s=s+b[i][++p];
 //            printf("\n\n. . \n\n");
            } 
      }
      arr[k]=s;
    }            
    for(i=0;i<t;i++)
     printf("%d\n",arr[i]);
    return 0;
  }   
        
