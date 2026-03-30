#ifndef D_LINK_LIST_H
#define D_LINK_LIST_H

#include "predef.h"

/** 双链表结点 */
typedef struct DNode {        // 定义双链表结点类型
  ElemType data;              // 数据域
  struct DNode *prior, *next; //前驱和后继指针域
} DNode, *DLinkList;

#endif // !D_LINK_LIST_H
