#include <stdio.h>
#include <stdlib.h>
#include "computerCourse.h"

int main(){
    int menu; //메뉴 선택
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
        
        else if(menu==3){
            //수정
            int no = selectDataNum(c,index);
            if(no>0)
                updateCourse(&c[no-1]);
            else
                printf("=>취소되었습니다!\n");
        }
        else if(menu==4){
            //삭제
            int delCourse = selectDataNum(c, index);
            int del = 0;
            if(delCourse>0){
                printf("정말로 삭제하시겠습니까?(삭제:1)");
                scanf("%d", &del);
                if(del == 1){
                    if(deleteCourse(&c[delCourse-1]) == 1){
                    printf("=>삭제됨!\n");
                    count --;
                    }
                }
            }else{
                printf("=>취소됨!\n");
            }
        }
        else if(menu==5){
            //저장
            saveCourse(c,index);
        }else if(menu==6){
            //이름으로 검색
            searchCourseByName(c,index);
        }else if(menu==7){
            //학점으로 검색
            searchCourseByCredit(c,index);
        }
        else if(menu==8){
            //장바구니에 과목 담기
            int no = selectDataNum(c,index);
            if(no>0){
                cartCount += addInCart(&cart[cartIndex++],c[no-1]);
            }else{
                printf("=>취소됨!\n");
            }
        }

        else if(menu==9){ 
            //장바구니에 담은 과목 보여주기
            if(cartCount>0){ 
                //만약 지금 장바구니에 있는 데이터가 있다면
                showchoose(cart, cartCount);
                //장바구니에 담은 과목 list보여주기
            } else{
                //만약 지금 장바구니에 있는 데이터가 하나도 없다면?
                printf("=>장바구니에 담긴 과목이 없습니다.\n");
            }
        
        }
        
        else if(menu==10){
            break;
        }
    }

    return 0;
}