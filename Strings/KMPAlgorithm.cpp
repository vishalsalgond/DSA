#include <bits/stdc++.h>
using namespace std;

int KMP(string &str, string &pattern) {

    int N = str.length(), M = pattern.length();
    vector<int> suffixTable(M);

    // construct suffix table
    int left = 0;
    for(int right = 1; right < M; right++) {
        if(pattern[left] == pattern[right]) {
            suffixTable[right] = left + 1;
            left++;
        }
    }

    // pattern matching
    int ptr2 = 0;
    for(int i = 0; i <= N - M; i++) {
        int ptr1 = i;
        if(str[ptr1] == pattern[ptr2]) {
            while(ptr2 < M && str[ptr1] == pattern[ptr2]) {
                ptr1++;
                ptr2++;
            }
        }

        if(ptr2 == M) return i;
        else ptr2 = suffixTable[ptr2 - 1];
        
    }

    return -1;
}

int main() {
    
    string str = "adsgwadsxdsgwadsgz";
    string pattern = "dsgwadsgz";
    
    cout << pattern << " found at index " << KMP(str, pattern) << endl;
}
