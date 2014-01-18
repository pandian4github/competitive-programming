#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,conind=0,vowind=0,vind,cind,i,j,tind=1;
    char vowels[200],consonants[200],ansvow[200],anscon[200];
    char alp[30]="AJSBKTCLUDMVENWFOXGPYHQZIR";
    for(i=0;i<26;i++)
    {
       if(alp[i]=='A' || alp[i]=='E' || alp[i]=='I' || alp[i]=='O' || alp[i]=='U')
       {
         for(j=0;j<21;j++)
           vowels[vowind++]=alp[i];
       }
       else
       {
         for(j=0;j<5;j++)
           consonants[conind++]=alp[i];
       }
    }
    scanf("%d",&t);
    while(t--)
    {
      printf("Case %d: ",tind++);
      vind=0;
      cind=0;
      scanf("%d",&n);
      for(i=0;i<n;i++)
        if(i%2==0)
          ansvow[vind]=vowels[vind++];
        else
          anscon[cind]=consonants[cind++];
   //   printf("before sorting . . .\n");
   //   for(i=0;i<cind;i++)
   //     printf("%c  ",anscon[i]);    
      sort(ansvow,ansvow+vind);
      sort(anscon,anscon+cind);
    //  for(i=0;i<cind;i++)
    //    for(j=0;j<cind;j++)
          
   //   printf("after sorting . . .\n");
   //   for(i=0;i<cind;i++)
   //     printf("%c  ",anscon[i]);    
      vind=0;
      cind=0;
      for(i=0;i<n;i++)
        if(i%2==0)
          printf("%c",ansvow[vind++]);
        else
          printf("%c",anscon[cind++]);    
      printf("\n");
    }
    return 0;
}
      
