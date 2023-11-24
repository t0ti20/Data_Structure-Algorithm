/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Stack.c
 *  Module:  Data_Structure/Stack
 *  Description:  Stack Implementation
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Stack.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*****************************************************************************************
* Function Name   : Stack_Initialization
* Description     : Initializes a stack based on the chosen memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure to be initialized.
* Parameters (out): None
* Return value    : Stack_Error_t - Status of the initialization process. 
*                   Returns `Stack_Error_Ok` if successful, or an error code for issues.
* Notes           : - Returns `Stack_Error_Null` if the input pointer is NULL.
*                   - Initializes stack properties based on the selected memory mode:
*                       - Linked List: Sets size to zero and top node to NULL.
*                       - Array: Sets top index to zero.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Essential for setting up a stack before push and pop operations.
*****************************************************************************************/
Stack_Error_t Stack_Initialization(Stack_t *Stack)
{
     Stack_Error_t Flag=Stack_Error_Ok;
     if(NULL==Stack){Flag=Stack_Error_Null;}
     else
     {
#if Memory_Mode == Linked_List
          Stack->Current_Size = ZERO;
          Stack->Stack_Node_Top = NULL;
#else
          Stack->Stack_Top = ZERO;
#endif
     }
     return Flag;
}
/*****************************************************************************************
* Function Name   : Stack_Status
* Description     : Checks if the stack is full based on the chosen memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure to be checked.
* Parameters (out): None
* Return value    : Stack_Error_t - Status indicating whether the stack is full, empty, or an error.
* Notes           : - Returns `Stack_Error_Null` if the input pointer is NULL.
*                   - Checks stack status based on the selected memory mode:
*                       - Array: Returns `Stack_Error_Full` if the stack is full; otherwise, `Stack_Error_Empty`.
*                       - Linked List: (TODO) - Currently not implemented.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Stack_Error_t Stack_Status(Stack_t *Stack)
{
     Stack_Error_t Flag=Stack_Error_Ok;
     if(NULL==Stack)
     {
          Flag=Stack_Error_Null;
     }
     else
     {
#if Memory_Mode == Array
          Flag=(Stack->Stack_Top==Maximum_Stack_Size)?Stack_Error_Full:((Stack->Stack_Top==ZERO)?Stack_Error_Empty:Stack_Error_Available);
#else
          /*TODO*/
#endif
     }
     return Flag;
}
/*****************************************************************************************
* Function Name   : Stack_Push
* Description     : Pushes data onto the stack based on the chosen memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
*                   Data - Data to be pushed onto the stack.
* Parameters (out): None
* Return value    : Stack_Error_t - Status indicating the success of the push operation or an error.
* Notes           : - Returns `Stack_Error_Null` if the input pointer is NULL.
*                   - Pushes data onto the stack based on the selected memory mode:
*                       - Array: Checks if the stack is not full before pushing.
*                       - Linked List: Allocates memory for a new node and adds it to the top of the stack.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Returns `Stack_Error_Full` if the stack is full (Array mode).
*                   - Returns `Stack_Allocation_Error` if memory allocation fails (Linked List mode).
*****************************************************************************************/
Stack_Error_t Stack_Push(Stack_t *Stack,Storage_Type Data)
{
     Stack_Error_t Flag=Stack_Error_Ok;
     if(NULL==Stack){Flag=Stack_Error_Null;}
     else
     {
#if Memory_Mode == Array
          if(Stack_Status(Stack)!=Stack_Error_Full)
          {
               Stack->Stack_Elements[Stack->Stack_Top]=Data;
               Stack->Stack_Top++;
          }
          else {Flag=Stack_Error_Full;}
#else
          /*ToDo*/
          Stack_node_t *node=(Stack_node_t *)malloc(sizeof(Stack_node_t));
          if(node)
          {
               node->data=data;
               node->next_node=my_stack->top;
               my_stack->top=node;
               my_stack->size++;
          }
          else flag=Stack_Allocation_Error;
#endif
     }
     return Flag;
}
/*****************************************************************************************
* Function Name   : Stack_Pop
* Description     : Pops data from the stack based on the chosen memory mode.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
* Parameters (out): Data - Pointer to store the popped data.
* Return value    : Stack_Error_t - Status indicating the success of the pop operation or an error.
* Notes           : - Returns `Stack_Error_Null` if the input pointer is NULL.
*                   - Pops data from the stack based on the selected memory mode:
*                       - Array: Checks if the stack is not empty before popping.
*                       - Linked List: Removes the top node and retrieves its data.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Returns `Stack_Error_Empty` if the stack is empty (Array mode).
*****************************************************************************************/
Stack_Error_t Stack_Pop(Stack_t *Stack,Storage_Type *Data)
{
     Stack_Error_t Flag=Stack_Error_Ok;
     if(NULL==Stack){Flag=Stack_Error_Null;}
     else
     {
#if Memory_Mode == Array
          if(Stack_Status(Stack)!=Stack_Error_Empty)
          {
               *Data=Stack->Stack_Elements[(Stack->Stack_Top)-ONE];
               (Stack->Stack_Top)--;
          }
          else{*Data=ZERO;Flag=Stack_Error_Empty;}
#else
          /*TODO*/
          // if(my_stack->size)
          // {
          //      Stack_node_t *node=my_stack->top->next_node;
          //      *data=my_stack->top->data;
          //      free(my_stack->top);
          //      my_stack->top=node;
          //      my_stack->size--;
          // }
          // else flag=Stack_Empty;
#endif
     }
     return Flag;
}
/*****************************************************************************************
* Function Name   : Stack_Top
* Description     : Retrieves the top element of the stack without removing it.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
* Parameters (out): Data - Pointer to store the top element.
* Return value    : Stack_Error_t - Status indicating the success of the operation or an error.
* Notes           : - Returns `Stack_Error_Null` if the input pointer is NULL.
*                   - Retrieves the top element from the stack based on the selected memory mode:
*                       - Array: Checks if the stack is not empty before retrieving.
*                       - Linked List: (TODO) - Currently not implemented.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Returns `Stack_Error_Empty` if the stack is empty (Array mode).
*****************************************************************************************/
Stack_Error_t Stack_Top(Stack_t *Stack,Storage_Type *Data)
{
     Stack_Error_t Flag=Stack_Error_Ok;
     if(NULL==Stack){Flag=Stack_Error_Null;}
     else
     {
#if Memory_Mode == Array
          if(Stack_Status(Stack)!=Stack_Error_Empty)
          {
               *Data=Stack->Stack_Elements[(Stack->Stack_Top)-ONE];
          }
          else{*Data=ZERO;Flag=Stack_Error_Empty;}
#else
          /*TODO*/
#endif
     }
     return Flag;
}
/*****************************************************************************************
* Function Name   : Stack_Size
* Description     : Retrieves the current size of the stack.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
* Parameters (out): Size - Pointer to store the current size of the stack.
* Return value    : Stack_Error_t - Status indicating the success of the operation or an error.
* Notes           : - Returns `Stack_Error_Null` if the input pointer is NULL.
*                   - Retrieves the current size of the stack based on the selected memory mode:
*                       - Array: Returns the current stack top index.
*                       - Linked List: (TODO) - Currently not implemented.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Stack_Error_t Stack_Size(Stack_t *Stack,Storage_Type *Size)
{
     Stack_Error_t Flag=Stack_Error_Ok;
     if(NULL==Stack){Flag=Stack_Error_Null;}
     else
     {
#if Memory_Mode == Array
          *Size=Stack->Stack_Top;
#else
          /*TODO*/
