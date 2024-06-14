#ifndef VIRTUAL_HEAP_H_
#define VIRTUAL_HEAP_H_

/**************************************
*  Header file for the virtual heap
*  code module which records all memory
*  allocation operations.
*--------------------------------------
*  In HW #6 use only these functions
*  to allocate/free memory:
*  - ourMalloc()
*  - ourRealloc()
*  - ourFree()
**************************************/

/*************************************/
/**      FUNCTION  DECLARATION      **/
/*************************************/

/*** memory allocation function ***/
void* ourMalloc(int numBytes);

/*** memory re-allocation function ***/
void* ourRealloc(void* original_block, int numBytes);

/*** memory freeing function ***/
void ourFree(void* ptr);

/*** free all resources allocated by virtual heap ***/
void freeAll();

/*** returns bound on number of bytes user can allocate ***/
int getMaxBytes();

/*** set bound on number of bytes user can allocate ***/
void setMaxBytes(int maxBytes);

/*** returns number of allocated bytes ***/
int getNumAllocatedBytes();

/*** returns number of allocated blocks of memory ***/
int getNumAllocatedBlocks();

#endif
