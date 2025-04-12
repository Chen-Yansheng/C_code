/*判断是否为回文链表*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int N = 4;

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
    struct node *rand;
} Node;

typedef struct {
    ElemType *data;
    int top;
} Stack;

Node * InitList(){
    Node *head=(Node *)malloc(sizeof(Node));
    if(!head){
        printf("头节点申请失败\n");
        return NULL;
    }
    head->next=NULL;
    return head;
}

Node *TailInsert(Node *head, Node *tail, ElemType data){
    if(!tail){
        printf("Error: head is NULL\n\n");
        return NULL;
    }
    Node *newNode=(Node *)malloc(sizeof(Node));
    if(!newNode){
        printf("尾插时新节点分配失败\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=tail->next;
    tail->next=newNode;
    tail=newNode;
    return tail;
}

void Ergodic(Node *head){
    if(!head){
        printf("Error: head is NULL\n\n");
        return ;
    }

    Node *current=head->next;
    while(current){
        if(current->rand){
            printf("%d(%d) -> ",current->data, current->rand->data);
        }
        else{
            printf("%d(NULL) -> ",current->data);
        }
        //printf("%d(%s) -> ",current->data,current->rand?"RAND":"NULL");
        current=current->next;
    }
    printf("NULL\n\n");
}

void Destroy(Node *head){
    if(!head){
        printf("Error: head is NULL\n");
        return ;
    }
    Node *current=head;
    while(current){
        Node *next=current->next;
        free(current);
        current=next;
    }
}

void pushStack(Stack *s, ElemType data){
    if(s->top == N/2-1){
        printf("Error: Stack is full\n");
        return ;
    }
    s->data[++s->top]=data;
}

ElemType popStack(Stack *s){
    if(s->top == -1){
        printf("Error: Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}

bool IsPalindrome(Node *head){
    if(!head){
        printf("Error: head is NULL\n");
        return false;
    }

    //快慢指针，慢指针(middle+1)后面的节点入栈
    Node *fast=head, *slow=head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    //创建栈
    Stack *s=(Stack *)malloc(sizeof(Stack));
    if(!s){
        printf("Error: Stack Initialization Failed\n");
        return NULL;
    }
    s->data=(ElemType *)malloc(sizeof(ElemType)*(N/2));
    if(!s->data){
        printf("Error: Stack data request failed\n");
        return false;
    }
    s->top = -1;

    //入栈
    while(slow){
        pushStack(s, slow->data);
        slow = slow->next;
    }

    //第一节点开始和出栈元素比较
    Node *current=head->next;
    while(current && s->top != -1){
        if(current->data != popStack(s)){
            return false;
        }
        current = current->next;
    }

    //释放内存
    free(s->data);
    free(s);
    return true;
}

int main(){
    Node *head=InitList();
    Node *tail=head;

    tail=TailInsert(head,tail,11);
    tail=TailInsert(head,tail,22);
    tail=TailInsert(head,tail,33);
    tail=TailInsert(head,tail,22);
    tail=TailInsert(head,tail,11);

    printf("%d\n",IsPalindrome(head));

    Destroy(head);
    return 0;
}