#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct examinee //学生信息结构
{   char examno[20]; //学号
char name[10]; //姓名
char sex[4]; //性别
short age; //年龄
char examtype[10]; //选修科目
}ElemType;

typedef struct Node //定义链表结点
{
ElemType data; //数据域
struct Node *next; //指针域
}Node,*List,*position;

List make_empty( List L ); //创建一个带头结点的空表
int is_empty( List L ); //测试链表是否是空表
int is_last( position p, List L ); //测试当前位置是否是表尾
position make_node( position p,int n ); //创建结点并输入考生信息
void put_information( position p ); //是否输出该考生信息
void put_name_information( List L ); //输出姓名为xx的考生信息
int put_pos_information( position p ); //输出该地址考生信息
void link_to_tail( List L, position p ); //将结点连接到表尾
int ciculation_make(); //循环创建考生信息
int judge_put_all(); //是否输出所有考生信息
void put_all(List L); //输出所有考生信息。
position find( List L ); //查找第一个姓名为xx的元素并返回位置
position find_previous( List L ); //查找第一个姓名为xx的元素并返回该元素直接前驱的位置
//int judge_delete_val(); //询问是否删除考生数据
int delete_val( List L ); //删除指定考生信息并输出其信息
void menu(List L); //菜单函数
List L;
//position p;

int
main( void ) 
{
List L = NULL; //定义头结点指针
position p = NULL; //定义表工作指针
L = make_empty( L ); //创建空表
printf("\t\t\t★★学生管理程序(198111559107何晴)★★\n\t\t----------------------------------------\n");
menu(L);
return 0;
}

//创建一个带头结点的空表
List
make_empty( List L)
{
L = ( List ) malloc (sizeof( Node ));
if(NULL == L)
{
printf("内存分配失败");
exit( 1 );
}
L->next = NULL;
//printf("空表创建成功。\n");
return L;
}

//创建结点并输入考生信息
position
make_node( position p ,int n)
{
gets(p->data.sex);
if(n) //n为1是创建结点并输入，n为0是修改
{
p = ( position ) malloc ( sizeof ( Node ));
p->next = NULL ;
}
printf("请输入学生学号：");
gets(p->data.examno);
printf("请输入学生姓名：");
gets(p->data.name);
do
{
printf("请输入学生性别：");
gets(p->data.sex);
}
while( 0 != strcmp( p->data.sex, "男" ) && 0 != strcmp( p->data.sex, "女" )); //判断性别是否有误
printf("请输入考生年龄：");
scanf("%hd",&p->data.age);
getchar();  //如果把这句删掉，就“无法执行”下面的报考类别
/*下面的do while用来判断报考类别是否输入有误*/

printf("请输入选修科目：");
gets(p->data.examtype);
if(n)
{
printf("添加成功\n");
}
else
{
printf("修改成功\n");
}
return p;
}

//前插法；
void
link_to_tail( List L, position p)
{
p->next = L->next;
L->next = p;
}

//查找第一个姓名为xx的元素并返回位置
position
find( List L )
{
position p = L->next;
char name[10];
printf("请输入你要查找的学生姓名：");
gets(name);
while( p != NULL && 0 != strcmp( p->data.name , name))
{
p=p->next;
}
return p;
}
//测试链表是否是空表
int
is_empty( List L )
{
return L->next == NULL;
}
//测试当前位置是否是表尾
int
is_last( position p, List L )
{
return p->next == NULL;
}
//输出姓名为xx的学生信息
void
put_name_information( List L )
{
position p = find(L);
if(p!=NULL)
{
printf("您要查找的学生信息：\n");
printf("准考证号：%s\t姓名：%s\t性别：%s\t年龄：%hd\t报考科目：%s\n\n",p->data.examno,p->data.name,p->data.sex,p->data.age,p->data.examtype);
}
else
{
printf("没有您要找的学生。\n");
}
}
//循环创建考生信息
int
ciculation_make()
{
int n = 2;
do
{
printf("是否继续创建学生信息？是请输入“1”，不是请输入“0”：");
scanf("%d",&n);
getchar();
}
while( n != 0 && n != 1);
return n;
}

