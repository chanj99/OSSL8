#include <stdio.h>
#include <stdlib.h>
#include "computerCourse.h"

int main(){
    int menu;
    int index=0,count=0;
    int cartIndex=0,cartCount=0;
    computerCourse c[100];
    computerCourse cart[20];

    //index = count = loadData(c);

    while(1){
        menu = selectMenu();
        if((menu==1||menu==3||menu==4)&&count==0) continue;

        if(menu==1){
            //μ‘°ν
            if(count>0){ 
                //λ§μ½ μ§?κΈ? λ³΄μ ?κ³? ?? ?°?΄?°κ°? ??€λ©?
                listCourse(c, index);
                //listλ³΄μ¬μ£ΌκΈ°
            } else{
                //λ§μ½ μ§?κΈ? λ³΄μ ?κ³? ?? ?°?΄?°κ°? ??? ??€λ©??
                printf("?°?΄?°κ°? ??΅??€!\n");
            }
        }
        else if(menu==2){
            //μΆκ??
              count += addCourse(&c[index]);
              index++;
              }
        
        else if(menu==3){
            //?? 
            int no = selectDataNum(c,index);
            if(no>0)
                updateCourse(&c[no-1]);
            else
                printf("μ·¨μ???΅??€!n");
        }
        else if(menu==4){
            //?­? 
            int delCourse = selectDataNum(c, index);
            int del = 0;
            printf("? λ§λ‘ ?­? ??κ² μ΅?κΉ??(?­? :1)");
            scanf("%d", &del);
            if(del == 1){
                if(deleteCourse(&c[delCourse-1]) == 1){
                printf("?­? ?¨!\n");
                count --;
                }
            }
        }

        /*
        else if(menu==5){
            //????₯
        }else if(menu==6){
            //?΄λ¦μΌλ‘? κ²??
        }else if(menu==7){
            //?? ?Όλ‘? κ²??
        }*/
        else if(menu==8){
            int no = selectDataNum(c,index);
            cartCount += addInCart(&cart[cartIndex++],c[no-1]);
            //?₯λ°κ΅¬?? ?΄κΈ?
        }
        else if(menu==9){ 
            //?₯λ°κ΅¬?? ?΄??? κ³Όλͺ© λ³΄μ¬μ£ΌκΈ°
            if(cartCount>0){ 
                //λ§μ½ μ§?κΈ? ?₯λ°κ΅¬?? ?? ?°?΄?°κ°? ??€λ©?
                showchoose(cart, cartCount);
                //listλ³΄μ¬μ£ΌκΈ°
            } else{
                //λ§μ½ μ§?κΈ? ?₯λ°κ΅¬?? ?? ?°?΄?°κ°? ??? ??€λ©??
                printf("?₯λ°κ΅¬?? ?΄κΈ? κ³Όλͺ©?΄ ??΅??€.\n");
            }
        
        }
        
        else if(menu==10){
            break;
        }
    }

    return 0;
}