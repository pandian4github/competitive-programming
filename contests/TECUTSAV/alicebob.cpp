#include<stdio.h>
int main()
{
    int t,i,n;
    scanf("%d",&t);
    while(t--)
    {
      scanf("%d",&n);
      int arr[n],start[n];
      int count=0;
      for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
      if(arr[n-1]>1)
        start[n-1]=1;
      else
        start[n-1]=0;
      for(i=n-2;i>=0;i--)
        if(arr[i]==1)
          start[i]=1-start[i+1];
        else
          start[i]=1;
      if(start[0]==0)
        printf("Bob\n");
      else
        printf("Alice\n");
    }
 //   scanf("%d",&t);
    return 0;
}
