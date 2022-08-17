#include <stdio.h>
 #include <malloc.h>
#include <stdlib.h>
 #include <string.h>

int N1,N2,kk1,kk2,kk3;

struct couse * head1;

struct student * head2;

struct couse//课程信息结构体

{
int num1;

char name1[20];

int score;

int nelepeo;

//课程已选人数

int Melepeo;

//课程人数上限

struct couse * next;

}

;

struct student//学生信息结构体

{
int num2;

char name2[20];

int nelenum[50];

//已选课程编号

int nelen;

//已选课程数量

struct student * next;

}

;

void Ms()

{
for (kk1=0;kk1<1100;kk1++)

for (kk2=0;kk2<1200;kk2++)

for (kk3=0;kk3<1200;kk3++);

}

void keyboardc()//录入课程子函数(从键盘录入)

{
struct couse *p1,*p2;

N1=0;

p1=p2=(struct couse*)malloc(sizeof(struct couse));

printf("课程编号\t课程名称\t学分\t课程人数上限\n");

scanf("%d%s%d%d",&p1->num1,p1->name1,&p1->score,&p1->Melepeo);

p1->nelepeo=0;

head1=NULL;

while(p1->num1!=0)

{
N1=N1+1;

if(N1==1)head1=p1; else p2->next=p1;

p2=p1;

p1=(struct couse * )malloc(sizeof(struct couse));

scanf("%d%s%d%d",&p1->num1,p1->name1,&p1->score,&p1->Melepeo);

p1->nelepeo=0;

}

p2->next=NULL;

}

void filec()//录入键盘子函数(从文件录入)

{
FILE * fp;

char filepath[20];

struct couse *p1,*p2;

N1=0;

printf("输入要读入的文件路径:");

getchar();

gets(filepath);

if((fp=fopen(filepath,"r"))==NULL)

{
printf("找不到%s文件!\n",filepath);

exit(0);

}

p1=p2=(struct couse*)malloc(sizeof(struct couse));

fscanf(fp,"%d%s%d%d%d",&p1->num1,p1->name1,&p1->score,&p1->nelepeo,&p1->Melepeo);

head1=NULL;

while(!feof(fp))

{
N1=N1+1;

if(N1==1)head1=p1; else p2->next=p1;

p2=p1;

p1=(struct couse * )malloc(sizeof(struct couse));

fscanf(fp,"%d%s%d%d%d",&p1->num1,p1->name1,&p1->score,&p1->nelepeo,&p1->Melepeo);

}

p2->next=NULL;

}

void inputc()//录入课程主函数

{
int i;

printf("\t\t\t录入课程信息\n");

printf("\n1.从键盘录入\n");

printf("2.从文件录入\n");

printf("3.返回主菜单\n");

printf("请选择(1~3):\n");

scanf("%d",&i);

switch(i)

{
case(1):keyboardc();

break;

case(2):filec();

break;

case(3):break;

}

}

void insertc(struct couse *incouse)//课程管理子函数(增加课程)

{
struct couse *p0,*p1,*p2;

p1=head1;

p0=incouse;

if(head1==NULL)

{
head1=p0;

p0->next=NULL;

} else

{
while((p0->num1 > p1->num1) && (p1->next!=NULL))

{
p2=p1;

p1=p1->next;

}

if(p0->num1 <= p1->num1)

{
if(head1==p1) head1=p0; else p2->next=p0;

p0->next=p1;

} else

{
p1->next=p0;

p0->next=NULL;

}

}

N1=N1+1;

}

void delc(int num1)//课程管理子函数(删除课程)

{
struct couse *p1,*p2;

if(head1==NULL)

{
printf("\n没有课程,无法删除!\n");

goto end;

}

p1=head1;

while(num1!=p1->num1 && p1->next!=NULL)

{
p2=p1;

p1=p1->next;

}

if(num1==p1->num1)

{
if(p1==head1) head1=p1->next; else p2->next=p1->next;

printf("已删除该编号课程!\n");

N1=N1-1;

} else printf("无该编号的课程!\n");

end:;

}

