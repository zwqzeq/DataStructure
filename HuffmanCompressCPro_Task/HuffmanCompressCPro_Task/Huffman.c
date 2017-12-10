//��������Թ��������Ĳ���
#include "Huffman.h"
#include "Compress.h"

//��ʼ����
int InitQueue(SeqQueue * Q)
{
	if (!Q)
		return 1;
	Q->tag = Empty;
	Q->front = Q->rear = 0;
	Q->length = 0;
	return 0;
}

//��������
int In_seqQueue(SeqQueue * Q, char x)
{
	if (Q->front == Q->rear && Q->tag == SOME)
		return FULL;	

	Q->elem[Q->rear] = x;
	Q->rear = (Q->rear + 1) % Maxsize;
	Q->length++;
	Q->tag = SOME;
	return SOME;
}

//���ݳ�����
int Out_Queue(SeqQueue * Q, char *x)
{
	if (Q->tag == Empty)
		return Empty;

	*x = Q->elem[Q->front];
	Q->length--;
	Q->front = (Q->front + 1) % Maxsize;

	if (Q->front == Q->rear)
		Q->tag = Empty;

	return SOME;
}

//ѡ����С��������
void SelectMinTree(HTNode * ht, int n, int *k)
{
	int i, temp;
	WeightType min;
	for (i = 0; i <= n; i++) {
		if (0 == ht[i].parent) {
			min = ht[i].weight;	
			temp = i;
			break;
		}
	}
	for (i++; i <= n; i++) {
		if (0 == ht[i].parent && ht[i].weight < min) {
			min = ht[i].weight;
			temp = i;
		}
	}
	*k = temp;
}
// �Թ����������򣬲�ͳ��Ҷ������
int SortTree(HTNode * ht)
{
	short i, j;
	HTNode tmp;
	for (i = N - 1; i >= 0; i--) {
		for (j = 0; j < i; j++)
			if (ht[j].weight < ht[j + 1].weight) {
				tmp = ht[j];
				ht[j] = ht[j + 1];
				ht[j + 1] = tmp;
			}
	}
	for (i = 0; i < N; i++)
		if (0 == ht[i].weight)
			return i;
	//����Ҷ�Ӹ���
	return i;		
}

//�������0-1�ַ������
//��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
char **CrtHuffmanCode(HTNode * ht, short LeafNum)
{
	char *cd, **hc;	//����
	int i, start, p, last;
	hc = (char **)malloc((LeafNum) * sizeof(char *));	//����n�������ͷָ��
	if (1 == LeafNum)	//ֻ��һ��Ҷ�ӽڵ�ʱ 
	{
		hc[0] = (char *)malloc((LeafNum + 1) * sizeof(char));
		strcpy(hc[0], "0");
		return hc;
	}
	cd = (char *)malloc((LeafNum + 1) * sizeof(char));	//������ǰ����Ĺ����ռ� 
	cd[LeafNum] = '\0';	//����������λ��ű��룬���ȴ�ű�������� 
	printf("Դ�ļ�������Ϊ��\n");
	for (i = 0; i < LeafNum; i++) {	//��n��Ҷ�ӽ���Ӧ�Ĺ��������� 
		start = LeafNum;	//��ʼ��������ʼָ��
		last = i;
		for (p = ht[i].parent; p != 0; p = ht[p].parent) {	//��Ҷ�ӵ����������� 
			if (ht[p].LChild == last)
				cd[--start] = '0';	//���֧��0 
			else
				cd[--start] = '1';	//�ҷ�֧��1 
			last = p;
		}
		hc[i] = (char *)malloc((LeafNum - start) * sizeof(char));	//Ϊ��i���������ռ� 
		strcpy(hc[i], &cd[start]);
		printf("%s",&cd[start]);
	}			
	free(cd);
	return hc;
}

//����һ����������
HTNode *CreatHFM(FILE * fp, short *n, WeightType * FileLength)
{
	HTNode *ht = NULL;
	int i, m, s1, s2;
	MyType ch;
	ht = (HTNode *) malloc(2 * N * sizeof(HTNode));
	if (!ht)
		exit(1);
	for (i = 0; i < N; i++) {
		ht[i].weight = 0;
		ht[i].ch = (MyType) i;	//1-n��ch Ϊ�ַ�����ʼ�� 
	}
	for (*FileLength = 0; !feof(fp); ++(*FileLength)) {
		ch = fgetc(fp);	   
		ht[ch].weight++;	
	}
	--(*FileLength);//ȥ���ļ�������ĳ���
	*n = SortTree(ht);
	m = *n * 2 - 1;	
	if (1 == *n) {
		ht[0].parent = 1;
		return ht;
	} else if (0 > *n)
		return NULL;

	for (i = m - 1; i >= 0; i--) {
		ht[i].LChild = 0;
		ht[i].parent = 0;
		ht[i].RChild = 0;
	}

	//������Ҷ�ӽ��,����������
	for (i = *n; i < m; i++)	
	{			
		//��ht[0]~ht[i-1]�ķ�Χ��ѡ������parentΪ0��weight��С�Ľ�㣬����ŷֱ�ֵ��s1��s2����
		SelectMinTree(ht, i - 1, &s1);
		ht[s1].parent = i;
		ht[i].LChild = s1;
		SelectMinTree(ht, i - 1, &s2);
		ht[s2].parent = i;
		ht[i].RChild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}	

	//��������������� 
	return ht;
}

//�Ӷ�����ȡ8���ַ���0��1����ת����һ���ֽ�
MyType GetBits(SeqQueue * Q)
{
	MyType i, bits = 0;
	char x;
	for (i = 0; i < 8; i++) {
		if (Out_Queue(Q, &x) != Empty) {
			if ('0' == x)
				bits = bits << 1;
			else
				bits = (bits << 1) | 1;
		} else
			break;
	}			
	return bits;
}

//�������̣����볤��
void MaxMinLength(FILE * File, HTNode * ht, char **hc, short NLeaf, MyType * Max, MyType * Min)
{
	int i;
	MyType length;
	*Max = *Min = strlen(hc[0]);
	for (i = 0; i < NLeaf; i++) {
		length = strlen(hc[i]);
		fwrite(&ht[i].ch, sizeof(MyType), 1, File);	//�ַ��Ͷ�Ӧ��
		fwrite(&length, sizeof(MyType), 1, File);	//���볤��д���ļ�
		if (length > *Max)
			*Max = length;
		if (length < *Min)
			*Min = length;
	}
}

//�ѳ��ֹ����ַ��������ѹ��д���ļ�
short CodeToFile(FILE * fp, char **hc, short n, SeqQueue * Q, MyType * length)
{
	int i;
	char *p;
	MyType j, bits;
	short count = 0;
	for (i = 0; i < n; i++)	// ��n��Ҷ��ѹ����д���ļ�
	{
		for (p = hc[i]; '\0' != *p; p++)
			In_seqQueue(Q, *p);
		while (Q->length > 8) {	//  puts("����");
			bits = GetBits(Q);	//����8��Ԫ��
			fputc(bits, fp);
			count++;
		}
	}
	*length = Q->length;
	i = 8 - *length;
	bits = GetBits(Q);	//ȡ8������Ӳ���
	for (j = 0; j < i; j++)
		bits = bits << 1;	
	fputc(bits, fp);	
	count++;		
	InitQueue(Q);
	return count;
}