#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

typedef struct queue {
    int cnt;
    NODE* front;
    NODE* rear;
} QUEUE;

typedef struct link {
    NODE* start;
    NODE* last;
    int cnt;
} LINK;

void initLink(LINK* l) {
    l->start = l->last = NULL;
    l->cnt = 0;
}

void insLink(LINK* l, int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    
    if (l->cnt == 0) {
        l->start = newNode;
    }
    
    else {
        l->last->next = newNode;
    }
    
    l->last = newNode;
    l->cnt++;
}

void initQueue(QUEUE* q) {
    q->rear = q->front = NULL;
    q->cnt = 0;
}

void enQueue(QUEUE* q, int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
   
    if (q->cnt == 0) {
        q->front = newNode;
    }
   
    else {
        q->rear->next = newNode;
    }
   
    q->rear = newNode;
    q->cnt++;
}

int deQueue(QUEUE* q) {
    int ret;
    NODE* ptr;
    
    ptr = q->front;
    ret = ptr->data;
    q->front = ptr->next;
    free(ptr);
    q->cnt--;
   
    return ret;
}

int* BFS(LINK* graph, int length) {
    QUEUE q;
    initQueue(&q);
    enQueue(&q, 1);
    int* tree = (int*)malloc(sizeof(int) * (length + 1));
   
    int parents;
    NODE* now;
    while (q.cnt != 0) {
        parents = deQueue(&q);
        now = graph[parents].start;
        while (now != NULL) {
            if (tree[now->data] == 0) {
                enQueue(&q, now->data);
                tree[now->data] = parents;
            }
            
            now = now->next;
        }
    }
   
    return tree;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    LINK* graph = (LINK*)malloc(sizeof(LINK) * (N + 2));
    for (int i = 0; i < N + 2; i++) {
        initLink(&graph[i]);
    }
    
    int x, y;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d%d", &x, &y);
        insLink(&graph[x], y);
        insLink(&graph[y], x);
    }
       
    int* tree = (int*)malloc(sizeof(int) * (N + 1));
    tree = BFS(graph, N);
   
    for (int i = 2; i <= N; i++) {
        printf("%d\n", tree[i]);
    }
}