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
using namespace std;

#define fori(a,b) for(i = a; i <= b; i++)
#define forj(a,b) for(j = a; j <= b; j++)
#define fork(a,b) for(k = a; k <= b; k++)
#define scani(a) scanf("%d",&a);
#define scanc(c) scanf("%c",&c);
#define println printf("\n");

int main()
{
	int t, dgame, ngame, dtie, ntie, i, len, nstate, dstate, finish;
	char win;
	bool tie;
	string str;
	//char str[100000];
	scani(t)
	char ch = getchar();
	while(t--)
	{
		getline(cin, str);
		//scanf("%[^\n]s", str);
		//cout << str <<"\n";
		len = str.length();
		//len = strlen(str);
		ngame = dgame = 0;
		nstate = dstate = 0;
		dtie = ntie = 0;
		tie = false;
		finish = 0;
		//printf("len : %d\n", len);
		fori(0, len-1)
		{
			if(finish == 1)
				continue;
		//	printf(" ::%c:: dgame : %d ngame : %d dstate : %d nstate : %d dtie : %d ntie : %d\n", str[i], dgame, ngame, dstate, nstate, dtie, ntie);
			if(tie == true)
			{
				if(str[i] == 'D')
					dtie++;
				else
					if(str[i] == 'N')
						ntie++;
					else
						continue;
				if(dtie >= 7 && (dtie - ntie) >= 2)
				{
					win = 'd';
					dgame++;
					finish = 1;//break;
				}
				else
					if(ntie >= 7 && (ntie - dtie) >= 2)
					{
						win = 'n';
						ngame++;
						finish = 1;//break;
					}
					else
						continue;
			}
			if(str[i] == 'D')
			{
				if(dstate == 0)
					dstate = 15;
				else
					if(dstate == 15)
						dstate = 30;
					else
						if(dstate == 30)
							dstate = 40;	
						else
							if(dstate == 40)
							{
								if(nstate <= 30)
								{
									dgame++;
									dstate = nstate = 0;
								}
								else
									if(nstate == 40)
										dstate = 50;
									else
										if(nstate == 50)
											nstate = 40;
										
							}
							else
							{
								dgame++;
								dstate = nstate = 0;
							}
			}
			else
			if(str[i] == 'N')
			{
				if(nstate == 0)
					nstate = 15;
				else
					if(nstate == 15)
						nstate = 30;
					else
						if(nstate == 30)
							nstate = 40;
						else
							if(nstate == 40)
							{
								if(dstate <= 30)
								{
									ngame++;
									nstate = dstate = 0;
								}
								else
									if(dstate == 40)
										nstate = 50;
									else
										if(dstate == 50)
											dstate = 40;
							}
							else
							{
								ngame++;
								nstate = dstate = 0;
							}
			}
			else
				continue;
			if(dgame == 6 && ngame == 6)
				tie = true;
			else
			{
				if(dgame >= 6 && (dgame - ngame) >= 2)
				{
					win = 'd';
					finish = 1;
					//break;
				}
				else
					if(ngame >= 6 && (ngame - dgame) >= 2)
					{
						win = 'n';
						finish = 1;
						//break;
					}
					else
						continue;
			}
		}
		if(win == 'd')
		{
			if(tie == false)
				printf("D %d\nN %d\n", dgame, ngame);
			else
				printf("D %d (%d-%d)\nN %d\n", dgame, dtie, ntie, ngame);
		}
		else
		{
			if(tie == false)
				printf("N %d\nD %d\n", ngame, dgame);
			else
				printf("N %d (%d-%d)\nD %d\n", ngame, ntie, dtie, dgame);			
		}
		printf("\n");
	}
	return 0;
}
