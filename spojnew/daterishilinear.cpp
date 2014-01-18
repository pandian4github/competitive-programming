#include<stdio.h>
int main()
{
    int t,n,left,right,i;
    long long int temp,max;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              long long int arr[n];
              for(i=0;i<n;i++)
                scanf("%lld",&arr[i]);
              left=0;
              right=n-1;
              max=0;
              while(left<right)
              {
               if(arr[left]<=arr[right])
                { 
                  temp=(right-left)*arr[left];
                  left++;
                }
               else
                {
                  temp=(right-left)*arr[right];
                  right--;
                }      
               if(temp>max)
                 max=temp;
              }
              printf("%lld\n",max);
    }
    return 0;
}
                    
