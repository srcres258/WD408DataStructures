#include <stdlib.h>
#include "LinkList.h"

#ifdef WITH_HEAD_NODE
/*
带头结点与不带头结点的单链表在初始化时有所不同. 带头结点的单链表初始化时,
需创建一个头结点, 并令头指针L指向该头结点, 其next指针初始化为NULL.
*/
bool InitList(LinkList *L) {
  *L = (LNode*)malloc(sizeof(LNode)); // 创建头结点
  (*L)->next = NULL;                  // 头结点之后暂无数据结点
  return true;
}
#else
/*
不带头结点的单链表初始化时, 只需将头指针L初始化为NULL.
*/
bool InitList(LinkList *L) {
  *L = NULL; // 初始化头指针为NULL
  return true;
}
#endif

int Length(LinkList *L) {
  int len = 0;            // 计数变量, 初始为0
  LNode *p = *L;
  while (p->next!=NULL) {
    p = p->next;          // 每访问1个结点, 计数加1
    len++;
  }
  return len;
}

LNode *GetElem(LinkList *L, int i) {
  LNode *p = *L;            // 指针p指向当前扫描结点
  int j = 0;                // j记录当前位序, 头结点为第0个结点
  while (p!=NULL && j<i) {  // 循环找到第i个结点
    p = p->next;
    j++;
  }
  return p;                 // 返回第i个结点的指针或NULL
}

LNode *LocateElem(LinkList *L, ElemType e) {
  LNode *p = (*L)->next;
  while (p!=NULL && p->data!=e) // 从第一个结点开始查找数据域为e的结点
    p = p->next;
  return p;                     // 找到后返回该结点指针, 否则返回NULL
}

bool ListInsert(LinkList *L, int i, ElemType e) {
  LNode *p = *L;              // p指向当前扫描结点
  int j = 0;                  // j记录当前位序, 头结点为第0个结点
  while (p!=NULL && j<i-1) {  // 循环找到第i-1个结点
    p = p->next;
    j++;
  }
  if (p==NULL)                // i值不合法
    return false;
  LNode *s = (LNode*)malloc(sizeof(LNode));
  s->data = e;
  s->next = p->next;
  p->next = s;
  return true;
}

bool ListDelete(LinkList *L, int i, ElemType *e) {
  LNode *p = *L;                    // p指向当前扫描结点
  int j = 0;                        // j记录当前位序, 头结点为第0个结点
  while (p->next!=NULL && j<i-1) {  // 循环找到第i-1个结点
    p = p->next;
    j++;
  }
  if (p->next==NULL || j>i-1)       // i值不合法
    return false;
  LNode *q = p->next;               // 令q指向被删除的结点
  *e = q->data;                     // 用e返回元素的值
  p->next = q->next;                // 将*q结点从链表中断开
  free(q);                          // 释放结点的存储空间
  return true;
}

LinkList List_HeadInsert(LinkList *L) { // 逆向建立单链表
  LNode *s; int x;                      // 设元素类型为整型
  *L = (LNode*)malloc(sizeof(LNode));   // 创建头结点
  (*L)->next = NULL;                    // 初始为空链表
  scanf("%d", &x);                      // 输入结点的值
  while (x!=9999) {                     // 输入9999表示结束
    s = (LNode*)malloc(sizeof(LNode));  // 创建新结点
    s->data = x;                        // 将输入的值赋给新结点的数据域
    s->next = (*L)->next;               // 将新结点插入到头结点之后
    (*L)->next = s;                     // 将新结点插入表中, L为头指针
    scanf("%d", &x);                    // 继续输入下一个结点的值
  }
  return *L;
}

LinkList List_TailInsert(LinkList *L) { // 正向建立单链表
  int x;                                // 设元素类型为整型
  *L = (LNode*)malloc(sizeof(LNode));   // 创建头结点
  LNode *s, *r = *L;                    // r为表尾指针
  scanf("%d", &x);                      // 输入结点的值
  while (x!=9999) {                     // 输入9999表示结束
    s = (LNode*)malloc(sizeof(LNode));  // 创建新结点
    s->data = x;                        // 将输入的值赋给新结点的数据域
    r->next = s;                        // 将新结点插入到表尾
    r = s;                              // r指向新的表尾结点
    scanf("%d", &x);                    // 继续输入下一个结点的值
  }
  r->next = NULL;                       // 尾结点指针置空
  return *L;
}
