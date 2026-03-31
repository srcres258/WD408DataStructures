#include <stdlib.h>

#include "LinkQueue.h"

void InitQueue(LinkQueue *Q) {      // 初始化带头结点的链式队列
  Q->front = Q->rear = (LinkNode *)
    malloc(sizeof(LinkNode));       // 建立头结点
  Q->front->next = NULL;            // 初始为空
}

int QueueEmpty(LinkQueue *Q) {
  return Q->front == Q->rear;       // 队空条件: 头尾指针相同
}

void EnQueue(LinkQueue *Q, ElemType e) {
  LinkNode *s = (LinkNode *)
    malloc(sizeof(LinkNode));       // 生成新结点
  s->data = e;                      // 将元素值赋给新结点的数据域
  s->next = NULL;                   // 将新结点的指针域置空
  Q->rear->next = s;                // 将新结点连接到队尾
  Q->rear = s;                      // 将rear指向新的队尾
}

bool DeQueue(LinkQueue *Q, ElemType *e) {
  if (Q->front == Q->rear)          // 队空
    return false;
  LinkNode *p = Q->front->next;     // 将欲删除的结点暂存
  *e = p->data;                     // 将欲删除的结点的数据域赋值给e
  Q->front->next = p->next;         // 将欲删除的结点从链中断开
  if (Q->rear == p)                 // 若欲删除的结点是队尾
    Q->rear = Q->front;             // 将rear指向头结点
  free(p);                          // 释放欲删除的结点
  return true;
}
