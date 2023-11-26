/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Queue.c
 *  Module:  Data Structure/Queue
 *  Description:  Queue Implementation
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Queue.h"
/*****************************************
----------    GLOBAL DATA     ------------
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
Queue_Status_t Queue_Initialization(Queue_t *Queue)
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
          Queue->Queue_Size=ZERO;
#if Memory_Mode == Array
          Queue->Queue_Front=ZERO;
          Queue->Queue_Rear=-ONE;
#else
          Queue->Queue_Front=NULL;
          Queue->Queue_Rear=NULL;
#endif
     }
     return Flag;
}
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
Queue_Status_t Queue_Status(Queue_t *Queue)
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
#if Memory_Mode == Array
          Flag=(Queue->Queue_Size==Maximum_Queue_Size)?Queue_Status_Full:(Queue->Queue_Size==ZERO)?Queue_Status_Empty:Queue_Status_Available;
#else
          Flag=(Queue->Queue_Size==ZERO)?Queue_Status_Empty:Queue_Status_Available;
#endif
     }
     return Flag;
}
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
Queue_Status_t Queue_Enqueue(Queue_t *Queue,Storage_Type Data)
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
#if Memory_Mode == Array
          if(Queue_Status(Queue)!=Queue_Status_Full)
          {
               Queue->Queue_Rear=(Queue->Queue_Rear+ONE)%Maximum_Queue_Size;
               Queue->Queue_Elements[Queue->Queue_Rear]=Data;
               Queue->Queue_Size++;
          }
          else {Flag=Queue_Status_Full;}
#else
          Queue_Node_t *Queue_Node=(Queue_Node_t *)malloc(sizeof(Queue_Node_t));
          if(Queue_Node)
          {
               Queue_Node->Queue_Node_Next=NULL;
               Queue_Node->Data=Data;
               if(!(Queue->Queue_Rear)){Queue->Queue_Front=Queue_Node;}
               else{Queue->Queue_Rear->Queue_Node_Next=Queue_Node;}
               Queue->Queue_Rear=Queue_Node;
               Queue->Queue_Size++;
          }
          else {Flag=Queue_Status_Allocation;}
#endif
     }
     return Flag;
}
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
Queue_Status_t Queue_Dequeue_Node(Queue_t *Queue,u8 Node_Number)
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
          if(Queue_Status(Queue)!=Queue_Status_Empty)
          {
#if Memory_Mode == Array
               for(u8 Counter=Node_Number-ONE;Counter<Queue->Queue_Size;Counter++)
               {
                    Queue->Queue_Elements[Counter]=Queue->Queue_Elements[Counter+1];
               }
#else
               Queue_Node_t *Previous_Queue_Node=NULL,*Next_Queue_Node=NULL;
               for(Previous_Queue_Node=Queue->Queue_Front;--Node_Number;Previous_Queue_Node=Queue->Queue_Front){}
               Next_Queue_Node=Previous_Queue_Node->Queue_Node_Next->Queue_Node_Next;
               free(Previous_Queue_Node->Queue_Node_Next);
               Previous_Queue_Node->Queue_Node_Next=Next_Queue_Node;
#endif
               Queue->Queue_Size--;
          }
          else {Flag=Queue_Status_Empty;}
     }
     return Flag;
}
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
Queue_Status_t Queue_Traverse_Origin(Queue_t *Queue,void (*Function)(Storage_Type*))
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
          if(Queue_Status(Queue)!=Queue_Status_Empty)
          {
#if Memory_Mode == Array
               for(u8 Index=Queue->Queue_Front,Counter=ZERO;Counter<Queue->Queue_Size;Counter++)
               {
                    Function(&(Queue->Queue_Elements[Index]));
                    Index=(Index+1)%Maximum_Queue_Size;
               }
#else
     for(Queue_Node_t *Queue_Node=Queue->Queue_Front;Queue_Node;Queue_Node=Queue_Node->Queue_Node_Next){Function(&(Queue_Node->Data));}
#endif
          }
          else {Flag=Queue_Status_Empty;}
     }
     return Flag;
}
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
Queue_Status_t Queue_Traverse(Queue_t *Queue,void (*Function)(Storage_Type))
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
          if(Queue_Status(Queue)!=Queue_Status_Empty)
          {
#if Memory_Mode == Array
               for(u8 Index=Queue->Queue_Front,Counter=ZERO;Counter<Queue->Queue_Size;Counter++)
               {
                    Function(Queue->Queue_Elements[Index]);
                    Index=(Index+1)%Maximum_Queue_Size;
               }
#else
               for(Queue_Node_t *Queue_Node=Queue->Queue_Front;Queue_Node;Queue_Node=Queue_Node->Queue_Node_Next){Function(Queue_Node->Data);} 
#endif
          }
          else Flag=Queue_Status_Empty;
     }
     return Flag;
}
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
Queue_Status_t Queue_Dequeue(Queue_t *Queue,Storage_Type *Data)
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
          if(Queue_Status(Queue)!=Queue_Status_Empty)
          {
#if Memory_Mode == Array
               *Data=Queue->Queue_Elements[Queue->Queue_Front];
               Queue->Queue_Front=(Queue->Queue_Front+ONE)%Maximum_Queue_Size;
               Queue->Queue_Size--;
#else
               Queue_Node_t *Queue_Node=Queue->Queue_Front;
               *Data=Queue_Node->Data;
               Queue->Queue_Front=Queue_Node->Queue_Node_Next;
               free(Queue_Node);
               if(!(Queue->Queue_Front)){Queue->Queue_Rear=NULL;}
               Queue->Queue_Size--;
#endif
          }
          else {Flag=Queue_Status_Empty;*Data=ZERO;}
     }
     return Flag;
}
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
Queue_Status_t Queue_Clear(Queue_t *Queue)
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
#if Memory_Mode != Array
          if(Queue_Status(Queue)!=Queue_Status_Empty)
          {
               for(Queue_Node_t *Queue_Node=Queue->Queue_Front;Queue_Node;Queue_Node=Queue->Queue_Front)
               {
                    Queue->Queue_Front=Queue_Node->Queue_Node_Next;
                    free(Queue_Node);
               }
          }
#endif
          Flag=Queue_Initialization(Queue);
     }
     return Flag;
}
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
Queue_Status_t Queue_Rear(Queue_t *Queue,Storage_Type *Data)
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
          if(Queue_Status(Queue)!=Queue_Status_Empty)
          {
#if Memory_Mode == Array
               *Data=Queue->Queue_Elements[Queue->Queue_Rear];
#else
               *Data=Queue->Queue_Rear->Data;
#endif
          }
          else {Flag=Queue_Status_Empty;*Data=ZERO;}
     }
     return Flag;
}
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
Queue_Status_t Queue_Front(Queue_t *Queue,Storage_Type *Data)
{
     Queue_Status_t Flag=Queue_Status_Ok;
     if(NULL==Queue){Flag=Queue_Status_Null;}
     else
     {
          if(Queue_Status(Queue)!=Queue_Status_Empty)
          {
#if Memory_Mode == Array
               *Data=Queue->Queue_Elements[Queue->Queue_Front];
#else
               *Data=Queue->Queue_Front->Data;
#endif
          }
          else {Flag=Queue_Status_Empty;*Data=ZERO;}
     }
     return Flag;
}
/********************************************************************
 *  END OF FILE: Queue.c
********************************************************************/