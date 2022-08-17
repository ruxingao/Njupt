#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;
unsigned int length=10000;
void swap(int *m,int *n)
{
    int temp;
    temp=*m;
    *m=*n;
    *n=temp;}
void fix_tree(float *tree, unsigned int start, unsigned int end){
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && tree[son] < tree[son + 1])
            son++;
        if (tree[dad] > tree[son])
            return;
        else {
            swap(tree[dad], tree[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void build_tree(float *tree, unsigned int length){
    for (int i = length / 2 - 1; i >= 0; i--) 
        fix_tree(tree, i, length - 1);
}
int main(){
	int b,c,i,d=length;
	float a[length];
	for(i=0;i<length;i++){
		b=rand()%101;
		c=rand()%10;
		a[i]=b+c*0.1;
		if(a[i]>100)
		a[i]--;}
	build_tree(a,length-1);
	swap(a[0],a[length]);
	cout<<a[length]<<endl;
	
    for(i=0;i<9;i++){
    	fix_tree(a,0,d-2);
    	swap(a[0],a[d-1]);
	cout<<a[d-1]<<endl;
    	d--;
    	
	}
	
	return 0;

}
