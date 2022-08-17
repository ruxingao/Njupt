#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <malloc.h>
using namespace std;
typedef int ElemType;
typedef struct btnode
{ElemType element;
struct btnode *lChild;
struct btnode *rChild;
}BTNode;
typedef struct binarytree
{BTNde *root;
}BinaryTree;
void Create(BinaryTree *bt)
{bt->root=NULL;
}
BTNode *NewNode(ElemType x,BTNode *ln,BTNode *rn)
{BTNode *p=(ElemType*)
}
