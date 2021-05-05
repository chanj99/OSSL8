#include <stdio.h>
#include <stdlib.h>
#include "computerCourse.h"

int main(){
    int menu;
    int index,count;
    int cartIndex,cartCount;
    computerCourse c[100];
    computerCourse cart[20];

    index = count = loadData(c);

    while(1){
        menu = selectMenu();
        if((menu==1||menu==3||menu==4)&&count==0) continue;

        if(menu==1){
            //조회
        }else if(menu==2){
            //추가
        }else if(menu==3){
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
        }else if(menu==10){
            break;
        }
    }

    return 0;
}
