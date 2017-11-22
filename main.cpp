/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE -1
#define OK 1
#define ERROR -2

typedef int status;
typedef int ElemType; //数据元素类型定义
using namespace std;
/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
struct SqList{  //顺序表（顺序结构）的定义
	ElemType * elem=NULL;
	int length;
	int listsize;
};
vector<SqList>
const char* filename="data.bin";
bool flag=false;
/*-----page 19 on textbook ---------*/
status IntiaList(SqList& );
status DestroyList(SqList &);
status ClearList(SqList &);
status ListEmpty(SqList &);
status ListLength(SqList &);
status GetElem(const SqList &,int &i,ElemType & e);
status LocateElem(const SqList &L,ElemType &e); //简化过
status PriorElem(const SqList &L,ElemType cur,ElemType & pre_e);
status NextElem(const SqList &L,ElemType cur,ElemType & next_e);
status ListInsert(SqList & L,int &i,ElemType &e);
status ListDelete(SqList & L,int i,ElemType &e);
status ListTrabverse(SqList &L); //简化过
status SaveList(FILE*,SqList &);
status LoadList(FILE*,SqList &);
/*--------------------------------------------*/
int main(void)
{
    SqList L;  int op=1;
    int i,tmp;
    FILE* fp;
  while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. IntiaList       7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty     10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem       12. ListTrabverse\n");
	printf("         13. LoadList      14. SaveList     \n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~14]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiaList功能待实现！\n");
        IntiaList(L);
		 getchar();getchar();
		 break;
	   case 2:
		 //printf("\n----DestroyList功能待实现！\n");
		 DestroyList(L);
		 getchar();getchar();
		 break;
	   case 3:
         //printf("\n----ClearList功能待实现！\n");
		 ClearList(L);
		 getchar();getchar();
		 break;
	   case 4:
         //printf("\n----ListEmpty功能待实现！\n");
		 ListEmpty(L);
		 getchar();getchar();
		 break;
	   case 5:
		 //printf("\n----ListLength功能待实现！\n");
		 ListLength(L);
		 getchar();getchar();
		 break;
	   case 6:
		 //printf("\n----GetElem功能待实现！\n");
		 if(GetElem(L,i,tmp)==OK)
            //printf("查找的数据为:%d\n",tmp);
		 getchar();getchar();
		 break;
	   case 7:
		 //printf("\n----LocateElem功能待实现！\n");
		 tmp=LocateElem(L,i);
		 getchar();getchar();
		 break;
	   case 8:
		 //printf("\n----PriorElem功能待实现！\n");
         PriorElem(L,i,tmp);
		 getchar();getchar();
		 break;
	   case 9:

         NextElem(L,i,tmp);
		 getchar();getchar();
		 break;
	   case 10:
		 //printf("\n----ListInsert功能待实现！\n");

        ListInsert(L,i,tmp);
		 getchar();getchar();
		 break;
	   case 11:
		 //printf("\n----ListDelete功能待实现！\n");
		 ListDelete(L,i,tmp);
		 getchar();getchar();
		 break;
	   case 12:
		 //printf("\n----ListTrabverse功能待实现！\n");
		 //if(!ListTrabverse(L)) printf("线性表是空表！\n");
		 ListTrabverse(L);
		 getchar();getchar();
		 break;
       case 14:
        SaveList(fp,L);
        getchar();getchar();
        break;
       case 13:
        LoadList(fp,L);
        getchar();getchar();
	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("欢迎下次再使用本系统！\n");
}//end of main()
/*--------page 23 on textbook --------------------*/
/**
 * 函数名称：InitiaList
 * 函数参数：线性表L的地址
 * 函数功能：构造一个空的线性表
 * 返回值：成功构造返回OK，否则返回ERROR
 **/
