#include <bits/stdc++.h>
using namespace std;

//type of function pointer --> return_type(*function_name)(argument data type)

int get_square(int a) { return a * a; }


void test(vector<int> &a, int(*func)(int)) {

    for(int num : a) {
        cout << func(num) << endl;
    }
}

//custom comparator
bool comp(const int &a, const int &b) {
    return a > b;
}


int main() {
    
    vector<int> a = {1, 5, 3, 2, 8};

    //use of lambda functions as a comaparator
    sort(a.begin(), a.end(), [](const int &a, const int &b) { return a < b; });

    test(a, get_square);
}
