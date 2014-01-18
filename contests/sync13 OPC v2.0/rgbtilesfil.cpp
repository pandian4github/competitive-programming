#include<stdio.h>
//#include<math.h>
#include<string.h>
#include<stdlib.h>

#include<fstream>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanlli(a) scanf("%lld", &a);
#define scanc(c) scanf("%c",&c);
#define scans(s) scanf("%s", s);
#define mp(a,b) make_pair(a, b)
#define ll long long int
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define println printf("\n");
#define sz(v) v.size()
#define len(s) s.length()
#define max(a,b) (a > b) ? a : b
#define min(a,b) (a < b) ? a : b
#define ll(a) (long long int)(a)

int main()
{
	int t, i, j, k, n, m, sx, sy, ex, ey, a, b, x, y;
	scani(t)
	char strs[] = "RGBBBGBBRBRGBRBGRRGB";
	ofstream inp;
	ofstream oup;
	inp.open("rgbtilesinput1.txt");
	oup.open("rgbtilesoutput1.txt");
	while(t--)
	{
		//scani(n)
		//scani(m)
		
		n = rand() % 10;
		m = rand() % 10;
		if(n == 0)
			n = 34;
		if(m == 0)
			m = 23;
		
		inp << n << " " << m << " ";
		char mat[n][m];
		int count[n][m], visited[n][m];
		fori(0, n-1)
			forj(0, m-1)
				count[i][j] = visited[i][j] = 0;
		
		//scani(sx)
		//scani(sy)
		//scani(ex)
		//scani(ey)
		
		sx = rand() % n + 1;
		sy = rand() % m + 1;
		ex = rand() % n + 1;
		ey = rand() % m + 1;
		
		inp << sx << " " << sy << " " << ex << " " << ey << "\n";
		sx--;
		sy--;
		ex--;
		ey--;
		
		fori(0, n-1)
		{
			forj(0, m-1)
				mat[i][j] = strs[rand() % 20];
			mat[i][m] = '\0';
		}
		mat[sx][sy] = 'B';
		
		fori(0, n-1)
			inp << mat[i] << "\n";
		
	//	fori(0, n-1)
	//		scanf("%s", mat[i]);

		queue<int> qx;
		queue<int> qy;
		
		qx.push(sx);
		qy.push(sy);
		visited[sx][sy] = 1;
		
		fori(0, n-1)
			forj(0, m-1)
				if(mat[i][j] == 'G')
					count[i][j] = 1;
		
		while(!qx.empty())
		{
			x = qx.front();
			y = qy.front();
			qx.pop();
			qy.pop();
			
			if(x == ex && y == ey)
			{
				visited[x][y] = 1;
				break;
			}

			a = x - 1; b = y;
			if((a >= 0 && a < n && b >= 0 && b < m) && visited[a][b] == 0)
			{
				if(mat[a][b] == 'B')
				{
					visited[a][b] = 1;
					qx.push(a);
					qy.push(b);					
				}
				else
				{
					count[a][b]++;
					if(count[a][b] >= 2)
					{
						mat[a][b] = 'B';
						visited[a][b] = 1;
						qx.push(a);
						qy.push(b);
					}
				}
			}
			
			a = x + 1; b = y;
			if((a >= 0 && a < n && b >= 0 && b < m) && visited[a][b] == 0)
			{
				if(mat[a][b] == 'B')
				{
					visited[a][b] = 1;
					qx.push(a);
					qy.push(b);					
				}
				else
				{
					count[a][b]++;
					if(count[a][b] >= 2)
					{
						mat[a][b] = 'B';
						visited[a][b] = 1;
						qx.push(a);
						qy.push(b);
					}
				}
			}
			
			a = x ; b = y - 1;
			if((a >= 0 && a < n && b >= 0 && b < m) && visited[a][b] == 0)
			{
				if(mat[a][b] == 'B')
				{
					visited[a][b] = 1;
					qx.push(a);
					qy.push(b);					
				}
				else
				{
					count[a][b]++;
					if(count[a][b] >= 2)
					{
						mat[a][b] = 'B';
						visited[a][b] = 1;
						qx.push(a);
						qy.push(b);
					}
				}
			}
			
			a = x ; b = y + 1;
			if((a >= 0 && a < n && b >= 0 && b < m) && visited[a][b] == 0)
			{
				if(mat[a][b] == 'B')
				{
					visited[a][b] = 1;
					qx.push(a);
					qy.push(b);					
				}
				else
				{
					count[a][b]++;
					if(count[a][b] >= 2)
					{
						mat[a][b] = 'B';
						visited[a][b] = 1;
						qx.push(a);
						qy.push(b);
					}
				}
			}
			
		}
		if(visited[ex][ey] == 1)
			oup << "Yes\n";
		else
			oup << "No\n";
	}
	return 0;
}



