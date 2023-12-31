#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    short x;
    short y;
} data;

typedef struct Graphdata {
    short distance;
    short visited;
} GraphData;

typedef struct Node {
    data data;
    struct Node* next;
} node;

typedef struct Queue {
    int size;
    node* front;
    node* back;
} queue;

void initQueue(queue* q) {
    q->size = 0;
    q->front = q->back = NULL;
}

void enQueue(queue* q, data data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->size == 0) {
        q->front = newNode;
    }
    
    else {
        q->back->next = newNode;
    }
    
    q->back = newNode;
    q->size++;
}

data deQueue(queue* q) {
    node* ptr = q->front;
    data data = ptr->data;
    q->front = ptr->next;
    q->size--;
    free(ptr);
    return data;
}

void func(short** graph, short goalx, short goaly, short n, short m) {
    queue q;
    queue* ptr = &q;
    data tmp;
    data now;
    GraphData graphTmp;
    
    GraphData** graphData = (GraphData**)malloc(sizeof(GraphData*) * n);
    for (short i = 0; i < n; i++) {
        graphData[i] = (GraphData*)malloc(sizeof(GraphData) * m);
        for (short j = 0; j < m; j++) {
            graphTmp.distance = 0;
            graphTmp.visited = graph[i][j] == 0;
            graphData[i][j] = graphTmp;
        }
    }
    
    tmp.x = goalx;
    tmp.y = goaly;
    initQueue(ptr);
    enQueue(ptr, tmp);
    graphData[goaly][goalx].visited = 1;
    
    short movx, movy, nextDis;
    while (ptr->size != 0) {
        now = deQueue(ptr);
        nextDis = graphData[now.y][now.x].distance + 1;
        
        movx = now.x + 1;
        movy = now.y;
        if (movx < m && graphData[movy][movx].visited == 0) {
            graphData[movy][movx].visited = 1;
            graphData[movy][movx].distance = nextDis;
            tmp.x = movx;
            tmp.y = movy;
            enQueue(ptr, tmp);
        }
        
        movx = now.x - 1;
        if (movx >= 0 && graphData[movy][movx].visited == 0) {
            graphData[movy][movx].visited = 1;
            graphData[movy][movx].distance = nextDis;
            tmp.x = movx;
            tmp.y = movy;
            enQueue(ptr, tmp);
        }
        
        movy = now.y - 1;
        movx = now.x;
        if (movy >= 0 && graphData[movy][movx].visited == 0) {
            graphData[movy][movx].visited = 1;
            graphData[movy][movx].distance = nextDis;
            tmp.x = movx;
            tmp.y = movy;
            enQueue(ptr, tmp);
        }
        
        movy = now.y + 1;
        if (movy < n && graphData[movy][movx].visited == 0) {
            graphData[movy][movx].visited = 1;
            graphData[movy][movx].distance = nextDis;
            tmp.x = movx;
            tmp.y = movy;
            enQueue(ptr, tmp);
        }
    }
    
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < m; j++) {
            printf("%hd ", graphData[i][j].visited ? graphData[i][j].distance : -1);
        }
        putchar('\n');
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    short goalx, goaly;
    short** graph = (short**)malloc(sizeof(short*) * n);
    short** visited = (short**)malloc(sizeof(short) * n);
    for (short i = 0; i < n; i++) {
        graph[i] = (short*)malloc(sizeof(short) * m);
        for (short j = 0; j < m; j++) {
            scanf("%hd", &graph[i][j]);
            if (graph[i][j] == 2) {
                goaly = i;
                goalx = j;
            }
        }
    }
    
    func(graph, goalx, goaly, n, m);
}