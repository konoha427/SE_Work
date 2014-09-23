/**************************************************************************************************/
/* Copyright (C) mc2lab.com, SSE@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Shi Weihao JG14225071                                                */
/*  SUBSYSTEM NAME        :  test                                                                 */
/*  MODULE NAME           :  test                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/20                                                           */
/*  DESCRIPTION           :  This is a test program                                               */
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

#define DESC_LEN      1024
#define CMD_NUM       10
#define CMD_MAX_LEN   1024
#define MENU_MAX_LEN  100 

/*initialize data struct*/
tDataNode data[MENU_MAX_LEN] =
{
    { NULL, "help", "this is help command!", Help },
    { NULL, "AddCmd", "Add CMD to CMDList!", AddCmd},
    { NULL, "DelCmd", "Delete CMD from CMDList", DelCmd},
    { NULL, "version", "menu program v1.1", NULL },
    { NULL, "list", "this is list command", NULL }
};

/*the menu cmd start*/
int main()
{
    CreateMenu(data);
    RunMenu();
    return 0;
}

