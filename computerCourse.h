typedef struct //�İ���ȭ ����
{
    char name[100]; //�����̸�
    int credit; //����
    char designCourse; //������� ����(Y or N)
    char classification[100]; //�̼�����(�����ʼ�, ��������, ���������ʼ�)
}computerCourse;

typedef struct{
    char id[20];
    char pw[20];
}User;

void signUp();
int login();
int addCourse(computerCourse *c); //���� ��� �߰��ϱ�
void readCourse(computerCourse c); //���� ��� �б�
void updateCourse(computerCourse *c); //���� ��� ������Ʈ
int deleteCourse(computerCourse *c); //���� ����
int addInCart(computerCourse *cart, computerCourse c); //������ ������ ��ٱ��Ͽ� ��� ���
void showchoose(computerCourse *cart, int count); //���� ���� ���� ��ȸ�� �� �ִ� ��� �߰�
void saveCourse(computerCourse *c, int count); //���� ���� ���
int loadData(computerCourse *c); //���� �ҷ����� ���
void searchCourseByCredit(computerCourse *c,int count); //�������� �˻��ϴ� ���


void searchCourseByName(computerCourse *c,int count); //�����̸����� �˻��ϴ� ���


int selectDataNum(computerCourse *c, int count);
void listCourse(computerCourse *c, int count); //������� ��ü �б�
int selectMenu(); //ó�� �޴� ����


