#include<iostream>
#include<string>
#include<fstream>
#include<regex> 
#include<iomanip>
#include<queue>
#include<Windows.h>
#define max 10000
//������ʽͷ�ļ�
using namespace std;
typedef struct node;
typedef node *tree;
int visited[max];
string name ("test.txt");   
//����ƥ��
int  kuohao = 0;
//�������ȼ�������
int flag = 0;
//��������
int fun = 0;	
//����������
int line = 0;	
 
struct result
{	
	int Code;//������
	
	int Comments;//ע����			
	
	int Blanklines;//����		
	
	int scode ;//��������
	int scomment;//ע������
	int sspace;
	int countfun ;//��������		
	int funlen ;//�����ܳ���		
	int maxlen;//�����
	double avelen ;//����ƽ������


	
}list;

string evaluate(result l) 
	//���ݻ�ȡ�������ݣ��Գ����������
{
	string value;
	if (l.avelen >= 10 && l.avelen <= 15)
		value += 'A';
	else if ((l.avelen >= 8 && l.avelen < 10) || (l.avelen > 15 && l.avelen <= 20))
		value += 'B';
	else if ((l.avelen >= 5 && l.avelen < 8) || (l.avelen > 20 && l.avelen <= 24))
		value += 'C';
	else
		value += 'D';
	if (list.scomment >= 15 && list.scomment <= 25)
		value += 'A';
	else if ((list.scomment >= 10 && list.scomment < 15) || (list.scomment > 25 && list.scomment <= 30))
		value += 'B';
	else if ((list.scomment >= 5 && list.scomment < 10) || (list.scomment > 30 && list.scomment <= 35))
		value += 'C';
	else
		value += 'D';
	if (list.sspace >= 15 && list.sspace <= 25)
		value += 'A';
	else if ((list.sspace >= 10 && list.sspace < 15) || (list.sspace > 25 && list.sspace <= 30))
		value += 'B';
	else if ((list.sspace >= 5 && list.sspace < 10) || (list.sspace > 30 && list.sspace <= 35))
		value += 'C';
	else
		value += 'D';
	return value;
}
/*���ݳɼ�������ӡ������*/
string remark(char s)
{
	if (s=='A')
		return " ";
	else if (s == 'B')
		return " ";
	else if (s == 'C')
		return  " ";
	else
		return " ";
}

void analyze(string s) //�ж�����һ��
{
	//ƥ�䵽��������(regex_match����������ʽ�Ƿ�������Ŀ���ַ�����ƥ��)
	if (regex_match(s, regex("(\\w{1,10}) (\\w{1,100})\\(.{0,100}\\).{0,2}")))
	//��������+1	
	{
	list.countfun++;	
		
		//����������
		flag = 1;
	
	}
	if (regex_search(s, regex("\\{"))) 
	{
		kuohao++;
	}
	if (regex_search(s, regex("\\}"))) 
	{
		if (kuohao)
			kuohao--;
		if(kuohao==0&&flag)
			{
			fun++;   
			//����β������
			list.funlen++;
			fun = 0;
			flag = 0;
		}
	}
	if (regex_search(s, regex("//")))  
		//ע��������;
		list.Comments++;
		if (regex_search(s, regex("\\/\\*")))  
		//ע��������;
		list.Comments++;
	else if (s == "")					
		//��������
		list.Blanklines++;
	else {
		if (flag)
		{
			
			list.funlen++;
		}
		list.Code++;
	}
	if (flag) {
		fun++;
	}
}

/*չʾ���*/
void show() 
{	
	list.scode = (int)((double)list.Code / (list.Code + list.Comments + list.Blanklines)*100+0.5);
	list.scomment = (int)((double)list.Comments / (list.Code + list.Comments + list.Blanklines) * 100 + 0.5);
	list.sspace = 100 - list.scode - list.scomment;
	list.avelen = (double)list.funlen / list.countfun;
	string res = evaluate(list);
	cout << "The result of analysing program file \"" + name + "\":" << endl;
	cout << "    �������� :      " << list.Code << endl;
	cout << "    ע������ :  " << list.Comments << endl;
	cout << "    ������ :        " << list.Blanklines << endl;
	cout << "    ����      ע��      ����" << endl;
	cout << "    ====    ========    =====" << endl;
	cout << "     " <<list.scode<< "%   "<<setw(6)<<list.scomment << "%        " << list.sspace<<"%"<< endl;
	cout << "    ������ " << list.countfun << " ������." << endl;
	cout << "    ƽ������ " <<list.avelen<< " ��" << endl;
	cout << "    ����ȼ� " << res[0] <<" "<< remark(res[0])  << endl;
	cout << "    ע�͵ȼ� " << res[1] <<" "<< remark(res[1]) << endl;
	cout << "    ���еȼ� " << res[2] <<" "<< remark(res[2]) << endl;
}
int main()
{	
	int key;
	cout << "---------------------------------------------------------------" << endl;
	cout << "    ��������з����ĳ����ļ�·�������׺����ʹ�����·����" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "�����ļ�·����";
	getline(cin, name);
	ifstream in(name);
	//�����ļ�
	system("cls");
	if (!in) 
	{
		cout << "----------------------------------------------------------" << endl;
		cout << "                     �ļ���ʧ��                         " << endl;
		cout << "----------------------------------------------------------" << endl;
		Sleep(2000);
		system("cls");
		main();
	}
	string str;
	while (1) 
	{
		line++;
		if (in.eof())			
			//�ж��ļ���ȡ����eof�ж����Ͳ��᷵��false
			break;
		getline(in, str);	
		analyze(str);
	}
	in.close();
	show();
	cout << "----------------------------------------------------------" << endl;
	cout << "               1.������������   2.�˳�                    " << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "��������� �� ";
	cin >> key;
	if (key == 1) {
		system("cls");	//����
		getchar();	  //�������
		main();
	}
	return 0;
}