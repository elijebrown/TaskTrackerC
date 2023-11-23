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
    task->tracking = FALSE;
}
// cant use scanf for strings with spaces NEED TO FIX, USE BUFFER THING
void getTaskInput(TaskType *task){
    char name[MAX_STR];
    int total;
    printf("\nEnter task name: ");
    scanf("%s", name);
    printf("\nEnter pre-existing time spent on task, if any (input 0 if none): \n");
    scanf("%d", &total);
    initTask(task, name, total, time(NULL));
}

void printTask(TaskType *task){
    char id[MAX_ID+1];
    switch(task->tracking){
        case TRUE:
            strcpy(id, "[TRUE]");
            char* time = ctime(&task->start);
        case FALSE:
            strcpy(id, "[FALSE]");
    }
    // conver to time format 

    printf("ID: %7.7s | Name: %20.20s | Total: %d | Tracking Since: %s", task->id, task->name, task->total, ctime(&task->start));
}

void printTaskList(ListType *list){
    NodeType *temp = list->head;
    while(temp!=NULL){
        printTask(temp->data);
        temp = temp->next;
    }
}

void cleanData(TaskType *task){
    free(task);
}