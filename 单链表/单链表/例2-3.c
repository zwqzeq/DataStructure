#include<stdio.h>
#include<malloc.h>
typedef int DataType;
#include "LinList.h"

void main() {
	SLNode *head;
	int i, x;
	ListInitiate(&head);
	for (i = 0; i < 10; i++) 
		ListInsert(head, i, i + 1);
		ListDelete(head, 4, &x);
		for (i = 0; i < ListLength(head); i++) {
			ListGet(head, i, &x);
			printf("%d   ", x);
		}
		Destroy(&head);                //³·ÏúÁ´±í
	
}