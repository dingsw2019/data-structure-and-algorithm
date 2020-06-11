/**
 * 单向链表
 */

#include <stdio.h>
#include "single_list.h"

bool isLast(Position P,List L) {
    return (P->next == NULL) ? true : false;
}

bool isEmpty(List L) {
    return (L->next == NULL) ? true : false;
}

// 清空链表
void makeEmpty(List L) {
    Position P = L->next;
    Position tmp;

    while(P != NULL) {
        tmp = P->next;
        free(P);
        P = tmp;
    }
}

// 释放链表
void deleteList(List L) {
    makeEmpty(L);
    free(L);
}

// 查找节点
Position find(ElementType X, List L) {
    Position P = L->next;
    while (P != NULL && P->element != X)
        P = P->next;
    return P;
}

// 查找节点, 返回目标节点的前置节点
Position findPrevious(ElementType X, List L) {
    Position P = L;
    while (P->next != NULL && P->next->element != X)
        P = P->next;
    return P;
}

// 添加节点
void insert(ElementType X, List L, Position P){
    Position tmpCell = malloc(sizeof(struct Node));
    if (tmpCell == NULL) {
        perror("insert");
        return ;
    }

    tmpCell->element = X;
    tmpCell->next = P->next;
    
    P->next = tmpCell;
}

void delete(ElementType X, List L){

    Position P = findPrevious(X,L);
    Position tmpCell;

    if (!isLast(P,L)) {
        tmpCell = P->next;
        P->next = tmpCell->next;
        free(tmpCell);
    }
}

void printList(List L){
    if (isEmpty(L)) return;

    Position P = L->next;
    while (P != NULL || P->next != NULL) {
        printf("%d -> ",P->element);
        P = P->next;
    }

    if (P != NULL && P->next == NULL) {
        printf("%d\n", P->element);
    }
}

List fromArray(ElementType *A, size_t N){
    List L = malloc(sizeof(struct Node));
    Position P = L;
    int i;
    for (i=0; i<N; ++i) {
        insert(A[i],L,P);
        P = P->next;
    }
    return L;
}

Position header(List L){
    return L;
}

Position first(List L){
    return L->next;
}

Position advance(Position P){
    return P->next;
}

// 交集
List intersect(List L1, List L2) {
    List L = malloc(sizeof(struct Node));
    Position P = L;

    Position l1 = L1->next;
    Position l2 = L2->next;

    while (l1 != NULL && l2 != NULL) {
        if (l1->element == l2->element) {

        } else if (l1->element < l2->element) {

        } else {
            // l1 = 
        }
    }
}

// 并集
List Union(List L1, List L2){}


List reverseList(List L){}
