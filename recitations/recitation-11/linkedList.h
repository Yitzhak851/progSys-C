#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

/************************************
*  linkedList.h                     *
*  ~~~~~~~~~~~~                     *
*  Header file of linked list       *
*  data structure                   *
************************************/


/************************************
*    TYPE DEFINITIONS               *
************************************/

/*** public types are Data (int)
     and object type (pointer to struct.
     Note that the struct type is
     "privately" defined in source file
***/
typedef int Data;
typedef struct listNode * ListNode;

/************************************
*    FUNCTION DECLARATIONS          *
************************************/

/***********************************************************
  getNext
  returns next list node
  param
  - listNode - ListNode object
  return
  - next ListNode object
***********************************************************/
ListNode getNext (ListNode listNode);

/***********************************************************
  getData
  returns data of list node
  param
  - listNode - ListNode object
  return
  - data for list node
***********************************************************/
Data getData (ListNode listNode);

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
ListNode newListNode (Data val);

/***********************************************************
  freeList
  frees all memory allocated by list nodes in list
  param
  - head - head of list
  return
  - void
***********************************************************/
void freeList (ListNode head);

/***********************************************************
  listLength
  returns number of nodes in linked list starting from head
  param
  - head - list node where counting should start
  return
  - number of nodes downstream of head node (until next==NULL)
***********************************************************/
int listLength (ListNode head);
/***********************************************************
  listNodeFind
  finds node that holds given data value
  param
  - head - list node where searching should start
  return
  - list node downstream of head whose data is equal to given data,
    or NULL if no downstream node has data value
***********************************************************/
ListNode listNodeFind (ListNode head, Data val);

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
int listNodeInsert (ListNode listNode, ListNode singleNode);

/***********************************************************
  listNodeSplit
  splits list after given list node
  param
  - listNode - node in list, after which list is to be split
  return
  - list node that was after given node in list
    (head of new list), or NULL if input is NULL
***********************************************************/
ListNode listSplit (ListNode listNode);

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
ListNode listConcat (ListNode list1, ListNode list2);

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
int listNodeDisconnect (ListNode head, ListNode listNode);

#endif
