#pragma once
//����ṹ��
typedef struct PLNODE {
	double dbCoef;                              //ϵ����
	int nExpn;                                       //ָ����
	struct PLNODE*next;                     //ָ����,ָ����һ���ڵ�
} PLNODE;                                           //  ����PLNODE���ʹ���struct PLNODE
typedef PLNODE *  PLinkList;            //����PLinkList����PLNODE *����
