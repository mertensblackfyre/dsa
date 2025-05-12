#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool linear_search(int *haystack, int needle, size_t size);

int main(int argc, char *argv[]) {
  int arr[] = {22, 33, 53, 1, 12, 55, 90};
  int needle = 19;

  if (linear_search(arr, needle, sizeof(arr) / sizeof(arr[0]))) {
    printf("Found");
  } else
    printf("Not\n");

  return 0;
}

bool linear_search(int *haystack, int needle, size_t size) {
  for (size_t i = 0; i < size; i++) {
    if (haystack[i] == needle) {
      return true;
    }
  }
  return false;
}
