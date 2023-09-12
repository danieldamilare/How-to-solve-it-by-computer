#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partitionHoare(int arr[], int low, int high, int pivot) {
  int left = low;
  int right = high;

  while (left <= right) {
    while (arr[left] < pivot) {
      left++;
    }

    while (arr[right] > pivot) {
      right--;
    }

    if (left <= right) {
      swap(&arr[left], &arr[right]);
      left++;
      right--;
    }
  }

  return left;
}

int quickselect(int arr[], int low, int high, int k) {
  if (low == high) {
    return arr[low];
  }

  int pivot = arr[low];
  int pi = partitionHoare(arr, low, high, pivot);

  if (pi == k) {
    return arr[pi];
  } else if (pi < k) {
    return quickselect(arr, pi + 1, high, k);
  } else {
    return quickselect(arr, low, pi - 1, k);
  }
}

int main() {
  int arr[] =  {3, 5, 1, 12, 7, 2, 0};

  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;

  int smallest = quickselect(arr, 0, n - 1, k-1);
  printf("The %dth smallest element is: %d\n", k, smallest);

  return 0;
}
