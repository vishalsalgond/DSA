#include <bits/stdc++.h>
using namespace std;

enum CASE : char
{
	UPPER = 'A', LOWER = 'a'
};

CASE base = UPPER;
const int size = 26;

int mulInverse(int a) {
	int r1 = size, r2 = a;
	int t1 = 0, t2 = 1;
	int r = 1, t;
	while(r2 > 0) {
		int q = r1 / r2; //find quotient
		r = r1 % r2; //compute r
		r1 = r2; r2 = r; //shift values
		t = t1 - (q * t2); //compute t
		t1 = t2; t2 = t; //shift values
	}
	if(t1 > 0) return t1;
	return size + t1;
}

string encrypt(string plainText, int a, int b) {
	string ans;
	for(char x : plainText) {
		x = x - base;
		char cipher = ((a * x) + b) % size;
		ans += base + cipher;
	}
	return ans;
}

string decrypt(string cipherText, int a, int b) {
	string ans;
	int mulInv = mulInverse(a);
	for(char x : cipherText) {
		x = x - base;
		char plain = mulInv * (x - b) % size;
		if(plain < 0) plain += size;
		ans += base + plain;
	}
	return ans;
	}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
#endif
	int a,b;
	string plainText;
	cin >> plainText;
	cin >> a >> b;
	string cipherText = encrypt(plainText, a, b);
	cout << "Cipher Text : " << cipherText << endl;
	plainText = decrypt(cipherText, a , b);
	cout << "Recovered Plain Text : " << plainText << endl;
}
