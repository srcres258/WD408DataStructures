#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdbool.h>
#include "predef.h"

// 1. 单链表的定义

/** 单链表结点 */
typedef struct LNode {  // 定义单链表结点类型
  ElemType data;        // 数据域
  struct LNode* next;   // 指针域
} LNode, *LinkList;

// 2. 单链表上基本操作的实现

/** 单链表的初始化 */
bool InitList(LinkList *L);

/** 求表长操作 */
int Length(LinkList *L);

/** 按序号查找结点 */
LNode *GetElem(LinkList *L, int i);

/** 按值查找结点 */
LNode *LocateElem(LinkList *L, ElemType e);

/** 插入结点操作 */
bool ListInsert(LinkList *L, int i, ElemType e);

/** 删除结点操作 */
bool ListDelete(LinkList *L, int i, ElemType *e);

/** 采用头插法建立单链表 */
LinkList List_HeadInsert(LinkList *L);

/** 采用尾插法建立单链表 */
LinkList List_TailInsert(LinkList *L);

#endif // !LINK_LIST_H
