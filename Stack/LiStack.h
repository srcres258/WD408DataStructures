#ifndef LI_STACK_H
#define LI_STACK_H

#include "predef.h"

/** 栈的链式存储结构 */
typedef struct LinkNode {
  ElemType data;          // 数据域
  struct LinkNode *next;  // 指针域
} LiStack;                // 链栈类型定义

#endif // !LI_STACK_H
