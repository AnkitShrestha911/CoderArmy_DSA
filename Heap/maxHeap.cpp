#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    int size;
    int total_size;
    int* list;

public:
    MaxHeap(int size) {
        this->list = new int[size];
        this->size = 0;
        this->total_size = size;
    }

    void insert(int data) {
        if (size == total_size) {
            cout << "OverFlow\n";
            return;
        }

        list[size] = data;
        int index = size;
        size++;

        while (index > 0 && list[index] > list[(index - 1) / 2]) {
            swap(list[(index - 1) / 2], list[index]);
            index = (index - 1) / 2;
        }

        cout << data << " is inserted into the heap\n";
    }

    void heapify(int index) {
        int maxIndex = index;
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        if (left < size && list[left] > list[maxIndex]) {
            maxIndex = left;
        }

        if (right < size && list[right] > list[maxIndex]) {
            maxIndex = right;
        }

        if (maxIndex != index) {
            swap(list[index], list[maxIndex]);
            heapify(maxIndex);
        }
    }

    void deleteHeap() {
        // coderarmy tutorial code
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        cout << list[0] << " is deleted from heap\n";
        list[0] = list[size - 1];
        size--;

        if (size == 0) {
            return;
        }

        heapify(0); // heapify means take the first data and placed it to the
                    // correct position

        /*

        Myself -> iterative way

          if (size == 0) {
              cout << "Heap is empty\n";
              return;
          }

          list[0] = list[size - 1];
          int index = 0;
          int maxIndex = -1;

          while (index < size) {
              int leftChildIndex = (index * 2) + 1;
              int rightChildIndex = (index * 2) + 2;
              if (leftChildIndex >= size && rightChildIndex >= size) {
                  break;
              }
              if (leftChildIndex < size && rightChildIndex > size) {
                  maxIndex =
                      list[leftChildIndex] > list[index] ? leftChildIndex :
        index;
              }

              if (rightChildIndex < size && leftChildIndex > size) {
                  maxIndex = list[rightChildIndex] > list[index] ?
        rightChildIndex : index;
              }

              if (leftChildIndex < size && rightChildIndex < size) {
                  maxIndex = (list[leftChildIndex] > list[index] &&
                              list[leftChildIndex] > list[rightChildIndex])
                                 ? leftChildIndex
                             : list[rightChildIndex] > list[index]
                                 ? rightChildIndex
                                 : index;
              }

              if (maxIndex == index) {
                  break;
              }

              swap(list[maxIndex], list[index]);
              index = maxIndex;
          }

          this->size--;
          */
    }

    int getSize() {
        return this->size;
    }

    int getTotalSize() {
        return this->total_size;
    }

    void printList() {

        for (int i = 0; i < size; i++) {
            cout << list[i] << " ";
        }

        cout << "\n";
    }
};

int main() {
    MaxHeap heap(10);

    heap.insert(10);
    heap.insert(1);
    heap.insert(15);
    heap.insert(17);
    heap.insert(20);
    heap.insert(60);
    heap.insert(30);
    heap.insert(40);
    heap.insert(70);
    heap.insert(55);

    heap.printList();
    cout << "Size: " << heap.getSize() << endl;
    heap.deleteHeap();
    heap.printList();
    cout << "Size: " << heap.getSize() << endl;

    return 0;
}