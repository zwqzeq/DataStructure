
void InThread(ThreadBiNode *current, ThreadBiNode **pre) {
	//中序线索化二叉树
	if(InThread!=NULL) {      //current 为当前结点的指针，pre为当前结点的中序前驱结点指针
	    InThread(current->leftChild,pre);//中序线索化左子树
		if(current->leftChild==NULL){
		    curent->leftThread=1;//建立左线索标记
			current->leftChild=*pre;//建立左线索指针
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
			   (*pre)->rightThread=1;//建立右线索标记
	          (*pre)->rightChild=current;//建立右线索指针     
		}
		 else {
			 current->rightThread=0;
		 }
		 *pre = current;
		 InThread(current->rightChild,pre);
	}
}

void CreatInThread(ThreadBiNode **root){
     //创建中序线索化二叉树
	ThreadBiNode *t=*root;
	ThreadBiNode *current,*pre = *root;
	//建立头结点
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