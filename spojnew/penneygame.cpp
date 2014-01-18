#include<stdio.h>
#include<string.h>
int main()
 {
   int i,t,n;
   char str[41];
   char st[4];
   int arr[8];
   scanf("%d",&t);
   while(t--)
    {
      scanf("%d",&n);
      scanf("%s",str);
      printf("%d",n);
      for(i=0;i<8;i++)
        arr[i]=0;
      st[0]=str[0];
      st[1]=str[1];
      st[2]=str[2];
      st[3]='\0';
      if(strcmp(st,"TTT")==0)
        arr[0]++;
      if(strcmp(st,"TTH")==0)
        arr[1]++;
      if(strcmp(st,"THT")==0)
        arr[2]++;
      if(strcmp(st,"THH")==0)
        arr[3]++;
      if(strcmp(st,"HTT")==0)
        arr[4]++;
      if(strcmp(st,"HTH")==0)
        arr[5]++;
      if(strcmp(st,"HHT")==0)
        arr[6]++;
      if(strcmp(st,"HHH")==0)
        arr[7]++;
      for(i=3;i<40;i++)
       {
        st[0]=st[1];
        st[1]=st[2];
        st[2]=str[i];
        if(strcmp(st,"TTT")==0)
          arr[0]++;
        if(strcmp(st,"TTH")==0)
          arr[1]++;
        if(strcmp(st,"THT")==0)
          arr[2]++;
        if(strcmp(st,"THH")==0)
          arr[3]++;
        if(strcmp(st,"HTT")==0)
          arr[4]++;
        if(strcmp(st,"HTH")==0)
          arr[5]++;
        if(strcmp(st,"HHT")==0)
          arr[6]++;
        if(strcmp(st,"HHH")==0)
          arr[7]++;
       }
      for(i=0;i<8;i++)
        printf(" %d",arr[i]);
      printf("\n");
    }
   return 0;
 }       
           
                
