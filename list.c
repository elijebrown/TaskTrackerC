#include "defs.h"

void initList(ListType *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

int initNode(NodeType **node, TaskType *data) {
    *node = (NodeType *) malloc(sizeof(NodeType));
    if (*node == NULL) {
        return FALSE;
    }
    (*node)->data = data;
    (*node)->next = NULL;
    (*node)->prev = NULL;
    return TRUE;
}

void add(ListType *list, TaskType *data) {
    addLast(list, data);
}

void addFirst(ListType *list, TaskType *data) {
    NodeType *node;
    if (initNode(&node, data) == FALSE) {
        return;
    }
    if (list->head == NULL) {
        list->tail = node;
    } else {
        node->next = list->head;
        node->next->prev = node;
    }
    list->head = node;
    list->size++;
}

void addLast(ListType *list, TaskType *data) {
    NodeType *node;
    if (initNode(&node, data) == FALSE) {
        return;
    }
    NodeType *temp = list->tail;
    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
        list->tail->next->prev = list->tail;
    }
    list->tail = node;
    list->size++;
}

char* find(ListType *list, char* name){
    if(list->size==0){
        return NULL;
    }
    else if(list->size==1){
        if(strcmp(list->head->data->name, name)==0){
            return list->head->data->id;
        }
        else{
            return NULL;
        }
    }
    else{
        NodeType* temp=list->head;
        while(temp!=NULL){
            if(strcmp(temp->data->name, name)==0){
                return temp->data->id;
            }
            temp=temp->next;
        }
        return NULL;
    }
}

int listRemove(ListType *list, char* id){
    if(list->size==0 || !id){
        return FALSE;
    }
    else if(list->size==1){
        NodeType *temp=list->head->data;
        list->size--;
        free(list->head->data);
        free(list->head);
        list->head=NULL;
        list->tail=NULL;
        return TRUE;
    }
    NodeType* temp=list->head;
    while(temp!=NULL){
        if(strcmp(temp->data->id, id)==0){
            if(temp==list->head){
                list->head=list->head->next;
                list->head->prev=NULL;
                list->size--;
                free(temp->data);
                free(temp);
                return TRUE;
            }
            else if(temp==list->tail){
                list->tail=list->tail->prev;
                list->tail->next=NULL;
                list->size--;
                free(temp->data);
                free(temp);
                return TRUE;
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                list->size--;
                free(temp->data);
                free(temp);
                return TRUE;
            }
        }
        temp=temp->next;
    } 
}

TaskType* getFirst(ListType *list){
    if(list->size==0){
        return NULL;
    }
    else{
        return list->head->data;
    }
}

TaskType* getLast(ListType *list){
    if(list->size==0){
        return NULL;
    }
    else{
        return list->tail->data;
    }
}

int size(ListType *list) {
    return list->size;
}
