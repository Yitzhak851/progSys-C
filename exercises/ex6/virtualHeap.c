/**************************************
*  Source file for the virtual heap
*  code module which records all memory
*  allocation operations
**************************************/
#include <stdio.h>
#include <stdlib.h>
#include "virtualHeap.h"

/*************************************/
/**       SYMBOLIC CONSTANTS        **/
/*************************************/
#define MAX_ALLOCATED_BLOCKS         10000
#define DEFAULT_MAX_ALLOCATED_BYTES  10000

/*************************************/
/**          TYPE DEFINITIONS       **/
/*************************************/
typedef struct {
   void* address;
   int numBytes;
} AllocatedBlocks;

/*************************************/
/**         GLOBAL VARIABLES        **/
/*************************************/
/*** number of successfully allocated bytes ***/
int numAllocatedBytes  = 0;
/*** number of successfully allocated blocks ***/
int numAllocatedBlocks = 0;
/*** max size of "virtual heap" ***/
int maxAllocatedBytes  = DEFAULT_MAX_ALLOCATED_BYTES;
/*** array of allocated blocks - start address and size ***/
AllocatedBlocks allocatedBlocks[MAX_ALLOCATED_BLOCKS];


/*************************************/
/**      FUNCTION  DEFINITIONS      **/
/*************************************/

/*** memory allocation function ***/
void* ourMalloc(int numBytes) {
   if(numAllocatedBytes + numBytes > maxAllocatedBytes) {
#ifdef PRINT_MESSAGES
      printf("Virtual heap: Allocation of %d additional bytes will exceed max number of allowed allocated bytes - %d\n", numBytes, maxAllocatedBytes);
#endif
      return NULL;
   }
   if(numAllocatedBlocks + 1 > MAX_ALLOCATED_BLOCKS) {
#ifdef PRINT_MESSAGES
      printf("Virtual heap: ourMalloc() tries to exceed max number of allocated blocks - %d\n", MAX_ALLOCATED_BLOCKS);
#endif
      return NULL;
   }
   allocatedBlocks[numAllocatedBlocks].address = malloc(numBytes);
   if(!allocatedBlocks[numAllocatedBlocks].address) {
#ifdef PRINT_MESSAGES
      printf("Virtual heap: malloc failed when current allocation size is %d bytes and asking for %d additional bytes\n", numAllocatedBytes, numBytes);
#endif
      return NULL;
   }
   allocatedBlocks[numAllocatedBlocks].numBytes = numBytes;
   numAllocatedBlocks++;
   numAllocatedBytes += numBytes;
#ifdef PRINT_MESSAGES
   printf("Virtual heap: successfully allocated block of size %d bytes.\n", numBytes);
#endif

   return allocatedBlocks[numAllocatedBlocks-1].address;
}

/*** memory re-allocation function ***/
void* ourRealloc(void* original_block, int numBytes) {
   int i;
   for(i=0; i<numAllocatedBlocks; i++) {
      if(allocatedBlocks[i].address == original_block) break;
   }
   if(i==numAllocatedBlocks) {
#ifdef PRINT_MESSAGES
      printf("Virtual heap: Error - trying to re-allocate starting in address %p. No such block is currently allocated.\n", original_block);
#endif
      return NULL;
   }

   /** now i is the index of the allocated block in the table **/
   if(numAllocatedBytes + numBytes - allocatedBlocks[i].numBytes > maxAllocatedBytes) {
#ifdef PRINT_MESSAGES
      printf("Virtual heap: Re-allocation of block starting in address %p from size %d to %d will exceed max number of allowed allocated bytes - %d\n" ,
               original_block, allocatedBlocks[i].numBytes, numBytes, maxAllocatedBytes);
#endif
      return NULL;
   }

   allocatedBlocks[i].address = realloc(original_block,numBytes);
   if(!allocatedBlocks[i].address) {
#ifdef PRINT_MESSAGES
      printf("Virtual heap: realloc failed when current allocation size is %d bytes and asking for %d additional bytes\n",
                numAllocatedBytes, numBytes-allocatedBlocks[i].numBytes);
#endif
      return NULL;
   }
#ifdef PRINT_MESSAGES
   printf("Virtual heap: successfully re-allocated block from size %d bytes to size %d bytes.\n", allocatedBlocks[i].numBytes, numBytes);
#endif
   numAllocatedBytes += numBytes - allocatedBlocks[i].numBytes;
   allocatedBlocks[i].numBytes = numBytes;

   return allocatedBlocks[i].address;
}

/*** memory freeing function ***/
void ourFree(void* ptr) {
   int i;
   for(i=0; i<numAllocatedBlocks; i++) {
      if(allocatedBlocks[i].address == ptr) break;
   }
   if(i==numAllocatedBlocks) {
      /** always print this **/
      printf("Virtual heap: Error - cannot free block starting in address %p. No such block is currently allocated.\n", ptr);
      return;
   }
   free(ptr);
#ifdef PRINT_MESSAGES
   printf("Virtual heap: successfully freed block of size %d bytes.\n", allocatedBlocks[i].numBytes);
#endif

   numAllocatedBlocks--;
   numAllocatedBytes -= allocatedBlocks[i].numBytes;
   allocatedBlocks[i] = allocatedBlocks[numAllocatedBlocks];
   allocatedBlocks[numAllocatedBlocks].address =  NULL;
   allocatedBlocks[numAllocatedBlocks].numBytes =  0;
}

/*** free all resources allocated by virtual heap ***/
void freeAll() {
   while(numAllocatedBlocks>0) {
      ourFree(allocatedBlocks[numAllocatedBlocks-1].address);
   }
}

/*** returns bound on number of bytes user can allocate ***/
int getMaxBytes() {
   return maxAllocatedBytes;
}

/*** set bound on number of bytes user can allocate ***/
void setMaxBytes(int maxBytes) {
   if(maxBytes < numAllocatedBytes) {
      /*** always print this ***/
      printf("Virtual heap: Error - trying to reduce max number of allocated bytes to %d when virtual heap has %d allocated bytes\n", maxBytes, numAllocatedBytes);
      return;
   }
   maxAllocatedBytes = maxBytes;
}


/*** returns number of allocated bytes ***/
int getNumAllocatedBytes() {
   return numAllocatedBytes;
}


/*** returns number of allocated blocks of memory ***/
int getNumAllocatedBlocks() {
   return numAllocatedBlocks;
}