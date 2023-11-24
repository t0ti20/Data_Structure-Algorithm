/*******************************************************************
 *  FILE DESCRIPTION
--------------------------------------------------------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Queue.h
 *  Module:  Data Structure/Queue
 *  Description:  Queue Implementation
*******************************************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_
/*---------- Include Files -------------*/
#include "./Standard_Types.h"
#include "./Macros.h"
#include <stdio.h>
/*****************************************
----------   Configuration    ------------
*****************************************/
#define Memory_Mode           Array                                 /*(Linked_List) (Array)*/
#define storage_type          u8                                    /*(u8) (u16) (u32) (s8) (...)*/
#define Queue_Size            Maximum_Tasks                         /*When Chosing (Array) Max Number Of Stack*/
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum queue_error 
{
     Queue_Full                =0,
     Queue_Ok                  =1,
     Queue_Empty               =2,
     Queue_Allocation_Error    =3,
}queue_error;
#if Memory_Mode == Array
typedef struct queue_t {s8 front;storage_type elements[Queue_Size];s8 rear;u8 size;}queue_t;
#else
typedef struct queue_node_t {struct queue_node_t *next_node;storage_type data;}queue_node_t;
typedef struct queue_t {queue_node_t *rear;queue_node_t *front;u8 size;}queue_t;
#endif
/*----------- Functins To Use ---------*/
queue_error Queue_Traverse_Origin(queue_t *my_queue,void (*function)(storage_type*));
queue_error Queue_Traverse(queue_t *my_queue,void (*function)(storage_type));
queue_error Queue_Dequeue_Node(queue_t *my_queue,u8 Node_Number);
queue_error Queue_Dequeue(queue_t *my_queue,storage_type *data);
queue_error Queue_Enqueue(queue_t *my_queue,storage_type data);
queue_error Queue_Initialization(queue_t *my_queue);
queue_error Queue_Clear(queue_t *my_queue);
s8 Queue_Is_Empty(queue_t *my_queue);
s8 Queue_Is_Full(queue_t *my_queue);
void *malloc(size_t size);
void free(void *ptr);
#endif
/********************************************************************
 *  END OF FILE: Queue.h
********************************************************************/