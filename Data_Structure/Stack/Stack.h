/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Stack.h
 *  Module:  Data_Structure/Stack
 *  Description:  Stack Implementation
*******************************************************************/
#ifndef _STACK_H_
#define _STACK_H_
/*---------- Include Files -------------*/
#include "Standard_Types.h"
#include "Macros.h"
/*****************************************
----------   Configuration    ------------
*****************************************/
#define Memory_Mode                     Linked_List         /*(Linked_List) (Array)*/
#define Storage_Type                    u8                  /*(u8) (u16) (u32) (s8) (...)*/
#define Maximum_Stack_Size              5U                  /*When Chosing (Array) Max Number Of Stack*/
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
#define Array                           (1)
#define Linked_List                     (2)
/*------------ Stack Error -------------*/
typedef enum Stack_Status_t
{
     Stack_Status_Ok                     =(0U),
     Stack_Status_Full                   =(1U),
     Stack_Status_Empty                  =(2U),
     Stack_Status_Allocation             =(3U),
     Stack_Status_Available              =(4U),
     Stack_Status_Null                   =(5U),
}Stack_Status_t;
/*------------- Stack Mode -------------*/
#if Memory_Mode == Array
typedef struct Stack_t
{
     Storage_Type Stack_Elements[Maximum_Stack_Size+1];
     u8 Stack_Top;
}Stack_t;
#else
#include <stdlib.h>
typedef struct Stack_Node_t
{
     struct Stack_Node_t *Stack_Node_Next;Storage_Type Data;
}Stack_Node_t;
typedef struct Stack_t
{
     Stack_Node_t *Stack_Node_Top;u8 Stack_Top;
}Stack_t;
#endif
/*****************************************
---  Application Programming Interface  --
*****************************************/
/*****************************************************************************************
* Function Name   : Stack_Initialization
* Description     : Initializes a stack based on the chosen memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure to be initialized.
* Parameters (out): None
* Return value    : Stack_Status_t - Status of the initialization process. 
*                   Returns `Stack_Status_Ok` if successful, or an error code for issues.
* Notes           : - Returns `Stack_Status_Null` if the input pointer is NULL.
*                   - Initializes stack properties based on the selected memory mode:
*                       - Linked List: Sets size to zero and top node to NULL.
*                       - Array: Sets top index to zero.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Essential for setting up a stack before push and pop operations.
*****************************************************************************************/
Stack_Status_t Stack_Initialization(Stack_t *Stack);

/*****************************************************************************************
* Function Name   : Stack_Status
* Description     : Checks if the stack is full based on the chosen memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure to be checked.
* Parameters (out): None
* Return value    : Stack_Status_t - Status indicating whether the stack is full, empty, or an error.
* Notes           : - Returns `Stack_Status_Null` if the input pointer is NULL.
*                   - Checks stack status based on the selected memory mode
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Stack_Status_t Stack_Status(Stack_t *Stack);

/*****************************************************************************************
* Function Name   : Stack_Push
* Description     : Pushes data onto the stack based on the chosen memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
*                   Data - Data to be pushed onto the stack.
* Parameters (out): None
* Return value    : Stack_Status_t - Status indicating the success of the push operation or an error.
* Notes           : - Returns `Stack_Status_Null` if the input pointer is NULL.
*                   - Pushes data onto the stack based on the selected memory mode:
*                       - Array: Checks if the stack is not full before pushing.
*                       - Linked List: Allocates memory for a new node and adds it to the top of the stack.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Returns `Stack_Status_Full` if the stack is full (Array mode).
*                   - Returns `Stack_Allocation_Error` if memory allocation fails (Linked List mode).
*****************************************************************************************/
Stack_Status_t Stack_Push(Stack_t *Stack,Storage_Type Data);

/*****************************************************************************************
* Function Name   : Stack_Pop
* Description     : Pops data from the stack based on the chosen memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
* Parameters (out): Data - Pointer to store the popped data.
* Return value    : Stack_Status_t - Status indicating the success of the pop operation or an error.
* Notes           : - Returns `Stack_Status_Null` if the input pointer is NULL.
*                   - Pops data from the stack based on the selected memory mode:
*                       - Array: Checks if the stack is not empty before popping.
*                       - Linked List: Removes the top node and retrieves its data.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Returns `Stack_Status_Empty` if the stack is empty (Array mode).
*****************************************************************************************/
Stack_Status_t Stack_Pop(Stack_t *Stack,Storage_Type *Data);

/*****************************************************************************************
* Function Name   : Stack_Top
* Description     : Retrieves the top element of the stack without removing it.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
* Parameters (out): Data - Pointer to store the top element.
* Return value    : Stack_Status_t - Status indicating the success of the operation or an error.
* Notes           : - Returns `Stack_Status_Null` if the input pointer is NULL.
*                   - Retrieves the top element from the stack based on the selected memory mode
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Returns `Stack_Status_Empty` if the stack is empty (Array mode).
*****************************************************************************************/
Stack_Status_t Stack_Top(Stack_t *Stack,Storage_Type *Data);

/*****************************************************************************************
* Function Name   : Stack_Size
* Description     : Retrieves the current size of the stack.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
* Parameters (out): Size - Pointer to store the current size of the stack.
* Return value    : Stack_Status_t - Status indicating the success of the operation or an error.
* Notes           : - Returns `Stack_Status_Null` if the input pointer is NULL.
*                   - Retrieves the current size of the stack based on the selected memory mode
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Stack_Status_t Stack_Size(Stack_t *Stack,Storage_Type *Size);

/*****************************************************************************************
* Function Name   : Stack_Traverse
* Description     : Applies a function to each element of the stack, without modifying it.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
*                   Function - Pointer to the function to be applied to each stack element.
* Parameters (out): None
* Return value    : Stack_Status_t - Status indicating the success of the operation or an error.
* Notes           : - Returns `Stack_Status_Null` if the input pointer is NULL.
*                   - Applies the provided function to each element of the stack based on the selected memory mode.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Returns `Stack_Status_Empty` if the stack is empty (Array mode).
*****************************************************************************************/
Stack_Status_t Stack_Traverse(Stack_t *Stack,void (*Function)(Storage_Type));

/*****************************************************************************************
* Function Name   : Stack_Clear
* Description     : Clears all elements from the stack.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
* Parameters (out): None
* Return value    : Stack_Status_t - Status indicating the success of the operation or an error.
* Notes           : - Returns `Stack_Status_Null` if the input pointer is NULL.
*                   - Clears all elements from the stack based on the selected memory mode.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Stack_Status_t Stack_Clear(Stack_t *Stack);

/********************************************************************
 *  END OF FILE: Stack.h
********************************************************************/
#endif
