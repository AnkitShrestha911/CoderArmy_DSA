#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& heapElement, int index) {
    int leftChild = (index * 2) + 1;
    int rightChild = (index * 2) + 2;
    int maxIndex = index;
    int size = heapElement.size();

    if (leftChild < size && heapElement[leftChild] > heapElement[maxIndex]) {
        maxIndex = leftChild;
    }

    if (rightChild < size && heapElement[rightChild] > heapElement[maxIndex]) {
        maxIndex = rightChild;
    }

    if (maxIndex != index) {
        swap(heapElement[maxIndex], heapElement[index]);
        heapify(heapElement, maxIndex);
    }
}

// TC: O(n)
/**
 * We start from the bottom of non-leaf element 
 * The last has n/2+1 element no work ignore +1 just consider n/2 here 
 * The second last has n/4 element, worst case element can go 1 step down
 * The third last has n/8 element, worst case the element can go 2 step down
 * 
 * Sum up all (n/2 + n/4*1 + n/8*2 + n/16*3 + ......)
 * Taking n common here 
 * --> n (1/2 + 1/4 + 2/8 + 3/16 + ...)
 * 
 * Here using tailor method to solve this (1/2 + 1/4 + 2/8 + 3/16 + ...) that gives 1 or less than 20 
 * constant it does not matter at the end it ignore in time complexity
 * 
 *  n * 1 = O(n) 
 * 
 */
void heapify_maxHeap(vector<int>& heapElement) {
    int size = heapElement.size();
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(heapElement, i);
    }
}

void printList(vector<int>& lists) {
    for (auto element : lists) {
        cout << element << " ";
    }

    cout << "\n";
}

int main() {
    vector<int> heapElement = {14, 15, 12, 22, 17, 20, 18, 24, 23, 30, 19};
    cout << "Without heapify:\n";
    printList(heapElement);
    cout << "With heapify\n";
    heapify_maxHeap(heapElement);
    printList(heapElement);

    return 0;
}