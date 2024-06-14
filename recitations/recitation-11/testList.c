/************************************
*  testlistList.c                   *
*  ~~~~~~~~~~~~~~                   *
*  Testing linked list functionality*
************************************/
#include "linkedList.h"
#include <stdio.h>
/************************************
*    FUNCTION DEFINITIONS           *
************************************/



/***********************************************************
  main
  ~~~~
  testing linked list insertion and disconnect
***********************************************************/
int main () {
   ListNode head, listNode, newNode;
   int data[] = {1, 7, 3, 5, 2, 4, 3, 7};
   int dataSize = sizeof(data) / sizeof(int);
   int i, exitCode;

   newNode = newListNode(data[0]);
   if(!newNode) {
      fprintf(stderr, "Out of memory\n");
      return 1;
   }
   head = newNode;
   /*** create sorted list of values ***/
   exitCode = 0;
   for(i=1; i<dataSize; i++) {
      printf("Inserting %d ",data[i]);
      newNode = newListNode(data[i]);
      if(!newNode) {
         fprintf(stderr, "Out of memory\n");
         exitCode = 1;
         break;
      }
      if(getData(newNode)< getData(head)) {
         /*** if value smaller than first value, replace head ***/
         printf("as new head. ");
         listConcat(newNode, head);
         head = newNode;
      } else {
         /*** otherwise, find correct place and insert new node ***/
         listNode = head;
         while(getNext(listNode) && getData(getNext(listNode)) <= getData(newNode)) {
            listNode = getNext(listNode);
         }
         printf(" after %d. ", getData(listNode));
         listNodeInsert(listNode,newNode);
      }
      printf("Sorted numbers: ");
      for(listNode=head; listNode!=NULL; listNode=getNext(listNode)) {
         printf(" %d",getData(listNode));
      } // end of for(listNode)
      printf("\n");
   } // end of for(i)

   /*** free all list ***/
   freeList(head);
   return exitCode;
}
