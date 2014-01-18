#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
#define max_len 100
#define scani(a) scanf("%d", &a);

int  first[max_len], second[max_len];
int d[max_len][max_len];

int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
	int t;

	int len1, len2;
	int i, j;
	scanf("%d", &t);
	while(t--)
	{
//		cin>>len1;
		scani(len1)
		for(int k=0;k<len1;k++)
			scani(first[k])
		//cin>>first[k];
		scani(len2)
		//c
		//in>>len2;
		for(int k=0;k<len2;k++)
			scani(second[k])
		//cin>>second[k];
		
		d[0][0] = 0;
        	for(i=0 ; i<=len1 ; i++) 
        		d[i][0] = i;
        	for(j=0 ; j<=len2 ; j++) 
        		d[0][j] = j;

        	for(i=1 ; i<=len1 ; i++)
        		for(j=1 ; j<=len2 ; j++)
            	{
//            		if(first[i-1]==second[j-1]) d[i][j]=d[i-1][j-1];
  //          		else
            		d[i][j] = minimum(d[i-1][j-1]+!(first[i-1]==second[j-1]) , minimum(d[i-1][j]+1, d[i][j-1]+1));
            	}
        //	for(i=0 ; i<=len1 ; i++)
       // 	{
        //		for(j=0 ; j<=len2 ; j++)
          //  		printf("%d ", d[i][j]);
            //	printf("\n");
        //	}
            	printf("%d\n", d[len1][len2]);
	}
	return 0;
}

