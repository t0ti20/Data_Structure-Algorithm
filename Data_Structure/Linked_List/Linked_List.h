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
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Linked_List_Config.h"
#include "Standard_Types.h"
#include "Macros.h"
#include <stdlib.h>
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- List Error -------------*/
typedef enum Linked_List_Status_t 
{
     Linked_List_Status_Empty           =(0U),    /*Linked List Is Empty*/
     Linked_List_Status_Ok              =(1U),    /*Linked List No Errors*/
     Linked_List_Status_Size            =(2U),    /*Linked List Invalid Size*/
     Linked_List_Status_Allocation      =(3U),    /*Linked List Cannot Allocate Memory*/
     Linked_List_Status_Null            =(4U),    /*Linked List Passing Null Ptr*/
     Linked_List_Status_Available       =(5U)     /*Linked List Available To ADD*/
}Linked_List_Status_t;
/*------------- Type Defs --------------*/
typedef struct Linked_List_Node_t {struct Linked_List_Node_t *Linked_List_Node_Next_Ptr;Storage_Type Data;}Linked_List_Node_t;
typedef struct Linked_List_t {Linked_List_Node_t *Linked_List_Hear_Ptr;s16 Linked_List_Size;}Linked_List_t;
/*****************************************
---  Application Programming Interface  --
*****************************************/
/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Initialization(Linked_List_t *Linked_List)
* Description     : Initializes a linked list by setting its head pointer to NULL and size to -1.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
* Parameters (out): None
* Return value    : Linked_List_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Ok` if the operation is successful.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Initialization(Linked_List_t *Linked_List);

/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Status(Linked_List_t *Linked_List)
* Description     : Returns the status of the linked list (empty or available).
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
* Parameters (out): None
* Return value    : Linked_List_Status_t - Status indicating whether the linked list is empty or available.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Empty` if the linked list is empty.
*                   - Returns `Linked_List_Status_Available` if the linked list has nodes.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Status(Linked_List_t *Linked_List);

/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Clear(Linked_List_t *Linked_List)
* Description     : Clears all nodes from the linked list, freeing memory associated with each node.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
* Parameters (out): None
* Return value    : Linked_List_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Ok` if the operation is successful.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Clear(Linked_List_t *Linked_List);

/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Insert(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type Data)
* Description     : Inserts a new node with the specified data at the specified position in the linked list.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
*                 : Node_Number - Position at which the new node should be inserted (0-based index).
*                 : Data - The data to be stored in the new node.
* Parameters (out): None
* Return value    : Linked_List_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Size` if the specified node number exceeds the size of the linked list.
*                   - Returns `Linked_List_Status_Allocation` if memory allocation for the new node fails.
*                   - Returns `Linked_List_Status_Ok` if the operation is successful.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Insert(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type Data);

/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Append(Linked_List_t *Linked_List,Storage_Type Data)
* Description     : Appends a new node with the specified data to the end of the linked list.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
*                 : Data - The data to be stored in the new node.
* Parameters (out): None
* Return value    : Linked_List_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Allocation` if memory allocation for the new node fails.
*                   - Returns `Linked_List_Status_Ok` if the operation is successful.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Append(Linked_List_t *Linked_List,Storage_Type Data);

/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Get_Node(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type *Data)
* Description     : Retrieves the data from a node at the specified position in the linked list.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
*                 : Node_Number - Position of the node to retrieve data from (0-based index).
* Parameters (out): Data - Pointer to the variable where the retrieved data will be stored.
* Return value    : Linked_List_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Size` if the specified node number exceeds the size of the linked list.
*                   - Returns `Linked_List_Status_Ok` if the operation is successful.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Get_Node(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type *Data);

/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Delete_Node(Linked_List_t *Linked_List,u8 Node_Number)
* Description     : Deletes a node at the specified position in the linked list.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
*                   : Node_Number - Position of the node to be deleted (0-based index).
* Parameters (out): None
* Return value    : Linked_List_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Size` if the specified node number exceeds the size of the linked list.
*                   - Returns `Linked_List_Status_Ok` if the operation is successful.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Delete_Node(Linked_List_t *Linked_List,u8 Node_Number);

/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Traverse(Linked_List_t *Linked_List,void (*function)(Storage_Type*))
* Description     : Traverses the linked list and applies a user-defined function to each node's data.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
*                   : function - Pointer to the user-defined function to be applied to each node's data.
* Parameters (out): None
* Return value    : Linked_List_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Empty` if the linked list is empty.
*                   - Returns `Linked_List_Status_Ok` if the operation is successful.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Traverse(Linked_List_t *Linked_List,void (*function)(Storage_Type*));

/*****************************************************************************************
* Function Name   : Linked_List_Status_t Linked_List_Get_Node_From_End(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type *Data)
* Description     : Retrieves the data from a node at a specified position counting from the end of the linked list.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Linked_List - Pointer to the linked list structure.
*                   : Node_Number - Position of the node counting from the end (1 for the last node).
* Parameters (out): Data - Pointer to the variable where the retrieved data will be stored.
* Return value    : Linked_List_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Linked_List_Status_Null` if the input pointer to the linked list is NULL.
*                   - Returns `Linked_List_Status_Size` if the specified node number exceeds the size of the linked list.
*                   - Returns `Linked_List_Status_Empty` if the linked list is empty.
*                   - Returns `Linked_List_Status_Ok` if the operation is successful.
*****************************************************************************************/
Linked_List_Status_t Linked_List_Get_Node_From_End(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type *Data);

/********************************************************************
 *  END OF FILE: Linked_List.h
********************************************************************/
#endif