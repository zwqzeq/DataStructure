
//学生信息结构体
struct Student
{
	int nNum;    //学号
	float fScore;//分数
};

//链表结点结构体类型
struct Node
{
	struct Student data; //结点数据
	struct Node* next;   //指向下个结点的指针
};

//所有函数声明
int init();                                  //初始化链表
int addNode(struct Student * pStu);          //添加结点
struct Student* traverseList(int *pCount);   //遍历链表
int deleteNode(int nNum);                    //删除结点
void release();                              //释放空间
void addStu();                               //添加学生信息
void displayStu();                           //显示学生信息
void deleteStu();                            //删除学生信息
