/**
 * 单向链表
 */

#include <stdio.h>
#include "single_list.h"

bool isLast(Position P,List L) {
    return (P->next == NULL) ? true : false;
}

bool isEmpty(List L) {

}


void makeEmpty(List L) {

}

void deleteList(List L) {

}

Position find(ElementType X, List L) {

}
Position findPrevious(ElementType X, List L) {

}

// 添加节点
void insert(ElementType X, List L, Position P){
    Position node = malloc(sizeof(struct Node));
    if (node == NULL) {
        perror("insert");
        return ;
    }

    node->element = X;
    node->next = P->next;
    
    P->next = node;
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

List intersect(List L1, List L2){}
List Union(List L1, List L2){}
List reverseList(List L){}
