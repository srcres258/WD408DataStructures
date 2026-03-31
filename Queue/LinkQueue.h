#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#include <stdbool.h>

#include "predef.h"

// 1. 队列的链式存储

/** 链式队列结点 */
typedef struct LinkNode { // 链式队列结点
  ElemType data;
  struct LinkNode *next;
} LinkNode;
/** 队列的链式存储结构 */
typedef struct {          // 链式队列
  LinkNode *front, *rear; // 队头和队尾指针
} LinkQueue;

// 2. 链式队列的基本操作

/** 初始化 */
void InitQueue(LinkQueue *Q);

/** 判队空 */
int QueueEmpty(LinkQueue *Q);

/** 入队 */
void EnQueue(LinkQueue *Q, ElemType e);

/** 出队 */
bool DeQueue(LinkQueue *Q, ElemType *e);

#endif // !LINK_QUEUE_H
