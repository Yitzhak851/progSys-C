#include <stdio.h>

/*** allocate memory for vector object (incl. array) ***/
struct vector* newVector(int len);
/*** free all memory allocated by vector object ***/
void freeVector(struct vector* v);
/*** set one vector element ***/
int setVectorElement(struct vector* v, int ind, float val);
/*** set a block of vector elements ***/
int setVectorBlock (struct vector* v,int startInd, int numElements, float* source);
/*** return one vector element ***/
float getVectorElement(struct vector* v, int ind);
/*** compute sum of vector entries ***/
float sumVector(struct vector* v);
/*** print vector entries ***/
void printVector(struct vector* v);

struct vector {
        int length; // fields of this structure type
        float* values; // fields of this structure type
} Vector_st;
typedef Vector_st* Vector;

/*** Constructor ***/
Vector newVector(int len) {
        Vector v;
        if(len <= 0){
                 return NULL; // canot create vector length 0
        }
        // i want to take some block and insert values
        v = malloc(sizeof(Vector_st));
        if(!v) {
                return NULL;
        }
        // i want to insert in this adrees the next value
        v->values = malloc(len*sizeof(float));
        // i have to check that the __ succseed
        if(!v->values) {
                free(v);
                return NULL;
        }
        // just need to initional length
        v->length = len;
        return v;
}

void freeVector(Vector v) {
        free(v->values);
        free(v);
}

float getVectorElement(Vector v, int ind) {
        if(ind<0 || ind >= v->length) {
                return 0.0;
        }
        return v->values[ind];
}

int setVectorElement(Vector v, int ind, float val) {
        if(ind<0 || ind >= v->length){
                return 0;
        }
        v->values[ind] = val;
        return 1;
}

int setVectorBlock (Vector v, int startInd, int numElements, float* source) {
        int ind;
        if(startInd < 0 || numElements < 0 || startInd + numElements > v->length){
                return 0;
        }
        for(ind=startInd; ind < startInd+numElements; ind++) {
                v->values[ind] = source[ind - startInd];
        }
        return 1;
}

float vectorSum(Vector v) {
        int i;
        float sum=0;
        for(i=0; i<v->length; i++) {
                sum += v->values[i];
        }
        return sum;
}

void vectorPrint(Vector v) {
        int i;
        printf("[");
        for(i=0; i<v->length; i++) {
            printf(" %.3f",v->values[i]); /*** 3 decimal places ***/
        }
        printf(" ]");
}
