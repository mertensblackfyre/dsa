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

void push(int value, Heap *data);
void print(Heap *data);

void pop(Heap *data);
Tuple *min(int *lchild, int *rchild, int lpos, int rpos);

int main() {
  Heap *data = malloc(sizeof(Heap));
  data->size = 1;
  push(16, data);
  push(21, data);
  push(14, data);
  push(19, data);
  push(26, data);
  push(19, data);

  push(68, data);
  push(65, data);
  push(30, data);

  pop(data);

  print(data);
  return 0;
}

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

  int i = data->size - 1;
  while (data->data[i] < data->data[i / 2]) {
    int tmp = data->data[i];
    data->data[i] = data->data[i / 2];
    data->data[i / 2] = tmp;

    i = i / 2;
  };
};

Tuple *min(int *lchild, int *rchild, int lpos, int rpos) {
  Tuple *t = malloc(sizeof(Tuple));
  if (lchild <= rchild) {
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

  data->data[1] = data->data[data->size - 1];
  data->data[data->size - 1] = 0;

  Tuple *min_tupe =
      min(&data->data[lchild], &data->data[rchild], lchild, rchild);
  while (*min_tupe->min <= data->data[i]) {
    int tmp = *min_tupe->min;
    *min_tupe->min = data->data[i];
    data->data[i] = tmp;
 
/*
    i = min_tupe->pos;

    lchild = 2 * i;
    rchild = 2 * i + 1;
    min_tupe = min(&data->data[lchild], &data->data[rchild], lchild, rchild);
  */
    }
};
