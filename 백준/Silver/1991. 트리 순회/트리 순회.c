#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    char data;
    struct tree* left;
    struct tree* right;
} t_node;

void preorder_traversal(t_node* head) {
    printf("%c", head->data);
    if (head->left != NULL)
        preorder_traversal(head->left);
    if (head->right != NULL)
        preorder_traversal(head->right);
}

void inorder_traversal(t_node* head) {
    if (head->left != NULL)
        inorder_traversal(head->left);
    printf("%c", head->data);
    if (head->right != NULL)
        inorder_traversal(head->right);
}

void postorder_traversal(t_node* head) {
    if (head->left != NULL)
        postorder_traversal(head->left);
    if (head->right != NULL)
        postorder_traversal(head->right);
    printf("%c", head->data);
}

int main()
{
    int N;
    scanf("%d", &N);
    
    t_node* arr = (t_node*)malloc(sizeof(t_node) * N);
    char p_node, l_node, r_node;
    getchar();
    
    for (int i = 0; i < N; i++) {
        
        t_node* newTree = (t_node*)malloc(sizeof(t_node));
        newTree->right = NULL;
        newTree->left = NULL;
        p_node = getchar();
        getchar();
        l_node = getchar();
        getchar();
        r_node = getchar();
        getchar();
        
        arr[p_node - 'A'].data = p_node;
        if (l_node != '.')
            arr[p_node - 'A'].left = &arr[l_node - 'A'];
        if (r_node != '.')
            arr[p_node - 'A'].right = &arr[r_node - 'A'];
    }
    
    preorder_traversal(&arr[0]);
    putchar('\n');
    inorder_traversal(&arr[0]);
    putchar('\n');
    postorder_traversal(&arr[0]);
}