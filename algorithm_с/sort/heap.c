#include "sor.h"

#define LEFT i<<1
#define RIGHT (i<<1)+1

void maxHeapify(int arr[], int N, int i) {
  int l = LEFT;
  int r = RIGHT;
  int largest;
  if (l <= N && arr[l] > arr[i])
    largest = l;
  else
    largest = i;
  if (r <= N && arr[r] > arr[largest])
    largest = r;
  if (largest != i) {
    swap(&arr[largest], &arr[i]);
    maxHeapify(arr, N, largest);
  }
}

void buildMaxHeap(int arr[], int n) {
  for (int i = n / 2; i > 0; --i)
    maxHeapify(arr, n, i);
}

void heapsort(int arr[], int n) {
  buildMaxHeap(arr, n);
  for (int i = n; i > 1; --i) {
    swap(&arr[1], &arr[i]);
    n--;
    maxHeapify(arr, n, 1);
  }
}

void heapR() {
  int arr[] = {1, 4, 2, 13, 22, 10, 90, 33, 22, 88};
  heapsort(arr, 9);
  int n = sizeof(arr) / sizeof(arr[0]);
  printArray(arr, n);
}