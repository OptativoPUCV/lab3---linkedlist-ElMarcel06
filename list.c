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
  List* nuevo = malloc(sizeof(List));
  nuevo->head = NULL;
  nuevo->tail = NULL;
  nuevo->current = NULL;
  
  
     return nuevo;
}

void * firstList(List * list) {
  if(list->head == NULL){
      return NULL;
    }
  list->current = list->head;
  return list->head->data;
}

void * nextList(List * list) {
  if(list->current == NULL){
    return NULL;
  }
  if(list->current->next == NULL){
    return NULL;
  }
  list->current = list->current->next;
  return list->current->data;
}

void * lastList(List * list) {
  if(list->tail != NULL){
    list->current = list->tail;
  }
  
  return list->current->data;
} 
  

void * prevList(List * list) {
  if(list->current == NULL){
    return NULL;
  }
  if(list->current->prev == NULL){
    return NULL;
  }
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) {
  Node* nuevo = createNode(data);
  if(list->head == NULL){
    list->head = nuevo;
    list->tail = nuevo;
    
  }
  else{
    nuevo->next = list->head;
    list->head->prev = nuevo;
    
  }
  list->head = nuevo;
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* aux = malloc(sizeof(Node));
  aux->data = data;
  aux->next = list->current->next;
  aux->prev = list->current;
  list->current->next = aux;
  if(aux->next != NULL){
    aux->next->prev = aux;
  }
  else{
    list->tail = aux;
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
  if(list->current == NULL){
    return NULL;
  }
  if(list->current->prev == NULL){
    list->head = list->current->next;
    
  }
  else{
    list->current->prev->next = list->current->next;
  }
  if(list->current->next == NULL){
    list->tail = list->current->prev;
  }
  else{
    list->current->next->prev = list->current->prev;
  }
  return list->current->data;
    
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}