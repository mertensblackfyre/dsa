#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *arr, size_t size);
void print(int *arr, size_t size);
void swap(int *a, int *b);

int main(int argc, char *argv[]) {
  // int arr[] = {7, 5, 2, 1, 4, 6, 3};

  int arr[] = {33, 12, 211, 94, 1};
  quick_sort(arr, sizeof(arr) / sizeof(arr[0]));
  print(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void quick_sort(int *array, size_t size) {

  if (array == NULL || size < 2) {
    return;
  }

  if (size == 2) {
    if (array[0] > array[1])
      swap(&array[0], &array[1]);
    return;
  }

  int pivot = array[0];

  int *left = malloc(sizeof(int) * size);
  int *right = malloc(sizeof(int) * size);

  if (right == NULL || left == NULL) {
    perror("Failed allocation");
    return;
  }

  int ls = 0, rs = 0;
  int *lp, *rp;
  lp = &left[0];
  rp = &right[0];

  for (int i = 1; i < size; ++i) {
    if (pivot > array[i]) {
      *lp++ = array[i];
      ls++;
    } else {
      *rp++ = array[i];
      rs++;
    }
  }

  quick_sort(left, ls);
  quick_sort(right, rs);
  int i = 0;
  for (int j = 0; j < ls; j++)
    array[i++] = left[j]; 
  array[i++] = pivot;    
  for (int j = 0; j < rs; j++)
    array[i++] = right[j]; 
  free(left);
  free(right);
};

void print(int *arr, size_t size) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == 0) {
      continue;
    }
    printf("%i,", arr[i]);
  }
  printf("\n");
}
