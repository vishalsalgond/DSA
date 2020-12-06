#include<bits/stdc++.h>
using namespace std;
enum CASE : char
{
	UPPER = 'A', LOWER = 'a'
};

CASE base = LOWER;
const int size = 26;

//Encryption
string encrypt(string plainText, string key) {
	int length = key.length();
	string ans;
	int key_pos = 0;
	for(char x : plainText) {
		int row = key[key_pos] - base, col = x - base;
		ans += base + (row + col) % size;
		key_pos = (key_pos + 1) % length;
	}
	return ans;
}

//Decryption
string decrypt(string cipherText, string key) {
	int length = key.length();
	string ans;
	char z;
	int key_pos = 0;
	for(char x : cipherText) {
		int a = x - base, b = key[key_pos] - base;
		if(a >= b)
			ans += base + (a - b);
		else
			ans += base + (size - b) + a;
		key_pos = (key_pos + 1) % length;


	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("input1.txt","r",stdin);
	freopen("output1.txt","w",stdout);
#endif
	string plainText , key;
	cin >> plainText;
	cin >> key;
	string cipherText = encrypt(plainText, key);
	cout << "Cipher Text : " << cipherText << endl;
	string plain_Text = decrypt(cipherText, key);
	cout << "Recovered Plain Text : " << plain_Text << endl;
	return 0;
}
