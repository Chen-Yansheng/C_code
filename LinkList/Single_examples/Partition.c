/*链表分区*/

#include <stdio.h>  
#include <stdlib.h>

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node* next;
}Node;

Node* InitList() {
    Node* head = (Node*)malloc(sizeof(Node));
    if (!head) {
        printf("头节点申请失败\n");
        return NULL;
    }
    head->next = NULL;
    return head;
}

void HeadInsert(Node* head, ElemType data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("头插时新节点申请失败\n");
        return;
    }
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
}

void ErgodicList(Node* list) {
    if (!list) {
        printf("Error:head is NULL\n");
        return;
    }
    Node* current = list->next;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n\n");
}

void DestroyList(Node* list) {
    if (!list) {
        printf("Error:head is NULL\n");
        return;
    }
    Node* current = list->next;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void partition(Node* list, ElemType pivot) {
    if (!list) {
        printf("Error:head is NULL\n");
        return;
    }
    Node *sh, *st, *eh, *et, *bh, *bt;  //smallhead, smalltail, equalhead, equaltail, bighead, bigtail
    sh = st = eh = et = bh = bt = NULL;

    Node *current = list->next;     //注意正确处理链表的尾部节点的 next 指针，否则可能导致循环链表。
    while (current) {
        Node *next = current->next;
        current->next = NULL;       //断开当前节点的连接，可以使每个区的尾指针指向NULL
        if (current->data < pivot) {
            if (!sh) {
                sh = st = current;
            }
            else {
                st->next = current;
                st = current;
            }
        }
        else if (current->data == pivot) {
            if (!eh) {
                eh = et = current;
            }
            else {
                et->next = current;
                et = current;
            }
        }
        else {
            if (!bh) {
                bh = bt = current;
            }
            else {
                bt->next = current;
                bt = current;
            }
        }
        current = next;
    }

    //打印各组链表
    puts("Small list:");
    ErgodicList(sh);
    puts("Equal list:");
    ErgodicList(eh);    
    puts("Big list:");
    ErgodicList(bh);

    //将三组链表连起来
    if (sh) {
        list->next = sh;
        if (eh) {
            st->next = eh;
            if (bh) {
                et->next = bh;
            }
        }
        else {
            if (bh) {
                st->next = bh;
            }
        }
    }
    else if (eh) {
        list->next = eh;
        if (bh) {
            et->next = bh;
        }
    }
    else {
        list->next = bh;
    }
}


int main() {
    Node* list = InitList();
    HeadInsert(list, 7);
    HeadInsert(list, 6);
    HeadInsert(list, 4);
    HeadInsert(list, 11);
    HeadInsert(list, 5);
    HeadInsert(list, 9);
    puts("Original list:");
    ErgodicList(list);

    partition(list, 7);
    puts("Partitioned list:");
    ErgodicList(list);

    DestroyList(list);
    return 0;
}