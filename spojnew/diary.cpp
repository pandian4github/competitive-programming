#include<iostream>
using namespace std;
#include<string.h>
main()
 {
   int t;
   int arr[26],arr1[26],i,len,flag,dif,j;
   scanf("%d",&t);
   while(t--)
    {
      fflush(stdin);
      char str[10001],ch;
      cin.getline(str,1001,'\n');
//      cout<<str<<"\n";
      len=strlen(str);
      for(i=0;i<26;i++)
        arr[i]=0;
      for(i=0;i<len;i++)
         if(str[i]!=' ')
           arr[str[i]-65]++;
 //     for(i=0;i<26;i++)
   //     printf("%d  ",arr[i]);     
      int max=arr[0];
      int pos=0;
      flag=0;
      for(i=1;i<26;i++)
       if(arr[i]>max)
        {
         flag=0;
         max=arr[i];
         pos=i;
        }
       else
        if(arr[i]==max)
          flag=1;
      if(flag==1)
       {
        printf("NOT POSSIBLE\n");
        continue; 
       }         
      if(pos==4)
       {
        printf("0 %s\n",str);
        continue;
       }
      if(pos>4)
        dif=pos-4;
      else
        dif=22+pos;
      for(i=0;i<26;i++)
       {
         arr1[i]=i-dif;  
         if(arr1[i]<0)
           arr1[i]=arr1[i]+26;
       }   
  //    printf("\n");    
  //    for(i=0;i<26;i++)
  //      printf("%d  ",arr1[i]);
//      printf("\n");    
      printf("%d ",dif);
      for(i=0;i<len;i++)
       if(str[i]!=' ')
         printf("%c",arr1[str[i]-65]+65);
       else 
         printf(" ");  
      printf("\n");
    }
   return 0;
 }    
               
