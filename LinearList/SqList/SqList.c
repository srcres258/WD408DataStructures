#include "SqList.h"

void InitList(SqList *L) {
  /*
  静态分配: 在声明顺序表时, 数组空间已由编译器分配,
  因此初始化只需将当前长度设置为0.
  */
  L->length = 0;
}

bool ListInsert(SqList *L, int i, ElemType e) {
  if (i<1||i>L->length+1)         // 判断i的范围是否有效
    return false;
  if (L->length>=MAX_SIZE)        // 当前存储空间已满
    return false;
  for (int j=L->length;j>=i;j--)  // 将第i个元素及之后的元素后移
    L->data[j] = L->data[j-1];
  L->data[i-1] = e;               // 在位置i插入e (注意下标转换)
  L->length++;                    // 表长加1
  return true;
}

bool ListDelete(SqList *L, int i, ElemType *e) {
  if (i<1||i>L->length)           // 判断i的范围是否有效
    return false;
  *e = L->data[i-1];              // 将被删除的元素保存到e中 (注意下标转换)
  for (int j=i;j<L->length;j++)   // 将第i个元素之后的元素前移
    L->data[j-1] = L->data[j];
  L->length--;                    // 表长减1
  return true;
}

int LocateElem(SqList *L, ElemType e) {
  int i;
  for (i=0;i<L->length;i++)
    if (L->data[i]==e)
      return i+1;           // 下标为i的元素值等于e, 返回其位序i+1
  return 0;                 // 查找失败
}
