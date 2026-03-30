#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include "predef.h"

#define InitSize 100    // 表长度的初始定义

// 1. 顺序表的定义

/** 动态分配的顺序表 */
typedef struct {
  ElemType *data;       // 指配动态分配数组的指针
  int MaxSize, length;  // 数组的最大容量和当前个数
} SeqList;              // 动态分配数组顺序表的类型定义

// 2. 顺序表上基本操作的实现

/** 顺序表的初始化 */
void InitList(SeqList *L);

/** 插入操作 */
bool ListInsert(SeqList *L, int i, ElemType e);

/** 删除操作 */
bool ListDelete(SeqList *L, int i, ElemType *e);

/** 按值查找 (顺序查找) */
int LocateElem(SeqList *L, ElemType e);

#endif // !SEQ_LIST_H