void managementc()//课程管理主函数

{
struct couse * incouse;

int i,num1;

printf("\t\t\t课程管理\n");

printf("1.新增课程\n");

printf("2.删除课程\n");

printf("3.返回主菜单\n");

printf("请选择(1~3):\n");

scanf("%d",&i);

switch(i)

{
case(1):

{
incouse=(struct couse *)malloc(sizeof(struct couse));

printf("课程编号\t课程名称\t学分\t课程人数上限\n");

scanf("%d%s%d%d",&incouse->num1,incouse->name1,&incouse->score,&incouse->Melepeo);

incouse->nelepeo=0;

insertc(incouse);

break;

}

case(2):

{
printf("请输入要删除课程的编号:\n");

scanf("%d",&num1);

delc(num1);

break;

}

case(3):break;

}

}

void keyboards()//录入学生信息子函数(从键盘录入)

{
int i;

struct student *p1,*p2;

N2=0;

p1=p2=(struct student *)malloc(sizeof(struct student));

printf("学生学号\t学生姓名\n");

scanf("%d%s",&p1->num2,p1->name2);

p1->nelen=0;

for (i=0;i<20;i++) p1->nelenum[i]=0;

head2=NULL;

while(p1->num2!=0)

{
N2=N2+1;

if(N2==1)head2=p1; else p2->next=p1;

p2=p1;

p1=(struct student * )malloc(sizeof(struct student));

scanf("%d%s",&p1->num2,p1->name2);

p1->nelen=0;

for (i=0;i<20;i++) p1->nelenum[i]=0;

}

p2->next=NULL;

}

void files()//录入学生信息子函数(从文件录入)

{
int i=0;

FILE * fp;

char filepath[20];

struct student *p1,*p2;

N2=0;

printf("输入要读入的文件路径:");

getchar();

gets(filepath);

if((fp=fopen(filepath,"r"))==NULL)

{
printf("找不到%s文件!\n",filepath);

exit(0);

}

p1=p2=(struct student*)malloc(sizeof(struct student));

fread(p1,sizeof(struct student),1,fp);

head2=NULL;

while(!feof(fp))

{
i=0;

N2=N2+1;

if(N2==1)head2=p1; else p2->next=p1;

p2=p1;

p1=(struct student * )malloc(sizeof(struct student));

fread(p1,sizeof(struct student),1,fp);

}

p2->next=NULL;

}

void inputs()//录入学生信息主函数

{
int i;

printf("\t\t\t录入学生信息\n");

printf("\n1.从键盘录入\n");

printf("2.从文件录入\n");

printf("3.返回主菜单\n");

printf("请选择(1~3):\n");

scanf("%d",&i);

switch(i)

{
case(1):keyboards();

break;

case(2):files();

break;

case(3):break;

}

}

void inserts(struct student * incouse)//学生信息管理子函数(填加学生信息)

{
struct student *p0,*p1,*p2;

p1=head2;

p0=incouse;

if(head2==NULL)

{
head2=p0;

p0->next=NULL;

} else

{
while((p0->num2 > p1->num2) && (p1->next!=NULL))

{
p2=p1;

p1=p1->next;

}

if(p0->num2 <= p1->num2)

{
if(head2==p1) head2=p0; else p2->next=p0;

p0->next=p1;

} else

{
p1->next=p0;

p0->next=NULL;

}

}

N2=N2+1;

}

void dels(int num2)//学生信息管理子函数(删除学生信息)

{
struct student *p1,*p2;

if(head2==NULL)

{
printf("\n没有该学生信息,无法删除!\n");

goto end;

}

p1=head2;

while(num2!=p1->num2 && p1->next!=NULL)

{
p2=p1;

p1=p1->next;

}

if(num2==p1->num2)

{
if(p1==head2) head2=p1->next; else p2->next=p1->next;

printf("已删除该学生信息!\n");

N2=N2-1;

} else printf("无该学号的学生!\n");

end:;

}

