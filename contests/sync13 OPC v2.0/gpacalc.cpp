#include<stdio.h>
#include<map>
using namespace std;

#define scani(a) scanf("%d", &a);
#define fori(a,b) for(i=a; i<=b ;i++)

int main()
{
    int t, sum, s, n, i;
    scani(t)
    map<char, int> mp;
    mp['S'] = 10;
    mp['A'] = 9;
    mp['B'] = 8;
    mp['C'] = 7;
    mp['D'] = 6;
    mp['E'] = 5;
        
    while(t--)
    {
        scani(n)
        int c[n];
        char g[n];
        fori(0, n-1)
            scanf("%d %c", &c[i], &g[i]);
        s = 0;
        sum = 0;
        fori(0, n-1)
            s += c[i];
        fori(0, n-1)
            sum += c[i] * mp[g[i]];
        printf("%0.2lf\n", sum * 1.0 / s);
    }
    return 0;
}
