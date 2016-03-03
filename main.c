/**
* Author: Alex Orozco
* Description: Simple linked list in c implementation.
*/

#include <stdio.h>
#include <stdlib.h>

#include "list.c"

void printTest(struct node *intlist,struct node *testListHalf ,struct node *testListDouble)
{
    int i;
    i = nodupdata(intlist);
    printf("1 list, Boolean Value for double data: %d\n", i);
    printAll(intlist);
    printf("\n\n");
    i = nodupdata(testListHalf);
    printf("2nd list, Boolean Value for double data: %d\n", i);
    printAll(testListHalf);
    printf("\n\n");
    i = nodupdata(testListDouble);
    printf("3rd list, Boolean Value for double data: %d\n", i);
    printAll(testListDouble);
    printf("\n\n");
}
//////////////////////This test isnt working correctly//////////////////////This test isnt working correctly//////////////////////This test isnt working correctly
struct node *testLoopless(struct node *list)
{
  if(list == NULL)
    return NULL;
  struct node *temp = list;
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = list->next;  
  return list;
}

int main(void) {

    struct node *intlist = NULL;
    struct node *testListHalf = NULL;
    struct node *testListDouble = NULL;
    struct node *testListTriple = NULL;
    struct node *testListQuad = NULL;
    int i;
     for (i = 0; i < 10; i ++) {  
        intlist = add_to_list(intlist ,i );
        testListHalf = add_to_list(testListHalf ,i/2 );
        testListDouble = add_to_list(testListDouble ,i*2 );
        testListTriple = add_to_list(testListTriple ,i*3 );
        testListQuad = add_to_list(testListQuad ,i*4 );
    }
    
    //Tests the double function
    doubleAll(intlist);
    doubleAll(testListHalf);
    printTest(intlist, testListHalf, testListDouble);
    
    //test the mergedList
    struct node *mergedList = merge(testListTriple, testListQuad);
    printf("printing merged list 2/3 lists.\n");
    printAll(mergedList);
    intlist = merge(mergedList, intlist);
    printf("printing merged list of all three lists.\n");
    printAll(intlist);
    
    //tests the looplesslength function;   
    i = looplesslength(testListHalf);
    printf("We are testing the loopless, the length is: %d \n", i );
    testListDouble = testLoopless(testListDouble);
    i = looplesslength(testListDouble);
    printf("We are testing the loopless using bubble sort 2: %d \n", i);
    
    //tests the delete all
    intlist = deleteAll(intlist, 36);
    testListHalf = deleteAll(testListHalf, 4);
    doubleAll(testListQuad);
    doubleAll(testListQuad);
    testListQuad = deleteAll(testListQuad, 8);
    printTest(intlist, testListHalf, testListQuad);
    
    return 0;
}
