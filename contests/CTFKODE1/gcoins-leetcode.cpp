#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stdlib.h>
#include<assert.h>
using namespace std;
const int MAX_N = 100;
#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanc(c) scanf("%c",&c);
#define println printf("\n");
long long int max(long long int a, long long int b)
{
	if(a > b)
		return a;
	return b;
}
long long int min(long long int a, long long int b)
{
	if(a < b)
		return a;
	return b;
}
/*void printMoves(int P[][MAX_N], int A[], int N) {
  int sum1 = 0, sum2 = 0;
  int m = 0, n = N-1;
  bool myTurn = true;
  while (m <= n) {
    int P1 = P[m+1][n]; // If take A[m], opponent can get...
    int P2 = P[m][n-1]; // If take A[n]
    cout << (myTurn ? "I" : "You") << " take coin no. ";
    if (P1 <= P2) {
      cout << m+1 << " (" << A[m] << ")";
      m++;
    } else {
      cout << n+1 << " (" << A[n] << ")";
      n--;
    }
    cout << (myTurn ? ", " : ".\n");
    myTurn = !myTurn;
  }
  cout << "\nThe total amount of money (maximum) I get is " << P[0][N-1] << ".\n";
}
*/
void print(long long int arr[MAX_N][MAX_N], int n)
{
	int i, j;
	fori(0, n-1)
	{
		forj(0, n-1)
			printf("%lld ", arr[i][j]);
		printf("\n");
	}
}
long long int maxMoney(long long int A[], int N) {
  long long int P[MAX_N][MAX_N] = {0LL};
  long long int a, b, c;
  for (int i = 0; i < N; i++) {
    for (int m = 0, n = i; n < N; m++, n++) {
      assert(m < N); assert(n < N);
      a = ((m+2 <= N-1) ? P[m+2][n] : 0LL);
      b = ((m+1 <= N-1 && n-1 >= 0) ? P[m+1][n-1] : 0LL);
      c = ((n-2 >= 0) ? P[m][n-2] : 0LL);
      P[m][n] = max(A[m] + min(a,b),
                    A[n] + min(b,c));
    }
  }
//  printMoves(P, A, N);
  //print(P, N);
  return P[1][N-1];
}

int main()
{
	int t, i, n;
	scani(t)
	while(t--)
	{
		scani(n)
		long long int arr[n];
		fori(0, n-1)
			scani(arr[i])
		printf("%lld\n", maxMoney(arr, n));
	}
	return 0;
}
