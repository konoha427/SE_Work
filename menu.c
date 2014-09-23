/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

#define DESC_LEN    1024
#define CMD_NUM     10
#define CMD_MAX_LEN 1024

/*initialize globle variable*/
tLinkTable * pLinkHead = NULL;
int count = 5;

/*find the command given*/
tDataNode * FindCmd(tLinkTable * lhead, char * cmd)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(lhead);
    while (pNode != NULL)
    {
        if (!strcmp(pNode->cmd, cmd))
        {
            return pNode;
        }
        pNode = (tDataNode*)GetNextLinkTableNode(lhead, (tLinkTableNode*)pNode);
    }
    return NULL;
}

/*show all the command*/
int ShowAllCmd(tLinkTable * lhead)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(lhead);
    while (pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(lhead, (tLinkTableNode*)pNode);
    }
    return 0;
}

int Help()
{
    ShowAllCmd(pLinkHead);
    return 0;
}

/*create the menu list*/
int CreateMenu(tDataNode data[])
{
    pLinkHead = CreateLinkTable();
    int i = 0;
    while (i < count)
    {
        AddLinkTableNode(pLinkHead, (tLinkTableNode*)&data[i]);
        i++;
    }
    return 0;
}

/*add the command given to the menu list*/
int AddCmd()
{
    count = count + 1;
    char AddCmd[CMD_MAX_LEN];
    char AddDesc[DESC_LEN];
    //while (getchar() != '\n');
    printf("Add your CMD here > ");
    scanf("%s",AddCmd);
    printf("Add the Description here > ");
    scanf("%s",AddDesc);
    tDataNode * p = FindCmd(pLinkHead, AddCmd);
    if (p == NULL)
    {
        strcpy(data[count - 1].cmd, AddCmd);
        strcpy(data[count - 1].desc, AddDesc);
        AddLinkTableNode(pLinkHead, (tLinkTableNode*)&data[count - 1]);
        printf("CMD add success!\n");
    }
    else
    {
        printf("The CMD has already exists!\n");
    }
    return 0;
}

/*delete the command given from the list*/
int DelCmd()
{
    char DelCmd[CMD_MAX_LEN];
    printf("Input the CMD you want to delete here > ");
    scanf("%s", DelCmd);
    tDataNode * pFind = FindCmd(pLinkHead, DelCmd);
    if (pFind == NULL)
    {
        printf("There is no CMD in list!\n");
    }
    else if (!strcmp(pFind->cmd, "AddCmd"))
    {
        printf("This CMD is System CMD,You can NOT DELETE it!\n");
    }
    else if (!strcmp(pFind->cmd, "DelCmd"))
    {
        printf("This CMD is System CMD,You can NOT DELETE it!\n");
    }
    else if (!strcmp(pFind->cmd, "help"))
    {
        printf("This CMD is System CMD,You can NOT DELETE it!\n");
    }
    else
    {
        DelLinkTableNode(pLinkHead, (tLinkTableNode*)pFind);
        printf("The CMD has been DELETED!\n");
    }
    return 0;
}

/*run the menu list*/
int RunMenu()
{
    while (1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a Command > ");
        scanf("%s", cmd);
        tDataNode * p = FindCmd(pLinkHead, cmd);
        if (p == NULL)
        {
            printf("This is a wrong Conmmand!\n");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if (p->handler == Help)
        {
            p->handler();
        }
        if (p->handler == AddCmd)
        {
            p->handler();
        }
        if (p->handler == DelCmd)
        {
            p->handler();
        }
    }
    return 0;
}