void managements()//学生信息管理主函数

{
struct student * incouse;

int i,num2;

printf("\t\t\t学生信息管理\n");

printf("1.新增学生信息\n");

printf("2.删除学生信息\n");

printf("3.返回主菜单\n");

printf("请选择(1~3):\n");

scanf("%d",&i);

switch(i)

{
case(1):

{
incouse=(struct student *)malloc(sizeof(struct student));

incouse->nelen=0;

incouse->nelenum[0]=0;

printf("学生学号\t学生姓名\n");

scanf("%d%s",&incouse->num2,incouse->name2);

inserts(incouse);

break;

}

case(2):

{
printf("请输入要删除学生的学号:\n");

scanf("%d",&num2);

dels(num2);

break;

}

case(3):break;

}

}

void elect(struct student * s)//选课

{
struct couse * p;

int num1,i;

printf("请输入要选课的编号:\n");

scanf("%d",&num1);

for (i=0;s->nelenum[i]!=0;i++);

s->nelenum[i]=num1;

(s->nelen)++;

p=head1;

while(p->num1!=num1) p=p->next;

(p->nelepeo)++;

}

void cheak()//学生选课子函数(查询可选课程)

{
char e;

struct couse * c;

struct student * s;

int num2,i,j=0,t=0;

printf("请输入你的学号:");

scanf("%d",&num2);

s=head2;

while(s->num2!=num2 && s->next!=NULL) s=s->next;

if(s->num2!=num2)

{
printf("不存在你的信息,请进入主菜单录入你的信息!\n");

goto end;

}

c=head1;

printf("你的可选课程编号:\n");

while(c!=NULL)

{
for (t=0,i=0;s->nelenum[i]!=0;i++)

{
if(c->num1==s->nelenum[i]) t=1;

}

if(t==0 && (c->nelepeo!=c->Melepeo))

{
printf("%d\n",c->num1);

j++;

}

c=c->next;

}

if(j==0)

{
printf("你已选完所有课程，无法再多选!\n");

goto end;

}

printf("选课(y/n)?:\n");

getchar();

e=getchar();

i=0;

while(e=='y')

{
elect(s);

printf("继续选课(y/n)?:\n");

getchar();

e=getchar();

}

end:;

}

void back(struct student * p)//退课

{
struct couse * p1;

int num1,i,j;

printf("请输入你要退掉的课程编号:\n");

scanf("%d",&num1);

p1=head1;

while(p1->num1!=num1) p1=p1->next;

for (i=0;p->nelenum[i]!=num1;i++);

for (j=i;p->nelenum[j]!=0;j++) p->nelenum[j]=p->nelenum[j+1];

p->nelenum[--j]=0;

(p1->nelepeo)--;

printf("退课成功!\n");

}

void hcheak()//学生选课子函数(查询已选课程)

{
char c;

struct couse * p0;

struct student * p;

int num2,i,f=0;

printf("请输入学号:\n");

scanf("%d",&num2);

p=head2;

while(p->num2!=num2 && p!=NULL) p=p->next;

if(p==NULL)

{
printf("不存在你的信息,请回主菜单录入信息:\n");

goto end;

}

printf("已选课程编号:\n");

if(p->nelenum[0]==0)

{
printf("你还没选课!\n");

goto end;

}

for (i=0;p->nelenum[i]!=0;i++)

{
printf("%d\n",p->nelenum[i]);

p0=head1;

while(p0->num1!=p->nelenum[i]) p0=p0->next;

f=f+p0->score;

}

printf("总学分:%d\n",f);

printf("是否进行退课(y/n)?");

getchar();

c=getchar();

while(c=='y')

{
back(p);

printf("继续退课(y/n)?");

getchar();

c=getchar();

(p->nelen)--;

}

end:;

}

void elective()//学生选课主函数

