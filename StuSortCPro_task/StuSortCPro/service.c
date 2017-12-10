
#include<stdio.h>
#include <stdlib.h>
#include"model.h"
struct Node * stuList = NULL;           //���� ��---ȫ�ֱ���

//��ʼ������
int init() {
	struct Node * head = NULL;         //����ͷָ�����
	if (stuList == NULL)               //�������Ϊ��
	{
		head = (struct Node *)malloc(sizeof(struct Node));//����ͷ���(Ϊͷ�������ڴ�)     
		if (head == NULL) {
			return 0;                  //����ͷ���ʧ�ܷ���0������ʼ��ʧ��
		}
		head ->next = NULL;//��ʱͷ��㴴���ɹ�����ͷ����ָ����Ϊ�գ�����ʱֻ��һ��ͷ��㣬��ͷ���ָ����ָ���κν�㣩
		stuList = head;    //��stuList��headָ��ͬһͷ���
		return 1;          //����ͷ���ɹ�����1������ʼ���ɹ�
	}
	return 0;              //�����Ѿ�����ʱ����0������ʼ��ʧ��
}

//��ӽ��
int addNode(struct Student * pStu) {
	struct Node * node = NULL;
	struct Node * cur = NULL;

	if (stuList == NULL) {
		//�������Ϊ�գ��ͳ�ʼ������
		if (init() == 0) {
			//�����ʼ��ʧ�ܾͷ���0
			return 0;
		}
	}

	//Ϊ��ӵĽ������ڴ�
	cur = (struct Node*)malloc(sizeof(struct Node));        //curָ���´����Ľ��
	if (cur == NULL) {
		return 0;         //����һ�����ʧ��ʱ����0
	}

	cur->data = *pStu;              //����ӵ�ѧ����Ϣ���浽�����Ľ����                      
	cur->next = NULL;
	//���������������ӵ�����β��
	node = stuList;
	while (node->next != NULL)
	{
		node = node->next;     //����

	}
	node->next = cur;          //��ʱ�Ѿ�����������β����β����ָ����ָ���´������Ұ���ѧ����Ϣ�Ľ�㣨��curָ��Ľ�㣩
	return 1;                  //��ӽ��ɹ�����1
}

//��������
struct Student* traverseList(int *pCount) {
	struct Node*node = NULL;
	int i = 0;
	struct Student*pStu = NULL;
	node = stuList->next;
	if (node == NULL) {
		return NULL;
	}
	//��ȡ���������
	node = stuList->next;
	do {
		(*pCount)++;
		node = node->next;
	} while (node != NULL);
	//��̬�����ڴ�
	pStu = (struct Student*)malloc(sizeof(struct Student)*(*pCount));
	
	//ȡ���������е�����
	node = stuList->next;
	while (node != NULL) {
		pStu[i] = node->data;
		node = node->next;
		i++;
	}
	return pStu;
}

//ɾ�����
int deleteNode(int nNum) {
	struct Node * node = stuList;
	struct Node * pTemp = NULL;
	if (node == NULL) {
		return 0;
	}
	//������ĵ�һ����㿪ʼ����
	while (node->next != NULL) {
		//����������Ľ�㣨��ǰ��㣩��ѧ����ɾ����ѧ����ͬ
		if (node->next->data.nNum == nNum) {
			//�����ڽ�����һ�����ָ��ǰ������һ�� ���
			pTemp = node ->next;
			node -> next =pTemp -> next;
			//�ͷŵ�ǰ���
			free(pTemp);
			pTemp = NULL;
			return 1;
		}
		node = node->next;
	}
	return 0;
}

//�ͷſռ�
void release() {
	struct Node*cur = stuList;
	struct Node *next = NULL;
	while (cur!=NULL) {
		next = cur->next;//����ڴ��ͷ�ǰ��next��������
		free(cur);//�ͷŽ���ڴ�
		cur = next;
	}
	stuList = NULL;
}