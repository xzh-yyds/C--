#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
typedef struct Queue {
    int head;
    int rear;
    // defend stack overflow
    Node* node[2000];
} queue ;
void pop(queue* q);
void push(Node *node,queue* q);
Node* front(queue* q);
int size(queue* q);
void GetContent(Node * Tree);
void PrintTree(Node *Tree,int depth);
#endif