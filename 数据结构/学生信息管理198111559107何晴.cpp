#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct examinee //ѧ����Ϣ�ṹ
{   char examno[20]; //ѧ��
char name[10]; //����
char sex[4]; //�Ա�
short age; //����
char examtype[10]; //ѡ�޿�Ŀ
}ElemType;

typedef struct Node //����������
{
ElemType data; //������
struct Node *next; //ָ����
}Node,*List,*position;

List make_empty( List L ); //����һ����ͷ���Ŀձ�
int is_empty( List L ); //���������Ƿ��ǿձ�
int is_last( position p, List L ); //���Ե�ǰλ���Ƿ��Ǳ�β
position make_node( position p,int n ); //������㲢���뿼����Ϣ
void put_information( position p ); //�Ƿ�����ÿ�����Ϣ
void put_name_information( List L ); //�������Ϊxx�Ŀ�����Ϣ
int put_pos_information( position p ); //����õ�ַ������Ϣ
void link_to_tail( List L, position p ); //��������ӵ���β
int ciculation_make(); //ѭ������������Ϣ
int judge_put_all(); //�Ƿ�������п�����Ϣ
void put_all(List L); //������п�����Ϣ��
position find( List L ); //���ҵ�һ������Ϊxx��Ԫ�ز�����λ��
position find_previous( List L ); //���ҵ�һ������Ϊxx��Ԫ�ز����ظ�Ԫ��ֱ��ǰ����λ��
//int judge_delete_val(); //ѯ���Ƿ�ɾ����������
int delete_val( List L ); //ɾ��ָ��������Ϣ���������Ϣ
void menu(List L); //�˵�����
List L;
//position p;

int
main( void ) 
{
List L = NULL; //����ͷ���ָ��
position p = NULL; //�������ָ��
L = make_empty( L ); //�����ձ�
printf("\t\t\t���ѧ���������(198111559107����)���\n\t\t----------------------------------------\n");
menu(L);
return 0;
}

//����һ����ͷ���Ŀձ�
List
make_empty( List L)
{
L = ( List ) malloc (sizeof( Node ));
if(NULL == L)
{
printf("�ڴ����ʧ��");
exit( 1 );
}
L->next = NULL;
//printf("�ձ����ɹ���\n");
return L;
}

//������㲢���뿼����Ϣ
position
make_node( position p ,int n)
{
gets(p->data.sex);
if(n) //nΪ1�Ǵ�����㲢���룬nΪ0���޸�
{
p = ( position ) malloc ( sizeof ( Node ));
p->next = NULL ;
}
printf("������ѧ��ѧ�ţ�");
gets(p->data.examno);
printf("������ѧ��������");
gets(p->data.name);
do
{
printf("������ѧ���Ա�");
gets(p->data.sex);
}
while( 0 != strcmp( p->data.sex, "��" ) && 0 != strcmp( p->data.sex, "Ů" )); //�ж��Ա��Ƿ�����
printf("�����뿼�����䣺");
scanf("%hd",&p->data.age);
getchar();  //��������ɾ�����͡��޷�ִ�С�����ı������
/*�����do while�����жϱ�������Ƿ���������*/

printf("������ѡ�޿�Ŀ��");
gets(p->data.examtype);
if(n)
{
printf("��ӳɹ�\n");
}
else
{
printf("�޸ĳɹ�\n");
}
return p;
}

//ǰ�巨��
void
link_to_tail( List L, position p)
{
p->next = L->next;
L->next = p;
}

//���ҵ�һ������Ϊxx��Ԫ�ز�����λ��
position
find( List L )
{
position p = L->next;
char name[10];
printf("��������Ҫ���ҵ�ѧ��������");
gets(name);
while( p != NULL && 0 != strcmp( p->data.name , name))
{
p=p->next;
}
return p;
}
//���������Ƿ��ǿձ�
int
is_empty( List L )
{
return L->next == NULL;
}
//���Ե�ǰλ���Ƿ��Ǳ�β
int
is_last( position p, List L )
{
return p->next == NULL;
}
//�������Ϊxx��ѧ����Ϣ
void
put_name_information( List L )
{
position p = find(L);
if(p!=NULL)
{
printf("��Ҫ���ҵ�ѧ����Ϣ��\n");
printf("׼��֤�ţ�%s\t������%s\t�Ա�%s\t���䣺%hd\t������Ŀ��%s\n\n",p->data.examno,p->data.name,p->data.sex,p->data.age,p->data.examtype);
}
else
{
printf("û����Ҫ�ҵ�ѧ����\n");
}
}
//ѭ������������Ϣ
int
ciculation_make()
{
int n = 2;
do
{
printf("�Ƿ��������ѧ����Ϣ���������롰1�������������롰0����");
scanf("%d",&n);
getchar();
}
while( n != 0 && n != 1);
return n;
}

