#include<stdio.h>
#include<map>
#include<fstream>
#include<stdlib.h>
using namespace std;

#define scani(a) scanf("%d", &a);
#define fori(a,b) for(i=a; i<=b ;i++)

int main()
{
    int t, sum, s, n, i;
    scani(t)
    char strs[] = "SABCDE";
    ofstream inp;
	ofstream oup;
	
	inp.open("gpainput1.txt");
	oup.open("gpaoutput1.txt");
	
    map<char, int> mp;
    mp['S'] = 10;
    mp['A'] = 9;
    mp['B'] = 8;
    mp['C'] = 7;
    mp['D'] = 6;
    mp['E'] = 5;
        
    while(t--)
    {
    	char ostr[100];
    	n = rand() % 15 + 1;
    	inp << n << "\n";
        //scani(n)
        int c[n];
        char g[n];
        fori(0, n-1)
        {
        	c[i] = rand() % 4 + 1;
        	g[i] = strs[rand() % 6];
        	inp << c[i] << " " << g[i] << "\n";
        }//    scanf("%d %c", &c[i], &g[i]);
        s = 0;
        sum = 0;
        fori(0, n-1)
            s += c[i];
        fori(0, n-1)
            sum += c[i] * mp[g[i]];
        sprintf(ostr, "%0.2lf", sum * 1.0 / s);
        oup << ostr << "\n";
     //   printf("%0.2lf\n", sum * 1.0 / s);
    }
    return 0;
}
