
void InThread(ThreadBiNode *current, ThreadBiNode **pre) {
	//����������������
	if(InThread!=NULL) {      //current Ϊ��ǰ����ָ�룬preΪ��ǰ��������ǰ�����ָ��
	    InThread(current->leftChild,pre);//����������������
		if(current->leftChild==NULL){
		    curent->leftThread=1;//�������������
			current->leftChild=*pre;//����������ָ��
		} else{
		     current->leftThread=0;
		} 
		if(current->rightChild!=NULL){
		  current->rightThread=0;//
		}
		else{
		  current->rightThread=1;
		   }
		 if((*prq)->rightChild==NULL) {
			   (*pre)->rightThread=1;//�������������
	          (*pre)->rightChild=current;//����������ָ��     
		}
		 else {
			 current->rightThread=0;
		 }
		 *pre = current;
		 InThread(current->rightChild,pre);
	}
}

void CreatInThread(ThreadBiNode **root){
     //��������������������
	ThreadBiNode *t=*root;
	ThreadBiNode *current,*pre = *root;
	//����ͷ���
	*root=(ThreadBiNode *)malloc(sizeof(ThreadNode));
	if(t==NULL){
	   (*root)->leftThread = 0;
	   (*root)->rightThread = 1;
	   (*root)->leftChild = *root;
	   (*root)->rightChild = *root;
	}
	else{
	    current =t;
		(*root)->leftChild=t;
		(*root)->leftThread=0;

	}

}