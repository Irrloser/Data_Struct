#include"bitree.h"
void FreeBiTree(node *&head)
{
    node**now =&head;
    if(head==nullptr) return;
    queue<node**> q;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if((*now)->lchild!=nullptr)
            q.push(&(*now)->lchild);
        if((*now)->rchild!=nullptr)
            q.push(&(*now)->rchild);
        free(*now);
        *now=nullptr;
    }
}

status IntalialBiTree(tree *&root)
{
    if(root==nullptr)
    {root=(tree*)malloc(sizeof(tree));
    root->depth=0;
    root->root=nullptr;
    printf("初始化成功\n");
    return OK;
    }
    else {
        printf("已初始化\n");
        return ERROR;
    }
}

status DestroyBiTree(tree *& T)
{
    if(T->depth==-1) return ERROR;
    if(T->root==nullptr) return ERROR;
    FreeBiTree(T->root);
    free(T);
    T=nullptr;
    printf("删除成功\n");
    return OK;
}
status ClearBiTree(tree *&T)
{
    if(T->depth==-1)    {printf("ERROR\n");return ERROR;}
    if(T->root==nullptr) {printf("ERROR\n");return ERROR;}
    FreeBiTree(T->root);
    T->depth=0;
    T->root=nullptr;
    printf("清空成功\n");
    return OK;
}
status CreatBiTree_2(tree *T)
{
    if(T->depth<0||T->root!=nullptr) {printf("ERROR");return ERROR;}
    printf("请输入数据个数:");
    int i,num;
    cin>>num;
    i=0;
    node** q[100];
    int head=0,tail=0;
    node** now;
    q[tail++]=&T->root;
    cout<<"key is an interger."<<endl;
    cout<<"data is a char"<<endl;
    cout<<"key and data are separated by a space"<<endl;
    cout<<"sample:2 a"<<endl;
    while(i<num)
    {
        now=q[head++];
        *now=new node;
        printf("input key and data:");
        scanf("%d",&((*now)->key));
        getchar();
        (*now)->data=getchar();
        //visit(now);
        getchar();
        i++;
        q[tail++]=&((*now)->lchild);
        q[tail++]=&((*now)->rchild);
    }
    //LevelOrderTraverse(T->root);
    //printf("%p\n",T->root->lchild);
    printf("创建成功\n");
    LevelOrderTraverse(T->root);
    return OK;
}
status CreatBiTree(tree *T)
{
    if(T->depth<0||T->root!=nullptr)   return ERROR;
    printf("请输入数据个数:");
    int i,num;
    cin>>num;
    i=0;
    queue<node**> q;
    q.push(&T->root);
    node**now =&T->root;
    //printf("%p\n",T->root);
    cout<<"key is an interger."<<endl;
    cout<<"data is a char"<<endl;
    cout<<"key and data are separated by a space"<<endl;
    cout<<"sample:2 a"<<endl;
    while(!q.empty()&&i<num)
    {

        now=q.front();
        //printf("%p\n",now);
        q.pop();
        *now=new node;
        //now=(node*)malloc(sizeof(node));
        //printf("%p\n",now);
        //now->lchild=nullptr,now->rchild=nullptr;
        printf("input key and data:");
        scanf("%d",&((*now)->key));
        getchar();
        (*now)->data=getchar();
        //visit(now);
        getchar();
        i++;
        q.push(&(*now)->lchild);
        //cout<<q.size()<<endl;
        q.push(&(*now)->rchild);
        //cout<<q.size()<<endl;
        q.pop();
    }
    while(!q.empty())
        q.pop();
    LevelOrderTraverse(T->root);
    //printf("%p\n",T->root->lchild);
    //printf("%p %d\n",T->root,T->root->key);
    return OK;
}
/*void Getdata(node*& now)
{
  int ans=0,i;
  for(i=0;now->d[i]>='0'&&now->d[i]<='9';++i)
  {
    ans*=10;
    ans+=now->d[i]-'0';
  }
  now->data=now->d[i];
}*/
status BiTreeDepth(tree*& T)
{
    if(!T||T->root==nullptr) {printf("ERROR\n");return ERROR;}
    else T->depth=Get_Depth(T);
    printf("depth:%d\n",T->depth);
    return OK;
}
node* ROOT( tree*& T)
{
    visit(T->root);
    return T->root;
}
status Value(tree *&T,char ans)
{
    if(!T||T->root==nullptr) {printf("ERROR\n");return ERROR;}
    int tmp;
    printf("input target node's key:");
    scanf("%d",&tmp);
    node *tp=FindNode(T->root,tmp);
    if(tp==nullptr) {printf("not exsit\n");return NE;}
    else{
        ans=tp->data;
        visit(tp);
        return OK;
    }

}
node* FindNode(node *&p,int tar)
{
    queue<node**> q;
    q.push(&p);
    node** now;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if((*now)->key==tar)
        {
            return *now;
        }
        if((*now)->lchild!=nullptr)
            q.push(&(*now)->lchild);
        if((*now)->rchild!=nullptr)
            q.push(&(*now)->rchild);
    }
    return NULL;
}

