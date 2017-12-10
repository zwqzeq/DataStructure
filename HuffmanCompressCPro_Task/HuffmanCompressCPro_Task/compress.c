
#include "Huffman.h"
#include "Compress.h"

//ѹ������
void Compress()
{
	char desFile[80];//�ļ�ԭʼ����
	char rename[80] = " ";//�ļ�������
	char *suffix=".huf"; //�ļ���׺
	MyType maxLen, minLen, ch, bits, n, finalLength;
	int i;
	short LeafNum, codeNum;
	WeightType count = 0, Length = 0, FileLength;
	FILE *fp, *compressFile;
	SeqQueue *Q;
	HTNode *ht = NULL;
	char **hc = NULL, **Map = NULL, *p;
	printf("������Ҫ��ѹ�����ļ���Ҫ��·�� + �ļ���  ʾ����E:\\Pic.bmp��:");
	scanf("%s", desFile);
	strcpy(rename, desFile);//�Ȱ�ԭ�ļ�����rename���ٸ������ѹ������ļ�����׺
	strcat(rename, suffix);
	compressFile = fopen(rename, "wb");
	fp = fopen(desFile, "rb");	//ԭ�ļ�
	if (!fp || !compressFile) {
		puts("Cannot open file.");
		return;
	}
	ht = CreatHFM(fp, &LeafNum, &FileLength);	//������������,ͳ��Ҷ�Ӹ�����ԭ�ļ�����
	if (!FileLength) {
		fclose(fp);
		fclose(compressFile);
		free(ht);
		return;
	}
	Q = (SeqQueue *) malloc(sizeof(SeqQueue));
	InitQueue(Q);		//SEEK_SET:�ļ���ͷ SEEK_CUR:��ǰλ�� SEEK_END:�ļ���β
	hc = CrtHuffmanCode(ht, LeafNum);	//ȡ�ù�����0��1����,hc�ĳ���ΪLeafNum
	//MapΪ��ȡ����ö�λ���ٽ���ȫ��(256��)//
	Map = (char **)malloc(N * sizeof(char *));	//�ַ������
	if (!Map) {
		puts("����ռ�ʧ��");
		return;
	}
	for (i = 0; i < N; i++)	//��ʼ��
		Map[i] = NULL;
	for (i = 0; i < LeafNum; i++)	// ��λ������ָ������Map[256]
		Map[(int)(ht[i].ch)] = hc[i];
	fseek(compressFile, sizeof(WeightType) + sizeof(short) + 6 * sizeof(MyType), SEEK_SET);	//��ռ��λ�� 
	//��ռ��λ��,������ѹ��Ҷ�ӱ���ʣ����������볤
	MaxMinLength(compressFile, ht, hc, LeafNum, &maxLen, &minLen);	//�����봮����,˳����д�ַ���Ӧ���볤
	free(ht);
	codeNum = CodeToFile(compressFile, hc, LeafNum, Q, &finalLength);	//���ַ�ת��������Ʊ���д���ļ�,����ѹ�ɶ��ٸ�
	rewind(compressFile);	//ʹ�ļ�ָ���Ƶ���ʼprintf("ftelll = %d\n",ftell(compressFile));
	fseek(compressFile, sizeof(WeightType) + sizeof(MyType), SEEK_SET);
	fwrite(&LeafNum, sizeof(short), 1, compressFile);	//д��Ҷ�Ӹ���
	fwrite(&maxLen, sizeof(MyType), 1, compressFile);	//��봮����
	fwrite(&minLen, sizeof(MyType), 1, compressFile);	//����봮����
	fwrite(&codeNum, sizeof(short), 1, compressFile);	//��дҶ�ӱ���ѹ���ٸ�
	fwrite(&finalLength, sizeof(MyType), 1, compressFile);
	fseek(compressFile, 2 * LeafNum * sizeof(MyType) + codeNum, SEEK_CUR);
	fseek(fp, 0, SEEK_SET);
	//��ʼѹ��
	while (count < FileLength) {
		ch = fgetc(fp);	     
		++count;
		for (p = Map[ch]; *p != '\0'; p++)
			In_seqQueue(Q, *p);
		while (Q->length > 8)
		{
			bits = GetBits(Q);	//����8��Ԫ��,�ϳ�һ���ֽ�
			fputc(bits, compressFile);   
			Length++;
		}
	}			
	finalLength = Q->length;	
	n = 8 - finalLength;
	bits = GetBits(Q);
	for (i = 0; i < n; i++)
		bits = bits << 1;	//�ԡ�0����
	fwrite(&bits, sizeof(MyType), 1, compressFile);
	Length++;
	rewind(compressFile);
	fwrite(&Length, sizeof(WeightType), 1, compressFile);	//ѹ����ĳ�
	fwrite(&finalLength, sizeof(char), 1, compressFile);	//���Ĵ���
	Length = Length + 12 + codeNum;
	printf("\n");
	printf("ѹ����ɣ�\n");
	if (Length >= FileLength)
		puts("\nѹ������: 0.0%");
	else
		printf("\nѹ������: %.2lf%c\n",
		(double)((FileLength - Length) / (double)FileLength) * 100.0, '%');
	fclose(fp);
	fclose(compressFile);
	free(Q);
	free(hc);
	free(Map);
}

//�Ѷ������ַ���ת����8��0��1�ַ��������
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

//��ѹ��ͼƬ--------->��չ����
void UnCompress()
{
	MyType *str, MaxLength, MinLength, ch, *num, finalLength = 0, final = 0;
	FILE *cf, *uf;
	short NLeaf, Ncom;
	char CName[N], UName[N], **hc, *p, x, *buf;
	SeqQueue *Q = NULL;
	int i, j;
	WeightType srcLen = 0, thisFile = 0;
	fflush(stdin);		//������뻺������
	printf("������Ҫ����ѹ���ļ���Ҫ��·�� + �ļ���  ʾ����E:\\Pic.bmp.huf��:");
	scanf("%s", CName);
	if (CName[0] == '\0') {
		printf("try again:");
		scanf("%s", CName);
		fflush(stdin);
	}
	fflush(stdin);		//������뻺������
	printf("�������µ��ļ�����Ҫ��·�� + �ļ���  ʾ����E:\\123.bmp��:");
	scanf("%s", UName);
	if (UName[0] == '\0') {
		printf("try again:");
		scanf("%s", UName);
	}
	cf = fopen(CName, "rb");
	uf = fopen(UName, "wb");
	if (!cf || !uf) {
		puts("�޷����ļ�");
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
	//ѹ��Ҷ������x�����ʣ��
	if (!Q || !str || !num || !buf) {
		puts("�洢���󣡣���");
		exit(1);
	}
	InitQueue(Q);//��ʼ��
	fread(&Ncom, sizeof(short), 1, cf);
	fread(&final, sizeof(MyType), 1, cf);
	for (i = 0; i < NLeaf; i++)	//��ȡҶ�Ӽ����볤
	{
		fread(&str[i], sizeof(MyType), 1, cf);
		fread(&num[i], sizeof(MyType), 1, cf);
	}
	hc = (char **)malloc((NLeaf) * sizeof(char *));	//hcΪ������ָ������
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
	printf("���ڽ�ѹ�С�����������\n");
	printf("\n");
	while (thisFile < srcLen) {
		ch = fgetc(cf);	
		ToQueue(Q, ch);
		thisFile++;
		//���˺���г����봮�����ֵ       
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
	ch = fgetc(cf);	//��ȡ���һ��ѹ����getchar();
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
	printf("��ѹ��ϣ���򿪶�Ӧ�Ĵ��̲鿴\n");
}