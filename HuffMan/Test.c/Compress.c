
#include "Huffman.h"
#include "Compress.h"

//压缩函数
void Compress()
{
	char desFile[80];//文件原始名字
	char rename[80] = " ";//文件新名字
	char *suffix=".huf"; //文件后缀
	MyType maxLen, minLen, ch, bits, n, finalLength;
	int i;
	short LeafNum, codeNum;
	WeightType count = 0, Length = 0, FileLength;
	FILE *fp, *compressFile;
	SeqQueue *Q;
	HTNode *ht = NULL;
	char **hc = NULL, **Map = NULL, *p;
	printf("请输入要被压缩的文件（要求：路径 + 文件名  示例：E:\\Pic.bmp）:");
	scanf("%s", desFile);
	strcpy(rename, desFile);//先把原文件名给rename，再给他添加压缩后的文件名后缀
	strcat(rename, suffix);
	compressFile = fopen(rename, "wb");
	fp = fopen(desFile, "rb");	//原文件
	if (!fp || !compressFile) {
		puts("Cannot open file.");
		return;
	}
	ht = CreatHFM(fp, &LeafNum, &FileLength);	//创建哈夫曼树,统计叶子个数和原文件长度
	if (!FileLength) {
		fclose(fp);
		fclose(compressFile);
		free(ht);
		return;
	}
	Q = (SeqQueue *) malloc(sizeof(SeqQueue));
	InitQueue(Q);		//SEEK_SET:文件开头 SEEK_CUR:当前位置 SEEK_END:文件结尾
	hc = CrtHuffmanCode(ht, LeafNum);	//取得哈夫曼0、1编码,hc的长度为LeafNum
	//Map为了取编码好定位，再建立全部(256个)//
	Map = (char **)malloc(N * sizeof(char *));	//字符编码表
	if (!Map) {
		puts("申请空间失败");
		return;
	}
	for (i = 0; i < N; i++)	//初始化
		Map[i] = NULL;
	for (i = 0; i < LeafNum; i++)	// 定位，编码指针数组Map[256]
		Map[(int)(ht[i].ch)] = hc[i];
	fseek(compressFile, sizeof(WeightType) + sizeof(short) + 6 * sizeof(MyType), SEEK_SET);	//先占个位置 
	//先占个位置,等下填压缩叶子编码剩几个和最长编码长
	MaxMinLength(compressFile, ht, hc, LeafNum, &maxLen, &minLen);	//获得最长码串长度,顺便填写字符对应编码长
	free(ht);
	codeNum = CodeToFile(compressFile, hc, LeafNum, Q, &finalLength);	//把字符转成其二进制编码写入文件,返回压成多少个
	rewind(compressFile);	//使文件指针移到开始printf("ftelll = %d\n",ftell(compressFile));
	fseek(compressFile, sizeof(WeightType) + sizeof(MyType), SEEK_SET);
	fwrite(&LeafNum, sizeof(short), 1, compressFile);	//写入叶子个数
	fwrite(&maxLen, sizeof(MyType), 1, compressFile);	//最长码串长度
	fwrite(&minLen, sizeof(MyType), 1, compressFile);	//最短码串长度
	fwrite(&codeNum, sizeof(short), 1, compressFile);	//填写叶子编码压多少个
	fwrite(&finalLength, sizeof(MyType), 1, compressFile);
	fseek(compressFile, 2 * LeafNum * sizeof(MyType) + codeNum, SEEK_CUR);
	fseek(fp, 0, SEEK_SET);
	//开始压缩
	while (count < FileLength) {
		ch = fgetc(fp);	     
		++count;
		for (p = Map[ch]; *p != '\0'; p++)
			In_seqQueue(Q, *p);
		while (Q->length > 8)
		{
			bits = GetBits(Q);	//出队8个元素,合成一个字节
			fputc(bits, compressFile);   
			Length++;
		}
	}			
	finalLength = Q->length;	
	n = 8 - finalLength;
	bits = GetBits(Q);
	for (i = 0; i < n; i++)
		bits = bits << 1;	//以‘0’补
	fwrite(&bits, sizeof(MyType), 1, compressFile);
	Length++;
	rewind(compressFile);
	fwrite(&Length, sizeof(WeightType), 1, compressFile);	//压缩后的长
	fwrite(&finalLength, sizeof(char), 1, compressFile);	//最后的串长
	Length = Length + 12 + codeNum;
	printf("\n");
	printf("压缩完成！\n");
	if (Length >= FileLength)
		puts("\n压缩比率: 0.0%");
	else
		printf("\n压缩比率: %.2lf%c\n",
		(double)((FileLength - Length) / (double)FileLength) * 100.0, '%');
	fclose(fp);
	fclose(compressFile);
	free(Q);
	free(hc);
	free(Map);
}

//把读出的字符，转换成8个0、1字符串并入队
void ToQueue(SeqQueue * Q, MyType ch)
{
	int i;
	MyType temp;
	for (i = 0; i < 8; i++) {
		temp = ch << i;
		temp = temp >> 7;
		if (1 == temp)
			In_seqQueue(Q, '1');	
		else
			In_seqQueue(Q, '0');	
	}			
}

