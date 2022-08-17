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
int graph[max][max];	//����Ƕ�׶����ڽӾ���
int num[max];
int visited[max];
//���ļ���
string name ("test.cpp");   
//����ƥ��
int  kuohao = 0;
//�������ȼ�������
int flag = 0;
//��������
int fun = 0;	
//����������
int line = 0;	
 
struct result
{	//������
	int Code;			
	//ע����
	int Comments ;			
	//����
	int Blanklines;			
	
	int scode ;
	int scomment;
	int sspace ;
	//��������
	int countfun;		
	//�����ܳ���
	int funlen;		
	//�����
	int maxlen;
	//����ƽ������
	double avelen ;
	//�������������
	int maxline;
	//��¼������
	int maxh ;
	string funname[max];
	//�������
	string maxfun;
	
}list;
/*���ݻ�ȡ�������ݣ��Գ����������*/
string evaluate(result l) 
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
		return "Excellent";
	else if (s == 'B')
		return "good";
	else if (s == 'C')
		return  "common";
	else
		return "bad";
}
string off(string s)
{
	string cs;
	int open = 0;
	for (int i = 0;; i++) {
		if (s[i] == '('&&open == 1) {
			return cs;
		}
		if (open)
			cs += s[i];
		if (s[i] == ' '&&open==0) {
			open = 1;
		}
	}
}
void analyze(string s) 
{
	//ƥ�䵽��������
	if (regex_match(s, regex("^(\\w{1,10}) ([qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_]{1,100})([qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_0123456789]{0,100})\\((.{0,100})\\).{0,2}"))) {    
		//��������+1
		list.countfun++;	
		
		list.funname[list.countfun] = s;
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
			if (fun > list.maxlen) 
			{
				list.maxlen = fun;
				list.maxfun = list.funname[list.countfun];
				list.maxline = line-fun+1;
			}
			fun = 0;
			flag = 0;
		}
	}
	if (regex_search(s, regex("//")))  
		//ע��������;
		list.Comments++;
	else if (s == "")					
		//��������
		list.Blanklines++;
	else {
		if (flag)
		{
			for (int i = 1; i < list.countfun; i++) {
				if (regex_search(s,regex(off(list.funname[i]))) != NULL) {
					graph[list.countfun][++num[list.countfun]] = i;
				}
			}		
			list.funlen++;
		}
		list.Code++;
	}
	if (flag) {
		fun++;
	}
}
/*ͨ��������ȱ���Ѱ�Һ�����������*/
void dfs(int i) {
	static int count;
	visited[i] = 1;
	for (int j = 1; j <= num[i]; j++) {
		if (!visited[graph[i][j]]) {
			count++;
			dfs(graph[i][j]);
			
		}
	}
	if (!num[i]) {
		if (count+1>list.maxh) {
			list.maxh = count + 1;
		}
		count = 0;
	}
}
/*չʾ���*/
void show() 
{	
	//����ÿ�������������Ƕ���
	for (int i = 1; i <= list.countfun; i++) {
		dfs(i);
		memset(visited, 0, sizeof(visited));
	}
	list.scode = (int)((double)list.Code / (list.Code + list.Comments + list.Blanklines)*100+0.5);
	list.scomment = (int)((double)list.Comments / (list.Code + list.Comments + list.Blanklines) * 100 + 0.5);
	list.sspace = 100 - list.scode - list.scomment;
	list.avelen = (double)list.funlen / list.countfun;
	string res = evaluate(list);
	cout << "The result of analysing program file \"" + name + "\":" << endl;
	cout << "    Lines of code :      " << list.Code << endl;
	cout << "    Lines of comments :  " << list.Comments << endl;
	cout << "    Blank lines :        " << list.Blanklines << endl;
	cout << "    Code    Comments    Space" << endl;
	cout << "    ====    ========    =====" << endl;
	cout << "     " <<list.scode<< "%   "<<setw(6)<<list.scomment << "%        " << list.sspace<<"%"<< endl;
	cout << "    The program include " << list.countfun << " functions." << endl;
	cout << "    The average length of a section of code is " <<list.avelen<< " lines." << endl;
	cout << "    The longest function is " << list.maxfun << ":" << list.maxlen << " lines." << endl;
	cout << "    The longest function is " <<"on the " <<list.maxline<<" line"<< endl;	
	cout << "    The maximum function nesting is :" << list.maxh << endl;
	cout << "    Grade " << res[0] <<" "<< remark(res[0]) << " routine size style." << endl;
	cout << "    Grade " << res[1] <<" "<< remark(res[1]) << " commenting style." << endl;
	cout << "    Grade " << res[2] <<" "<< remark(res[2]) << " white space style." << endl;
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
			//�ж��ļ���ȡ����
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
