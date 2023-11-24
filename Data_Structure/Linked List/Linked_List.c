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
#include "./Linked_List.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : Linked_List_Error Linked_List_Clear(Linked_List_t *my_list)
* Description     : Delete All Linked List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List)
* Parameters (out): None
* Return value:   : Linked_List_Error
********************************************************************/
Linked_List_Error Linked_List_Clear(Linked_List_t *my_list)
{
     Linked_List_Error flag;
     for(s16 Counter=my_list->size;Counter>=ZERO;Counter--)
     {
          flag=Linked_List_Delete_Node(my_list,Counter);
     }
     return flag;
}
/********************************************************************
* Syntax          : Linked_List_Error Linked_List_Initialization(Linked_List_t *my_list)
* Description     : Initialize The List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List)
* Parameters (out): None
* Return value:   : Linked_List_Error
********************************************************************/
Linked_List_Error Linked_List_Initialization(Linked_List_t *my_list)
{
     my_list->head=NULL;
     my_list->size=-1;
     return Linked_List_Ok;
}
/********************************************************************
* Syntax          : Linked_List_Error Linked_List_Insert(Linked_List_t *my_list,u8 node_number,storage_type data)
* Description     : Insert Node To Linked List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Node Number),(Data)
* Parameters (out): None
* Return value:   : Linked_List_Error
********************************************************************/
Linked_List_Error Linked_List_Insert(Linked_List_t *my_list,u8 node_number,storage_type data)
{
     Linked_List_Error flag;
     if(my_list->size>=(node_number-ONE))
     {
          Linked_List_node_t *new_node=(Linked_List_node_t*)malloc(sizeof(Linked_List_node_t));
          if(new_node)
          {
               Linked_List_node_t *temp=my_list->head;
               new_node->data=data;
               if(node_number==ZERO)
               {
                    temp=my_list->head;
                    my_list->head=new_node;
                    new_node->next_ptr=temp;
               }
               else
               {
                    for(u8 i=TWO;i<=node_number;i++) temp=temp->next_ptr;
                    new_node->next_ptr=temp->next_ptr;
                    temp->next_ptr=new_node;
               }
               my_list->size++;
               flag=Linked_List_Ok;
          }
          else
          {
               flag=Linked_List_Wrong_Memory;
          }
     }
     else 
     {
          flag=Linked_List_Wrong_Size;
     }
     return flag;
}
/********************************************************************
* Syntax          : Linked_List_Error Linked_List_Append(Linked_List_t *my_list,storage_type data)
* Description     : Append To The List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Data)
* Parameters (out): None
* Return value:   : Linked_List_Error
********************************************************************/
Linked_List_Error Linked_List_Append(Linked_List_t *my_list,storage_type data)
{
     Linked_List_Error flag;
     Linked_List_node_t *new_node=(Linked_List_node_t*)malloc(sizeof(Linked_List_node_t));
     if(new_node)
     {
          new_node->data=data;
          new_node->next_ptr=NULL;
          if(!my_list->head)
          {
               my_list->head=new_node;
          }
          else
          {
               Linked_List_node_t *temp=my_list->head;
               while(temp->next_ptr!=NULL) temp=temp->next_ptr;
               temp->next_ptr=new_node;
          }
          my_list->size++;
          flag=Linked_List_Ok;
     }
     else
     {
          flag=Linked_List_Wrong_Memory;
     }
     return flag;
}
/********************************************************************
* Syntax          : storage_type Linked_List_Get_Node(Linked_List_t *my_list,u8 node_number)
* Description     : Get Specific Node
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Node Number)
* Parameters (out): None
* Return value:   : Node Data
********************************************************************/
Linked_List_Error Linked_List_Get_Node(Linked_List_t *my_list,u8 node_number,storage_type *data)
{
     Linked_List_Error flag;
     if(node_number>my_list->size)
     {
          flag=Linked_List_Wrong_Size;
     }
     else
     {
          Linked_List_node_t *temp=my_list->head;
          while(node_number>=ONE)
          {
               temp=temp->next_ptr;
               node_number--;
          }
          *data=temp->data;
          flag=Linked_List_Ok;
     }
     return flag;
}
/********************************************************************
* Syntax          : storage_type Linked_List_Delete_Node(Linked_List_t *my_list,u8 node_number)
* Description     : Delete Specific Node
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Node Number)
* Parameters (out): None
* Return value:   : storage_type
********************************************************************/
Linked_List_Error Linked_List_Delete_Node(Linked_List_t *my_list,u8 node_number)
{
     Linked_List_Error flag;
     if(node_number>my_list->size)
     {
          flag=Linked_List_Wrong_Size;
     }
     else
     {
          Linked_List_node_t *current=my_list->head;
          if(node_number==ZERO)
          {
               my_list->head=current->next_ptr;
               free(current);
               my_list->size--;
          }
          else
          {
               Linked_List_node_t *previous=my_list->head;
               current=current->next_ptr;
               while(node_number>=TWO)
               {
                    previous=previous->next_ptr;
                    current=current->next_ptr;
                    node_number--;
               }
               previous->next_ptr=current->next_ptr;
               free(current);
               my_list->size--;
          }
          flag=Linked_List_Ok; 
     }
     return flag;
}
/********************************************************************
* Syntax          : Linked_List_Error Linked_List_Traverse(Linked_List_t *my_list,void (*function)(storage_type*))
* Description     : Traverse Linked List
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Function(storage_type*))
* Parameters (out): None
* Return value:   : Linked_List_Error
********************************************************************/
Linked_List_Error Linked_List_Traverse(Linked_List_t *my_list,void (*function)(storage_type*))
{
     Linked_List_Error flag=Linked_List_Empty;
     if(my_list->size>=ZERO)
     {
          Linked_List_node_t *temp=my_list->head;
          function(&(temp->data));
          while (temp=temp->next_ptr)
          {
               function(&(temp->data));
          }
          flag=Linked_List_Ok;
     }
     return flag;
}
/********************************************************************
* Syntax          : Linked_List_Error Linked_List_Get_Node_From_End(Linked_List_t *my_list,u8 node_number,storage_type *data)
* Description     : Get Specific Node Data
* Sync-Async      : *
* Reentrancy      : *
* Parameters (in) : (Ptr To List),(Node Number),(Pointer To Data)
* Parameters (out): None
* Return value:   : Linked_List_Error
********************************************************************/
Linked_List_Error Linked_List_Get_Node_From_End(Linked_List_t *my_list,u8 node_number,storage_type *data)
{
     Linked_List_Error flag;
     if(node_number>my_list->size)
     {
          flag=Linked_List_Wrong_Size;
     }
     else
     {
          Linked_List_node_t *start=my_list->head,*end=my_list->head;
          while(node_number--)
          {
               end=end->next_ptr;
          }
          while(end=end->next_ptr)
          {
               start=start->next_ptr;
          }
          *data=start->data;
          flag=Linked_List_Ok;
     }
     return flag;
}
/********************************************************************
 *  END OF FILE:  Linked_List.h
********************************************************************/
