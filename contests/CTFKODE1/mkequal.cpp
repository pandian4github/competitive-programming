#include<stdio.h>
#include<fstream>
#include<math.h>
#include<stdlib.h>
using namespace std;

#define scani(a) scanf("%d",&a);
#define fori(a,b) for(i=a;i<=b;i++)
#define fork(a,b) for(k=a;k<=b;k++)
#define forj(a,b) for(j=a;j<=b;j++)

int main()
{
	int t, n, num, i, sum;
	ofstream inp;
	ofstream oup;
	inp.open("mkequalinp.txt");
	oup.open("mkequaloup.txt");
	scani(t)
	inp<<t<<"\n";
	while(t--)
	{
		sum = 0;
		n = rand()%98761;
		inp<<n<<"\n";
		fori(0, n-1)
		{
			num = rand() % 9094;
			inp<<num<<" ";
			sum = sum + num;
		}
		inp<<"\n";
		if(sum % n == 0)
			oup<<n<<"\n";
		else
			oup<<n-1<<"\n";
	}
	return 0;
}
