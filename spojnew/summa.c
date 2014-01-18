#include<stdio.h>
int main()
{
int i=31,j=1;
int numer=1,denom=1;
for(j=1;j<i;j++)
denom = denom*j;

for(i=31;i<=60;i++)
numer= numer*i;

printf("%d        %d",numer,denom);
}

