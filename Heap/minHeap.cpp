#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    int size;
    int total_size;
    int* list;

public:
    MinHeap(int size) {
        this->size = 0;
        total_size = size;
        list = new int[size];
    }

    void heapify(int index) {
        int minIndex = index;
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;

        if (left < size && list[left] < list[minIndex]) {
            minIndex = left;
        }

        if (right < size && list[right] < list[minIndex]) {
            minIndex = right;
        }

        if (minIndex != index) {
            swap(list[index], list[minIndex]);
            heapify(minIndex);
        }
    }

    void deleteHeap() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }

        if (size == 1) {
            size--;
            return;
        }

        list[0] = list[size - 1];
        size--;

        heapify(0);
    }

    void insert(int value) {
        if (size == total_size) {
            cout << "Heap overflow\n";
            return;
        }

        int index = size;
        list[size] = value;
        size++;

        while (index > 0 && list[index] < list[(index - 1) / 2]) {
            swap(list[index], list[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void printList() {
        for (int i = 0; i < size; i++) {
            cout << list[i] << " ";
        }
        cout << "\n";
    }
};

int main() {

    MinHeap heap(5);
    heap.insert(30);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(16);
    heap.printList();
    heap.deleteHeap();
    heap.printList();

    return 0;
}