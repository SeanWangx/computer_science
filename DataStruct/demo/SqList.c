//
//  main.c
//  SqList
//
//  Created by wangxb on 2018/5/21.
//  Copyright © 2018年 wangxb. All rights reserved.
//
#include <stdio.h>

#define ElemType int
#define MaxSize 50
#define Status int
#define TRUE 1
#define FALSE 0

typedef struct {
    ElemType data[MaxSize];
    int length;
    int maxSize;
} SqList;

/**
 顺序表初始化
@param L 表指针
*/
void InitList(SqList *L) {
    L->length = 0;
    L->maxSize = MaxSize;
    for (int i = 0; i < L->maxSize; i++) {
        L->data[i] = 0;
    }
}

/**
 插入操作
@param L 表指针
@param i 待插入位置，从1开始
@param e 待插入元素
*/
Status ListInsert (SqList *L, int i, ElemType e) {
    if (L->length >= L->maxSize) {
        return FALSE;
    }
    if (i <= 0 || i > L->length + 1) {
        return FALSE;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length = L->length + 1;
    return TRUE;
}

/**
 删除操作
@param L 表指针
@param i 待删除位置，从1开始
@param e 保存删除的元素
*/
Status ListDelete(SqList *L, int i, ElemType *e) {
    if (L->length == 0) {
        return FALSE;
    }
    if (i <= 0 || i > L->length) {
        return FALSE;
    }
    *e = L->data[i - 1];
    for (int j = i - 1; j < L->length; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length = L->length - 1;
    return TRUE;
}

/**
 打印顺序表
@param L 顺序表
*/
void PrintList(SqList L) {
    printf("********** Print Start **********\n");
    printf("L->maxSize: %d\n", L.maxSize);
    printf("L->length: %d\n", L.length);
    printf("L->data: [");
    for (int i = 0; i < L.length; i++) {
        if (i == L.length - 1) {
            printf("%d", L.data[i]);
        } else {
            printf("%d, ", L.data[i]);
        }
    }
    printf("]\n");
    printf("********** Print End   **********\n");
}

/**
 定位元素位置
@param L 顺序表
@param e 定位的值
@return 目标值在表中位置，从1开始，若不存在则返回0
*/
Status LocateElem(SqList L, ElemType e, int *location) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            *location = i + 1;
            return TRUE;
        }
    }
    return FALSE;
}

/**
 按位查找
@param L 顺序表
@param i 位置，从1开始
@return 表中对应位置元素，否则为0
*/
Status GetElem(SqList L, int location, ElemType *e) {
    if (location <= 0 || location > L.length) {
        *e = 0;
        return FALSE;
    } else {
        *e = L.data[location - 1];
        return TRUE;
    }
}

int main(int argc, const char * argv[]) {
    SqList L;
    InitList(&L);

    if (ListInsert(&L, 1, 1) && ListInsert(&L, 1, 2)) {
        PrintList(L);
    }

    ElemType res_delete = 0;
    if (ListDelete(&L, 2, &res_delete)) {
        printf("delete elem: %d, location: %d\n", res_delete, 2);
        PrintList(L);
    }

    if (ListInsert(&L, 1, 91) && ListInsert(&L, 2, 66)) {
        PrintList(L);
    }

    int location = 0;
    if (LocateElem(L, 66, &location)) {
        printf("66 location: %d\n", location);
    }

    ElemType res_get = 0;
    if (GetElem(L, 2, &res_get)) {
        printf("location 2: %d\n", res_get);
    }
    return 0;
}