//是否输出考生信息
void
put_information( position p )
{
int n=2;
do
{
printf("是否输出该学生信息？是请输入“1”，不是请输入“0”：");
scanf("%d",&n);
getchar();
}
while( n != 0 && n != 1);
if(n)
{
printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%hd\t选修科目：%s\n",p->data.examno,p->data.name,p->data.sex,p->data.age,p->data.examtype);
}
}

//是否输出所有考生信息
int
judge_put_all()
{
int n = 2;
do
{
printf("是否输出所有学生信息？是请输入“1”，不是请输入“0”：");
scanf("%d",&n);
getchar();
}
while( n != 0 && n != 1);
return n;
}

//输出所有考生信息
void
put_all(List L)
{
if(L->next == NULL)
{
printf("现无学生信息！\n");
}
else
{
position p=L->next;
while( p != NULL )
{
printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%hd\t选秀科目：%s\n",p->data.examno,p->data.name,p->data.sex,p->data.age,p->data.examtype);
p=p->next;
}
}
//getchar();
}

//询问是否删除考生数据
int
judge_delete_val()
{
int n = 2;

do
{
printf("是否要删除某个学生数据？是请输入“1”，不是输入“0”：");
scanf("%d",&n);
getchar();
}
while( n != 0 && n != 1);
return n;
}

//查找第一个姓名为xx的元素并返回其直接前驱的位置
position
find_previous( List L )
{
position q = L;
position p = L->next;
char name[10];
printf("请输入你要查找的学生姓名：");
gets(name);
while( p != NULL && 0 != strcmp( p->data.name , name))
{
q=p;
p=p->next;
}
if( p != NULL )
{
return q;
}
else
return p;
}

//删除指定考生信息并输出其信息
int
delete_val(List L)
{
int n=2;
position q=NULL;
position p=find_previous( L ); //返回考生信息地址
if( NULL == p )
{
printf("你要删除的学生不存在\n");
return 0;
}
else
{
q = p->next;
p->next = q->next;
printf("删除成功。\n删除的考生信息为：\n");
printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%hd\t选修科目：%s\n",q->data.examno,q->data.name,q->data.sex,q->data.age,q->data.examtype);
free(q);
return 1;
}

}

//输出该地址考试信息
int
put_pos_information( position p )
{
if(p != NULL )
{
printf("学号：%s\t姓名：%s\t性别：%s\t年龄：%hd\选修科目：%s\n\n",p->data.examno,p->data.name,p->data.sex,p->data.age,p->data.examtype);
return 1;
}
else
{
printf("没有您要查找的学生。");
return 0;
}
}
//菜单函数
void
menu(List L)
{
printf("\t\t\t   a. 学生信息录入\n");
printf("\t\t\t   b. 查询学生信息\n");
printf("\t\t\t   c. 修改学生信息\n");
printf("\t\t\t   d. 删除学生信息\n");
printf("\t\t\t   e. 全部学生信息\n");
printf("\t\t\t   g.   退出程序\n");
char n='h';
while(n != 'g')
{
do  //确定正确输入
{
printf("请通过字母序号选择功能：");
n = getchar();
getchar();
putchar('\n');
if( n < 'a' || n > 'g')
{
printf("错误的字母序号。\n");
}
}
while( n < 'a' || n > 'f' );
switch (n)
{
case 'a':
{
printf("请输入学生信息：\n");
position p = make_node( p, 1 ); //创建新结点
link_to_tail( L, p ); //将新结点连接到表上
put_information( p );   //是否输出该考生信息
putchar('\n');
}
break;

case 'b':
{
put_name_information( L );
putchar('\n');
}
break;

case 'c':
{
int n=0;
position p = NULL;
printf("您正在进行修改操作。\n");
p = find(L);
n = put_pos_information( p );
if(n)
{
make_node( p , 0 );
put_information( p );   //是否输出该学生信息
}
putchar('\n');
}
break;

case 'd':
{
printf("您正在进行删除操作。\n");
delete_val( L );
putchar('\n');
}
break;

case 'e':
{
put_all( L );
putchar('\n');
}
break;


default:
break;
}
}
printf("                     感谢本次使用，祝您生活愉快。");
getch();
}
