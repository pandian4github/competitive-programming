#include<stdio.h>
#include<string.h>
int main()
 {
   char str[32001],set;
   int count[32001],i,j,k,flag,choice,choice2,start;
   int positive,test=0,max;
   while(1)
    {
      scanf("%s",str);
      if(strcmp(str,"()")==0)
        break;
      test++;  
      max=0;
      positive=0;
      for(i=0;i<strlen(str);i++)
        if(str[i]=='(')
          {
           count[i]=++positive;
           if(positive>max)
             max=positive;
          }
        else
          if(str[i]==')')
           {
             count[i]=-1*positive;
             positive--;
           }
          else
            count[i]=0;
  //    for(i=0;i<strlen(str);i++)
  //      printf("%d  ",count[i]);
  //    printf("\n\n");       
      int nocount[max+1];
      for(i=0;i<=max;i++)
        nocount[i]=0;
      int indexes[max+1][16000-max+1];
      for(i=0;i<strlen(str);i++)
        if(count[i]>0)
           indexes[count[i]][nocount[count[i]]++]=i;
      choice=max%2;
      for(i=max;i>=1;i--)
       {
         choice2=i%2;
         for(j=0;j<nocount[i];j++)
          {
            start=indexes[i][j];
            if(choice2==choice)
             {
               flag=0;
               for(k=start;count[k]!=(-1*i);k++)
                 if(str[k]=='F')
                  {
                    flag=1;
                    break;
                  }
               if(flag==0)
                 set='T';
               else
                 set='F';
               for(k=start;count[k]!=(-1*i);k++)
                 str[k]=set;
               str[k]=set;
             }
            else
             {
               flag=0;
               for(k=start;count[k]!=(-1*i);k++)
                 if(str[k]=='T')
                  {
                    flag=1;
                    break;
                  }
               if(flag==0)
                 set='F';
               else
                 set='T';
               for(k=start;count[k]!=(-1*i);k++)
                 str[k]=set;
               str[k]=set;
             }
          }
       }
      if(str[0]=='T')
        printf("%d. true\n",test);
      else
        printf("%d. false\n",test);                     
  /*    for(i=1;i<=max;i++)
        {
           for(j=0;j<nocount[i];j++)
             printf("%d  ",indexes[i][j]);
           printf("\n");
        }*/        
    }
   return 0;
 }      
                
              
