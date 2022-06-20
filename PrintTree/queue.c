#include "node.h"
#include "queue.h"
#include <stdio.h>
#define Print_ for(int i=0;i<depth;i++)printf("%s","---");
void pop(queue* q){
    q->head++;
};
void push(Node *node,queue* q){
    q->node[q->rear] = node;
    q->rear++;
};
Node* front(queue* q){
    return q->node[q->head];
}
int size(queue* q){
    return q->rear - q->head;
};
void PrintfTreeNode(Node * p,int depth){
    if (p == NULL)
    {
        Print_
        PRINTF_NULL_NODE
        printf("\n");
        return ;
    }
    switch(p->type){
        case TYPE_CONSTANT:
        {
            Print_
            PRINTF_CONTENT_NODE
            printf("\n");
        }
            break;
        case TYPE_INDENTIFER:
        {
            Print_
            PRINTF_INDEX_NODE
            printf("\n");
        }
            break;
        case TYPE_OP:
        {
            Print_
            OpNode op = p->op;
            PRINTF_OP_NODE
            printf("\n");
            break;
        }
        case TYPE_VAR:
        {
            Print_
            PRINTF_TYPENODE
            printf("\n");
            break;
        }
    }
}
// 44 ,
// 59 ;
// 60 = 
// 61 > 
// 62 ?
// 74 *
// 75 +
// 77 -
// 79 /
// 76 ,
// 123 {
/*
    CONSTANT = 258,
    INT = 259,
    VOID = 260,
    IDENTIFIER = 261,
    STRING_LITERAL = 262,
    LE_OP = 263,
    GE_OP = 264,
    EQ_OP = 265,
    NE_OP = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    FOR = 270,
    RETURN = 271,
    PARAM = 272,
    FUNC = 273,
    VAR = 274,
    CALL = 275,
    GLOBAL_VAR = 276
*/
void GetContent(Node * Tree)
{
    printf("\n树的横向输出是");
    queue ss;
    ss.head = 0;
    ss.rear = 0;
    push(Tree,&ss);
    int end = 0;
    while(size(&ss)!=0)
    {
        Node * p = front(&ss);
        if (ss.head == end)
        {
            end = ss.rear;
            printf("\n");
        }
        if(p == NULL)
        {
            PRINTF_NULL_NODE
            pop(&ss);
            continue;
        }
        // 代表栈的head rear分别是多少
        // printf("%d %d ",ss.head,ss.rear);
        switch (p->type)
        {
        case TYPE_CONSTANT:
            PRINTF_CONTENT_NODE
            break;
        case TYPE_INDENTIFER:
            PRINTF_INDEX_NODE
            break;
        case TYPE_VAR:
            PRINTF_TYPENODE
            break;
        case TYPE_OP:
            {
                OpNode op = p->op;
                PRINTF_OP_NODE
                for(int i=0;i<p->op.num;i++)
                {
                    // if(p->op.nodeArray[i]!=NULL)
                    push(p->op.nodeArray[i],&ss);
                }
            }
        default:
            break;
        }
        pop(&ss);
        // printf("%d %d %d ",ss.head,ss.rear,end);
        // printf(" %d ",ss.node[end]->type);
    }
}
void PrintTree(Node *Tree,int depth){
    PrintfTreeNode(Tree,depth);
    if(Tree == NULL)
    {
        // Print_
        // PRINTF_NULL_NODE
        // printf("\n");
        return ;
    }
    if(Tree->type == TYPE_OP)
    {
        for(int i=0;i<Tree->op.num;i++)
        {
            PrintTree(Tree->op.nodeArray[i],depth+1);
        }
    }
}