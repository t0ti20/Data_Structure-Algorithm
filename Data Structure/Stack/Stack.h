/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Owner:  Khaled El-Sayed @t0ti20
 *  File:  Stack.h
 *  Module:  Data Structure/Stack
 *  Description:  Stack Implementation
*******************************************************************/
#ifndef _STACK_H_
#define _STACK_H_
/*---------- Include Files -------------*/
#include <stdio.h>
#include "../../Library/Standard_Types.h"
#include "../../Library/Macros.h"
/*****************************************
----------   Configuration    ------------
*****************************************/
#define Memory_Mode Array                           /*(Linked_List) (Array)*/
#define storage_type u8                             /*(u8) (u16) (u32) (s8) (...)*/
#define Stack_size 5                                /*When Chosing (Array) Max Number Of Stack*/
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/*------------- Type Defs --------------*/
typedef enum Stack_error
{
     Stack_Full                =0,
     Stack_Ok                  =1,
     Stack_Empty               =2,
     Stack_Allocation_Error    =3,
}Stack_error;
#define Array                1
#define Linked_List          2
#if Memory_Mode == Array
     typedef struct Stack_t {storage_type elements[Stack_size+1];u8 top;} Stack_t ;
#else
     typedef struct Stack_node_t {struct Stack_node_t *next_node;storage_type data;}Stack_node_t;
     typedef struct Stack_t {Stack_node_t *top;u8 size;}Stack_t;
#endif
/*----------- Functins To Use ---------*/
Stack_error Stack_Clear(Stack_t *my_stack);
Stack_error Stack_Initialization(Stack_t *my_stack);
Stack_error Stack_Push(Stack_t *my_stack,storage_type data);
Stack_error Stack_Pop(Stack_t *my_stack,storage_type *data);
Stack_error Stack_traverse(Stack_t *my_stack,void (*function)(storage_type));
s8 Stack_Is_Empty(Stack_t *my_stack);
s8 Stack_Is_Full(Stack_t *my_stack);
void *malloc(size_t size);
void free(void *ptr);
/********************************************************************
 *  END OF FILE: Stack.h
********************************************************************/
#endif
