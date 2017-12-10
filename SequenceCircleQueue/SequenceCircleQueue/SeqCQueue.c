#include"SeqCQueue.h"

//队列初始化
void QueueInitiate(SeqCQueue *Q) {
	 Q->rear = 0;//队尾标记置0                                       //之前此处出现错误，写成了int rear = 0;
	 Q->front = 0;//队头标记置0
	 Q->count = 0;//计数器初始化为0
}

//队列非空否
int QueueNotEmpty(SeqCQueue *Q) {
	if (Q->count != 0) {
		return 1;//队列非空返回1
	}
	return 0;//队列为空返回0
}

//入队列
int QueueAppend(SeqCQueue *Q, Datatype x) {
	if (Q->count >= Max) {//或者为	if (Q->count>0&&Q->rear==Q->front) 
		printf("队列已满，无法入队！");
		return 0;//入队失败
	}
	Q->seqCQue[Q->rear] = x;//元素入队列
	Q->count++;//队列中元素数目加一
	(Q->rear)++;//队尾标记向后移动一位
	if (Q->rear == Max) {
		Q->rear = 0;
	}
	return 1;//入队成功
}

/*int QueueAppend(SeqCQueue *Q, Datatype x) {
	if (Q->count > 0 && Q->rear == Q->front) {
		printf("队列已满，无法插入！");
		return 0;
	}
	else {
		Q->seqCQue[Q->rear] = x;
		Q->rear = (Q->rear + 1) % Max;
		Q->count++;
		return 1;
	}
}*/


//出队列
int  QueueDelete(SeqCQueue *Q, Datatype *d) {
	if (Q->count <= 0) {
		printf("队列已空，无法出队列！");
		return 0;//出队失败
	}
	*d = Q->seqCQue[Q->front];//将出队列的元素存放到d变量中
	Q->count--;//队列中数据个数减一
	Q->front++;//队头标记向后移动一位
	if (Q->front == Max) {
		Q->front = 0;
	}
	return 1;//出队成功
}

//取队头元素
int QueueGet(SeqCQueue *Q, Datatype *d) {
	if (Q->count == 0) {
		printf("队列已空，无法取队头数据！");
		return 0;
	}
	*d = Q->seqCQue[Q->front];//将取得的队头元素存放到变量d
	return 1;//取队头元素成功
}