#include "Stack.h"
#include <stdio.h>
void print_error(Stack_Status_t Error)
{
     switch (Error)
     {
          case Stack_Status_Ok:printf("There Is No Error\n");break;
          case Stack_Status_Available:printf("Stack Is Available\n");break;
          case Stack_Status_Full:printf("Stack Is Full \n");break;
          case Stack_Status_Empty:printf("Stack Is Empty \n");break;
          case Stack_Status_Allocation:printf("Cannot Allocate Memory \n");break;
          case Stack_Status_Null:printf("Null Pointer Error\n");break;
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
     Stack_t First;
     Stack_t Second;
     u8 Data,ADD=0;
     print_error(Stack_Initialization(&First));
     print_error(Stack_Status(&First));
     print_error(Stack_Push(&First,1));
     print_error(Stack_Push(&First,2));
     print_error(Stack_Push(&First,3));
     print_error(Stack_Push(&First,4));
     print_error(Stack_Push(&First,5));
     print_error(Stack_Push(&First,6));
     print_error(Stack_Traverse(&First,Print_Elements));
     printf("======================\n===================\n");
     /*(-------------------------------------)*/
     print_error(Stack_Pop(&First,&Data));
     ADD+=Data;
     print_error(Stack_Pop(&First,&Data));
     ADD+=Data;
     print_error(Stack_Pop(&First,&Data));
     ADD+=Data;
     print_error(Stack_Pop(&First,&Data));
     ADD+=Data;
     print_error(Stack_Pop(&First,&Data));
     ADD+=Data;
     print_error(Stack_Pop(&First,&Data));
     ADD+=Data;
     print_error(Stack_Pop(&First,&Data));
     ADD+=Data;
     printf("Data===================>%d\n",ADD);
     print_error(Stack_Traverse(&First,Print_Elements));
     printf("======================\n===================\n");
     print_error(Stack_Push(&First,6));
     print_error(Stack_Top(&First,&Data));
     print_error(Stack_Traverse(&First,Print_Elements));
     printf("Data===================>%d\n",Data);

}

