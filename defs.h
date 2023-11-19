#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_STR 20
#define MAX_ID 7

typedef struct Node NodeType;
typedef struct List ListType;
typedef struct Task TaskType;

struct Node {
    TaskType *data;
    NodeType *next;
    NodeType *prev;
};

struct List {
    NodeType *head;
    NodeType *tail;
    int size;
};

struct Task{
    char id[MAX_ID+1];
    char name[MAX_STR];
    int  total;
    time_t start;
};

void add(ListType *list, TaskType* data);
void addFirst(ListType *list, TaskType* data);
void addLast(ListType *list, TaskType* data);


int listRemove(ListType *, char*);
// int removeFirst(ListType *list);
// int removeLast(ListType *list);

char* find(ListType *list, char *name);
TaskType* getFirst(ListType *list);
TaskType* getLast(ListType *list);

int size(ListType *list);

void initList(ListType *list);
int initNode(NodeType **node, TaskType* data);

void initTask(TaskType *task, char *name, int total, time_t start);
void genId(int length, char *randomString);
void cleanData(TaskType *task);
void printTask(TaskType *task);
void printTaskList(ListType *list);