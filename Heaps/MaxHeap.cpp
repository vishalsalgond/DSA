#include <bits/stdc++.h>
using namespace std;
class MaxHeap {
    vector<int> arr;
    int size = 0;
    void buildMaxHeap(vector<int> &arr); 
    void siftUp(int idx);
    void siftDown(int idx);
public:
    MaxHeap(vector<int> &arr) {
        this -> size = arr.size();
        for(auto &ele : arr) this -> arr.push_back(ele);
        buildMaxHeap(arr);
    }
    
    void push(int element);
    void pop();
    int top();
    bool empty();
};
void MaxHeap::buildMaxHeap(vector<int> &arr) {
    // build using siftUp
    // for(int i = 1; i < this -> size; i++) {
    //     siftUp(i);
    // }
    //build using siftDown
    int lastParent = (size - 1) / 2;
    for(int i = lastParent; i >= 0; i--) {
        siftDown(i);
    }
}
void MaxHeap::siftUp(int idx) {
    if(idx == 0) return;
    int parent = (idx - 1) / 2;
    if(this -> arr[parent] < this -> arr[idx]) {
        swap(this -> arr[parent], this -> arr[idx]);
        siftUp(parent);
    }
}
void MaxHeap::siftDown(int idx) {
    int firstChild = 2 * idx + 1;
    int secondChild = 2 * idx + 2;
    // ensure curr node has altleast one child
    if(firstChild >= size) return;
    if(secondChild < size) {
        if(this -> arr[idx] < this -> arr[firstChild] && this -> arr[firstChild] > this -> arr[secondChild]) {
            swap(this -> arr[idx], this -> arr[firstChild]);
            siftDown(firstChild);
        }
        else if(this -> arr[idx] < this -> arr[secondChild] && this -> arr[secondChild] > this -> arr[firstChild]) {
            swap(this -> arr[idx], this -> arr[secondChild]);
            siftDown(secondChild);
        }
    }
    else {
        if(this -> arr[idx] < this -> arr[firstChild]) {
            swap(this -> arr[idx], this -> arr[firstChild]);
            siftDown(firstChild);
        }
    }
}
void MaxHeap::push(int element) {
    this -> arr.push_back(element);
    size += 1;
    siftUp(size - 1);
}
void MaxHeap::pop() {
    if(size > 0) {
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        size -= 1;
        arr.resize(size);
        siftDown(0);
    }
    
}
int MaxHeap::top() {
    if(size > 0) {
        return this -> arr[0];
    }
    return -1;
}
bool MaxHeap::empty() {
    return size == 0;
}
int main() {
    
    vector<int> arr{9, 3, 4, 2, 11, 17, 5, 6};
    MaxHeap max_heap(arr);
    cout << max_heap.top() << endl;
    max_heap.pop();
    cout << max_heap.top() << endl;
    max_heap.pop();
    cout << max_heap.top() << endl;
    
    max_heap.push(23);
    cout << max_heap.top() << endl;
}
