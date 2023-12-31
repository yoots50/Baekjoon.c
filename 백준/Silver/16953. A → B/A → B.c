#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
    int number;
    int cnt;
} data;

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

int BFS(int A, int B) {
    queue q;
    queue* ptr = &q;
    data now;
    data tmp;
    initQueue(ptr);
    tmp.number = B;
    tmp.cnt = 1;
    enQueue(ptr, tmp);
    
    while (q.size != 0) {
        now = deQueue(ptr);
        if (now.number == A) {
            return now.cnt;
        }
        if (now.number % 10 == 1 && (now.number - 1) / 10 >= A) {
            tmp.number = (now.number - 1) / 10;
            tmp.cnt = now.cnt + 1;
            enQueue(ptr, tmp);
        }
        if (now.number % 2 == 0 && now.number / 2 >= A) {
            tmp.number = now.number / 2;
            tmp.cnt = now.cnt + 1;
            enQueue(ptr, tmp);
        }
    }
    
    return -1;
}

int main()
{
    int A, B;
    scanf("%d%d", &A, &B);
    
    printf("%d", BFS(A, B));
}