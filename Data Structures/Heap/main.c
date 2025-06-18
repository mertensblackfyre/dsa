
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

typedef struct Heap {
  int data[20];
  size_t size;
} Heap;

int push(int value, Heap *data);
void print(Heap *data);
int main() {

  Heap *data = malloc(sizeof(Heap));
  data->size = 1;
  push(16, data);
  push(21, data);
  push(26, data);
  push(14, data);
  push(19, data);

  print(data);
  return 0;
}

void print(Heap *data) {
  for (size_t i = 0; i < data->size; i++) {
    printf("%d -> ", data->data[i]);
  };

  printf("\n");
};
int push(int value, Heap *data) {
  data->data[data->size++] = value;

  int i = data->size;
  int parent = floor(i / 2);
  while (data->data[i] < data->data[parent]) {
    if (data->data[parent] == 0 || data->data[i] == 0) {
      break;
    }
    int tmp = data->data[i];
    data->data[i] = data->data[parent];
    data->data[parent] = tmp;

    i = floor(i / 2);
    parent = floor(i / 2);
  };

  return 1;
};
