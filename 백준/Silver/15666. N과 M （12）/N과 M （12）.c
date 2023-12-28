#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} node;

typedef struct Link {
    int size;
    node* first;
    node* last;
} link;

void initLink(link* l) {
    l->size = 0;
    l->first = l->last = NULL;
    return;
}

void insLink(link* l, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (l->size == 0) {
        l->first = newNode;
        newNode->prev = NULL;
    }
    
    else {
        l->last->next = newNode;
        newNode->prev = l->last;
    }
    
    l->size++;
    l->last = newNode;
    return;
}

void printLink(link* l) {
    node* ptr = l->first;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    putchar('\n');
    return;
}

void delLink(link* l) {
    if (l->size == 0) {
        return;
    }
    
    if (l->size == 1) {
        free(l->first);
        initLink(l);
        return;
    }
    
    node* ptr;
    ptr = l->last;
    ptr->prev->next = NULL;
    l->last = ptr->prev;
    l->size--;
    free(ptr);
    return;
}

void func(int* parr, int M, int cnt, link* l) {
    if (cnt == M) {
        printLink(l);
        return;
    }
    
    for (int i = 0; i < 10001; i++) {
        if (parr[i] == 1) {
            if (cnt == 0) {
                insLink(l, i);
                func(parr, M, cnt + 1, l);
                delLink(l);
            }
            else if (l->last->data <= i){
                insLink(l, i);
                func(parr, M, cnt + 1, l);
                delLink(l);
            }
        }
    }
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    
    int arr[10001];
    for (int i = 0; i < 10001; i++) {
        arr[i] = 0;
    }
    
    int input;
    for (int i = 0; i < N; i++) {
        scanf("%d", &input);
        arr[input] = 1;
    }
    
    link l;
    func(arr, M, 0, &l);    
}