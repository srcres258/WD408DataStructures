#include "SqStack.h"

void InitStack(SqStack *S) {
  S->top = -1; // 初始化栈顶指针
}

bool StackEmpty(SqStack *S) {
  if (S->top == -1) {
    // 栈空
    return true;
  } else {
    // 不空
    return false;
  }
}

bool Push(SqStack *S, ElemType x) {
  if (S->top == MaxSize - 1) {
    // 栈满, 报错
    return false;
  }
  S->data[++S->top] = x; // 指针先加1, 再入栈
  return true;
}

bool Pop(SqStack *S, ElemType *x) {
  if (S->top == -1) {
    // 栈空, 报错
    return false;
  }
  *x = S->data[S->top--]; // 先出栈, 指针再减1
  return true;
}

bool GetTop(SqStack *S, ElemType *x) {
  if (S->top == -1) {
    // 栈空, 报错
    return false;
  }
  *x = S->data[S->top]; // x记录为栈顶元素
  return true;
}
