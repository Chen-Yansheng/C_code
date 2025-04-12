/*rand指针是单链表节点结构的新增指针，rand可能指向链表的任意节点，也可能指向NULL。现有一个无环单链表的头节点head
请实现一个函数完成该链表的复制，并返回复制链表的头节点*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node *next;
    struct node *rand;
}Node;

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
        printf("头指针为空\n");
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
        printf("头指针为空\n");
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
        printf("头指针为空\n");
        return ;
    }
    Node *current=head->next;   //head(哨兵节点)不存储数据,释放head可能会导致free()异常
    while(current){
        Node *next=current->next;
        free(current);
        current=next;
    }
}

Node *CopyNode(Node *n){
    Node *newNode=(Node *)malloc(sizeof(Node));
    if(!newNode){
        printf("复制节点时新节点申请失败\n");
        return NULL;
    }
    newNode->data=n->data;
    return newNode;
}

Node *Copy(Node *head){
    //先再每个节点后面复制插入
    Node *current=head->next;
    while(current){
        Node *copyNode=CopyNode(current);
        copyNode->next=current->next;
        current->next=copyNode;
        current=current->next->next;
    }

    //设置rand指针
    current=head->next;
    while(current){
        if(current->rand){
            current->next->rand=current->rand->next;
        }
        else{
            current->next->rand=NULL;
        }
        current=current->next->next;
    }

    //分离链表
    current=head->next;
    Node *copyHead=InitList();
    Node *copyCurrent=copyHead;
    while(current){
        copyCurrent->next=current->next;
        copyCurrent=copyCurrent->next;

        current->next=copyCurrent->next;
        current=current->next;
    }
    return copyHead;
}

int main(){
    Node *head=InitList();
    Node *tail=head;

    tail=TailInsert(head,tail,11);
    tail=TailInsert(head,tail,22);
    tail=TailInsert(head,tail,33);
    tail=TailInsert(head,tail,44);
    //Ergodic(head);      //此时不输出的原因:rand未初始化,current->rand的值是未定义的,可能导致程序崩溃或没有输出.应先设置rand,再Ergodic

    head->next->rand=head->next->next->next->next;      //1->4, 2->1, 3->null, 4->4
    head->next->next->rand=head->next;
    head->next->next->next->rand=NULL;
    head->next->next->next->next->rand=head->next->next->next->next;
    Ergodic(head);

    Node *copyhead=Copy(head);
    Ergodic(copyhead);
    Ergodic(head);
    
    Destroy(copyhead);
    Destroy(head);
    return 0;
}