{
int i;

printf("\t\t\t学生选课\n");

printf("1.查询可选课程\n");

printf("2.查询已选课程\n");

printf("3.返回主菜单\n");

printf("请输入(1~3):\n");

scanf("%d",&i);

switch(i)

{
case(1):cheak();

break;

case(2):hcheak();

break;

case(3):break;

}

}

void listc()//输出课程信息

{
struct couse * p;

p=head1;

printf("课程编号 课程名称 学分 课程已选人数 课程人数上限\n");

while(p!=NULL)

{
printf("%-8d%10s%6d%8d%12d\n",p->num1,p->name1,p->score,p->nelepeo,p->Melepeo);

p=p->next;

}

}

void lists()//输出学生信息

{
struct student * p;

p=head2;

printf("学生学号 学生姓名 已选课程数量\n");

while(p!=NULL)

{
printf("%-4d %10s %6d\n",p->num2,p->name2,p->nelen);

p=p->next;

}

}

void intoc()//存储课程信息

{
FILE * fp;

struct couse * p;

char filepath[30];

printf("输入课程信息要保存的文件路径:");

getchar();

gets(filepath);

if((fp=fopen(filepath,"w"))==NULL)

{
printf("\n保存失败!");

exit(0);

}

p=head1;

while(p!=NULL)

{
fprintf(fp,"%d %s %d %d %d\n",p->num1,p->name1,p->score,p->nelepeo,p->Melepeo);

p=p->next;

}

fclose(fp);

printf("课程信息已保存在%s中!\n",filepath);

}

void intos()//存储学生信息

{
FILE * fp;

struct student * p;

char filepath[30];

printf("输入学生信息要保存的文件路径:");

getchar();

gets(filepath);

if((fp=fopen(filepath,"w"))==NULL)

{
printf("\n保存失败!");

exit(0);

}

p=head2;

while(p!=NULL)

{
fwrite(p,sizeof(struct student),1,fp);

p=p->next;

}

fclose(fp);

printf("学生信息已保存在%s中!\n",filepath);

}

void into()//存储信息

{
int i;

printf("1.存储课程信息\n");

printf("2.存储学生信息\n");

printf("3.返回主菜单\n");

printf("请输入(1~3)\n");

scanf("%d",&i);

switch(i)

{
case(1):intoc();

break;

case(2):intos();

break;

case(3):break;

}

}

void store()//信息主函数

{
int i;

printf("\t\t系统信息查看及存储\n");

printf("1.查看课程信息\n");

printf("2.查看学生信息\n");

printf("3.存储信息\n");

printf("4.返回主菜单\n");

printf("请输入(1~4):\n");

scanf("%d",&i);

switch(i)

{
case(1):listc();

break;

case(2):lists();

break;

case(3):into();

break;

case(4):break;

}

}

int main()//主函数

{
int i;

start:

printf("\n\t\t\t欢迎使用学生选课系统!\n");

printf("菜单:\n");

printf("1.录入课程信息\n");

printf("2.课程管理\n");

printf("3.录入学生信息\n");

printf("4.学生信息管理\n");

printf("5.学生选课\n");

printf("6.系统信息查看及存储\n");

printf("7.退出系统\n");

printf("\n请输入菜单选项(1~7):\n");

scanf("%d",&i);

if(i<1 || i>7)

{
printf("输入错误,请重输:\n");

goto start;

}

switch(i)

{
case(1):

{
system("cls");

inputc();

goto start;

break;

}

case(2):

{
system("cls");

managementc();

goto start;

break;

}

case(3):

{
system("cls");

inputs();

goto start;

break;

}

case(4):

{
system("cls");

managements();

goto start;

break;

}

case(5):

{
system("cls");

elective();

goto start;

break;

}

case(6):

{
system("cls");

store();

goto start;

break;

}

case(7):

{
system("cls");

printf("感谢使用本系统!\n\n再见!\n");

}

}

return(0);

}
