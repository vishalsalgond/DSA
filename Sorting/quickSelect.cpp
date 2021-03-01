#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int pIndex = low;

    for(int idx = low; idx <= high - 1; idx++) {
        if(a[idx] <= pivot) {
            swap(a[idx], a[pIndex]);
            pIndex++;
        }
    }

    swap(a[high], a[pIndex]);
    return pIndex;
}

int quickSelect(vector<int> &a, int low, int high, int k) {

    if(low < high) {

        int pIndex = partition(a, low, high);

        if(pIndex + 1 == k) return a[pIndex];

        if(pIndex + 1 < k) return quickSelect(a, pIndex + 1, high, k);
        else return quickSelect(a, low, pIndex - 1, k);
    }
    return a[low];
}

int kthLargest(vector<int> &a, int n, int k) {
    return quickSelect(a, 0, a.size() - 1, k);
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << kthLargest(a, n, k) << endl;
}
