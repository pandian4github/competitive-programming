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
    int n,i,j,k,t;
    ofstream inp;
    ofstream oup;
    inp.open("gcoinsinp.txt");
    oup.open("gcoinsoup.txt");
    scani(t)
    inp<<t<<"\n";
    while(t--)
    {
	//scani(n)
	n = 100;
	inp<<n<<"\n";
   	long long int arr[n];
    	fori(0,n-1)
    	{
    		arr[i] = rand()%987654LL;
		inp<<arr[i]<<" "; 
    	}
    	inp<<"\n";
      	//scani(arr[i])
    	long long int x[n+1][n+1], y[n+1][n+1], a, b;
    	fori(0,n-1)
    	{
      		x[i][i]=arr[i];
      		y[i][i]=0LL;
      		//steps[i][i]=i;
    	}
    	fori(2,n)
	    {
	    	forj(0,n-i)
      		{
        		k = j+i-1;
        		a = arr[j]+y[j+1][k];
        		b = arr[k]+y[j][k-1];
        		if(a>=b)
        		{
          			x[j][k] = a;
          			y[j][k] = x[j+1][k];
          			//steps[j][k] = j;
        		}
        		else
        		{
          			x[j][k] = b;
          			y[j][k] = x[j][k-1];
          			//steps[j][k] = k;
        		}
      		}
    	}
    	oup<<x[0][n-1]<<"\n";
		//printf("%lld\n",x[0][n-1]);
    }
	/*printf("Maximum obtainable by x is %d and by y is : %d\n",x[0][n-1], y[0][n-1]);
    printf("The sequence of steps are :\n");
    char players[2]={'x','y'};
    int cur = 0;
    int l = 0, r = n-1;
    while(l <= r)
    {
      printf("%c chooses %d (%d)\n",players[cur],arr[steps[l][r]],steps[l][r]);
      cur = 1 - cur;
      if(steps[l][r] == l)
        l++;
      else
        r--;
    }*/
    return 0;
}
