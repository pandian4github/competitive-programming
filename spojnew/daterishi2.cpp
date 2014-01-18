#include<stdio.h>
struct indexes
{
       long int val;
       int pos;
};
/*void print(struct indexes s[],int n)
{
     int i;
     printf("\nval : pos\n");
     for(i=0;i<n;i++)
       printf("%d : %d  ",s[i].val,s[i].pos);
}*/
int binarysearch(struct indexes st[],int l,int r,long long int k)
{
    int m=(l+r)/2;
    if(k<st[l].val)
      return st[l].pos;
    if(k>st[r].val)
      return -1;
    if(st[m].val==k)
      return st[m].pos;
    else
     if(st[m].val<k)
     {
       if(st[m+1].val>=k)
         return st[m+1].pos;
       return binarysearch(st,m+1,r,k);
     }
     else
     {
       if(st[m-1].val<k)
         return st[m].pos;
       return binarysearch(st,l,m-1,k);
     }
}
int main()
{
    int t,n,i,j,lindex,rindex,l,r;
    long long int max,a,max1;
    long long int arr[100001];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              struct indexes lindexes[n+1];
              struct indexes rindexes[n+1];
              max=-1;
              j=0;
              for(i=0;i<n;i++)
              {
                scanf("%lld",&arr[i]);
                if(arr[i]>max)
                {
                  max=arr[i];
                  lindexes[j].val=max;
                  lindexes[j].pos=i;
                  j++;
                }
              }  
              max=-1;
              lindex=j;
              j=0;
       //       printf("lindex : %d\n",lindex);
//              print(lindexes,lindex);
              for(i=n-1;i>=0;i--)
              {
                if(arr[i]>max)
                {
                  max=arr[i];
                  rindexes[j].val=max;
                  rindexes[j].pos=i;
                  j++;
                }
              }  
              rindex=j;
  //            print(rindexes,rindex);
              max=-1;
             // printf("\nArray : ");
             // for(i=0;i<n;i++)
             //   printf(" %d  ",arr[i]);
            //  printf("\n");
              for(i=0;i<n;i++)
              {
            //    printf("\narr[%d] : %d\n",i,arr[i]);
                l=binarysearch(lindexes,0,lindex-1,arr[i]);
                r=binarysearch(rindexes,0,rindex-1,arr[i]);
        //        printf("l : %d r : %d\n",l,r);
            //    printf("l : %d  r : %d\n",l,r);
                if(l==-1&&r==-1)
                  continue;
                else
                  if(l==-1)
                    a=r-i;
                  else
                    if(r==-1)
                      a=i-l;
                    else
                      a=(i-l)>(r-i)?(i-l):(r-i);
            //    printf("curr max : %lld\n",a*arr[i]);
                max1=arr[i]*a;
                if(max<max1)
                  max=max1;
            //    printf("max : %lld\n",max);  
              }
              printf("%lld\n",max);
    }   
    return 0;
}   
              