status Assign(tree*&T)
{
    if(!T||!T->root) {printf("ERROR\n");return ERROR;}
    int tar;
    printf("input target key:");
    scanf("%d",&tar);
    getchar();
    node *tp=FindNode(T->root,tar);
    if(tp==nullptr)
    {
        printf("not exist\n");
        return NE;
    }
    else{
        printf("Input data:");
        scanf("%c",&tp->data);
        print("赋值成功\n");
        return OK;
    }
}
//node* find_parent(node*p,int tar);
node* Parent(tree *&T)
{
    if(!T){printf("未初始化\n");return NULL;}
    if(T->root==nullptr){printf("空树\n");return NULL;}
    int tar;
    printf("input target:");
    cin>>tar;
    node *tmp=find_parent(T->root,tar);
    if(tmp==NULL)
    printf("未找到\n");
    else
        printf("parent's key:%d  parent's data:%c\n",tmp->key,tmp->data);
        /*if(C->root->lchild!=nullptr)
            node* leaf=find_leaf(C->root->rchild);
        leaf->lchild=C->root->lchild;
        C->root->lchild=tmp;mp->data);*/
    return tmp;
}

node* find_parent(node*&p,int tar)
{
     queue<node**> q;
    q.push(&p);
    node** now;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(((*now)->lchild!=nullptr&&(*now)->lchild->key==tar)||((*now)->rchild!=nullptr&&(*now)->rchild->key==tar))
            return *now;
        if((*now)->lchild!=nullptr)
            q.push(&(*now)->lchild);
        if((*now)->rchild!=nullptr)
            q.push(&(*now)->rchild);
    }
    return NULL;
}
node* LeftChild(tree*&T)
{
    if(!T||!T->root){printf("ERROR\n");return nullptr;}
    int tar;
    printf("input target key:");
    cin>>tar;
    node* tmp=FindNode(T->root,tar);
    //visit(tmp);
    if(!tmp||tmp->lchild==nullptr){printf("不存在\n");return nullptr;}
    else
        visit(tmp->lchild);
        return tmp->lchild;
}
node* RightChild(tree*&T)
{
    if(!T||!T->root){printf("ERROR\n");return nullptr;}
    int tar;
    printf("input target key:");
    cin>>tar;
    node* tmp=FindNode(T->root,tar);
    if(!tmp||tmp->rchild==nullptr){printf("不存在\n");return nullptr;}
    else
        visit(tmp->rchild);
    return tmp->lchild;
}
node *RightSibiling(tree*&T)
{
    if(!T||!T->root){printf("ERROR\n");return nullptr;}
    int tar;
    printf("input target key:");
    cin>>tar;
    node*tmp=find_parent(T->root,tar);
     if(tmp!=nullptr&&tmp->lchild!=nullptr&&tmp->lchild->key==tar&&tmp->rchild!=nullptr){visit(tmp->rchild);return tmp->rchild;}
    else{
        printf("不存在\n");
        return nullptr;
    }
}
node *LeftSibiling(tree*& T)
{
    if(!T||!T->root){printf("ERROR\n");return nullptr;}
    int tar;
    printf("input target key:");
    cin>>tar;
    node*tmp=find_parent(T->root,tar);
    if(tmp!=nullptr&&tmp->rchild!=nullptr&&tmp->rchild->key==tar&&tmp->lchild!=nullptr)
    {
        visit(tmp->lchild);
        return tmp->lchild;
    }
    else
    {
        printf("不存在\n");
        return nullptr;
    }
}
void visit(node*&tmp)
{
    //printf("debugger\n");
    printf("key:%d  data:%c\n",tmp->key,tmp->data);
}
//1 L 向C的左子树插入
//0 R
status InsertChild(tree *&T,int LR,tree *&C)
{
    if(!T||!T->root||!C||!C->root)
    {
        printf("ERROR\n");
        return ERROR;
    }
    int key;
    printf("input target key:");
    cin>>key;
    node *tmp=FindNode(T->root,key);
    node *leaf;
    if(tmp==nullptr){printf("p不存在\n");}
    if(LR==1)
    {
        if(C->root->lchild!=nullptr)
            leaf=find_leaf(C->root->rchild);
        leaf->lchild=C->root->lchild;
        C->root->lchild=tmp;
    }
    else{
        if(C->root->rchild!=nullptr)
            leaf=find_leaf(C->root->lchild);
        leaf->rchild=C->root->rchild;
        C->root->rchild=tmp;
    }
    return OK;
}
node* find_leaf(node*& f)
{
    queue<node**> q;
    q.push(&f);
    node** now;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if((*now)->lchild==nullptr&&(*now)->rchild==nullptr)
            return *now;
        if((*now)->lchild!=nullptr)
            q.push(&(*now)->lchild);
        if((*now)->rchild!=nullptr)
            q.push(&(*now)->lchild);
    }
    return nullptr;
}
status DeleteChild(tree*& T)
{
    if(!T||!T->root){printf("ERROR\n"); return ERROR;}
    int key;
    printf("input target key:");
    cin>>key;
    node *tmp=FindNode(T->root,key);
    if(tmp==nullptr) {printf("p不存在\n");return ERROR;}
    FreeBiTree(tmp);
    tmp=nullptr;
    return OK;

}
status PreOrderTraverse(tree*& T)
{
    if(!T||!T->root)
    {
        printf("ERROR\n");
        return ERROR;
    }
    PreOrderTraverse(T->root);
    return OK;
}
void PreOrderTraverse(node *p)
{
    if(p==nullptr) return;
    visit(p);
    PreOrderTraverse(p->lchild);
    PreOrderTraverse(p->rchild);
}
status InOrderTraverse(tree*& T)
{
    if(!T||!T->root)
    {
        printf("ERROR\n");
        return ERROR;
    }
    InOrderTraverse(T->root);
    return OK;
}
void InOrderTraverse(node *p)
{
    if(p==nullptr) return;
    InOrderTraverse(p->lchild);
    visit(p);
    InOrderTraverse(p->rchild);
}
void PostOrderTraverse(node *p);
status PostOrderTraverse(tree*& T)
{
    if(!T||!T->root)
    {
        printf("ERROR\n");
        return ERROR;
    }
    PostOrderTraverse(T->root);
    return OK;
}
void PostOrderTraverse(node *p)
{
    if(p==nullptr) return;

    PostOrderTraverse(p->lchild);
    PostOrderTraverse(p->rchild);
     visit(p);
}

