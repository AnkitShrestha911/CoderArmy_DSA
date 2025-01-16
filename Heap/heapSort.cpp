#include <bits/stdc++.h>
using namespace std;

/**
 * Step 1: convert into max heap using step down approach
 * Step 2: swap first and last
 * Step 3: now heapify from start to size - 1
 * Step 4: next time replaced with size - 2 and heapify from start to size - 3
 *
 */

// Recursive approach
void heapify(int arr[], int index, int size) {
    int leftChild = (index * 2) + 1;
    int rightChild = (index * 2) + 2;
    int maxIndex = index;

    if (leftChild < size && arr[leftChild] > arr[maxIndex]) {
        maxIndex = leftChild;
    }

    if (rightChild < size && arr[rightChild] > arr[maxIndex]) {
        maxIndex = rightChild;
    }

    if (maxIndex != index) {
        swap(arr[maxIndex], arr[index]);
        heapify(arr, maxIndex, size);
    }
}

//Iterative approach 
void heapify_iterative(int arr[], int index, int size) {
    int maxIndex = index;

    while (maxIndex < size) {
        int leftChild = (maxIndex * 2) + 1;
        int rightChild = (maxIndex * 2) + 2;

        if (leftChild < size && arr[leftChild] > arr[maxIndex]) {
            maxIndex = leftChild;
        }

        if (rightChild < size && arr[rightChild] > arr[maxIndex]) {
            maxIndex = rightChild;
        }

        if (maxIndex != index) {
            swap(arr[maxIndex], arr[index]);
            index = maxIndex;
        } else {
            break;
        }
    }
}

// Time: O(n)
void buildMaxHeap(int arr[], int size) {
    for (int i = (size - 1) / 2; i >= 0; i--) {
        heapify(arr, i, size);
    }
}

// Time: nlogn
void heapSort(int arr[], int size) {
    if (size == 0 || size == 1)
        return;

    for (int end = size - 1; end > 0; end--) {
        swap(arr[end], arr[0]);
        // heapify(arr, 0, end);
        heapify_iterative(arr, 0, end);
    }
}

void printList(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[] = {15, 17, 14, 22, 18, 12, 19, 23, 20, 24, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Without heapify\n";
    printList(arr, size);

    cout << "With heapift\n";
    buildMaxHeap(arr, size);
    printList(arr, size);

    cout << "Sorting:\n";
    heapSort(arr, size);
    printList(arr, size);

    return 0;
}