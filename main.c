#include "defs.h"


int main(){
    TaskType *task;
    task = (TaskType *) malloc(sizeof(TaskType));
    initTask(task, "test", 0, time(NULL));
    printTask(task);
    TaskType *task2;
    task2 = (TaskType *) malloc(sizeof(TaskType));
    initTask(task2, "test2", 0, time(NULL));
    printTask(task2);
    return 0;
}