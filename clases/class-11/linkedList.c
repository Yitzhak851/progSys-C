/************************************
*  linkedList.c                     *
*  ~~~~~~~~~~~~                     *
*  Implementation of linked list    *
*  data structure                   *
************************************/
#include "/share/classes/class11/linkedList.h"
#include <stdlib.h>
#include <stdio.h>
// adding comment and test git push command with git bash at windows

/************************************
*    TYPE DEFINITIONS               *
************************************/

/*** struct type is "privately" defined
     in source file and not in header
***/
struct listNode {
   Data data;
   ListNode next;
};

/************************************
*    FUNCTION DEFINITIONS           *
************************************/

/***********************************************************
  getNext
  returns next list node
  param
  - listNode - ListNode object
  return
  - next ListNode object
***********************************************************/
ListNode getNext (ListNode listNode) {
   return listNode->next;
}
/***********************************************************
  getData
  returns data of list node
  param
  - listNode - ListNode object
  return
  - data for list node
***********************************************************/
Data getData (ListNode listNode) {
   return listNode->data;
}


/***********************************************************
  newListNode
  creates new list node sith given data (allocation of node struct)
  param
  - val - data to initialize node with
  return
  - newly allocated list node, or NULL if allocation is not
        successful.
        Newly created node is a list of length 1 (next==NULL)
***********************************************************/
ListNode newListNode (Data val) {
   ListNode newElement = malloc (sizeof (struct listNode));

   /*** set structure members ***/
   if (newElement) {
      newElement->data = val;
      newElement->next = NULL;
   }

   /*** return NULL if allocation failed ***/
   return newElement;
}

/***********************************************************
  freeList
  frees all memory allocated by list nodes in list
  param
  - head - head of list
  return
  - void
***********************************************************/
void freeList (ListNode head) {
   ListNode curr = head, prev = NULL;

   while (curr) {
      prev = curr;
      curr = curr->next;
      free(prev);
   }
}

/***********************************************************
  listLength
  returns number of nodes in linked list starting from head
  param
  - head - list node where counting should start
  return
  - number of nodes downstream of head node (until next==NULL)
***********************************************************/
int listLength (ListNode head) {
   int count=0;
   /*** scan list until end (next==NULL) ***/
   while(head) {
      head = head->next;
      count++;
   }
   return count;
}

/***********************************************************
  listNodeFind
  finds node that holds given data value
  param
  - head - list node where searching should start
  return
  - list node downstream of head whose data is equal to given data,
    or NULL if no downstream node has data value
***********************************************************/
ListNode listNodeFind (ListNode head, Data val) {
   while (head) {
      if (head->data == val)
         return head;
      head = head->next;
   }
   /*** reach here only if val was not found ***/
   return NULL;
}

/***********************************************************
  listNodeInsert
  inserts single node into list in given place
  param
  - listNode   - node in list, after which insertion takes place
  - singleNode - node (list of length 1) to insert after listNode
  return
  - 1 if insertsion is successful
        0 if one of the given nodes is NULL
          or if singleNode has nodes donwstream of it.
***********************************************************/
int listNodeInsert (ListNode listNode, ListNode singleNode) {
   /*** Used in online questionnaire for Lecture #11 ***/
   if (!listNode || !singleNode || singleNode->next)
      return 0;

   singleNode->next = listNode->next;
   listNode->next = singleNode;

   return 1;
}

/***********************************************************
  listNodeSplit
  splits list after given list node
  param
  - listNode - node in list, after which list is to be split
  return
  - list node that was after given node in list
    (head of new list), or NULL if input is NULL
***********************************************************/
ListNode listSplit (ListNode listNode) {
   /*** Used in online questionnaire for Lecture #11 ***/
   ListNode nextNode;

   if(!listNode) return NULL;
   nextNode = listNode->next;
   listNode->next = NULL;
   return nextNode;
}

/***********************************************************
  listConcat
  concatenates two lists
  param
  - list1 - linked list
  - list2 - linked list
  return
  - if list1 is not empty, connects tail of list1 to head
    of list2 and returns head of concatenated list
  - if list1 is empty, returns list2
***********************************************************/
ListNode listConcat (ListNode list1, ListNode list2) {
   ListNode listNode = list1;

   /*** if list1 is empty, return list2 ***/
   if(!listNode) return list2;

   /*** find tail node of list1 ***/
   while(listNode->next)
      listNode = listNode->next;

   /*** connect tail node of list1 to head of list2 ***/
   listNode->next = list2;
   return list1;
}

/***********************************************************
  listNodeDisconnect
  removes node from list downstream of given head
  param
  - head       - head node of given list
  - listNode   - node downstream of head to be removed from list
  return
  - 1 if removal is successful
        0 if one of the given nodes is NULL
      or if listNode is not downstream of head
***********************************************************/
int listNodeDisconnect (ListNode head, ListNode listNode) {
   ListNode curr = head, prev = NULL;

   /*** scan list, keeping pointer to previous node ***/
   while (curr != NULL && curr != listNode) {
      prev = curr;
      curr = curr->next;
   }

   /*** here is where we check input ***/
   /*** why do we check prev here?   ***/
   if (!curr || !prev) return 0;

   /*** disconnect ***/
   prev->next = curr->next;
   curr->next = NULL;

   return 1;
}

