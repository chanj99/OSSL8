#include <stdio.h>
#include "computerCourse.h"

int addCourse(computerCourse *c){
    int count = 0;
    printf("과목이름은?");
    scanf(" %[^\n]s", c->name);
    printf("이수구분은?(전공필수, 전공선택, 전공선택필수)");
    scanf(" %s", c->classification);
    printf("학점은?");
    scanf(" %d", &c->credit);
    printf("설계과목 여부는?(Y or N)");
    scanf(" %c", &c->designCourse);
    count++;
    return count;
}

void readCourse(computerCourse c){
        printf(" %s  %d학점   %c       %s\n", c.classification, c.credit, c.designCourse, c.name);
}

int selectDataNum(computerCourse *c,int count){
    int no;
    listCourse(c,count);
    printf("선택한 메뉴를 실행할 데이터 번호는? (취소  :0) " );
    scanf("%d",&no);
    getchar();
    return no;
}


void updateCourse(computerCourse *c){
    printf("새 과목이름은?");
    scanf(" %[^\n]s", c->name);
    printf("새 이수구분은?(전공필수, 전공선택, 전공선택필수)");
    scanf(" %s", c->classification);
    printf("새 학점은?");
    scanf(" %d", &c->credit);
    printf("설계과목 여부는?(Y or N)");
    scanf(" %c", &c->designCourse);
    printf("=>수정완료!\n");
}
/*
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
*/

void listCourse(computerCourse *c, int count){
    printf("  이수구분  학점  설계과목여부  과목이름\n");
    printf("===============================\n");
    for(int i =0; i<count; i++){
        if(c[i].credit == -1) continue;
        //삭제됐으면 밑에꺼 수행하지 말고 실행해라.
        printf("%1d", i+1);
        //데이터의 번호를 먼저 출력해주기
        readCourse(c[i]);
        //그 다음 데이터 읽기
    }
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
