#ifndef S_LINK_LIST_H
#define S_LINK_LIST_H

#include "predef.h"

#define MAX_SIZE 50     // 静态链表的最大长度

/** 静态链表 */
typedef struct {        // 静态链表的结构类型定义
  ElemType data;        // 存储数据元素
  int next;             // 下一个元素的数组下标
} SLinkList[MAX_SIZE];

#endif // !S_LINK_LIST_H
