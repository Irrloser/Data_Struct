#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
//按宽度优先层次建树
const int OK=1;
const int ERROR=-1;
const int UNI=-2;
const int NE=-3;
using namespace std;
using ElemData=int;
using status=int;
struct node{
    char data;
    int key;
    node* lchild=nullptr,*rchild=nullptr;
};
struct dn{
    node *p;
    int d;
};
struct tree
{
    int depth=-1;
    node *root=nullptr;
};
node* FindNode(node *&p,int tar);
void visit(node*&);
void FreeBiTree(node *&head);
status IntalialBiTree(tree *&root);
status DestroyBiTree(tree *& T);
status ClearBiTree(tree *&T);
status CreatBiTree(tree *T);
status BiTreeDepth(tree*& T);
node* ROOT(const tree*& T);
status Value( tree *&T,char ans);
status Assign(tree*&T);
node* find_parent(node*&p,int tar);
node* Parent(tree *&T);
node* LeftChild(tree*&T);
node* RightChild(tree*&T);
node *RightSibiling(tree*& T);
node *LeftSibiling(tree*& T,int tar);
status InsertChild(tree *&T,int key,int LR,tree *&C);
node* find_leaf(node *&f);
status DeleteChild(tree*& T,int key);
void PreOrderTraverse(node *p);
status PreOrderTraverse(tree*& T);
void InOrderTraverse(node *p);
status InOrderTraverse(tree*& T);
void PostOrderTraverse(node *p);
status PostOrderTraverse(tree*& T);
status PostOrderTraverse(tree*& T);
status LevelOrderTraverse(tree*& T);
void LevelOrderTraverse(node*);
int Get_Depth(tree *&T);
bool BiTreeEmpty(tree*&);