#endif
     }
     return Flag;
}
/*****************************************************************************************
* Function Name   : Stack_Traverse
* Description     : Applies a function to each element of the stack, without modifying it.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
*                   Function - Pointer to the function to be applied to each stack element.
* Parameters (out): None
* Return value    : Stack_Error_t - Status indicating the success of the operation or an error.
* Notes           : - Returns `Stack_Error_Null` if the input pointer is NULL.
*                   - Applies the provided function to each element of the stack based on the selected memory mode:
*                       - Array: Checks if the stack is not empty before traversing.
*                       - Linked List: (TODO) - Currently not implemented.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*                   - Returns `Stack_Error_Empty` if the stack is empty (Array mode).
*****************************************************************************************/
Stack_Error_t Stack_Traverse(Stack_t *Stack,void (*Function)(Storage_Type))
{
     Stack_Error_t Flag=Stack_Error_Ok;
     if(NULL==Stack){Flag=Stack_Error_Null;}
     else
     {
#if Memory_Mode == Array
          if(Stack_Status(Stack)!=Stack_Error_Empty)
          {
               for(u8 Counter=(Stack->Stack_Top);(Counter--)>ZERO;)
               {
                    Function(Stack->Stack_Elements[Counter]);
               }
          }
          else {Flag=Stack_Error_Empty;}
#else
          /*TODO*/
          // if(my_stack->size)
          // {
          //      Stack_node_t *Node=my_stack->top;
          //      for(u8 counter=0;counter<my_stack->size;counter++)
          //      {
          //           function(Node->data);
          //           Node=Node->next_node;
          //      }
          // }
          // else flag=Stack_Empty;
#endif
     }
     return Flag;
}
/*****************************************************************************************
* Function Name   : Stack_Clear
* Description     : Clears all elements from the stack.
* Sync-Async      : Synchronous
* Reentrancy      : Reentrant
* Parameters (in) : Stack - Pointer to the stack structure.
* Parameters (out): None
* Return value    : Stack_Error_t - Status indicating the success of the operation or an error.
* Notes           : - Returns `Stack_Error_Null` if the input pointer is NULL.
*                   - Clears all elements from the stack based on the selected memory mode:
*                       - Array: Resets the stack top index to zero.
*                       - Linked List: (TODO) - Currently not implemented.
*                   - Ensure correct definition of `Memory_Mode` macro before use.
*****************************************************************************************/
Stack_Error_t Stack_Clear(Stack_t *Stack)
{
     Stack_Error_t Flag=Stack_Error_Ok;
     if(NULL==Stack){Flag=Stack_Error_Null;}
     else
     {
#if Memory_Mode == Array
          Stack->Stack_Top=ZERO;
#else
          /*TODO*/
          // if(my_stack->size)
          // {
          //      Stack_node_t *node;
          //      while(my_stack->top)
          //      {
          //           node=my_stack->top;
          //           my_stack->top=my_stack->top->next_node;
          //           free(node);
          //           my_stack->size--;
          //      }
          // }
          // else flag=Stack_Empty;
#endif
     }
     return Flag;
}
/********************************************************************
 *  END OF FILE: Stack.c
********************************************************************/
