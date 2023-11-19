#include "defs.h"


void genId(int length, char *randomString) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789#?!";

    if (length) {
        if (randomString) {
            int l = (int) (sizeof(charset) -1);
            for (int n = 0;n < length;n++) {
                int key = rand() % l;          // per-iteration instantiation
                randomString[n] = charset[key];
            }

            randomString[length] = '\0'; //
        }
    }
}

void initTask(TaskType *task, char *name, int total, time_t start){
    if(!total){
        total = 0;
    }

    char id[MAX_ID];
    genId(MAX_ID, id);
    strcpy(task->id, id);
    strcpy(task->name, name);
    task->total = total;
    task->start = start;
}

void printTask(TaskType *task){
    printf("ID: %s\n", task->id);
    printf("Name: %s\n", task->name);
    printf("Total: %d\n", task->total);
    //printf("Start: %s\n", ctime(&task->start));
}

void printTaskList(ListType *list){
    NodeType *temp = list->head;
    while(temp!=NULL){
        printTask(temp->data);
        temp = temp->next;
    }
}