#include <stdio.h>
#include <string.h>
#include "computerCourse.h"

int addCourse(computerCourse *c){
    int count = 0;
    printf("\n과목이름은? ");
    scanf(" %[^\n]s", c->name); //띄어쓰기가 포함된 과목이름이 있기 때문에 %[^\n]s사용 (엔터키 전 모든 것을 입력 받는다)
    printf("이수구분은?(전공필수, 전공선택, 전공선택필수) ");
    scanf(" %s", c->classification);
    printf("학점은? ");
    scanf(" %d", &c->credit);
    printf("설계과목 여부는?(Y or N) ");
    scanf(" %c", &c->designCourse);
    printf("=>과목추가완료!\n");
    count++; //과목 하나 추가
    return count; 
}

void readCourse(computerCourse c){
    //다른 함수에서도 과목 읽기가 빈번하게 나오기 때문에 readCourse 함수 추가
    printf(" %-12s  %d학점   %7c       %12s\n", c.classification, c.credit, c.designCourse, c.name);
}

int selectDataNum(computerCourse *c,int count){
    //삭제나 수정 함수를 구현할 때, 특정 함수를 선택해야 하기 때문에 selectDataNum 함수 구현
    int no;
    listCourse(c,count);
    printf("선택한 메뉴를 실행할 데이터 번호는? (취소  :0) " );
    scanf("%d",&no);
    getchar();
    return no;
}


void updateCourse(computerCourse *c){
    printf("\n새 과목이름은? ");
    scanf(" %[^\n]s", c->name); //띄어쓰기가 포함된 과목이름이 있기 때문에 %[^\n]s사용 (엔터키 전 모든 것을 입력 받는다)
    printf("새 이수구분은?(전공필수, 전공선택, 전공선택필수) ");
    scanf(" %s", c->classification);
    printf("새 학점은? ");
    scanf(" %d", &c->credit);
    printf("설계과목 여부는?(Y or N) ");
    scanf(" %c", &c->designCourse);
    printf("=>수정완료!\n");
}

int deleteCourse(computerCourse *c){
    //과목을 삭제 하면 학점을 -1로 만들어 준다.
    c->credit = -1;
    return 1;
}

int addInCart(computerCourse *cart, computerCourse c){
    *cart = c;
    printf("=>선택하신 과목이 장바구니에 추가되었습니다!\n");
    return 1;
}

void showchoose(computerCourse *cart, int count){ //장바구니에 담은 과목
    printf("\n==> 장바구니에 담은 과목입니다.\n");
    printf("  이수구분   학점     설계과목여부   과목이름\n");
    printf("==================================================\n");
    for(int i =0; i<count; i++){
        if(cart[i].credit == -1) continue;
        //삭제됐으면 아래의 statement를 수행하지 말고 i번째 loop 나가기
        printf("%1d", i+1);
        //데이터의 번호를 먼저 출력
        readCourse(cart[i]);
        //i번째 데이터 읽기
    }
}

void saveCourse(computerCourse *c, int count){
    FILE *fp;
    fp = fopen("test.txt","wt");
    for(int i=0;i<count;i++){
        if(c[i].credit==-1) continue;
        fprintf(fp,"%s %d %c %s\n",c[i].classification,c[i].credit,c[i].designCourse,c[i].name);
    }
    fclose(fp);
    printf("=>저장됨!\n");
}


int loadData(computerCourse *c){
    int count = 0;
    FILE *fp;
    fp = fopen("test.txt", "rt");
    if(fp == NULL){
        printf("=> 파일 없음\n");
        return 0;
    }
    else{
        for(int i  = 0; i<100; i++){
            fscanf(fp, "%s", c[i].classification);
            if(feof(fp)) break;
            fscanf(fp, "%d", &c[i].credit);
            fscanf(fp, "%c", &c[i].designCourse);
            fscanf(fp, "%s", c[i].name);
            count++;
        }
        fclose(fp);
        printf("=> 파일 로딩 성공!\n");
        return count;
    }

}

void searchCourseByCredit(computerCourse *c,int count){
    int searchresult = 0; //검색한 결과에 갯수
    int search = 0; //검색할 학점

    printf("검색할 학점은? ");
    scanf("%d", &search); //검색할 학점을 입력 받아 search에 저장한다.
    printf("  이수구분   학점     설계과목여부   과목이름\n");
    printf("==================================================\n");
    for(int i =0; i<count; i++){
        if(c[i].credit == -1) continue; //삭제된 함수라면 이번 loop를 끝낸다. 다른 i번째로 넘어감
        if(c[i].credit == search){ //검색할 학점과 같은 학점이 검색되면 
            printf("%2d", i+1); 
            readCourse(c[i]); //그 과목을 출력해준다
            searchresult++; //찾았으니 +1
        }
    }
    if(searchresult == 0) printf("=> 검색된 과목 없음!"); //만약에 검색된 결과가 없다면, 과목이 없다고 출력
    printf("\n");

}


void searchCourseByName(computerCourse *c,int count){
    char sn[20];
    int comp=0;
    printf("검색할 과목명은? ");
    scanf("%s",sn);
    printf("  이수구분   학점     설계과목여부   과목이름\n");
    printf("==================================================\n");
    for(int i=0;i<count;i++){
        if(c[i].credit==-1) continue;
        if(strstr(c[i].name,sn)){
            printf("%2d", i+1);
            readCourse(c[i]);
            comp++;
        }
    }
    if(comp==0){
        printf("=> 없는 과목입니다.\n");
    }
}



void listCourse(computerCourse *c, int count){
    printf("  이수구분   학점     설계과목여부   과목이름\n");
    printf("==================================================\n");
    for(int i =0; i<count; i++){
        if(c[i].credit == -1) continue;
        //삭제됐으면 아래의 statement를 수행하지 말고 i번째 loop 나가기
        printf("%1d", i+1);
        //데이터의 번호를 먼저 출력
        readCourse(c[i]);
        //i번째 데이터 읽기
    }
}


int selectMenu(){
    //main함수가 실행되고 종료되기 전까지 메뉴를 보여주는 함수
    int menu;
    printf("\n컴퓨터공학심화 과목 조회 프로그램");
    printf("===========================\n");
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