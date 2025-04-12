#include <stdio.h>
#include <stdlib.h>

int N;

typedef int ElemType;

typedef struct TreeTNode{
    ElemType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef struct stack{
    TreeNode **NodeArray;
    int top;
} Stack;

Stack *InitStack(){
    Stack *s=(Stack *)malloc(sizeof(Stack));
    if(!s){
        printf("Error: The allocation of stack structuer failed\n");
        return NULL;
    }
    s->NodeArray=(TreeNode**)malloc(sizeof(TreeNode*)*N);
    if(!s->NodeArray){
        printf("Error: The allocation of stack data failed\n");
        free(s);
        return NULL;
    }
    s->top=-1;
    return s;
}

void push(Stack *s, TreeNode* TreeNode){
    if(s->top == N-1){
        printf("The stack is full\n");
        return ;
    }
    s->NodeArray[++s->top] = TreeNode;
}

TreeNode *pop(Stack *s){
    if(s->top == -1){
        printf("The stack is empty\n");
        return ;
    }
    return s->NodeArray[s->top--];
}

//非递归方式遍历
void iterPreOrder_Traversal(TreeNode *Root, Stack *s){
    TreeNode *current = Root;
    while(current || s->top == -1){
        while(current){
            printf("%d ",current->data);
            push(s,current);
            current = current->lchild;
        }
        current = pop(s)->rchild;
    }
}

//递归方法
//前序遍历
void InOrder_Traversal(TreeNode *Root){
    if(!Root){
        return ;
    }
    printf("%d ",Root->data);
    InOrder_Traversal(Root->lchild);
    InOrder_Traversal(Root->rchild);
}

int main(){
    //节点数
    scanf("%d",&N);

    TreeNode *Root=NULL;

    Stack *s=InitStack();

    return 0;
}