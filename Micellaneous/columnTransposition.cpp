#include <bits/stdc++.h>
using namespace std;
 
string plain, key;
int n,m,rows;
map <char, int> mp;
string encrypted, decrypted;
 
void map_keys_to_column() {
    int pos = 0;
    for(char x : key) {
        mp[x] = pos;
        pos++;
    }
}
 
void encrypt() {
    char matrix[rows][m];
 
    //build the matrix
    int pos = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < m; j++) {
            if(pos < n) {
                matrix[i][j] = plain[pos];
                pos++;
            }
            else
                matrix [i][j] = '/';
        }
    }
 
    map_keys_to_column();
 
    sort(key.begin(), key.end());
    for(char x : key) {
        int col = mp[x];
        for(int i = 0; i < rows; i++) {
            if(matrix[i][col] != '/')
                encrypted += matrix[i][col];
        }
    }
    cout << encrypted << endl;
}
 
void decrypt() {
    //I have access to -
        //encryped text
        //key
        //map
 
    char matrix[rows][m];
    int size = rows * m;
 
    //build the matrix again
    int pos = 0;
    for(char x : key) {
        int col = mp[x];
        for(int i = 0; i < rows; i++) {
            int maxx = ((i) * m) + col;
            if(maxx < n) {
                matrix[i][col] = encrypted[pos];
                pos++;
            } else {
                matrix[i][col] = '/';
            }
        }
    }
 
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] != '/')
                decrypted += matrix[i][j];
        }
    }
 
    cout << decrypted << endl;
 
    
}
 
int main() {
#ifndef ONLINE_JUDGE
  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
#endif
    cin >> plain;
    cin >> key;
 
    n = plain.length();
    m = key.length();
    rows = floor(n / m) + 1;
 
    cout << "Columnar Transposition Cipher" << endl;
    cout << "Encrypted text : ";
    encrypt();
    cout << "Decrypted text : ";
    decrypt();
}
