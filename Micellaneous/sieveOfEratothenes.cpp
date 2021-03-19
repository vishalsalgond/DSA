#include <bits/stdc++.h>
using namespace std;

//Time complexity : O (N log log N)

void sieveOfEratothenes(int N) {

    vector<int> arr(N + 1, 1);
    arr[1] = 0; 

    //all even no's are not prime 
    for(int i = 3; i <= N; i++) {
        if(i % 2 == 0) arr[i] = 0;
    }

    //loop over every element and mark its multiple as not prime
    //we can directly start from i * i
    for(int i = 3; i <= N; i++) {
        for(int j = i * i; j <= N; j += i) {
            arr[j] = 0;
        }
    }

    for(int i = 1; i <= N; i++) {
        if(arr[i]) cout << i << " ";
    }

}

int main() {
    int n; cin >> n;
    sieveOfEratothenes(n);
}
