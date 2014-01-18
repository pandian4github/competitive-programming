#include<stdio.h>
//#include<conio.h>
long int a[50001],temp[50001],index[50001],index2[50001],answer[50001];
void Merge(int lpos,int rpos,int rtend)
 {
    int i,j,lfend,tmppos,l1=lpos,rtfirst=rpos,first=lpos,rem;
 //   printf("\nIn merge.. lpos = %d rpos = %d rtend = %d\n\n",lpos,rpos,rtend);
 //   printf("While entering.. a[] values :\n\n");
 //   for(i=lpos;i<=rtend;i++)
 //     printf("%d ",a[i]);
    lfend=rpos-1;
    tmppos=lpos;
    while(lpos<=lfend&&rpos<=rtend)
       {
         if(a[lpos]>a[rpos])
           {
             temp[tmppos]=a[lpos];
             index2[tmppos++]=index[lpos++];
             first=lpos;
           }
         else
           {
    //         printf("\nEntered else.. rpos = %d index[rpos] = %d\n",rpos,index[rpos]);
             answer[index[lpos]]=(index[rpos]<answer[index[lpos]])?index[rpos]:answer[index[lpos]];
             rem=index[rpos];
  //           printf("\nrem = %d\n",rem);
             for(j=first;j<=lfend;j++)
               if(answer[index[j]]>rem)
                 answer[index[j]]=rem;    
             temp[tmppos]=a[rpos];
             index2[tmppos++]=index[rpos++];
           }  
       }  
    while(lpos<=lfend)
       {
        temp[tmppos]=a[lpos];
      //  answer[index[lpos]]=(rtfirst<answer[index[lpos]])?rtfirst:answer[index[lpos]];
        index2[tmppos++]=index[lpos++];
       }
    while(rpos<=rtend)
       {
        temp[tmppos]=a[rpos];
        index2[tmppos++]=index[rpos++];
       }
    for(i=l1;i<=rtend;i++)
       {
        a[i]=temp[i];
        index[i]=index2[i];
      //    answer[index[i]]=rem;   
       }
  //  printf("\nrem = %d\n",rem);
  /*  printf("\na[] after sort : \n\n");   
    for(i=l1;i<=rtend;i++)
      printf("%d ",a[i]);
    printf("\nindex[] after sort : \n\n");   
    for(i=l1;i<=rtend;i++)
      printf("%d ",index[i]);
    printf("\nanswer[] after sort : \n\n");   
    for(i=l1;i<=rtend;i++)
      printf("%d ",answer[i]);
    printf("\n");*/ 
 }


void Msort(int left,int right)
 {
   int center;
   if(left<right)
    {
       center=(left+right)/2;
       Msort(left,center);
       Msort(center+1,right);
       Merge(left,center+1,right);
    }
 }
int main()
 {
   int count=0,m,n,x,y,i;
//   scanf("%d",&t);
 //  printf("%d\n",t);
   scanf("%d %d",&m,&n);
   for(i=0;i<m;i++)
    {
      scanf("%ld",&a[i]);
      index[i]=i;
    }
   for(i=0;i<m;i++)
     answer[i]=50001;
   Msort(0,m-1);
 //  for(i=0;i<m;i++)
 //    printf("%d ",answer[i]);
   for(i=0;i<n;i++)
    {
      scanf("%d %d",&x,&y);
      if(answer[x-1]<y-1)
        continue;
      count++;
    } 
   printf("%d\n",count);
  // getch();
   return 0;
 }     
