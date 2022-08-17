#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
using namespace std;
#define error 0
#define ok 1
typedef int ElemType;
typedef int status;
typedef struct node
{ElemType element;
struct node *link;  
	
}Node;
typedef struct singleList{
	Node *first;
	int n;
}SingleList;
status Init(SingleList *L)//创建 
{L->first=NULL;
L->n=0;
return ok;
}
status Find(SingleList L,int i,ElemType *x)//查找 
{   Node *p;
    int j;
	if(i=0||i>L.n-1)
	 {cout<<"没有数据"<<endl; 
	  return error;
    	}
	p=L.first;
	for(j=0;j<i;j++) p=p->link;
	
	*x=p->element;
	cout<<*x<<endl;
	return ok;

}
status Insert(SingleList *L,int i,ElemType x )//插入 
{Node *p,*q;
int j;
if(i<-1||i>L->n-1)
return error;
p=L->first;
for(j=0;j<i;j++) p=p->link;
q=(Node*)malloc(sizeof(Node));
q->element=x;
if(i>-1)
{q->link=p->link;
p->link=q;
}
else
{q->link=L->first;
L->first=q;
}
L->n++;
return ok;
}
status Delete(SingleList *L,int i)//删除 
{int j;
Node *p,*q;
if(i<0||i>L->n-1)
return error;
if(!L->n)
return error;
q=L->first;
p=L->first;
for(j=0;j<i-1;j++)
q=q->link;
if(i==0)
L->first=L->first->link;
else{
	p=q->link;
	q->link=p->link;
}
free(p);
L->n--;
return ok;
}
status Output(SingleList *L)//输出 
{Node *p;
if(!L->n)
return error;
cout<<"顺序表内容；"; 
p=L->first;
while(p)
{cout<<p->element<<" ";
p=p->link;
}
return ok;}
void Destroy(SingleList *L)//全部删除 
{Node *p;
while (L->first)
{p=L->first->link;
free(L->first);
L->first=p;
}
}
int main()
{int i,b,c,f,g,h;
ElemType d,e;
SingleList list;
Init(&list);
for(i=0;i<10;i++)
Insert(&list,i-1,i);
Output(&list);
do
{
cout<<"请输入功能：1:查找;2:插入;3:删除;其他:退出"<<endl;
cin>>b;
switch(b)
{case 1:
	{cout<<"请输入需要查找的位置"<<endl;
	cin>>c;
	Find(list,c,&h);
	cout<<"数据为：";
	cout<<h<<endl;
	}
	continue;
case 2:
	cout<<"请输入需要插入的位置"<<endl;
	cin>>f;
	cout<<"请输入需要插入的内容"<<endl;
	cin>>e;
	Insert(&list,f,e);
	Output(&list);
	continue;
case 3:
	cout<<"请输入需要删除的位置"<<endl;
	cin>>g;
	Delete(&list,g);
	Output(&list);
	continue;
	
}
}
while(b==1||b==2||b==3);
return 0;
}











