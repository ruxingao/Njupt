#include<stdio.h>
#include <windows.h>
 
typedef struct ENode{
    int adjVex;        //���ڶ���
    int w;             //�ߵ�Ȩֵ
    struct ENode *next;  //ָ����һ����
}ENode;
 
typedef struct{
    int n;             //������
    int e;             //����
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
    if(u < 0||v < 0||u > g->n-1 ||v > g->n-1 ||u == v) return 0; //������� 
    ENode *p = g->a[u];                   
    while(p!=NULL && p->adjVex != v){
        p = p->next;
    }
    if(!p) return 0; //δ�ҵ��˱�
    else return 1; //�ҵ��˱� 
}

void Insert(graph *g,int u,int v,int w){
    if(u < 0||v < 0||u > g->n-1||v > g->n-1 ||u == v) return; //������� 
    if(Exist(g,u,v)) return;  //���Ѵ���
    ENode *p = (ENode*)malloc(sizeof(ENode));   
    p->adjVex = v;
    p->w = w;
    p->next = g->a[u];         
    g->a[u] = p;
    g->e ++;                            
}
 
BOOL Remove(graph *g,int u,int v){
    if(u < 0||v < 0||u > g->n-1||v > g->n-1 ||u == v) return 0; //������� 
    ENode *p = g->a[u];
    ENode *q = NULL;
    while(p && p->adjVex!=v){      
        q = p; //q�� pǰһ��� 
        p = p->next;
    }
    if(!p) return 0; //δ�ҵ���ɾ���� 
    if(q) q->next = p->next; //ɾ���˱� 
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

//��ʼ��һ���ն��� 
void Create(Queue *Q,int mSize){
    Q->maxSize=mSize;
    Q->element=(int*)malloc(sizeof(int)*mSize);
    Q->front=Q->rear=0;
}
 
//�ж϶����Ƿ�Ϊ��
BOOL IsEmpty(Queue *Q){
    return Q->front==Q->rear;
}
 
//�ж϶����Ƿ�����
BOOL IsFULL(Queue *Q){
    return (Q->rear+1)%(Q->maxSize)==Q->front;
}
 
//��ȡ��ͷԪ�� 
void Front(Queue *Q,int *x){
    if(IsEmpty(Q)) return;
    *x=Q->element[(Q->front+1)%(Q->maxSize)];
}
 
//��β����Ԫ��
BOOL EnQueue(Queue *Q,int x){
    if(IsFULL(Q)) return 0;
    Q->rear=(Q->rear+1)%(Q->maxSize); 
    Q->element[Q->rear]=x;
    return 1;
}
 
//ɾ����ͷԪ��
BOOL DeQueue(Queue *Q){
    if(IsEmpty(Q)) return 0;
    Q->front=(Q->front+1)%(Q->maxSize);
    return TRUE;
}

//��һ���� DFS
void DFS(int i,int visited[],graph g){
    printf("%d ",i);                           
    visited[i] = 1;      
	ENode *w;                      
    for(w=g.a[i]; w; w=w->next){          
        if(!visited[w->adjVex]){ //���ڽӽ��δ������ 
            DFS(w->adjVex,visited,g);          
        }
    }
}
 
//ȫͼ DFS
void DFSGraph(graph g){
    int *visited = (int*)malloc(g.n*sizeof(int)); //���ʱ�� 
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
 
//��һ���� BFS
void BFS(int v,int visited[],graph g){
	printf("%d ",v);  
    visited[v] = 1;                        
    ENode *w;
    Queue q;
    Create(&q,g.n);                                            
    EnQueue(&q,v); //��Ӳ��� 
    while(!IsEmpty(&q)){
        Front(&q,&v); //��ͷԪ��
        DeQueue(&q); //���Ӳ���                   
        for(w=g.a[v]; w; w=w->next){  
            if(!visited[w->adjVex]){ //��δ������  
				printf("%d ",w->adjVex);     
                visited[w->adjVex] = 1;
                EnQueue(&q,w->adjVex); //��Ӳ��� 
            }
        }
    }
}

//ȫͼ BFS 
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
    //1���ڽӱ�ĳ�ʼ��
    Init(&g,node);
    printf("Please enter the number of the edges:"); scanf("%d",&edge);
	//2���ڽӱ�Ĳ����
    for(i=0; i<edge; i++){
        printf("Please enter the edge:");
        scanf("%d%d%d",&u,&v,&w);
        Insert(&g,u,v,w);
    }
    printf("Please enter the deleted edge:"); scanf("%d%d",&u,&v);
	//3���ڽӱ��������
    if(Exist(&g,u,v)) printf("Succeed to search to the edge.");
    else printf("Failed to search to the edge.");   
    //4���ڽӱ��ɾ���� 
    if(Remove(&g,u,v)) printf("Succeed to delete the edge.");
    else printf("Failed to delete the edge.");
	//5���ڽӱ������� 
    if(Destory(&g)) printf("Succeed to remove the table.");
    printf("Failed to remove the table.");
    //6��������ȱ��� DFS
    printf("DFS:\n"); DFSGraph(g);
    //7��������ȱ��� BFS
    printf("\nBFS:\n"); BFSGraph(g);
    return 0;
}
