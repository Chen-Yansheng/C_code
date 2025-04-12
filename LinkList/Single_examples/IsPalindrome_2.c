/*判断是否为回文链表*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    if(!head){
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

bool IsPalindrome(Node *head){
    if(!head || !head->next){
        return true;
    }

    //Slow eventually points to the middle(right) node
    Node *fast=head, *slow=head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    //Reverse the nodes after slow (including slow)
    Node *first=NULL, *second=slow, *third;
    while(second){
        third=second->next;
        second->next = first;
        first = second;
        second = third;
    }

    //compare the first node with "first"
    Node *current = head->next;
    while(current && first){
        if(current->data != first->data){
            return false;
        }
        current = current->next;
        first = first->next;
    }
    return true;
}

int main(){
    Node *head=InitList();
    Node *tail=head;

    tail=TailInsert(head,tail,11);
    tail=TailInsert(head,tail,22);
    tail=TailInsert(head,tail,33);
    tail=TailInsert(head,tail,44);
    tail=TailInsert(head,tail,33);
    tail=TailInsert(head,tail,22);
    tail=TailInsert(head,tail,11);

    printf("%d\n",IsPalindrome(head));

    Destroy(head);
    return 0;
}