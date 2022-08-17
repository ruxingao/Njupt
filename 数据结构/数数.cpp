#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
using namespace std;
int main(){
	int a[6],sum,b;
	do
	{cout<<"左上:"<<endl;
	cin>>a[0];
	cout<<"右上:"<<endl;
	cin>>a[1];
	cout<<"左下:"<<endl;
	cin>>a[2];
	cout<<"右下:"<<endl;
	cin>>a[3];
	cout<<"中间:"<<endl;
	cin>>a[4];
	cout<<"稀释倍数:"<<endl;
	cin>>a[5];
    sum=a[0]+a[1]+a[2]+a[3]+a[4];
    b=sum*5*a[5];
    cout<<"结果为："<<b<<"0000"<<endl;
	}
    while(1);
	return 0;
}

