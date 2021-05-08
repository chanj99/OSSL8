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
            //조회
            if(count>0){ 
                //만약 �?�? 보유?���? ?��?�� ?��?��?���? ?��?���?
                listCourse(c, index);
                //list보여주기
            } else{
                //만약 �?�? 보유?���? ?��?�� ?��?��?���? ?��?��?�� ?��?���??
                printf("?��?��?���? ?��?��?��?��!\n");
            }
        }
        else if(menu==2){
            //추�??
              count += addCourse(&c[index]);
              index++;
              }
        
        else if(menu==3){
            //?��?��
            int no = selectDataNum(c,index);
            if(no>0)
                updateCourse(&c[no-1]);
            else
                printf("취소?��?��?��?��?��!n");
        }
        else if(menu==4){
            //?��?��
            int delCourse = selectDataNum(c, index);
            int del = 0;
            printf("?��말로 ?��?��?��?��겠습?���??(?��?��:1)");
            scanf("%d", &del);
            if(del == 1){
                if(deleteCourse(&c[delCourse-1]) == 1){
                printf("?��?��?��!\n");
                count --;
                }
            }
        }

        /*
        else if(menu==5){
            //????��
        }else if(menu==6){
            //?��름으�? �??��
        }else if(menu==7){
            //?��?��?���? �??��
        }*/
        else if(menu==8){
            int no = selectDataNum(c,index);
            cartCount += addInCart(&cart[cartIndex++],c[no-1]);
            //?��바구?��?�� ?���?
        }
        else if(menu==9){ 
            //?��바구?��?�� ?��??? 과목 보여주기
            if(cartCount>0){ 
                //만약 �?�? ?��바구?��?�� ?��?�� ?��?��?���? ?��?���?
                showchoose(cart, cartCount);
                //list보여주기
            } else{
                //만약 �?�? ?��바구?��?�� ?��?�� ?��?��?���? ?��?��?�� ?��?���??
                printf("?��바구?��?�� ?���? 과목?�� ?��?��?��?��.\n");
            }
        
        }
        
        else if(menu==10){
            break;
        }
    }

    return 0;
}