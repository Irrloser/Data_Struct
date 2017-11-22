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
typedef int ElemType; //����Ԫ�����Ͷ���
using namespace std;
/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
struct SqList{  //˳���˳��ṹ���Ķ���
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
status LocateElem(const SqList &L,ElemType &e); //�򻯹�
status PriorElem(const SqList &L,ElemType cur,ElemType & pre_e);
status NextElem(const SqList &L,ElemType cur,ElemType & next_e);
status ListInsert(SqList & L,int &i,ElemType &e);
status ListDelete(SqList & L,int i,ElemType &e);
status ListTrabverse(SqList &L); //�򻯹�
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
	printf("    ��ѡ����Ĳ���[0~14]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiaList���ܴ�ʵ�֣�\n");
        IntiaList(L);
		 getchar();getchar();
		 break;
	   case 2:
		 //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
		 DestroyList(L);
		 getchar();getchar();
		 break;
	   case 3:
         //printf("\n----ClearList���ܴ�ʵ�֣�\n");
		 ClearList(L);
		 getchar();getchar();
		 break;
	   case 4:
         //printf("\n----ListEmpty���ܴ�ʵ�֣�\n");
		 ListEmpty(L);
		 getchar();getchar();
		 break;
	   case 5:
		 //printf("\n----ListLength���ܴ�ʵ�֣�\n");
		 ListLength(L);
		 getchar();getchar();
		 break;
	   case 6:
		 //printf("\n----GetElem���ܴ�ʵ�֣�\n");
		 if(GetElem(L,i,tmp)==OK)
            //printf("���ҵ�����Ϊ:%d\n",tmp);
		 getchar();getchar();
		 break;
	   case 7:
		 //printf("\n----LocateElem���ܴ�ʵ�֣�\n");
		 tmp=LocateElem(L,i);
		 getchar();getchar();
		 break;
	   case 8:
		 //printf("\n----PriorElem���ܴ�ʵ�֣�\n");
         PriorElem(L,i,tmp);
		 getchar();getchar();
		 break;
	   case 9:

         NextElem(L,i,tmp);
		 getchar();getchar();
		 break;
	   case 10:
		 //printf("\n----ListInsert���ܴ�ʵ�֣�\n");

