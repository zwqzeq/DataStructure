//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>        
#include<string.h>                            //Ԥ����ָ��

//�µ�����Student����ԭ������struct Student1
typedef  struct Student1
{
	int num;      //ѧ��
	char name[20];//����
	int nSex;     //�Ա�
	float fScore; //����
}Student;

int nCount = 0;
Student *pStu=NULL;

//��ʼ��
int init() {
	if (pStu == NULL) {
		pStu = (Student*)malloc(sizeof(Student));                      //�����ڴ�ռ䣬��pStuָ����ڴ�ռ�
	}
	else {
		pStu = (Student*)realloc(pStu, sizeof(Student)*(nCount + 1));  //��pStu��ָ����ѷ�����ڴ����Ĵ�С��Ϊsizeof(Student)*(nCount + 1)��sizeof(Student)*(nCount + 1)���Ա�ԭ������Ŀռ���С
	}
	if (pStu == NULL) {
		return 0;               //��ʼ��ʧ�ܷ���0
	}
	return 1;                   //��ʼ���ɹ�����1
}

//���ѧ����Ϣ
void add() {
	Student student;//����ṹ���������������ѧ����Ϣ
	       
		//�������ѧ����Ϣ���浽�ṹ����
		printf("������ѧ����Ϣ\n");
		printf("ѧ�ţ�");
		scanf("%d", &student.num);
		printf("������");
		scanf("%s", student.name);
		if (strlen(student.name) > 20) {
			do {
				printf("�����������������:\n");
				scanf("%s", student.name);
			} while (strlen(student.name) > 20);
		}
		printf("�Ա𣺣�1Ϊ�У�0ΪŮ��");
		scanf("%d", &student.nSex);
		if (student.nSex != 1 && student.nSex != 0) {
			do {
				printf("�����������������:\n");
				printf("�Ա𣺣�1Ϊ�У�0ΪŮ��");
				scanf("%d", &student.nSex);
			} while (student.nSex != 1 && student.nSex != 0);    // &&������ͬʱ�����ѭ����||������һ�������ѭ��
		}
		printf("��������0--100��");
		scanf("%f", &student.fScore);
		if (student.fScore<0 || student.fScore>100) {
			do {
				printf("�����������������:\n");
				printf("��������0--100��");
				scanf("%f", &student.fScore);
			} while (student.fScore < 0 || student.fScore > 100);
		}

		if(init()==1){                                  //��ʼ���ɹ�
		/*	*(pStu + nCount) = student;                 ָ�뷨���ȼ�������һ��*/
			pStu[nCount] = student;                    //�±귨
			nCount++;                                 //ѧ��������һ
	}
}

//��ʾѧ����Ϣ
void display() {
	int i = 0;
	printf("ѧ����Ϣ���£�\n");
	printf("ѧ��\t����\t�Ա�\t����\n");
	for (i = 0; i < nCount; i++) {
		printf("%d\t%s\t%d\t%0.1f\n", pStu[i].num, pStu[i].name, pStu[i].nSex, pStu[i].fScore);
	}
}

//����ѧ����Ϣ
void save(Student * pStudent) {
	FILE *fp = NULL;
	int i = 0;
	fp = fopen("student.txt","a");//���fp��Ϊ�գ���˵������student.txt�ļ���ֱ����student.txt�ļ�ĩβд������

	if (fp == NULL) {       
		fp = fopen("student.txt","w");//��ֻд�ķ�ʽ����student.txt�ļ�
		if (fp == NULL) {
			printf("����ѧ����Ϣʧ��\n");
			exit(0);
		}
	}
	//д��ѧ����Ϣ
	for (i = 0; i < nCount; i++) {
		fprintf(fp, "%d##%s##%d##%0.1f\n", pStudent[i].num, pStudent[i].name, pStudent[i].nSex, pStudent[i].fScore);
	}

	//ˢ��
	fflush(fp);

	//�ر��ļ�
	fclose(fp);
	printf("���ѧ����Ϣ�ɹ�\n");
}

//�ͷſռ�
void release() {
	if (pStu!=NULL) {
		free(pStu);
		pStu = NULL;
	}
}

//������ں���
int main() {
	int nSelection = -1; //�����û�����ı����ĳ�ʼ��
	do {
	//���ϵͳ�˵�
	printf("1. ���ѧ����Ϣ\n");
	printf("2. ��ʾѧ����Ϣ\n");
	printf("3. ����ѧ����Ϣ\n");
	printf("0. �˳�\n");

	//��ʾ�������û�������
	printf("�����������ţ�");
	scanf("%d", &nSelection);

	switch (nSelection)
	{
	case 1:
		add();          //���ѧ����Ϣ
		break;
	case 2:
		display();       //��ʾѧ����Ϣ
		break;
	case 3:
		save(pStu);      //����ѧ����Ϣ
		break;
	case 0:
		release();      //�ͷŽ��ռ�
		break;
	default:
		printf("����Ĳ˵������\n");
		break;
	}
	} while (nSelection!=0);
	return 0;
}