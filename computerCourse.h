typedef struct computerCourse //컴공심화 과정
{
    char name[50]; //과목이름
    int credit; //학점
    char designCourse; //설계과목 여부(Y or N)
    char majorRequired; //전공필수 여부(Y or N)
};

int addCourse(computerCourse *c); //수업 목록 추가하기
void readCourse(computerCourse c); //수업 목록 읽기
void updateCourse(computerCourse *c); //수업 목록 업데이트
int deleteCourse(computerCourse *c); //수업 삭제

void savaData(computerCourse *c, int count); //파일 저장 기능
int loadData(computerCourse *c); //파일 불러오기 기능
void searchCourse(computerCourse *c); //과목이름과 학점으로 검색하는 기능
void showchoose(computerCourse c); //내가 담은 과목만 조회할 수 있는 기능 추가

void listCourse(computerCourse *c, int count); //수업목록 전체 읽기
int selectMenu(); //처음 메뉴 선택




