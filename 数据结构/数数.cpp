#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
using namespace std;
int main(){
	int a[6],sum,b;
	do
	{cout<<"����:"<<endl;
	cin>>a[0];
	cout<<"����:"<<endl;
	cin>>a[1];
	cout<<"����:"<<endl;
	cin>>a[2];
	cout<<"����:"<<endl;
	cin>>a[3];
	cout<<"�м�:"<<endl;
	cin>>a[4];
	cout<<"ϡ�ͱ���:"<<endl;
	cin>>a[5];
    sum=a[0]+a[1]+a[2]+a[3]+a[4];
    b=sum*5*a[5];
    cout<<"���Ϊ��"<<b<<"0000"<<endl;
	}
    while(1);
	return 0;
}

