typedef struct //컴공심화 과정
{
    char name[100]; //과목이름
    int credit; //학점
    char designCourse; //설계과목 여부(Y or N)
    char classification[100]; //이수구분(전공필수, 전공선택, 전공선택필수)
}computerCourse;

int addCourse(computerCourse *c); //수업 목록 추가하기
void readCourse(computerCourse c); //수업 목록 읽기
void updateCourse(computerCourse *c); //수업 목록 업데이트
int deleteCourse(computerCourse *c); //수업 삭제
int addInCart(computerCourse *cart, computerCourse c); //선택한 과목을 장바구니에 담는 기능
/*
void savaData(computerCourse *c, int count); //파일 저장 기능
int loadData(computerCourse *c); //파일 불러오기 기능
void searchCourseByName(computerCourse *c,int count); //과목이름으로 검색하는 기능
void searchCourseByCredit(computerCourse *c,int count); //학점으로 검색하는 기능
void showchoose(computerCourse *cart, int count); //내가 담은 과목만 조회할 수 있는 기능 추가
*/
int selectDataNum(computerCourse *c, int count);
void listCourse(computerCourse *c, int count); //수업목록 전체 읽기
int selectMenu(); //처음 메뉴 선택


