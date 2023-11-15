/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Linked_List.h
 *  Module:  Data Structure/Linked List
 *  Description:  Linked List Implementation
*******************************************************************/
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
/*---------- Include Files -------------*/
#include "./Linked_List_Config.h"
#include "./Standard_Types.h"
#include "./Macros.h"
#include <stdlib.h>
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum Linked_List_Error 
{
     Linked_List_Empty               =0,
     Linked_List_Ok                  =1,
     Linked_List_Wrong_Size          =2,
     Linked_List_Wrong_Memory        =3,
}Linked_List_Error;
typedef struct Linked_List_node_t {struct Linked_List_node_t *next_ptr;storage_type data;}Linked_List_node_t;
typedef struct Linked_List_t {Linked_List_node_t *head;s16 size;}Linked_List_t;
/*----------- Functins To Use ---------*/
Linked_List_Error Linked_List_Initialization(Linked_List_t *my_list);
Linked_List_Error Linked_List_Clear(Linked_List_t *my_list);
Linked_List_Error Linked_List_Append(Linked_List_t *my_list,storage_type data);
Linked_List_Error Linked_List_Delete_Node(Linked_List_t *my_list,u8 node_number);
Linked_List_Error Linked_List_Insert(Linked_List_t *my_list,u8 node_number,storage_type data);
Linked_List_Error Linked_List_Traverse(Linked_List_t *my_list,void (*function)(storage_type*));
Linked_List_Error Linked_List_Get_Node(Linked_List_t *my_list,u8 node_number,storage_type *data);
Linked_List_Error Linked_List_Get_Node_From_End(Linked_List_t *my_list,u8 node_number,storage_type *data);
s8 Linked_List_Is_Empty(Linked_List_t *my_list);
#endif
/********************************************************************
 *  END OF FILE: Linked_List.h
********************************************************************/