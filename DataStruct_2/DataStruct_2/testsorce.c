#include "SLNode.h"
#include <stdlib.h>
typedef int DataType;
int main()
{
	void Delete(SLNode *head);                //ɾ����㺯������              
	SLNode *head;                            //����ͷָ�����
	int i, x, z; 
	ListInitiate(&head);                    //��ʼ��
	printf("������10�����ظ������ݣ�");     //����
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &z);
		ListInsert(head, i, z);
	}
	Delete(head);                        //ɾ����㺯������                    
	for (i = 0; i < ListLength(head); i++)
	{
		ListGet(head, i, &x);            //ȡ����Ԫ��
		printf("%d   ", x);              //���������̨
	}
	printf("\n");
	Destory(&head);                    //��������
	return 0;
}

//����ɾ�����ĺ���
void Delete(SLNode *head)
{
	SLNode *p, *s, *q;                               //��������ָ�����ָ��SLNode���͵Ľ��
	p = head->next;                                  //pָ��ͷ������һ�����
	while(p != NULL && p->next != NULL)              //pָ��Ľ�㲻Ϊ����pָ��Ľ�����һ����㲻Ϊ��
	{
		s = p;                                       //sָ��Ҫɾ������ǰ��
		q = p->next;                                 //qָ����һ�����
		while(q != NULL)                             
		{//qָ��Ľ�㲻Ϊ��
			if(q->data == p->data)                  //��������������ͬ
			{
				s->next = q->next;                  //ɾ��q���
				free(q);                            //�ͷ�q���
				q = s->next;                       //qָ����һ��Ԫ��
			}
			else
				//��������ݲ���
			{
				s = q;            //s����ƶ�һλ                      
				q = q->next;      //q����ƶ�һλ
			}
			
		}
		p = p->next;//p����ƶ�һλ
	}
}