status LevelOrderTraverse(tree*& T)
{
    if(!T||!T->root)
    {
        printf("ERROR\n");
        return ERROR;
    }
    LevelOrderTraverse(T->root);
    return OK;
}
void LevelOrderTraverse(node *p)
{
    queue<node*> q;
    //printf("1error\n");

    //printf("%p\n",p);
    node* now=p;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        visit(now);
        if(now->lchild!=nullptr)
            {
                q.push(now->lchild);
                //printf("3%p\n",now->lchild);
            }
        if(now->rchild!=nullptr)
            q.push(now->rchild);
    }
}
int Get_Depth(tree *&T)
{
    dn now,next;
    queue<dn> q;
    now.d=0;
    now.p=T->root;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if((now.p)->lchild!=nullptr)
        {
            next.p=now.p->lchild;
            next.d=now.d+1;
            q.push(next);
        }
        if(now.p->rchild!=nullptr)
        {
            next.p=now.p->rchild;
            next.d=now.d+1;
            q.push(next);
        }
    }
    return now.d;
}
bool BiTreeEmpty(tree*&T)
{
    if(!T) {printf("未初始化\n");return 0;}
    if(!T->root){printf("空树\n");return 0;}
    else printf("非空树\n");
    return 1;
}
int main(void){
  tree *T[100];  int op=1;
  int i,j;
  memset(T,0,sizeof(T));
  while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. IntiaLBiTree     11. LeftChild\n");
	printf("    	  2. CreatBiTree      12. RightChild\n");
	printf("    	  3. ClearList        13. LeftSibling \n");
	printf("    	  4. DestroyBiTree    14. RightSibling\n");
	printf("    	  5. BiTreeEmpty      15. InsertChild\n");
	printf("    	  6. BiTreeDepth      16. DeleteChild\n");
	printf("    	  7. ROOT             17. PreOrderTraverse\n");
	printf("    	  8. Value            18. InOrderTraverse\n");
	printf("    	  9. Assign           19. PostOrderTraverse\n");
	printf("    	 10. Parents          20. LevelOrderTraverse\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~12]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiaList功能待实现！\n");
		 cout<<"input target tree i:";
		 cin>>i;
         IntalialBiTree(T[i]);
		 getchar();getchar();
		 break;
	   case 2:
         cout<<"input target tree i:";
		 cin>>i;
		 CreatBiTree_2(T[i]);
		 getchar();getchar();
		 break;
	   case 3:
         cout<<"input target tree i:";
		 cin>>i;
         ClearBiTree(T[i]);
		 getchar();getchar();
		 break;
	   case 4:
         cout<<"input target tree i:";
		 cin>>i;
		 DestroyBiTree(T[i]);
		 getchar();getchar();
		 break;
	   case 5:
         cout<<"input target tree i:";
		 cin>>i;
         BiTreeEmpty(T[i]);
		 getchar();getchar();
		 break;
	   case 6:
         cout<<"input target tree i:";
		 cin>>i;
		 BiTreeDepth(T[i]);
		 getchar();getchar();
		 break;
	   case 7:
         cout<<"input target tree i:";
		 cin>>i;
		 ROOT(T[i]);
		 getchar();getchar();
		 break;
	   case 8:
         cout<<"input target tree i:";
		 cin>>i;
         char ans;
		 Value(T[i],ans);
		 getchar();getchar();
		 break;
	   case 9:
         cout<<"input target tree i:";
		 cin>>i;
		 Assign(T[i]);
		 getchar();getchar();
		 break;
	   case 10:
         cout<<"input target tree i:";
		 cin>>i;
         Parent(T[i]);
		 getchar();getchar();
		 break;
	   case 11:
		 //printf("\n----ListDelete功能待实现！\n");
		 cout<<"input target tree i:";
		 cin>>i;
		 LeftChild(T[i]);
		 getchar();getchar();
		 break;
       case 12:
        cout<<"input target tree i:";
        cin>>i;
        RightChild(T[i]);
        getchar();getchar();
        break;
       case 13:
        cout<<"input target tree i:";
        cin>>i;
        LeftSibiling(T[i]);
        getchar();getchar();
        break;
       case 14:
        cout<<"input target tree i:";
        cin>>i;
        RightSibiling(T[i]);
        getchar();getchar();
        break;
       case 15:
         int LR;
         cout<<"input target tree i and j:";
         cin>>i>>j;
         cout<<"input L(1) or R(0):";
         cin>>LR;
         InsertChild(T[i],LR,T[j]);
         LevelOrderTraverse(T[j]->root);
         getchar();getchar();
         break; break;
       case 16:
         cout<<"input target tree i:";
		 cin>>i;
         DeleteChild(T[i]);
         getchar();getchar();
         break;
       case 17:
         cout<<"input target tree i:";
		 cin>>i;
		 PreOrderTraverse(T[i]);
		 getchar();getchar();
		 break;
       case 18:
         cout<<"input target tree i:";
		 cin>>i;
		 InOrderTraverse(T[i]);
		 getchar();getchar();
		 break;
        case 19:
         cout<<"input target tree i:";
		 cin>>i;
		 PostOrderTraverse(T[i]);
		 getchar();getchar();
		 break;
	   case 20:
         cout<<"input target tree i:";
		 cin>>i;
		 LevelOrderTraverse(T[i]);
		 getchar();getchar();
		 break;
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
}//end of main()
