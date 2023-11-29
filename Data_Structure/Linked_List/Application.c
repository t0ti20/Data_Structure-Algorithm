#include "Linked_List.h"
#include <stdio.h>
void print_error(Li_Status_t Error)
{
     switch (Error)
     {
          case Queue_Status_Ok:printf("There Is No Error\n");break;
          case Queue_Status_Available:printf("Queue Is Available\n");break;
          case Queue_Status_Full:printf("Queue Is Full \n");break;
          case Queue_Status_Empty:printf("Queue Is Empty \n");break;
          case Queue_Status_Allocation:printf("Cannot Allocate Memory \n");break;
          case Queue_Status_Null:printf("Null Pointer Error\n");break;
          default:printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");break;
     }
     printf("=======================\n");
}
void Print_Elements(u8 Data)
{
     printf("- %d\n",Data);
}
int main()
{
     Queue_t First;
     Queue_t Second;
     u8 Data,ADD=0;
     print_error(Queue_Initialization(&First));
     print_error(Queue_Status(&First));
     print_error(Queue_Enqueue(&First,1));
     print_error(Queue_Enqueue(&First,2));
     print_error(Queue_Enqueue(&First,3));
     print_error(Queue_Enqueue(&First,4));
     print_error(Queue_Enqueue(&First,5));
     print_error(Queue_Enqueue(&First,6));
     print_error(Queue_Traverse(&First,Print_Elements));
     printf("======================\n===================\n");
     print_error(Queue_Dequeue_Node(&First,2));
     print_error(Queue_Traverse(&First,Print_Elements));
     // printf("======================\n===================\n");
     // /*(-------------------------------------)*/
     // print_error(Queue_Dequeue(&First,&Data));
     // ADD+=Data;
     // print_error(Queue_Dequeue(&First,&Data));
     // ADD+=Data;
     // print_error(Queue_Dequeue(&First,&Data));
     // ADD+=Data;
     // print_error(Queue_Dequeue(&First,&Data));
     // ADD+=Data;
     // print_error(Queue_Dequeue(&First,&Data));
     // ADD+=Data;
     // print_error(Queue_Dequeue(&First,&Data));
     // ADD+=Data;
     // print_error(Queue_Dequeue(&First,&Data));
     // ADD+=Data;
     // printf("Data===================>%d\n",ADD);
     // print_error(Queue_Traverse(&First,Print_Elements));
     // printf("======================\n===================\n");
     // print_error(Queue_Enqueue(&First,6));
     // print_error(Queue_Front(&First,&Data));
     // print_error(Queue_Rear(&First,&Data));
     // print_error(Queue_Traverse(&First,Print_Elements));
     // printf("Data===================>%d\n",Data);

}

