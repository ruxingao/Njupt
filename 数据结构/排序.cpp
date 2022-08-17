#include<stdio.h>
#include <windows.h>
 
typedef struct ENode{
    int adjVex;        //相邻顶点
    int w;             //边的权值
    struct ENode *next;  //指向下一顶点
}ENode;
 
typedef struct{
    int n;             //顶点数
    int e;             //边数
    ENode **a;         
}graph;
 
void Init(graph *g,int n){
    int  i;
    g->n = n;
    g->e = 0;
    g->a = (ENode**)malloc(n*sizeof(ENode*));  
	for(i=0; i<g->n; i++){
        g->a[i] = NULL;                        
    }
    return;
}

BOOL Exist(graph *g,int u,int v){
    if(u < 0||v < 0||u > g->n-1 ||v > g->n-1 ||u == v) return 0; //输入错误 
    ENode *p = g->a[u];                   
    while(p!=NULL && p->adjVex != v){
        p = p->next;
    }
    if(!p) return 0; //未找到此边
    else return 1; //找到此边 
}

void Insert(graph *g,int u,int v,int w){
    if(u < 0||v < 0||u > g->n-1||v > g->n-1 ||u == v) return; //输入错误 
    if(Exist(g,u,v)) return;  //边已存在
    ENode *p = (ENode*)malloc(sizeof(ENode));   
    p->adjVex = v;
    p->w = w;
    p->next = g->a[u];         
    g->a[u] = p;
    g->e ++;                            
}
 
BOOL Remove(graph *g,int u,int v){
    if(u < 0||v < 0||u > g->n-1||v > g->n-1 ||u == v) return 0; //输入错误 
    ENode *p = g->a[u];
    ENode *q = NULL;
    while(p && p->adjVex!=v){      
        q = p; //q是 p前一结点 
        p = p->next;
    }
    if(!p) return 0; //未找到待删除边 
    if(q) q->next = p->next; //删除此边 
    else g->a[u] = p->next;
    free(p);
    g->e --;
    return 1;
}
 
int Destory(graph *g){
    ENode *p,*q;
    for(int i=0; i<g->n; i++){
        p = g->a[i];                 
        q = p;
        while(p){                     
            p = p->next;
            free(q);
            q = p;
        }
    }
    free(g->a);                     
    return 1;                       
}

typedef struct{
    int front;
    int rear;
    int maxSize; 
    int *element;
}Queue;

//初始化一个空队列 
void Create(Queue *Q,int mSize){
    Q->maxSize=mSize;
    Q->element=(int*)malloc(sizeof(int)*mSize);
    Q->front=Q->rear=0;
}
 
//判断队列是否为空
BOOL IsEmpty(Queue *Q){
    return Q->front==Q->rear;
}
 
//判断队列是否已满
BOOL IsFULL(Queue *Q){
    return (Q->rear+1)%(Q->maxSize)==Q->front;
}
 
//获取队头元素 
void Front(Queue *Q,int *x){
    if(IsEmpty(Q)) return;
    *x=Q->element[(Q->front+1)%(Q->maxSize)];
}
 
//队尾插入元素
BOOL EnQueue(Queue *Q,int x){
    if(IsFULL(Q)) return 0;
    Q->rear=(Q->rear+1)%(Q->maxSize); 
    Q->element[Q->rear]=x;
    return 1;
}
 
//删除队头元素
BOOL DeQueue(Queue *Q){
    if(IsEmpty(Q)) return 0;
    Q->front=(Q->front+1)%(Q->maxSize);
    return TRUE;
}

//单一顶点 DFS
void DFS(int i,int visited[],graph g){
    printf("%d ",i);                           
    visited[i] = 1;      
	ENode *w;                      
    for(w=g.a[i]; w; w=w->next){          
        if(!visited[w->adjVex]){ //若邻接结点未被访问 
            DFS(w->adjVex,visited,g);          
        }
    }
}
 
//全图 DFS
void DFSGraph(graph g){
    int *visited = (int*)malloc(g.n*sizeof(int)); //访问标记 
    for(int i=0; i<g.n; i++){
        visited[i] = 0;                             
    }
    for(int i=0; i<g.n; i++){                        
        if(!visited[i]){
            DFS(i,visited,g);
        }
    }
    free(visited);                                
}
 
//单一顶点 BFS
void BFS(int v,int visited[],graph g){
	printf("%d ",v);  
    visited[v] = 1;                        
    ENode *w;
    Queue q;
    Create(&q,g.n);                                            
    EnQueue(&q,v); //入队操作 
    while(!IsEmpty(&q)){
        Front(&q,&v); //队头元素
        DeQueue(&q); //出队操作                   
        for(w=g.a[v]; w; w=w->next){  
            if(!visited[w->adjVex]){ //若未被访问  
				printf("%d ",w->adjVex);     
                visited[w->adjVex] = 1;
                EnQueue(&q,w->adjVex); //入队操作 
            }
        }
    }
}

//全图 BFS 
void BFSGraph(graph g){
    int *visited = (int*)malloc(g.n*sizeof(int));  
    for(int i=0; i<g.n; i++){                        
        visited[i] = 0;
    }
    for(int i=0; i<g.n; i++){                   
        if(!visited[i]){
            BFS(i,visited,g);
        }
    }
    free(visited);
}

int main(){
    graph g;
    int i,u,v,node,edge,w;
    printf("Please enter the number of the node:"); scanf("%d",&node);
    //1、邻接表的初始化
    Init(&g,node);
    printf("Please enter the number of the edges:"); scanf("%d",&edge);
	//2、邻接表的插入边
    for(i=0; i<edge; i++){
        printf("Please enter the edge:");
        scanf("%d%d%d",&u,&v,&w);
        Insert(&g,u,v,w);
    }
    printf("Please enter the deleted edge:"); scanf("%d%d",&u,&v);
	//3、邻接表的搜索边
    if(Exist(&g,u,v)) printf("Succeed to search to the edge.");
    else printf("Failed to search to the edge.");   
    //4、邻接表的删除边 
    if(Remove(&g,u,v)) printf("Succeed to delete the edge.");
    else printf("Failed to delete the edge.");
	//5、邻接表撤销操作 
    if(Destory(&g)) printf("Succeed to remove the table.");
    printf("Failed to remove the table.");
    //6、深度优先遍历 DFS
    printf("DFS:\n"); DFSGraph(g);
    //7、宽度优先遍历 BFS
    printf("\nBFS:\n"); BFSGraph(g);
    return 0;
}
