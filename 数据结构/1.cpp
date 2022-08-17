#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef int ElemType;
typedef struct Seqlist
{
	int n;   //已存数据长度
	int maxlength;    //最大长度
	ElemType *element;   //数据域
	
}seqlist;

int main()
{int i;
seqlist L;
char a;
Init(&L,10);
for(i=0;i<10,i++)
Insert(&L,i,cin>>a);
return 0;
}