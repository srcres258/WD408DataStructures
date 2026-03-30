#ifndef SQ_LIST_H
#define SQ_LIST_H

#include <stdbool.h>
#include "predef.h"

#define MAX_SIZE 50         // 定义线性表的最大长度

// 1. 顺序表的定义

/** 静态分配的顺序表 */
typedef struct {
  ElemType data[MAX_SIZE];  // 顺序表的元素
  int length;               // 顺序表的当前长度
} SqList;                   // 顺序表类型定义

// 2. 顺序表上基本操作的实现

/** 顺序表的初始化 */
void InitList(SqList *L);

/** 插入操作 */
bool ListInsert(SqList *L, int i, ElemType e);

/** 删除操作 */
bool ListDelete(SqList *L, int i, ElemType *e);

/** 按值查找 (顺序查找) */
int LocateElem(SqList *L, ElemType e);

#endif // !SQ_LIST_H
