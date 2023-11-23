#include "defs.h"


int main(){
    ListType *list = (ListType *) malloc(sizeof(ListType));
    initList(list);
    int choice;
    while(TRUE){
        printMenu(&choice);
        switch(choice){
            case 1:
                TaskType *task;
                task = (TaskType *) malloc(sizeof(TaskType));
                getTaskInput(task);
                add(list, task);
                break;
            case 2:
                printf("Remove Task\n");
                break;
            case 3:
                printf("Start Task\n");
                break;
            case 4:
                printf("Stop Task\n");
                break;
            case 5:
                printTaskList(list);
                break;
            case 6:
                printf("Print Tracked Task List\n");
                break;
            case 7:
                printf("Print Untracked Task List\n");
                break;
            case 8:
                printf("Print a Task\n");
                break;
            case 0:
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    // ListType *list;
    // list = (ListType *) malloc(sizeof(ListType));
    // initList(list);
    // TaskType *task;
    // task = (TaskType *) malloc(sizeof(TaskType));
    // initTask(task, "test", 0, time(NULL));
    // add(list, task);
    // TaskType *task2;
    // task2 = (TaskType *) malloc(sizeof(TaskType));
    // initTask(task2, "test2", 0, time(NULL));
    // add(list, task2);
    // printTaskList(list);
    // listRemove(list, find(list, "test"));
    // printTaskList(list);
    // char *name = find(list, "test2");
    // listRemove(list, name);
    // printTaskList(list);
    // TaskType *task3;
    // task3 = (TaskType *) malloc(sizeof(TaskType));
    // initTask(task3, "test3", 0, time(NULL));
    // add(list, task3);
    // printTask(getLast(list));
    // printTask(getFirst(list));
    // cleanList(list);
    return 0;
}

void printMenu(int *c){
    printf("(1) Add Task\n");
    printf("(2) Remove Task\n");
    printf("(3) Start Task\n");
    printf("(4) Stop Task\n");
    printf("(5) Print Task List\n");
    printf("(6) Print Tracked Task List\n");
    printf("(7) Print Untracked Task List\n");
    printf("(8) Print a Task\n");
    printf("(0) Exit\n");
    printf("Enter your choice: ");
    scanf("%d", c);
}