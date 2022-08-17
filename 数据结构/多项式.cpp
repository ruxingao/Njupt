#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
using namespace std;
struct PNode{
	int coef;
	int exp;
	PNode* link;
};
struct Polynominal{
	PNode *head;
};
void Create(Polynominal *p)
{
	PNode *pn,*pre,*q;
	p->head=(PNode*)malloc(sizeof(PNode));
	p->head->exp=-1;
	p->head->link=p->head;
	for(;;)
	{
		pn=(PNode*)malloc(sizeof(PNode));
		cout<<"输入系数：";
		cin>>pn->coef;
		cout<<"输入指数：";
		cin>>pn->exp;
		if(pn->exp<0) break;
		pre=p->head;
		q=p->head->link;
		while(q&&q->exp>pn->exp)
		{
			pre=q;
			q=q->link;
		 } 
		 pn->link=q;
		 pre->link=pn;
	}
}












