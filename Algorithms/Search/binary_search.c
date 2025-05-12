#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool binary_search(int *haystack, int needle, size_t size);

int main(int argc, char *argv[]) {
  int arr[] = {1,2,3,4,5,6};
  int needle = 4;

  if (binary_search(arr, needle, sizeof(arr) / sizeof(arr[0]))) {
    printf("Found");
  } else
    printf("Not\n");

  return 0;
}

bool binary_search(int *haystack, int needle, size_t size) {
  int low = 0;
  int high = size;

  do {
    int middle = floor(low + (high - low) / 2);
    int value = haystack[middle];
    if (needle == value)
      return true;
    else if (value < needle)
      low = middle + 1;
    else
      high = middle;
  } while (low < high);
  return false;
}
