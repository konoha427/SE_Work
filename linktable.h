/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  linktable.c                                                          */
/*  PRINCIPAL AUTHOR      :  Shi Weihao JG14225071                                                */
/*  SUBSYSTEM NAME        :  linktable                                                            */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  This is a linktable program                                          */
/**************************************************************************************************/

/*
* Revision log:
*
* Created by Shi Weihao JG14225071, 2014/09/20
*
*/

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#include <pthread.h>

#define SUCCESS 0
#define FAILURE (-1)

/*
* LinkTable Node Type
*/
typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;

/*
* LinkTable Type
*/
typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int            SumOfNode;
    pthread_mutex_t mutex;
}tLinkTable;

/*
* Create a LinkTable
*/
tLinkTable * CreateLinkTable();
/*
* Delete a LinkTable
*/
int DeleteLinkTable(tLinkTable *pLinkTable);
/*
* Add a LinkTableNode to LinkTable
*/
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode * pNode);
/*
* Delete a LinkTableNode from LinkTable
*/
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode * pNode);
/*
* Search a LinkTableNode from LinkTable
* int Conditon(tLinkTableNode * pNode);
*/
tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable, int Conditon(tLinkTableNode * pNode));
/*
* get LinkTableHead
*/
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);
/*
* get next LinkTableNode
*/
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode * pNode);

#endif /* _LINK_TABLE_H_ */
