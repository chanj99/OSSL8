#include <stdio.h>
#include "computerCourse.h"

int addCourse(computerCourse *c){

}
void readCourse(computerCourse c){

}
void updateCourse(computerCourse *c){

}
int deleteCourse(computerCourse *c){

}
void savaData(computerCourse *c, int count){

}
int loadData(computerCourse *c){

}
void searchCourseByName(computerCourse *c,int count){

}
void searchCourseByCredit(computerCourse *c,int count){

}
void addInCart(computerCourse *cart, computerCourse c){

}
void showchoose(computerCourse *cart, int count){

}


void listCourse(computerCourse *c, int count){

}
int selectMenu(){
    int menu;
    printf("\n=========================\n");
    printf("1. 전공과목 조회\n");
    printf("2. 전공과목 추가\n");
    printf("3. 전공과목 정보 수정\n");
    printf("4. 전공과목 삭제\n");
    printf("5. 저장\n");
    printf("6. 과목 이름으로 검색\n");
    printf("7. 학점으로 검색\n");
    printf("8. 장바구니에 담기\n");
    printf("9. 장바구니 보기\n");
    printf("10. 종료\n");
    printf("원하는 메뉴 번호를 입력하세요 : ");
    scanf("%d",&menu);
    
    return menu;

}
