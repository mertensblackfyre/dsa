#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

typedef struct Tuple {
  int *min;
  int pos;
} Tuple;

typedef struct Heap {
  int data[N];
  size_t size;
} Heap;

void heapify(Heap *data);
void top(Heap *data);
void push(int value, Heap *data);
void print(Heap *data);
void pop(Heap *data);
Tuple *min(int *lchild, int *rchild, int lpos, int rpos);

int main() {

  Heap *data = malloc(sizeof(Heap));

  int arr[] = {60, 50, 80, 40, 30, 10, 70, 20, 90};

 // data->data
  /*
    data->size = 1;
    data->data[0] = 0;


    push(16, data);
    push(21, data);
    push(14, data);

    push(19, data);
    push(26, data);
    push(19, data);

    push(68, data);
    push(65, data);
    push(30, data);

    // OUTPUT: 14 -> 19 -> 16 -> 21 -> 26 -> 19 -> 68 -> 65 -> 30 ->
    printf("Before pop()\n");
    print(data);

    pop(data);

    // OUTPUT: 19 -> 16 -> 21 -> 26 -> 19 -> 68 -> 65 -> 30 ->
    printf("After pop()\n");
    print(data);
    */
  return 0;
}

void top(Heap *data) {
  if (data->data[1] == 0)
    return;
  printf("%d\n", data->data[1]);
  return;
};

void print(Heap *data) {
  for (size_t i = 0; i < data->size; i++) {
    if (data->data[i] == 0)
      continue;
    printf("%d -> ", data->data[i]);
  };
  printf("\n");
};

void push(int value, Heap *data) {

  data->data[data->size++] = value;
  int i = data->size;
  while (data->data[i] < data->data[i / 2]) {
    if (data->data[i] == 0) {
      i = i / 2;
      continue;
    }
    int tmp = data->data[i];
    data->data[i] = data->data[i / 2];
    data->data[i / 2] = tmp;

    i = i / 2;
  };
};

Tuple *min(int *lchild, int *rchild, int lpos, int rpos) {
  Tuple *t = malloc(sizeof(Tuple));

  if (t == NULL) {
    printf("Error in alloaction");
    return t;
  };

  if (!*lchild || !*rchild) {
    printf("Error in finding the min\n");
    return t;
  }
  if (*lchild <= *rchild) {
    t->min = lchild;
    t->pos = lpos;
  } else {
    t->min = rchild;
    t->pos = rpos;
  }
  return t;
};

void pop(Heap *data) {
  if (data->size == 0)
    return;

  int i = 1;
  int lchild = 2 * i;
  int rchild = 2 * i + 1;

  data->data[1] = data->data[data->size];
  data->data[data->size] = 0;

  Tuple *min_tupe =
      min(&data->data[lchild], &data->data[rchild], lchild, rchild);

  if (min_tupe->min == NULL) {
    printf("Error in min function 2\n");
    return;
  };

  while (*min_tupe->min <= data->data[i]) {
    if (&data->data[lchild] == 0 || &data->data[rchild] == 0)
      break;

    int tmp = *min_tupe->min;
    *min_tupe->min = data->data[i];
    data->data[i] = tmp;

    i = min_tupe->pos;
    lchild = 2 * i;
    rchild = 2 * i + 1;
    min_tupe = min(&data->data[lchild], &data->data[rchild], lchild, rchild);
  };
  return;
};

void heapify(Heap *data) {

};
