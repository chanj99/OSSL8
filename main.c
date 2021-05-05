#include <stdio.h>
#include <stdlib.h>
#include "computerCourse.h"

int main(){
    int menu;
    int index,count;
    int cartIndex,cartCount;
    computerCourse c[100];
    computerCourse cart[20];

    //index = count = loadData(c);

    while(1){
        menu = selectMenu();
        if((menu==1||menu==3||menu==4)&&count==0) continue;

        if(menu==1){
            //조회
            if(count>0){ 
                //만약 지금 보유하고 있는 데이터가 있다면
                listCourse(c, index);
                //list보여주기
            } else{
                //만약 지금 보유하고 있는 데이터가 하나도 없다면?
                printf("데이터가 없습니다!\n");
            }
        }
        else if(menu==2){
            //추가
              count += addCourse(&c[index]);
              index++;
              }
        /*
        else if(menu==3){
            //수정
        }else if(menu==4){
            //삭제
        }else if(menu==5){
            //저장
        }else if(menu==6){
            //이름으로 검색
        }else if(menu==7){
            //학점으로 검색
        }else if(menu==8){
            //장바구니에 담기
        }else if(menu==9){
            //장바구니에 담은 과목 보여주기
        

        }
        */
        else if(menu==10){
            break;
        }
    }

    return 0;
}
