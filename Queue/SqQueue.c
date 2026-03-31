#include "SqQueue.h"

void InitQueue(SqQueue *Q) {
  Q->rear = Q->front = 0;               // 初始化队首指针和队尾指针
}

bool QueueEmpty(SqQueue *Q) {
  return Q->rear == Q->front;           // 队空条件: 队首指针和队尾指针相等
}

bool EnQueue(SqQueue *Q, ElemType x) {
  if ((Q->rear+1)%MaxSize==Q->front)    // 队满则报错
    return false;
  Q->data[Q->rear] = x;
  Q->rear = (Q->rear+1)%MaxSize;        // 队尾指针向后移一位, 若到最后则转到数组头部
  return true;
}

bool DeQueue(SqQueue *Q, ElemType *x) {
  if (Q->rear == Q->front)              // 队空则报错
    return false;
  *x = Q->data[Q->front];
  Q->front = (Q->front+1)%MaxSize;      // 队首指针向后移一位, 若到最后则转到数组头部
  return true;
}
