#include <bits/stdc++.h>
using namespace std;

class CompareMaxHeap {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

class CompareMinHeap {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main() {
    // Max Heap default
    priority_queue<int> maxHeap_default;
    maxHeap_default.push(1);
    maxHeap_default.push(2);
    maxHeap_default.push(3);
    maxHeap_default.push(10);
    maxHeap_default.push(6);
    maxHeap_default.push(11);

    cout << "Max Heap element at top: " << maxHeap_default.top() << endl; // 11

    // Max Heap in pair by default first value is taken for deciding priority
    priority_queue<pair<int, int>> maxHeap_pair;
    maxHeap_pair.push(make_pair(1, 100));
    maxHeap_pair.push(make_pair(5, 50));
    maxHeap_pair.push(make_pair(10, 60));

    cout << "Pair maxh heap at Top: " << maxHeap_pair.top().second
         << endl; // 60

    // Max Heap in pair using giving custom priority value

    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMaxHeap>
        maxHeap_custom;

    maxHeap_custom.push(make_pair(10, 100));
    maxHeap_custom.push(make_pair(1, 50));
    maxHeap_custom.push(make_pair(40, 500));
    maxHeap_custom.push(make_pair(60, 250));

    cout << "Max Heap of custom priority value top: "
         << maxHeap_custom.top().second << endl; // 500

    // Min-Heap default or as it is by library

    priority_queue<int, vector<int>, greater<int>> minHeap_default;
    minHeap_default.push(10);
    minHeap_default.push(8);
    minHeap_default.push(15);
    minHeap_default.push(7);

    cout << "Min Heap default at top: " << minHeap_default.top() << endl; // 7

    // Min-Heap with pair

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minHeap_pairt;
    minHeap_pairt.push(make_pair(10, 200));
    minHeap_pairt.push(make_pair(15, 500));
    minHeap_pairt.push(make_pair(6, 100));
    minHeap_pairt.push(make_pair(12, 300));

    cout << "Min Heap default at top: " << minHeap_pairt.top().second
         << endl; // 100

    // Max Heap in pair using giving custom priority value

    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareMinHeap>
        minHeap_custom;

    minHeap_custom.push(make_pair(10, 100));
    minHeap_custom.push(make_pair(1, 50));
    minHeap_custom.push(make_pair(40, 500));
    minHeap_custom.push(make_pair(60, 250));

    cout << "Min Heap of custom priority value top: "
         << minHeap_custom.top().second << endl; // 50

    return 0;
}