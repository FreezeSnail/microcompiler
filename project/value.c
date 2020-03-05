#include <stdio.h>                      

#include "memory.h"                     
#include "value.h"                      

void initValueArray(ValueArray* array) {
  array->values = NULL;                 
  array->capacity = 0;                  
  array->count = 0;                     
}     

void writeValueArray(ValueArray* array, int value) {       
  if (array->capacity < array->count + 1) {                  
    int oldCapacity = array->capacity;                       
    array->capacity = GROW_CAPACITY(oldCapacity);            
    array->values = GROW_ARRAY(array->values, int,         
                               oldCapacity, array->capacity);
  }

  array->values[array->count] = value;                       
  array->count++;                                            
}   


void freeValueArray(ValueArray* array) {            
  FREE_ARRAY(int, array->values, array->capacity);
  initValueArray(array);                            
}  

void printValue(int value) {
  printf("%d", value);        
}  