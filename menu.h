/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  linktable.c                                                          */
/*  PRINCIPAL AUTHOR      :  Shi Weihao JG14225071                                                */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
* Revision log:
*
* Created by Shi Weihao JG14225071, 2014/09/20
*
*/

#include "linktable.h"

#define DESC_LEN    1024
#define CMD_NUM     10
#define CMD_MAX_LEN 1024

/*define the data struct DataNode*/
typedef struct DataNode
{
    tLinkTableNode * pNext;
    char cmd[CMD_MAX_LEN];
    char desc[DESC_LEN];
    int(*handler)();
}tDataNode;

/*define the globle variable*/
extern tLinkTable * pLinkHead;
extern int count;
extern tDataNode data[];

/*declare the function and the parameter used*/
tDataNode * FindCmd(tLinkTable * head, char * cmd);
int ShowAllCmd(tLinkTable * head);
int CreateMenu(tDataNode * data);
int RunMenu();
int AddCmd();
int DelCmd();
int Help();
