
//ѧ����Ϣ�ṹ��
struct Student
{
	int nNum;    //ѧ��
	float fScore;//����
};

//������ṹ������
struct Node
{
	struct Student data; //�������
	struct Node* next;   //ָ���¸�����ָ��
};

//���к�������
int init();                                  //��ʼ������
int addNode(struct Student * pStu);          //��ӽ��
struct Student* traverseList(int *pCount);   //��������
int deleteNode(int nNum);                    //ɾ�����
void release();                              //�ͷſռ�
void addStu();                               //���ѧ����Ϣ
void displayStu();                           //��ʾѧ����Ϣ
void deleteStu();                            //ɾ��ѧ����Ϣ