        ListInsert(L,i,tmp);
		 getchar();getchar();
		 break;
	   case 11:
		 //printf("\n----ListDelete���ܴ�ʵ�֣�\n");
		 ListDelete(L,i,tmp);
		 getchar();getchar();
		 break;
	   case 12:
		 //printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");
		 //if(!ListTrabverse(L)) printf("���Ա��ǿձ�\n");
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
  printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()
/*--------page 23 on textbook --------------------*/
/**
 * �������ƣ�InitiaList
 * �������������Ա�L�ĵ�ַ
 * �������ܣ�����һ���յ����Ա�
 * ����ֵ���ɹ����췵��OK�����򷵻�ERROR
 **/
status IntiaList(SqList &L)
{
    if(flag==true) {cout<<"�Ѵ���"<<endl;return ERROR;}
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
	L.length=0;
    L.listsize=LIST_INIT_SIZE;
    flag=true;
	printf("��ʼ���ɹ�\n");
	return OK;
}
status ListTrabverse(SqList &L)
{
   int i;
   if(L.elem==NULL){printf("˳���δ��ʼ��\n");return ERROR;}
   printf("\n-----------all elements -----------------------\n");
   for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
   printf("\n------------------ end ------------------------\n");
   return L.length;
}
/**
 * �������ƣ�DestroyList
 * �������������Ա�L�ĵ�ַ
 * �������ܣ�ɾ�����Ա�
 * ����ֵ���ɹ����ٷ���OK�����򷵻�ERROR
 **/
status DestroyList(SqList & L)
{
    if(L.elem==NULL) {printf("δ��ʼ��˳���!\n");  return ERROR;}
    free(L.elem);
    L.elem=NULL;
    flag=false;
    printf("�ɹ�\n");
    return OK;
}
/**
 * �������ƣ�ClearList
 * �������������Ա�L�ĵ�ַ
 * �������ܣ��������Ա�
 * ����ֵ���ɹ��ÿշ���OK�����򷵻�ERROR
 **/
status ClearList(SqList &L)
{
    if(L.elem==NULL){printf("δ��ʼ��˳���!\n");  return ERROR;}
    L.length=0;
    printf("AC\n");
    return  OK;
}
/**
 * �������ƣ�ListEmpty
 * �������������Ա�L
 * �������ܣ��ж����Ա��Ƿ�Ϊ��
 * ����ֵ����LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
 **/
status ListEmpty(SqList &L)
{
    if(L.elem==NULL) {printf("δ��ʼ��˳���!\n");  return ERROR;}
    if(!L.length){printf("empty\n");return true;}
    else {
            printf("not empty\n");
            return false;
        }
}
/**
 * �������ƣ�ListLength
 * �������������Ա�L
 * �������ܣ��������Ա�L������Ԫ�ظ�����
 * ����ֵ���ɹ�����L������Ԫ�ظ�����ʧ�ܷ���ERROR
 **/
status ListLength(SqList &L)
{
    if(L.elem==NULL) {printf("δ��ʼ��˳���!\n");  return ERROR;}
    printf("��;%d\n",L.length);
    return OK;
}
/**
 * �������ƣ�GetElem
 * �������������Ա�L��eΪ��i�����ݵĵ�ַ��
 * �������ܣ����Ҳ���ʾL�е�i��Ԫ�ص�ֵ��
 * ����ֵ���ɹ��򷵻ص�i��Ԫ�ص�ֵ�����򷵻�ERROR
 **/
status GetElem(const SqList &L,int &i,ElemType & e)
{
    if(L.elem==NULL) {printf("δ��ʼ��˳���!\n");  return ERROR;}
    printf("������:");
		 scanf("%d",&i);
    if(i<1||i>L.length) {printf("overflow\n");return ERROR;}
    e=*(L.elem+i-1);
    printf("���ҵ�����Ϊ:%d\n",e);
    return  OK;
}
/**
 * �������ƣ�LocateElem
 * �������������Ա�L����Աȵ�Ԫ��ֵ��
 * �������ܣ�����L����e��ͬ�������ڵ�λ��λ���1��ʼ
 * ����ֵ���ɹ��򷵻ص�һ����e��ͬ�����ݵ�λ�򣬲������򷵻�0�������������ERROR
 **/
status LocateElem(const SqList &L,ElemType &e) //�򻯹�
{
    if(L.elem==NULL) {printf("δ��ʼ��˳���!\n");  return ERROR;}
    printf("������:");
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
 * �������ƣ�PriorElem
 * �������������Ա�L�����ҵ�����cur_e,ǰ��pre_e��
 * �������ܣ�����L����cur_e��ͬ�ĵ�һ�����ݣ���������ǰ��
 * ����ֵ���ɹ��򷵻���cur_e��ͬ�ĵ�һ�����ݣ����������һ��ǰ��������ǰ���Լ���������򷵻�ERROR
 **/
status PriorElem(const SqList &L,ElemType cur,ElemType & pre_e)
{
    if(L.elem==NULL){printf("δ��ʼ��˳���!\n");  return ERROR;}
    printf("input:");
    scanf("%d",&cur);
    for(int i=2;i<=L.length;++i)
    if(*(L.elem+i-1)==cur)
    {
        pre_e=*(L.elem+i-2);
         printf("ǰ��Ϊ:%d\n",pre_e);
        return true;
    }
printf("PriorElement not exist\n");
return ERROR;
}
/**
 * �������ƣ�NextElem
 * �������������Ա�L�����ҵ�����cur_e,����next_e��
 * �������ܣ�����L����cur_e��ͬ�ĵ�һ�����ݣ������������
 * ����ֵ���ɹ��򷵻���cur_e��ͬ�ĵ�һ�����ݣ�����������������޺����Լ���������򷵻�ERROR
 **/
status NextElem(const SqList &L,ElemType cur,ElemType & next_e)
{
    if(L.elem==NULL){printf("δ��ʼ��˳���!\n");  return ERROR;}
    printf("������:");
    scanf("%d",&cur);
    for(int i=1;i<L.length;++i)
    if(*(L.elem+i-1)==cur)
    {
        //1printf("%d\n",*(L.elem+i-1));
        next_e=*(L.elem+i);
        printf("���Ϊ:%d\n",next_e);
        return true;
    }
    printf("Next element not exist\n");
return ERROR;
}
/**
 * �������ƣ�ListInsert
 * �������������Ա�L�ĵ�ַ�������λ��i�����������Ԫ��e��
 * �������ܣ���L�ĵ�i��λ��֮ǰ�����µ�����Ԫ��e�����Ѳ��������շ����������������Ŀռ䡣
 * ����ֵ���ɹ����뷵��OK�����򷵻�ERROR
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
    printf("����ɹ�!\n");
    return true;
}
/**
 * �������ƣ�ListDelete
 * �������������Ա�L�ĵ�ַ��ɾ����λ��i��ָ��e�ĵ�ַ��
 * �������ܣ�ɾ��L�ĵ�i������Ԫ�أ���e������ֵ��
 * ����ֵ���ɹ�ɾ������OK�����򷵻�ERROR
 **/
status ListDelete(SqList &L,int i,ElemType &e)
{
    if(L.elem==NULL)  {printf("δ��ʼ��˳���!\n");  return ERROR;}
    if(L.length==0){printf("underflow\n");return ERROR;}
    printf("������:");
    scanf("%d",&i);
    if(i<0||i>L.length)
    {
        printf("Խ��\n");
        return ERROR;
    }
    e=*(L.elem+i-1);
    for(int j=i;j<L.length;++j)
    *(L.elem+j-1)=*(L.elem+j);
    L.length-=1;
    printf("ɾ����Ԫ��Ϊ:%d\n",e);
    return true;
}
 /**
 * �������ƣ�SaveList
 * �����������ļ�ָ�룬���Ա�L
 * �������ܣ���L�е����ݱ��浽fpָ��ָ����ļ���
 * ����ֵ��OK
 **/
 status SaveList(FILE *fp,SqList &L)
 {
    if(L.elem==NULL)  {printf("δ��ʼ��˳���!\n");  return ERROR;}
    if((fp=fopen(filename,"wb"))==nullptr)  {printf("�ļ���ʧ��\n");return ERROR;}
    fwrite(L.elem,sizeof(ElemType),L.length,fp);
    fclose(fp);
    printf("����ɹ�\n");
    return OK;
 }

/**
 * �������ƣ�LoadList
 * �����������ļ�ָ�룬���Ա�L
 * �������ܣ����ݼ��أ�Ϊ���Ա�����Ԫ�ء�
 * ����ֵ�����سɹ�����OK������ʧ�ܷ���E
 **/
 status LoadList(FILE *fp,SqList &L)
 {
    if(L.elem==NULL)  {printf("δ��ʼ��˳���!\n");  return ERROR;}
    L.length=0;
    if ((fp=fopen(filename,"rb"))==NULL)
	{
	 printf("File open error\n ");
	 return ERROR;
	}
    while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
        L.length++;
    fclose(fp);
    printf("��ȡ�ɹ�\n");
    return OK;
 }

