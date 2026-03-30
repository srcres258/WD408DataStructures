#ifndef SQ_STACK_H
#define SQ_STACK_H

#include <stdbool.h>

#include "predef.h"

// 1. 顺序栈的实现

#define MaxSize 50        // 定义栈中最大元素个数
/** 顺序栈: 栈的顺序存储结构 */
typedef struct {
  ElemType data[MaxSize]; // 存放栈中元素
  int top;                // 栈顶指针
} SqStack;

// 2. 顺序栈的基本操作

/** 初始化 */
void InitStack(SqStack *S);

/** 判栈空 */
bool StackEmpty(SqStack *S);

/** 入栈 */
bool Push(SqStack *S, ElemType x);

/** 出栈 */
bool Pop(SqStack *S, ElemType *x);

/** 读栈顶元素 */
bool GetTop(SqStack *S, ElemType *x);

#endif // !SQ_STACK_H
