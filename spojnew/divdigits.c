#include<stdio.h>
#include<string.h>
int divide(char str[],int x)
 {
   int i,p=0,len;
   char str1[250];
   len=strlen(str);
   int prev=0,val;
   for(i=0;i<len;i++)
    {
      val=prev*10+str[i]-48;
      str1[p++]=(val/x)+48;
      prev=val%x;
    }
   if(prev!=0)
     return 0;
   str1[p]='\0';
   strcpy(str,str1);
   return 1;
 }              
int main() 
 {
   char str[250],str2[250],str3[250],str7[250],str8[250];
   int arr[10],i,count,len1,len;
   while((scanf("%s",str))!=EOF)
    {
      count=0;
      strcpy(str2,str);
      strcpy(str3,str);
      strcpy(str7,str);
      for(i=0;i<10;i++)
        arr[i]=0;
      len=strlen(str); 
      arr[1]=1;
      if(str[len-1]%2==0)      
       {
        arr[2]=divide(str2,2);
        len1=strlen(str2);
        arr[4]=divide(str2,2);
       }  
      if(str[len-1]=='0'||str[len-1]=='5')      
        arr[5]=1;
      arr[3]=divide(str3,3);
      arr[7]=divide(str7,7);
      if(arr[3])
        arr[9]=divide(str3,3);
      if(arr[2]&&arr[3])
        arr[6]=1;
      if(arr[2]&&arr[4])
        arr[8]=divide(str2,2);
      for(i=0;i<len;i++)
        count=count+arr[str[i]-48];
      printf("%d\n",count);
    }
   return 0;
 }             
          
