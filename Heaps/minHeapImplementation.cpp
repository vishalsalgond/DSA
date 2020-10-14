#include <bits/stdc++.h>
using namespace std;

class MinHeap {

    int size;
    vector<int> arr;

public:    
    MinHeap(vector<int> a) {
        size = a.size();
        for(int index = 0; index < size; ++index) 
            arr.push_back(a[index]);
    }

    //O(logN)
    void siftUp(int currIndex) {
        
        //Find my parent
        int parent = (currIndex - 1) / 2;

        if(parent < 0) {
            return;
        }

        //If my parent is greater than me then swap
        if(arr[parent] > arr[currIndex]) {
            swap(arr[parent], arr[currIndex]);
            siftUp(parent);
        }

    }

    //O(logN)
    void siftDown(int currIndex) {
        
        //Find out children indices
        int firstChild = (2 * currIndex) + 1;
        int secondChild = (2 * currIndex) + 2;
        int changeIndex;

        //If no children exist then return;
        if(firstChild >= size) {
            return;
        }

        //If both children exist, find potential candidate
        if(secondChild < size) {
            if(arr[firstChild] < arr[secondChild])
                changeIndex = firstChild;
            else
                changeIndex = secondChild;
        }
        else {
            changeIndex = firstChild;
        }
        //If the potential candidate is smaller than currIndex, swap them
        if(arr[changeIndex] < arr[currIndex]) {
            swap(arr[changeIndex], arr[currIndex]);
            siftDown(changeIndex);
        }
    }

    //O(logN)
    void insert(int element) {
        
        //Insert to the end and update size
        arr.push_back(element);
        size++;

        //Call siftUp on newly inserted element
        siftUp(size - 1);

    }

    //O(logN)
    void remove() {

        //Swap with last element
        swap(arr[0], arr[size - 1]);

        //Remove the last element and update size
        arr.pop_back();
        size--;

        //Sift down root again
        siftDown(0);
    }

    //O(1)
    int getMin() {
        //return min element
        if(size < 1) 
            return -1;
        return arr[0];
    }


    //O(N) if we use siftDown else O(NlogN)
    void buildHeap() {

        //If array has less than 2 elements
        if(size <= 1) {
            return;
        }

        //Find out the last parent
        int lastParent = (size - 1) / 2;

        //Call siftDown on every parent
        for(int parent = lastParent; parent >= 0; parent--) {
            siftDown(parent);
        }
    }

    void showHeap() {
        for(int element : arr)
            cout << element << " ";
        cout << endl;
    }

};

int main() {

    vector <int> a = {30, 102, 23, 12, 18, 9, 44, 17, 31};
    MinHeap *min_heap = new MinHeap(a);
    min_heap -> buildHeap();

    cout << min_heap -> getMin() << endl;

    min_heap -> insert(15);

    min_heap -> remove();

    return 0;
}
