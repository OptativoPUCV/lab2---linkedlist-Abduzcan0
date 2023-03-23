#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* list=(List*)malloc(sizeof(List));
    list->head=NULL;
    list->tail=NULL;
    list->current=NULL;
    return list;
}

void * firstList(List * list) {

    if(list->head==NULL)return NULL;
    list->current=list->head;  
    return list->current->data;
}

void * nextList(List * list) {
    if(list==NULL || list->current==NULL || list->current->next==NULL)return NULL;
    list->current=list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    if(list==NULL || list->current==NULL || list->current->next==NULL)return NULL;

    while(list->current->next!=NULL){
      list->current=list->current->next;
    }
    return list->current->data;
}

void * prevList(List * list) {
    if(list==NULL || list->current==NULL || list->current->prev==NULL)return NULL;
    list->current=list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
    Node* n = createNode(data); 
    
    if(list->head==NULL){
      list->head=n;
      list->tail=n;
    }else{
      n->next=list->head;
      list->head->prev=n;
      list->head=n;
    }
   
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node *n = createNode(data);
    

    if (list->current == NULL) {
        list->head = n ;
        list->current = n ;
    } else {
        list->current->next = n ;
        list->tail=n;
        n->prev=list->current;
    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}