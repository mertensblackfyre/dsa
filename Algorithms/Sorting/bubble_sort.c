#include <stdbool.h>
#include <stddef.h>

#include <stdio.h>

void bubble_sort(int *arr, size_t size);

int main(int argc, char *argv[]) {
  int arr[] = {22, 33, 53, 1, 12, 55, 90, 2, 8, 21, 87, 99, 102, 23};

  bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
  return 0;
}

void bubble_sort(int *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    for (size_t j = i + 1; j < size; j++) {
      if (array[i] > array[j]) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}
