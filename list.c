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

// BEFORE FINISHING REMOVE FUNCTION, MUST IMPLEMENT HASH ID FUNCTION SO THAT WE CAN SEARCH BY IT

// int remove(ListType *list, char* id){
//     if(list->size==0){
//         return FALSE;
//     }
//     else if(list->size==1){
//         list->head=NULL;
//         list->tail=NULL;
//         list->size--;
//         void* temp=list->head->data;
//         free(list->head->data);
//         free(list->head);
//     }
    
// }
