#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define scani(a) scanf("%d",&a);
#define fori(a, b) for(i = a; i <= b; i++)
#define ll(a) (long long int)(a)
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k, i;
    scani(n)
    scani(k)
    int arr[n];
    long long int min, uf, ufn;
    fori(0, n-1)
        scani(arr[i])
    sort(arr, arr+n);
    long long int sum[n];
    sum[0] = ll(arr[0]);
    fori(1, n-1)
        sum[i] = ll(arr[i]) + sum[i-1];
    fori(0, n-1)
    	printf("%lld ", sum[i]);
    printf("\n");
    uf = 0LL;
    fori(0, k-2)
        uf += (sum[k-1] - sum[i]) - ll(arr[i]) * ll(k-i-1);
    min = uf;
    printf("uf : %lld\n", uf);
    fori(1, n-k)
    {
        ufn = uf - ((sum[i-1+k-1] - sum[i-1]) - ll(arr[i-1]) * ll(k-1)) + (ll(k-1) * ll(arr[i+k-1]) - (sum[i+k-2] - sum[i-1]));
        if(ufn < min)
            min = ufn;
        uf = ufn;
    }
    printf("%lld\n", min);
    return 0;
}

