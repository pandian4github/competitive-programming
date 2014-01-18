#include<stdio.h>
//#include<math.h>
#include<string.h>
#include<stdlib.h>

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
	int t, i, j, k, n, m, p, j1, j2, min, max, temp, maxdraft, mindraft;
	string tempstr;
	scani(t)
	fork(1, t)
	{
		scani(n)
		scani(m)
		scani(p)
		string names[n];
		int shot[n], height[n];
		fori(0, n-1)
		{
			cin >> names[i];
			scani(shot[i])
			scani(height[i])
		}
		fori(0, n-1)
		{
			forj(i+1, n-1)
			{
				if(shot[j] > shot[i] || (shot[j] == shot[i] && height[j] > height[i]))
				{
					tempstr = names[i];
					names[i] = names[j];
					names[j] = tempstr;
					
					temp = shot[i];
					shot[i] = shot[j];
					shot[j] = temp;
					
					temp = height[i];
					height[i] = height[j];
					height[j] = temp;
				}
			}
		}
		
		map<int, string> mnames;
		//map<int, int> mshot;
		//map<int, int> mheight;
		map<int, int> mtime;
		
		fori(0, n-1)
		{
			mnames[i+1] = names[i];
			//mshot[i+1] = shot[i];
			//mheight[i+1] = height[i];
			mtime[i+1] = 0;
		}
		
		vector<int> Aplayers, Arem, Bplayers, Brem;
		for(i = 1; i < 2*p; i+=2)
			Aplayers.push_back(i);
		for(i = 2*p+1; i <= n; i+=2)
			Arem.push_back(i);
		
		for(i = 2; i <= 2*p; i+=2)
			Bplayers.push_back(i);
		for(i = 2*p+2; i <= n; i+=2)
			Brem.push_back(i);
		if(n != 2*p)
		fori(1, m)
		{
			max = 0;
			forj(0, Aplayers.size()-1)
				mtime[Aplayers.at(j)]++;
			forj(0, Aplayers.size()-1)
				if(mtime[Aplayers.at(j)] > max)
					max = mtime[Aplayers.at(j)];
			maxdraft = -1;
			forj(0, Aplayers.size()-1)
			{
				if(mtime[Aplayers.at(j)] == max)
				{
					if(Aplayers.at(j) > maxdraft)
					{
						maxdraft = Aplayers.at(j);
						j1 = j;
					}
				}
			}
			min = 1000000000;
			forj(0, Arem.size()-1)
				if(mtime[Arem.at(j)] < min)
					min = mtime[Arem.at(j)];
			mindraft = n+1;
			forj(0, Arem.size()-1)
			{
				if(mtime[Arem.at(j)] == min)
				{
					if(Arem.at(j) < mindraft)
					{
						mindraft = Arem.at(j);
						j2 = j;
					}
				}
			}
			Aplayers[j1] = mindraft;
			Arem[j2] = maxdraft;
			
			//For team B
			max = 0;
			forj(0, Bplayers.size()-1)
				mtime[Bplayers.at(j)]++;
			forj(0, Bplayers.size()-1)
				if(mtime[Bplayers.at(j)] > max)
				{
					max = mtime[Bplayers.at(j)];
				}
			maxdraft = -1;
			forj(0, Bplayers.size()-1)
			{
				if(mtime[Bplayers.at(j)] == max)
				{
					if(Bplayers.at(j) > maxdraft)
					{
						maxdraft = Bplayers.at(j);
						j1 = j;
					}
				}
			}
			min = 1000000000;
			forj(0, Brem.size()-1)
				if(mtime[Brem.at(j)] < min)
					min = mtime[Brem.at(j)];
			mindraft = n+1;
			forj(0, Brem.size()-1)
			{
				if(mtime[Brem.at(j)] == min)
				{
					if(Brem.at(j) < mindraft)
					{
						mindraft = Brem.at(j);
						j2 = j;
					}
				}
			}
			Bplayers[j1] = mindraft;
			Brem[j2] = maxdraft;
			
		}
		vector<string> vecstr;
		fori(0, Aplayers.size()-1)
			vecstr.push_back(mnames[Aplayers.at(i)]);
		fori(0, Bplayers.size()-1)
			vecstr.push_back(mnames[Bplayers.at(i)]);
		sort(vecstr.begin(), vecstr.end());
		printf("Case #%d:", k);
		fori(0, vecstr.size()-1)
			cout<<" "<<vecstr[i];
		printf("\n");
		
	}
	return 0;
}



