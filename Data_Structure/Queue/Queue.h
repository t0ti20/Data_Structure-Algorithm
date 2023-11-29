/*******************************************************************
 *  FILE DESCRIPTION
--------------------------------------------------------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Queue.h
 *  Module:  Data_Structure/Queue
 *  Description:  Queue Implementation
*******************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_
/*****************************************
----------   Include Files    ------------
*****************************************/
#include "Standard_Types.h"
#include "Macros.h"
/*****************************************
----------   Configuration    ------------
*****************************************/
#define Memory_Mode                     Linked_List    /*(Linked_List) (Array)*/
#define Storage_Type                    u8             /*(u8) (u16) (u32) (s8) (...)*/
#define Maximum_Queue_Size              5U             /*When Chosing (Array) Max Number Of Stack*/
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
#define Array                           (1)
#define Linked_List                     (2)
/*------------- Type Defs --------------*/
typedef enum Queue_Status_t 
{
     Queue_Status_Full                         =(0U),
     Queue_Status_Null                         =(1U),
     Queue_Status_Ok                           =(2U),
     Queue_Status_Empty                        =(3U),
     Queue_Status_Available                    =(4U),
     Queue_Status_Allocation                   =(5U)
}Queue_Status_t;
/*------------- Queue Mode -------------*/
#if Memory_Mode == Array
typedef struct Queue_t {s8 Queue_Front;Storage_Type Queue_Elements[Maximum_Queue_Size];s8 Queue_Rear;u8 Queue_Size;}Queue_t;
#else
#include <stdlib.h>
typedef struct Queue_Node_t {struct Queue_Node_t *Queue_Node_Next;Storage_Type Data;}Queue_Node_t;
typedef struct Queue_t {Queue_Node_t *Queue_Rear;Queue_Node_t *Queue_Front;u8 Queue_Size;}Queue_t;
#endif
/*****************************************
---  Application Programming Interface  --
*****************************************/
/*****************************************************************************************
* Function Name   : Queue_Initialization
* Description     : Initializes the queue structure based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure to be initialized.
* Parameters (out): None
* Return value    : Queue_Status_t - Status indicating whether the initialization is successful or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Initializes the queue based on the selected memory mode:
*                       - Array: Initializes the queue size, front, and rear pointers.
*                       - Linked List: Initializes the queue size, front, and rear pointers as NULL.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Initialization(Queue_t *Queue);

/*****************************************************************************************
* Function Name   : Queue_Status
* Description     : Checks the status of the queue based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure to be checked.
* Parameters (out): None
* Return value    : Queue_Status_t - Status indicating whether the queue is full, empty, or available.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Checks queue status based on the selected memory mode:
*                       - Array: Returns `Queue_Status_Full` if the queue is full; otherwise, `Queue_Status_Empty`.
*                       - Linked List: (TODO) - Currently not implemented.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Status(Queue_t *Queue);

/*****************************************************************************************
* Function Name   : Queue_Enqueue
* Description     : Adds an element to the queue based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure where the element will be added.
*                   : Data - The element to be added to the queue.
* Parameters (out): None
* Return value    : Queue_Status_t - Status indicating whether the element is successfully enqueued or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Returns `Queue_Status_Full` if the queue is full (only applicable in Array memory mode).
*                   - Returns `Queue_Status_Allocation` if memory allocation fails (only applicable in Linked List memory mode).
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Enqueue(Queue_t *Queue,Storage_Type Data);

/*****************************************************************************************
* Function Name   : Queue_Dequeue
* Description     : Removes an element from the front of the queue and retrieves its value.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure from which the element will be dequeued.
* Parameters (out): Data - Pointer to store the value of the dequeued element.
* Return value    : Queue_Status_t - Status indicating whether the element is successfully dequeued or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Returns `Queue_Status_Empty` if the queue is empty.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Dequeue(Queue_t *Queue,Storage_Type *Data);

/*****************************************************************************************
* Function Name   : Queue_Front
* Description     : Retrieves the element at the front of the queue based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure to be checked.
* Parameters (out): Data - Pointer to the variable where the front element will be stored.
* Return value    : Queue_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Returns `Queue_Status_Empty` if the queue is empty.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Front(Queue_t *Queue,Storage_Type *Data);

/*****************************************************************************************
* Function Name   : Queue_Rear
* Description     : Retrieves the element at the rear of the queue based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure to be checked.
* Parameters (out): Data - Pointer to the variable where the rear element will be stored.
* Return value    : Queue_Status_t - Status indicating whether the operation is successful or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Returns `Queue_Status_Empty` if the queue is empty.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Rear(Queue_t *Queue,Storage_Type *Data);

/*****************************************************************************************
* Function Name   : Queue_Clear
* Description     : Clears all elements from the queue based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure to be cleared.
* Parameters (out): None
* Return value    : Queue_Status_t - Status indicating whether the clearing is successful or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Clear(Queue_t *Queue);

/*****************************************************************************************
* Function Name   : Queue_Traverse
* Description     : Traverses and applies a function to each element in the queue based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure to be traversed.
*                   : Function - Pointer to the function to be applied to each element.
* Parameters (out): None
* Return value    : Queue_Status_t - Status indicating whether the traversal is successful or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Returns `Queue_Status_Empty` if the queue is empty.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Traverse(Queue_t *Queue,void (*Function)(Storage_Type));

/*****************************************************************************************
* Function Name   : Queue_Traverse_Origin
* Description     : Traverses and applies a function to each element in the queue based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure to be traversed.
*                   : Function - Pointer to the function to be applied to each element.
* Parameters (out): None
* Return value    : Queue_Status_t - Status indicating whether the traversal is successful or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Returns `Queue_Status_Empty` if the queue is empty.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Traverse_Origin(Queue_t *Queue,void (*Function)(Storage_Type*));

/*****************************************************************************************
* Function Name   : Queue_Dequeue_Node
* Description     : Removes a specific node from the queue based on the selected memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Queue - Pointer to the queue structure from which the node will be dequeued.
*                   : Node_Number - The position of the node to be dequeued.
* Parameters (out): None
* Return value    : Queue_Status_t - Status indicating whether the node is successfully dequeued or an error occurred.
* Notes           : - Returns `Queue_Status_Null` if the input pointer is NULL.
*                   - Returns `Queue_Status_Empty` if the queue is empty.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Queue_Status_t Queue_Dequeue_Node(Queue_t *Queue,u8 Node_Number);

/********************************************************************
 *  END OF FILE: Queue.h
********************************************************************/
#endif
