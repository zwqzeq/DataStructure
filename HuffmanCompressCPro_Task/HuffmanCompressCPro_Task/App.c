#include "Huffman.h"
#include "Compress.h"
int main()
{
	char choice, c;
	int run = 1;
	while (run) 
	{  
		//打印菜单
		printf("哈夫曼编码压缩和解压缩文件\n");
		printf("1.压缩\n");
		printf("2.解压缩\n");
		printf("3.退出\n");
		printf("请输入你的选择：");
		choice = getchar();
		puts(" ");
		getchar();
		fflush(stdin);	//清空输入缓冲区域，否则键入的回车符将作为程序结尾处的scanf输入
		switch (choice) {
		case '1':
			Compress();
			fflush(stdin);
			printf("是否继续操作？(y/n)\n");
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
			printf("是否继续操作(y/n)：");
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