status IntiaList(SqList &L)
{
    if(flag==true) {cout<<"已存在"<<endl;return ERROR;}
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
	L.length=0;
    L.listsize=LIST_INIT_SIZE;
    flag=true;
	printf("初始化成功\n");
	return OK;
}
status ListTrabverse(SqList &L)
{
   int i;
   if(L.elem==NULL){printf("顺序表未初始化\n");return ERROR;}
   printf("\n-----------all elements -----------------------\n");
   for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
   printf("\n------------------ end ------------------------\n");
   return L.length;
}
/**
 * 函数名称：DestroyList
 * 函数参数：线性表L的地址
 * 函数功能：删除线性表
 * 返回值：成功销毁返回OK，否则返回ERROR
 **/
status DestroyList(SqList & L)
{
    if(L.elem==NULL) {printf("未初始化顺序表!\n");  return ERROR;}
    free(L.elem);
    L.elem=NULL;
    flag=false;
    printf("成功\n");
    return OK;
}
/**
 * 函数名称：ClearList
 * 函数参数：线性表L的地址
 * 函数功能：重置线性表
 * 返回值：成功置空返回OK，否则返回ERROR
 **/
status ClearList(SqList &L)
{
    if(L.elem==NULL){printf("未初始化顺序表!\n");  return ERROR;}
    L.length=0;
    printf("AC\n");
    return  OK;
}
/**
 * 函数名称：ListEmpty
 * 函数参数：线性表L
 * 函数功能：判断线性表是否为空
 * 返回值：若L为空表则返回TRUE，否则返回FALSE
 **/
status ListEmpty(SqList &L)
{
    if(L.elem==NULL) {printf("未初始化顺序表!\n");  return ERROR;}
    if(!L.length){printf("empty\n");return true;}
    else {
            printf("not empty\n");
            return false;
        }
}
/**
 * 函数名称：ListLength
 * 函数参数：线性表L
 * 函数功能：计算线性表L中数据元素个数；
 * 返回值：成功返回L中数据元素个数，失败返回ERROR
 **/
status ListLength(SqList &L)
{
    if(L.elem==NULL) {printf("未初始化顺序表!\n");  return ERROR;}
    printf("表长;%d\n",L.length);
    return OK;
}
/**
 * 函数名称：GetElem
 * 函数参数：线性表L，e为第i个数据的地址；
 * 函数功能：查找并显示L中第i个元素的值；
 * 返回值：成功则返回第i个元素的值，否则返回ERROR
 **/
status GetElem(const SqList &L,int &i,ElemType & e)
{
    if(L.elem==NULL) {printf("未初始化顺序表!\n");  return ERROR;}
    printf("请输入:");
		 scanf("%d",&i);
    if(i<1||i>L.length) {printf("overflow\n");return ERROR;}
    e=*(L.elem+i-1);
    printf("查找的数据为:%d\n",e);
    return  OK;
}
/**
 * 函数名称：LocateElem
 * 函数参数：线性表L，相对比的元素值；
 * 函数功能：查找L中与e相同数据所在的位序；位序从1开始
 * 返回值：成功则返回第一个与e相同的数据的位序，不存在则返回0，其余情况返回ERROR
 **/
status LocateElem(const SqList &L,ElemType &e) //简化过
{
    if(L.elem==NULL) {printf("未初始化顺序表!\n");  return ERROR;}
    printf("请输入:");
    scanf("%d",&e);
    for(int i=1;i<=L.length;++i)
    {

        if(*(L.elem+i-1)==e)
        {   printf("location: %d\n",i);
            return  OK;
        }
    }
    printf("not exist!\n");s
    return ERROR;
}
/**
 * 函数名称：PriorElem
 * 函数参数：线性表L，查找的数据cur_e,前驱pre_e；
 * 函数功能：查找L中与cur_e相同的第一个数据，并返回其前驱
 * 返回值：成功则返回与cur_e相同的第一个数据，并返回其第一个前驱；若无前驱以及其他情况则返回ERROR
 **/
status PriorElem(const SqList &L,ElemType cur,ElemType & pre_e)
{
    if(L.elem==NULL){printf("未初始化顺序表!\n");  return ERROR;}
    printf("input:");
    scanf("%d",&cur);
    for(int i=2;i<=L.length;++i)
    if(*(L.elem+i-1)==cur)
    {
        pre_e=*(L.elem+i-2);
         printf("前驱为:%d\n",pre_e);
        return true;
    }
printf("PriorElement not exist\n");
return ERROR;
}
/**
 * 函数名称：NextElem
 * 函数参数：线性表L，查找的数据cur_e,后驱next_e；
 * 函数功能：查找L中与cur_e相同的第一个数据，并返回其后驱
 * 返回值：成功则返回与cur_e相同的第一个数据，并返回其后驱；若无后驱以及其他情况则返回ERROR
 **/
