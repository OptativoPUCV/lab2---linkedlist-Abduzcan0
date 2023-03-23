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
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  return list;
}

void * firstList(List * list) {

  if(list->head == NULL)return NULL;
  list->current = list->head;  
  return list->current->data;
}

void * nextList(List * list) {
  if(list->current == NULL || list->current->next==NULL)return NULL;
  list->current=list->current->next;
  return list->current->data;
}

void * lastList(List * list) {
  if(list->current==NULL || list->current->next==NULL)return NULL;

  while(list->current->next!=NULL){
    list->current=list->current->next;
  }
  return list->current->data;
}

void * prevList(List * list) {
  if(list->current==NULL || list->current->prev==NULL)return NULL;
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
   if(list->current == NULL){  
      list->head = n;
      list->tail = n;
    }
    else{
      if(list->current == list->tail){
        list->tail = n;    
      }
      else{     
        n->next = list->current->next;
        list->current->next->prev = n;
      }
      n->prev = list->current;
      list->current->next = n;
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
  void *datoBorrado;
  if(list->current == NULL) return NULL;
  datoBorrado = list->current->data;
  
  if(list->current == list->tail){
    
      list->tail = list->current->prev;
      list->tail->next = NULL;
      list->current = NULL;
    
  }else if(list->current == list->head){
    
        list->head = list->current->next;
        list->head->prev = NULL;
        list->current = NULL;
       
  }else{
        
      list->current->prev->next = list->current->next;
      list->current->next->prev = list->current->prev;
      list->current = NULL;
    
  }  

  free(list->current);
  return datoBorrado;
   
}

void cleanList(List * list) {
  while (list->head != NULL) {
      popFront(list);
  }
}