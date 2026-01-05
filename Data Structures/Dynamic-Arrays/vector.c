#include "vector.h"
#include <stdlib.h>

int main() {

  int *arr = vector_create(1);

  vector_push_back(5, &arr);
  vector_push_back(2, &arr);
  vector_push_back(3, &arr);
  vector_push_back(4, &arr);
  vector_push_back(12, &arr);
  vector_push_back(123, &arr);

  vector_pop_back(&arr);
  vector_pop_back(&arr);
  vector_pop_back(&arr);

  free(arr);
};

int *resize(int *array) {
  int *new_array = vector_create(tail * 2);

  for (int i = 0; i < tail; i++)
    new_array[i] = array[i];

  return new_array;
};

void vector_push_back(int value, int **__array) {

  if (tail == capcity)
    *__array = resize(*__array);

  (*__array)[tail++] = value;
};

void vector_pop_back(int **__array) {

  if (tail == 0)
    return;

  (*__array)[tail--] = 0;
}

int *vector_create(int size) {
  capcity = size;
  int *array = malloc(size * sizeof(int));
  return array;
};