status NextElem(const SqList &L,ElemType cur,ElemType & next_e)
{
    if(L.elem==NULL){printf("未初始化顺序表!\n");  return ERROR;}
    printf("请输入:");
    scanf("%d",&cur);
    for(int i=1;i<L.length;++i)
    if(*(L.elem+i-1)==cur)
    {
        //1printf("%d\n",*(L.elem+i-1));
        next_e=*(L.elem+i);
        printf("后继为:%d\n",next_e);
        return true;
    }
    printf("Next element not exist\n");
return ERROR;
}
/**
 * 函数名称：ListInsert
 * 函数参数：线性表L的地址，插入的位置i，插入的数据元素e。
 * 函数功能：在L的第i个位置之前插入新的数据元素e；若已插满，则按照分配增量，分配更大的空间。
 * 返回值：成功插入返回OK，否则返回ERROR
 **/
status ListInsert(SqList &L,int &i,ElemType &e)
{
    if(L.elem==NULL)  {printf("UNINITIALIZED\n");  return ERROR;}
    if(L.length==LIST_INIT_SIZE)
    {
        L.elem=(int *)realloc(L.elem,L.listsize+10);
        L.listsize+=10;
    }
    printf("input:");
    scanf("%d%d",&e,&i);
    if(i<0||i>L.length+1)
    {
        printf("overflow\n");
        return ERROR;
    }
    L.length+=1;
    for(int j=L.length;j>=i;--j)
        *(L.elem+j)=*(L.elem+j-1);
    *(L.elem+i-1)=e;
    printf("插入成功!\n");
    return true;
}
/**
 * 函数名称：ListDelete
 * 函数参数：线性表L的地址，删除的位序i，指针e的地址。
 * 函数功能：删除L的第i个数据元素，用e返回其值。
 * 返回值：成功删除返回OK，否则返回ERROR
 **/
status ListDelete(SqList &L,int i,ElemType &e)
{
    if(L.elem==NULL)  {printf("未初始化顺序表!\n");  return ERROR;}
    if(L.length==0){printf("underflow\n");return ERROR;}
    printf("请输入:");
    scanf("%d",&i);
    if(i<0||i>L.length)
    {
        printf("越界\n");
        return ERROR;
    }
    e=*(L.elem+i-1);
    for(int j=i;j<L.length;++j)
    *(L.elem+j-1)=*(L.elem+j);
    L.length-=1;
    printf("删除的元素为:%d\n",e);
    return true;
}
 /**
 * 函数名称：SaveList
 * 函数参数：文件指针，线性表L
 * 函数功能：将L中的数据保存到fp指针指向的文件中
 * 返回值：OK
 **/
 status SaveList(FILE *fp,SqList &L)
 {
    if(L.elem==NULL)  {printf("未初始化顺序表!\n");  return ERROR;}
    if((fp=fopen(filename,"wb"))==nullptr)  {printf("文件打开失败\n");return ERROR;}
    fwrite(L.elem,sizeof(ElemType),L.length,fp);
    fclose(fp);
    printf("保存成功\n");
    return OK;
 }

/**
 * 函数名称：LoadList
 * 函数参数：文件指针，线性表L
 * 函数功能：数据加载，为线性表输入元素。
 * 返回值：加载成功返回OK，加载失败返回E
 **/
 status LoadList(FILE *fp,SqList &L)
 {
    if(L.elem==NULL)  {printf("未初始化顺序表!\n");  return ERROR;}
    L.length=0;
    if ((fp=fopen(filename,"rb"))==NULL)
	{
	 printf("File open error\n ");
	 return ERROR;
	}
    while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
        L.length++;
    fclose(fp);
    printf("读取成功\n");
    return OK;
 }

