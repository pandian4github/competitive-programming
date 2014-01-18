#include<stdio.h>
int main()
 {
   int t,g,ch;
   long long int power[50];
   power[0]=1LL;
   int i;
   for(i=1;i<=50;i++)
     power[i]=power[i-1]*2LL;
   char str[2][16]={"mffmfmmffmmfmffm","fmmfmffmmffmfmmf"};
  // char str2[16]="fmmfmffmmffmfmmf";
   long long int n,start,mid,end; 
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d %lld",&g,&n);
      if(g<=5)
       {
         if(str[0][n-1LL]=='m')
           printf("Male\n");
         else
           printf("Female\n");
         continue;
       }  
      start=1LL;
      end=power[g-1];
      ch=0;
 //     printf("\nstart = %lld\nend = %lld\n",start,end);
      while(1)
       {
         if(end-start==15LL)
           break;
         mid=(start+end)/2LL;
         if(n<=mid)
            end=mid;
         else
           {
            ch=1-ch;
            start=mid+1LL;
           }
       }
    //  if(ch==0)
    //    {
          if(str[ch][n-start]=='m')
            printf("Male\n");
          else
            printf("Female\n");  
     //   }
    //  else
    //   {
    //     if(str2[n-start]=='m')
    //       printf("Male\n");
    //     else
    //       printf  
    }
   return 0;
 }      
          
         
