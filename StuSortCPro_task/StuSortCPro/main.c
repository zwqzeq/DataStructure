#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include"model.h"                         

//���ѧ����Ϣ
void addStu() {
	struct Student stu;        //����struct Student���͵Ľṹ�����stu��������������ѧ����Ϣ
	printf("\n���ѧ����Ϣ\n");
	printf("������ѧ�ţ�");
	scanf("%d", &stu.nNum);
	printf("�����������");
	scanf("%f", &stu.fScore);

	//���ѧ����Ϣ
	if (addNode(&stu)==0) {          
		printf("���ʧ��\n");               //��ӽ��ĺ�������ֵΪ0ʱ���ʧ��
	}
	else {
		printf("��ӳɹ�\n");
	}
}

//��ʾѧ����Ϣ
void displayStu() {
	struct Student * pStu = NULL;
	int i = 0;
	int nCount = 0;
	printf("ѧ��\t����\n");
	//��ȡѧ����Ϣ�͸���
	pStu = traverseList(&nCount);
	if (pStu == NULL) {
		printf("��ʾʧ�ܣ�\n");
		return;
	}
	//��ʾѧ����Ϣ
	for (i = 0; i < nCount; i++) {
		printf("%d\t%0.1f\n", pStu[i].nNum, pStu[i].fScore);
	}
	//�ͷŶ�̬������ڴ�
	free(pStu);
	pStu = NULL;
}

//ɾ��ѧ����Ϣ
void deleteStu() {
	struct Node*node = NULL;
	struct Node*pTemp = NULL;
	int nNum = 0;
	printf("������ɾ����ѧ��ѧ�ţ�");
		scanf("%d",&nNum);
		if (0 == deleteNode(nNum)) {
			printf("ɾ��ʧ��\n");
			return;
		}
		else {
			printf("ɾ���ɹ�\n");
			return;
		}
		while (node -> next != NULL) {
		//����������Ľ�㣨��ǰ��㣩��ѧ����ɾ����ѧ����ͬ
		if (node->next->data.nNum == nNum) {
			//����ǰ������һ����㣬ָ��ǰ�����һ�����
			pTemp = node->next;
			node->next = pTemp->next;
			//�ͷŵ�ǰ���
			free(pTemp);
		}
		node = node->next;
	}
	return 0;
}


//�������
int main() {
	int nSelection = -1;
	do {
		printf("1. ���ѧ����Ϣ\n");            //�˵�
		printf("2. ��ʾѧ����Ϣ\n");
		printf("3. ɾ��ѧ����Ϣ\n");
		printf("0. �˳�\n");
		printf("�����������ţ�");
		scanf("%d", &nSelection);
		switch (nSelection) {
		case 1:
			addStu();           //���ѧ����Ϣ
			break;
		case 2:
			displayStu();       //��ʾѧ����Ϣ
			break;
		case 3:
			deleteStu();        //ɾ��ѧ����Ϣ
			break;
		case 0:
			printf("��л����ʹ�ã�");
			exit(0);
			break;
		default:
			printf("����������������룡");
			scanf("%d", &nSelection);
			break;
		}

	} while(nSelection != 0);        //ע�⣺while�����nSelectionӦ�ö�����do����
	
	return 0;
}