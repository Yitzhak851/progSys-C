#include <stdio.h>
#include <stdlib.h>

/**************************************
*  Source file with implementation of
*  Vector data structure, which allows
*  safe access to a float array of
*  arbitrary size
**************************************/

/*************************************/
/**         STRUCTURE  TYPE         **/
/*************************************/
typedef struct {
   int length;
   float* values;
} Vector_st;
typedef Vector_st* Vector;

/*************************************/
/**      FUNCTION  DECLARATION      **/
/*************************************/

/*** allocate memory for vector object (incl. array) ***/
Vector newVector(int len);
/*** free all memory allocated by vector object ***/
void freeVector(Vector v);
/*** set one vector element ***/
int setVectorElement(Vector v, int ind, float val);
/*** set a block of vector elements ***/
int setVectorBlock (Vector v, int startInd, int numElements, float* source);
/*** return one vector element ***/
float getVectorElement(Vector v, int ind);
/*** compute sum of vector entries ***/
float sumVector(Vector v);
/*** print vector entries ***/
void printVector(Vector v);
/*************************************/
/**      FUNCTION  DEiFINITIONS     **/
/*************************************/


/****************************************************
* Creates new vector of given size.
* Allocates space for struct and array on heap
* Returns pointer to struct, or NULL if not enough
* space
********************************************/
Vector newVector(int len) {
   Vector v;
   if(len <= 0) return NULL;

   v= malloc(sizeof(Vector_st)); /** <-- the only place where we mention the struct type and not its pointer type **/
   if(!v) return NULL;

   v->values = malloc(len*sizeof(float));
   if(!v->values) {
      free(v);
      return NULL;
   }

   v->length = len;
   return v;
}

/****************************************************
* Frees space allocated by vecotr (struct and array)
********************************************/
void freeVector(Vector v) {
   free(v->values);
   free(v);
}

/****************************************************
* Sets element of given index in vector to specified
* value.
* Returns 1 if successful, and 0 if index out of bound
********************************************/
int setVectorElement(Vector v, int ind, float val) {
   if(ind<0 || ind >= v->length) return 0;

   v->values[ind] = val;
   return 1;
}

/****************************************************
* Sets block of elements in vector to values specified
* in a given source array.
* startInd indicates the block start and numElements
* indicates the number of elements to copy
* Returns 1 if successful, and 0 if index out of bound
********************************************/
int setVectorBlock (Vector v, int startInd, int numElements, float* source) {
   int ind;
   if(startInd <0 || numElements <= 0 || startInd + numElements > v->length)
      return 0;

   for(ind=startInd; ind < startInd+numElements; ind++) {
     v->values[ind] = source[ind - startInd];
   }
   return 1;
}

/****************************************************
* Returns value of vector element of given index.
* If indeex is out of bound, return 0.
********************************************/
float getVectorElement(Vector v, int ind) {

   if(ind<0 || ind >= v->length) return 0.0;
   return v->values[ind];
}

/****************************************************
* Returns sum of vector elements
********************************************/
float vectorSum(Vector v) {
   int i;
   float sum=0;
   for(i=0; i<v->length; i++) {
      sum += v->values[i];
   }
   return sum;
}

/****************************************************
* Prints all vector elements in the following format:
* [ <e1> <e2> <e3> .... <en> ]
* with 3 digits after decimal point and no newline
********************************************/
void printVector(Vector v) {
   int i;
   printf("[");
   for(i=0; i<v->length; i++) {
      printf(" %.3f",v->values[i]);
   }
   printf(" ]");
}

/****************************************************
* main function for testing
********************************************/
int main() {
   Vector v1, v2, v3;
   /*** vals = { 1.0 , 0.0 , 0.0 , ... , 0.0 }***/
   float vals[100] = {1.0};
   int i;
   /*** set vals[i] = 1 / 2^i ***/
   for (i=1; i< sizeof(vals)/ sizeof(vals[0]); i++) {
      vals[i] = 0.5 * vals[i-1];
   }

   v1 = newVector(5);
   if(!v1) {
      printf("Out of memory\n");
      return 1;
   }
   v2 = newVector(3);
   if(!v2) {
      printf("Out of memory\n");
      freeVector(v1);
      return 1;
   }

   /*** Initialize the valuse of v1 to:
        0.5 , 0.25 , 0.125 , 0.0625 , 0.03125            ***/
   setVectorBlock(v1, 0, v1->length, vals+1);

   /*** Initialize the valuse of v2 to:
        0.25 ; 0.125 ; 0.0625            ***/
   setVectorBlock(v2, 0, v2->length, vals+2);

   printf("v1 = ");     printVector(v1);   printf("\n");
   printf("v2 = ");     printVector(v2);   printf("\n");

   /*** create a new vector object v3 that is a concatenation
        of vectors v1 and v2  (several lines of code)    ***/

   /*** write your code above this line                   ***/
   printf("v3 = ");     printVector(v3);   printf("\n");

   freeVector(v1);
   freeVector(v2);
   freeVector(v3);

   return 0;
}




