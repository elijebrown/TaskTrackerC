#include "defs.h"


int main(){
    ListType *list;
    list = (ListType *) malloc(sizeof(ListType));
    initList(list);
    TaskType *task;
    task = (TaskType *) malloc(sizeof(TaskType));
    initTask(task, "test", 0, time(NULL));
    add(list, task);
    TaskType *task2;
    task2 = (TaskType *) malloc(sizeof(TaskType));
    initTask(task2, "test2", 0, time(NULL));
    add(list, task2);
    printTaskList(list);
    printf("p1 \n");
    listRemove(list, find(list, "test"));
    printTaskList(list);
    printf("p2 \n");
    char *name = find(list, "test2");
    printf("%d\n", list->size);
    listRemove(list, name);
    printTaskList(list);
    printf("p3 \n");
    printf("%d\n", list->size);
    TaskType *task3;
    task3 = (TaskType *) malloc(sizeof(TaskType));
    initTask(task3, "test3", 0, time(NULL));
    add(list, task3);
    printTask(getLast(list));
    printTask(getFirst(list));
    
    return 0;
}