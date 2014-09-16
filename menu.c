/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Shi Weihao JG14225071                                                */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/13                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
* Revision log:
*
* Created by Shi Weihao JG14225071, 2014/09/13
*
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_LEN    1024
#define CMD_NUM     10
#define CMD_MAX_LEN 1024

int Help();

/* data struct and its operations */

typedef struct DataNode
{
    char *cmd;
    char *desc;
    int  (*handler)();
    struct DataNode *next;
}tDataNode;

tDataNode * FindCmd(tDataNode * head,char * cmd)
{
    if (head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDataNode * p = head;
    while (p != NULL)
    {
        if (strcmp(p->cmd, cmd) == 0)
        {
            return p;
            break;
        }
        p = p->next;
    }
    return NULL;
}

int ShowAllCmd(tDataNode * head)
{
    printf("Menu List:\n");
    tDataNode * p = head;
    while (p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc);
        p = p->next;
    }
    return 0;
}

/* menu program */

static tDataNode head[] =
{
    { "help", "this is help command!", Help, &head[1] },
    { "version", "menu program v1.1", NULL, &head[2] },
    { "list", "this is list command", NULL, NULL }
};

int main()
{
    /* cmd line begins */
    while (1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a Command > ");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
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
    }
}

int Help()
{
    ShowAllCmd(head);
    return 0;
}



