//解压缩图片--------->扩展功能
void UnCompress()
{
	MyType *str, MaxLength, MinLength, ch, *num, finalLength = 0, final = 0;
	FILE *cf, *uf;
	short NLeaf, Ncom;
	char CName[N], UName[N], **hc, *p, x, *buf;
	SeqQueue *Q = NULL;
	int i, j;
	WeightType srcLen = 0, thisFile = 0;
	fflush(stdin);		//清空输入缓冲区域
	printf("请输入要被解压的文件（要求：路径 + 文件名  示例：E:\\Pic.bmp.huf）:");
	scanf("%s", CName);
	if (CName[0] == '\0') {
		printf("try again:");
		scanf("%s", CName);
		fflush(stdin);
	}
	fflush(stdin);		//清空输入缓冲区域
	printf("请输入新的文件名（要求：路径 + 文件名  示例：E:\\123.bmp）:");
	scanf("%s", UName);
	if (UName[0] == '\0') {
		printf("try again:");
		scanf("%s", UName);
	}
	cf = fopen(CName, "rb");
	uf = fopen(UName, "wb");
	if (!cf || !uf) {
		puts("无法打开文件");
		return;
	}
	fread(&srcLen, sizeof(WeightType), 1, cf);
	fread(&finalLength, 1, 1, cf);
	fread(&NLeaf, sizeof(short), 1, cf);
	fread(&MaxLength, sizeof(MyType), 1, cf);
	fread(&MinLength, sizeof(MyType), 1, cf);
	Q = (SeqQueue *) malloc(sizeof(SeqQueue));
	buf = (char *)malloc((2 + MaxLength * sizeof(char)));
	str = (MyType *) malloc(NLeaf * sizeof(MyType));
	num = (MyType *) malloc(NLeaf * sizeof(MyType));
	//压缩叶子数量x和最后剩长
	if (!Q || !str || !num || !buf) {
		puts("存储错误！！！");
		exit(1);
	}
	InitQueue(Q);//初始化
	fread(&Ncom, sizeof(short), 1, cf);
	fread(&final, sizeof(MyType), 1, cf);
	for (i = 0; i < NLeaf; i++)	//读取叶子及其码长
	{
		fread(&str[i], sizeof(MyType), 1, cf);
		fread(&num[i], sizeof(MyType), 1, cf);
	}
	hc = (char **)malloc((NLeaf) * sizeof(char *));	//hc为编码表的指针数组
	if (!hc)
		exit(1);
	--Ncom;	
	for (j = i = 0; i < Ncom; i++) {
		ch = fgetc(cf);
		ToQueue(Q, ch);	
		while (Q->length > MaxLength) {
			hc[j] = p = (char *)malloc(1 + num[j]);
			for (ch = 0; ch < num[j]; ch++) {
				Out_Queue(Q, &x);
				*p++ = x;
			}
			*p = '\0';	
			j++;
		}
	}
	ch = fgetc(cf);		
	ToQueue(Q, ch);
	final = 8 - final;
	while (Q->length > final) {
		p = hc[j] = (char *)malloc(1 + num[j]);
		for (ch = 0; ch < num[j]; ch++) {
			Out_Queue(Q, &x);
			*p++ = x;
		}
		*p = '\0';	
		j++;
	}
	InitQueue(Q);
	--srcLen;
	--MinLength;
	printf("\n");
	printf("正在解压中。。。。。。\n");
	printf("\n");
	while (thisFile < srcLen) {
		ch = fgetc(cf);	
		ToQueue(Q, ch);
		thisFile++;
		//完了后队列长于码串的最大值       
		while (Q->length > MaxLength) {
			for (i = 0; i < MinLength; i++) {
				Out_Queue(Q, &x);
				buf[i] = x;
			}
			for (; i < MaxLength; i++) {
				Out_Queue(Q, &x);
				buf[i] = x;
				buf[i + 1] = '\0';
				for (j = 0; j < NLeaf; j++) {
					if (i + 1 == num[j]
					&& 0 == strcmp(hc[j], buf)) {
						ch = str[j];	
						fputc(ch, uf);	
						break;
					}
				}
				if (j < NLeaf)
					break;
			}
		}		
	}
	ch = fgetc(cf);	//读取最后一个压缩字getchar();
	ToQueue(Q, ch);
	finalLength = 8 - finalLength;
	while (Q->length > finalLength) {
		for (i = 0; i < MinLength; i++) {
			Out_Queue(Q, &x);
			buf[i] = x;
		}
		for (; i < MaxLength; i++) {
			Out_Queue(Q, &x);
			buf[i] = x;
			buf[i + 1] = '\0';
			for (j = 0; j < NLeaf; j++) {
				if (i + 1 == num[j] && 0 == strcmp(hc[j], buf)) {
					ch = str[j];	
					fputc(ch, uf);
					break;
				}
			}
			if (j < NLeaf)
				break;
		}
	}
	free(Q);
	free(str);
	free(num);
	free(hc);
	fclose(uf);
	fclose(cf);
	printf("解压完毕，请打开对应的磁盘查看\n");
}