#include "Huffman.h"
#include "Compress.h"
int main()
{
	char choice, c;
	int run = 1;
	while (run) 
	{  
		//��ӡ�˵�
		printf("����������ѹ���ͽ�ѹ���ļ�\n");
		printf("1.ѹ��\n");
		printf("2.��ѹ��\n");
		printf("3.�˳�\n");
		printf("���������ѡ��");
		choice = getchar();
		puts(" ");
		getchar();
		fflush(stdin);	//������뻺�����򣬷������Ļس�������Ϊ�����β����scanf����
		switch (choice) {
		case '1':
			Compress();
			fflush(stdin);
			printf("�Ƿ����������(y/n)\n");
			scanf("%c", &c);
			if (c != 'y')
			{
				exit(0);
			} 
			fflush(stdin);
			break;
		case '2':
			UnCompress();
			fflush(stdin);
			printf("�Ƿ��������(y/n)��");
			scanf("%c", &c);
			if (c != 'y')
			{
				exit(0);
			} 
			fflush(stdin);
			break;
		case '3':
			exit(0);
			break;
		}
	}
	exit(0);
	system("pause");
	return 0;
}
