/**
* Author: Alex Orozco
* Description: Simple linked list in c implementation.
*/
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

#include "list.h"

void printAll(struct node* list) {
    struct node* curr = list;
    printf("List: ");
    while (curr != NULL) {  // Watch Out: curr->next !=  NULL
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

struct node *add_to_list(struct node *list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

void add_to_listP2P( struct node **list  ,int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
}

int inOrder(struct node *list) {
    struct node *curr = list;
    if (curr == NULL)
        return 1;
    while (curr->next != NULL) {  // SAFETY CHECK: curr  != NULL
        if (curr->value > curr->next->value) {  // SAFETY CHECK:  curr->next != NULL
            return 0;
        }
        curr = curr->next;
    }
    return 1;
} 

struct node *delete_from_list(struct node *list, int n) {
   struct node *cur, *prev;
   for (cur = list, prev = NULL;
        cur != NULL ;
        prev = cur, cur = cur->next) {
       if (cur->value == n) {
           if (prev == NULL)
               list = list->next; /* n is in the first node */
           else
               prev->next = cur->next; /* n is in some other node */
           free(cur);
           break;
       }
   }
   return list;
}
//DONE  tested, passed
struct node *deleteAll(struct node *list, int n)
{
   struct node *cur, *prev;
   for (cur = list, prev = NULL; cur != NULL; cur = cur->next) {
       if (cur->value == n) {
           if (prev == NULL)
               list = list->next; /* n is in the first node */
           else
                 prev->next = cur->next; /* n is in some other node */
           free(cur);
       }
       else
         prev = cur;
   }
   return list;
}
//tested, passed
struct node *doubleAll(struct node *list)
{
   struct node *cur, *new_node;
   for (cur = list;cur != NULL ; cur = cur->next) {
    new_node = malloc(sizeof(struct node)); //allocate memory for new structure;
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = cur->value; //copy values over
    new_node->next = cur->next; //copy pointers over
    cur->next = new_node; //repoint the next
    cur = cur->next;  //assignnet before the iterator does it, will be at this new spot if not.
   }
   return list;
}
//DONE tested!
void MoveNode(struct node** destRef, struct node** sourceRef)
{
  /* the front source node  */
  struct node* newNode = *sourceRef;
  assert(newNode != NULL);
  /* Advance the source pointer */
  *sourceRef = newNode->next;
  /* Link the old dest off the new node */
  newNode->next = *destRef; 
  /* Move dest to point to the new node */
  *destRef = newNode;
}
//DONE! tested
struct node* merge(struct node* a, struct node* b) 
{
   /* a dummy first node to hang the result on */   
   struct node dummy;      
    
   /* tail points to the last result node  */
   struct node* tail = &dummy;  
 
   /* so tail->next is the place to add new nodes 
     to the result. */
   dummy.next = NULL;
   while(1) 
   {
      if(a == NULL) 
      { 
         /* if either list runs out, use the other list */
         tail->next = b;
         break;
      }
      else if (b == NULL) 
      {
         tail->next = a;
         break;
      }
      if (a->value <= b->value) 
      { 
         MoveNode(&(tail->next), &a);
      }
      else
     {
        MoveNode(&(tail->next), &b);
     }
     tail = tail->next;
  }
  return(dummy.next);
}  
//TESTED, passes
int nodupdata(struct node *list)
{
  if(list == NULL)
    return 0;
  struct node *cur, *digging;
  int currentIndex, diggingIndex;
  for (cur = list; cur != NULL ; cur = cur->next) 
  {
     for(digging = cur->next; digging != NULL; digging = digging->next)
        if(cur->value == digging->value)
          return 1;
   }
  return 0;
}

//DONE not tested//////////////////////////////////NOT WORKING///NOT WORKING///NOT WORKING///NOT WORKING///NOT WORKING///NOT WORKING///NOT WORKING///NOT WORKING///NOT WORKING///NOT WORKING
int looplesslength(struct node *list)
{
  if(list == NULL)
    return 0;
  int index = 0;  
  int ovrLpCtr = 0; //overlap loop control to determine if circular at any point.
  struct node *head, *slow, *fast;
  slow = list;
  head = list;
  fast = list->next;
  while(1)
  {
    if(ovrLpCtr == 0)
    {
      if(slow == NULL)//base case, not circular
        return index;
      if(slow == fast) //it is in fact circular.
      {
        ovrLpCtr++;
        index = 0;//we must reset it.
        printf("This is circular!!\n");
      }
      index += 1;  
      slow = slow->next; //iterate once each loop
      if(fast->next != NULL && fast->next->next != NULL) //iterate twice if we can
         fast = fast->next->next; 
       else if(fast!= list) //if we cant assign it/ we know its not circular so we can ignore it and get rid of the slow==fast conditional;
         fast = list;  
    } 
    else if(ovrLpCtr == 1)
    {
      slow = slow->next;
      if(slow == head)
      {
        ovrLpCtr++;
        slow = slow->next;
      }
      else if(slow == fast)
      {
        head = head->next;
        index++;
      }
    }
    else if(ovrLpCtr == 2)
    {
      if(slow == head)
      {
          index = index *-1; //turn negative and return.
          return index;
      }
      else
      {
        slow = slow->next;
        index++;
      }
    }
  }
  return index;
}
