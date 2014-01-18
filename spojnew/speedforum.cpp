    #include <stdio.h>
    #include <stdlib.h>
    #include <conio.h>

    int main(){
        int in1, in2, s1, s2, delta, lama, baru, tA, tB, loop, kasus, i;
       
        scanf("%d", &kasus);
        for (i=0; i<kasus; i++){
            scanf("%d %d", &in1, &in2);
            if ((in1>0 && in2>0)||(in1<0 && in2<0)){
                if (in1<0){
                    in1*=-1;
                    in2*=-1;       
                }
                if (in1>in2){
                    s1=in1;
                    s2=in2;       
                }
                else{
                    s1=in2;
                    s2=in1;       
                }
               
                while (s2!=0){
                      if (s1>s2) s1-=s2;
                      else s2-=s1;     
                }
                printf("%d\n", abs((in1/s1)-(in2/s1)));
            }
            else{
                if(abs(in1)>abs(in2)){
                     s1=abs(in1);
                     s2=abs(in2);       
                }
                else{
                     s1=abs(in2);
                     s2=abs(in1);       
                }
                lama=0;
                baru=0;
                //printf("%d %d\n", s1, s2);
                loop=1;
                do{
                    baru=baru-s2;
                    if (baru<0){
                        baru=s1+baru;       
                    }
                    //printf("%d\n", baru);
                    loop++;
                }while(baru!=0);
                printf("%d\n", loop); 
            }   
        }   
       
        getch();
        return 0;
    }
