#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
       long long int n,diff,count=0;
       scanf("%lld",&n);
       scanf("%lld",&diff);
       long long int A[100005],i,j;
       memset(A,0,sizeof(A));
   for(i=0;i<n;i++)
    {
               scanf("%lld",&A[i]);
        }
       sort(A,A+n);
for(i=0,j=1;j<n;j++)
         {
                if((A[j]-A[i])==diff)
                {
                                 i++;
                                 count++;
                }
                else if((A[j]-A[i])>diff)
                            i++;
                        else ;

         }
    printf("%lld\n",count);
    //cin>>count;
 return 0;
}
