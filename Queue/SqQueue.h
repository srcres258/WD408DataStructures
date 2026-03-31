#ifndef SQ_QUEUE_H
#define SQ_QUEUE_H

#include <stdbool.h>

#include "predef.h"

// 1. 队列的顺序存储

#define MaxSize 50        // 定义队列中元素的最大个数
/** 队列的顺序存储结构 */
typedef struct {
  ElemType data[MaxSize]; // 用数组存放队列元素
  int front, rear;        // 队首指针和队尾指针
} SqQueue;

// 2. 循环队列的操作 (基于牺牲一个单元法)

/** 初始化 */
void InitQueue(SqQueue *Q);

/** 判队空 */
bool QueueEmpty(SqQueue *Q);

/** 入队 */
bool EnQueue(SqQueue *Q, ElemType x);

/** 出队 */
bool DeQueue(SqQueue *Q, ElemType *x);

#endif // !SQ_QUEUE_H
