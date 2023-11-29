/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Linked_List.c
 *  Brief:  Handle Linked_List
 *  Description:  Logic C File Implementation Linked List
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Linked_List.h"
/*****************************************
----------    GLOBAL DATA     ------------
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
Linked_List_Status_t Linked_List_Initialization(Linked_List_t *Linked_List)
{
     Linked_List_Status_t Flag=Linked_List_Status_Ok;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          Linked_List->Linked_List_Hear_Ptr=NULL;
          Linked_List->Linked_List_Size=-ONE;
     }
     return Flag;
}
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
Linked_List_Status_t Linked_List_Status(Linked_List_t *Linked_List)
{
     Linked_List_Status_t Flag=Linked_List_Status_Ok;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          Flag=(Linked_List->Linked_List_Size==ZERO)?Linked_List_Status_Empty:Linked_List_Status_Available;
     }
     return Flag;
}
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
Linked_List_Status_t Linked_List_Clear(Linked_List_t *Linked_List)
{
     Linked_List_Status_t Flag=Linked_List_Status_Ok;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          for(s16 Counter=Linked_List->Linked_List_Size;Counter>=ZERO;Counter--)
          {
               Flag=Linked_List_Delete_Node(Linked_List,Counter);
          }
     }
     return Flag;
}
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
Linked_List_Status_t Linked_List_Insert(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type Data)
{
     Linked_List_Status_t Flag=Linked_List_Status_Ok;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          if(Linked_List->Linked_List_Size>=(Node_Number-ONE))
          {
               Linked_List_Node_t *Linked_List_Node_New=(Linked_List_Node_t*)malloc(sizeof(Linked_List_Node_t));
               if(Linked_List_Node_New)
               {
                    Linked_List_Node_t *temp=Linked_List->Linked_List_Hear_Ptr;
                    Linked_List_Node_New->Data=Data;
                    if(Node_Number==ZERO)
                    {
                         temp=Linked_List->Linked_List_Hear_Ptr;
                         Linked_List->Linked_List_Hear_Ptr=Linked_List_Node_New;
                         Linked_List_Node_New->Linked_List_Node_Next_Ptr=temp;
                    }
                    else
                    {
                         for(u8 i=TWO;i<=Node_Number;i++) temp=temp->Linked_List_Node_Next_Ptr;
                         Linked_List_Node_New->Linked_List_Node_Next_Ptr=temp->Linked_List_Node_Next_Ptr;
                         temp->Linked_List_Node_Next_Ptr=Linked_List_Node_New;
                    }
                    Linked_List->Linked_List_Size++;
                    Flag=Linked_List_Status_Ok;
               }
               else
               {
                    Flag=Linked_List_Status_Allocation;
               }
          }
          else 
          {
               Flag=Linked_List_Status_Size;
          }
     }
     return Flag;
}
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
Linked_List_Status_t Linked_List_Append(Linked_List_t *Linked_List,Storage_Type Data)
{
     Linked_List_Status_t Flag=Linked_List_Status_Ok;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          Linked_List_Node_t *Linked_List_Node_New=(Linked_List_Node_t*)malloc(sizeof(Linked_List_Node_t));
          if(Linked_List_Node_New)
          {
               Linked_List_Node_New->Data=Data;
               Linked_List_Node_New->Linked_List_Node_Next_Ptr=NULL;
               if(!Linked_List->Linked_List_Hear_Ptr)
               {
                    Linked_List->Linked_List_Hear_Ptr=Linked_List_Node_New;
               }
               else
               {
                    Linked_List_Node_t *temp=Linked_List->Linked_List_Hear_Ptr;
                    while(temp->Linked_List_Node_Next_Ptr!=NULL) temp=temp->Linked_List_Node_Next_Ptr;
                    temp->Linked_List_Node_Next_Ptr=Linked_List_Node_New;
               }
               Linked_List->Linked_List_Size++;
               Flag=Linked_List_Status_Ok;
          }
          else
          {
               Flag=Linked_List_Status_Allocation;
          }
     }
     return Flag;
}
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
Linked_List_Status_t Linked_List_Get_Node(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type *Data)
{
     Linked_List_Status_t Flag=Linked_List_Status_Ok;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          if(Node_Number>Linked_List->Linked_List_Size){Flag=Linked_List_Status_Size;}
          else
          {
               Linked_List_Node_t *temp=Linked_List->Linked_List_Hear_Ptr;
               while(Node_Number>=ONE)
               {
                    temp=temp->Linked_List_Node_Next_Ptr;
                    Node_Number--;
               }
               *Data=temp->Data;
               Flag=Linked_List_Status_Ok;
          }
     }
     return Flag;
}
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
Linked_List_Status_t Linked_List_Delete_Node(Linked_List_t *Linked_List,u8 Node_Number)
{
     Linked_List_Status_t Flag=Linked_List_Status_Ok;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          if(Node_Number>Linked_List->Linked_List_Size)
          {
               Flag=Linked_List_Status_Size;
          }
          else
          {
               Linked_List_Node_t *current=Linked_List->Linked_List_Hear_Ptr;
               if(Node_Number==ZERO)
               {
                    Linked_List->Linked_List_Hear_Ptr=current->Linked_List_Node_Next_Ptr;
                    free(current);
                    Linked_List->Linked_List_Size--;
               }
               else
               {
                    Linked_List_Node_t *previous=Linked_List->Linked_List_Hear_Ptr;
                    current=current->Linked_List_Node_Next_Ptr;
                    while(Node_Number>=TWO)
                    {
                         previous=previous->Linked_List_Node_Next_Ptr;
                         current=current->Linked_List_Node_Next_Ptr;
                         Node_Number--;
                    }
                    previous->Linked_List_Node_Next_Ptr=current->Linked_List_Node_Next_Ptr;
                    free(current);
                    Linked_List->Linked_List_Size--;
               }
               Flag=Linked_List_Status_Ok; 
          }
     }
     return Flag;
}
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
Linked_List_Status_t Linked_List_Traverse(Linked_List_t *Linked_List,void (*function)(Storage_Type*))
{
     Linked_List_Status_t Flag=Linked_List_Status_Empty;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          if(Linked_List->Linked_List_Size>=ZERO)
          {
               Linked_List_Node_t *temp=Linked_List->Linked_List_Hear_Ptr;
               function(&(temp->Data));
               while (temp=temp->Linked_List_Node_Next_Ptr)
               {
                    function(&(temp->Data));
               }
               Flag=Linked_List_Status_Ok;
          }
     }
     return Flag;
}
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
Linked_List_Status_t Linked_List_Get_Node_From_End(Linked_List_t *Linked_List,u8 Node_Number,Storage_Type *Data)
{
     Linked_List_Status_t Flag=Linked_List_Status_Empty;
     if(NULL==Linked_List){Flag=Linked_List_Status_Null;}
     else
     {
          if(Node_Number>Linked_List->Linked_List_Size)
          {
               Flag=Linked_List_Status_Size;
          }
          else
          {
               Linked_List_Node_t *Start_Node=Linked_List->Linked_List_Hear_Ptr,*End_Node=Linked_List->Linked_List_Hear_Ptr;
               while(Node_Number--)
               {
                    End_Node=End_Node->Linked_List_Node_Next_Ptr;
               }
               while(End_Node=End_Node->Linked_List_Node_Next_Ptr)
               {
                    Start_Node=Start_Node->Linked_List_Node_Next_Ptr;
               }
               *Data=Start_Node->Data;
               Flag=Linked_List_Status_Ok;
          }
     }
     return Flag;
}
/********************************************************************
 *  END OF FILE:  Linked_List.c
********************************************************************/