//�Ƿ����������Ϣ
void
put_information( position p )
{
int n=2;
do
{
printf("�Ƿ������ѧ����Ϣ���������롰1�������������롰0����");
scanf("%d",&n);
getchar();
}
while( n != 0 && n != 1);
if(n)
{
printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%hd\tѡ�޿�Ŀ��%s\n",p->data.examno,p->data.name,p->data.sex,p->data.age,p->data.examtype);
}
}

//�Ƿ�������п�����Ϣ
int
judge_put_all()
{
int n = 2;
do
{
printf("�Ƿ��������ѧ����Ϣ���������롰1�������������롰0����");
scanf("%d",&n);
getchar();
}
while( n != 0 && n != 1);
return n;
}

//������п�����Ϣ
void
put_all(List L)
{
if(L->next == NULL)
{
printf("����ѧ����Ϣ��\n");
}
else
{
position p=L->next;
while( p != NULL )
{
printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%hd\tѡ���Ŀ��%s\n",p->data.examno,p->data.name,p->data.sex,p->data.age,p->data.examtype);
p=p->next;
}
}
//getchar();
}

//ѯ���Ƿ�ɾ����������
int
judge_delete_val()
{
int n = 2;

do
{
printf("�Ƿ�Ҫɾ��ĳ��ѧ�����ݣ��������롰1�����������롰0����");
scanf("%d",&n);
getchar();
}
while( n != 0 && n != 1);
return n;
}

//���ҵ�һ������Ϊxx��Ԫ�ز�������ֱ��ǰ����λ��
position
find_previous( List L )
{
position q = L;
position p = L->next;
char name[10];
printf("��������Ҫ���ҵ�ѧ��������");
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

//ɾ��ָ��������Ϣ���������Ϣ
int
delete_val(List L)
{
int n=2;
position q=NULL;
position p=find_previous( L ); //���ؿ�����Ϣ��ַ
if( NULL == p )
{
printf("��Ҫɾ����ѧ��������\n");
return 0;
}
else
{
q = p->next;
p->next = q->next;
printf("ɾ���ɹ���\nɾ���Ŀ�����ϢΪ��\n");
printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%hd\tѡ�޿�Ŀ��%s\n",q->data.examno,q->data.name,q->data.sex,q->data.age,q->data.examtype);
free(q);
return 1;
}

}

//����õ�ַ������Ϣ
int
put_pos_information( position p )
{
if(p != NULL )
{
printf("ѧ�ţ�%s\t������%s\t�Ա�%s\t���䣺%hd\ѡ�޿�Ŀ��%s\n\n",p->data.examno,p->data.name,p->data.sex,p->data.age,p->data.examtype);
return 1;
}
else
{
printf("û����Ҫ���ҵ�ѧ����");
return 0;
}
}
//�˵�����
void
menu(List L)
{
printf("\t\t\t   a. ѧ����Ϣ¼��\n");
printf("\t\t\t   b. ��ѯѧ����Ϣ\n");
printf("\t\t\t   c. �޸�ѧ����Ϣ\n");
printf("\t\t\t   d. ɾ��ѧ����Ϣ\n");
printf("\t\t\t   e. ȫ��ѧ����Ϣ\n");
printf("\t\t\t   g.   �˳�����\n");
char n='h';
while(n != 'g')
{
do  //ȷ����ȷ����
{
printf("��ͨ����ĸ���ѡ���ܣ�");
n = getchar();
getchar();
putchar('\n');
if( n < 'a' || n > 'g')
{
printf("�������ĸ��š�\n");
}
}
while( n < 'a' || n > 'f' );
switch (n)
{
case 'a':
{
printf("������ѧ����Ϣ��\n");
position p = make_node( p, 1 ); //�����½��
link_to_tail( L, p ); //���½�����ӵ�����
put_information( p );   //�Ƿ�����ÿ�����Ϣ
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
printf("�����ڽ����޸Ĳ�����\n");
p = find(L);
n = put_pos_information( p );
if(n)
{
make_node( p , 0 );
put_information( p );   //�Ƿ������ѧ����Ϣ
}
putchar('\n');
}
break;

case 'd':
{
printf("�����ڽ���ɾ��������\n");
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
printf("                     ��л����ʹ�ã�ף��������졣");
getch();
}
