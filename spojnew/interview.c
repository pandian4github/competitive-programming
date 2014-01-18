#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include<conio.h>
//#define MAX 20
int comp(const void *s1, const void *s2)
 {
     return (strcmp(*(char **)s1, *(char **)s2));
 }
main()
 {
    char buf[20], *ptr, *key, **key1;
    int count,MAX;
    scanf("%d",&MAX);
    char *data[MAX];
    for (count = 0; count < MAX; count++)
     {
         scanf("%s",buf);
         data[count] = malloc(strlen(buf)+1);
         strcpy(data[count], buf);
     }
    qsort(data, MAX, sizeof(data[0]), comp);
    for (count = 0; count < MAX; count++)
      printf("%s\n",data[count]);
//     getch();
    return(0);
 }

