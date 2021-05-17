#include <bits/stdc++.h>
using namespace std;

//Hash Table for a phone book -> (123 => JOE)
class HashTable {

private:
	static const int hashSize = 10;
	list<pair<int, string>> hashTable[hashSize];

public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	void searchItem(int key);
	void printTable() const;
};

bool HashTable::isEmpty() const {

	int currSize = 0;
	for (int idx = 0; idx < hashSize; idx++) {
		currSize += hashTable[idx].size();
	}

	if (currSize == 0) return true;
	return false;
}

int HashTable::hashFunction(int key) {
	return (key) % hashSize;
}

void HashTable::insertItem(int key, string value) {

	int hashValue = hashFunction(key);
	bool keyExists = false;

	//if key already exists, update the value
	for (auto &kv : hashTable[hashValue]) {
		if (kv.first == key) {
			kv.second = value;
			keyExists = true;
			cout << "[WARNING] Key already exists. Value Updated." << endl;
			break;
		}
	}

	//if key does not exist
	if (!keyExists) {
		hashTable[hashValue].push_back({key, value});
	}
}

void HashTable::removeItem(int key) {

	int hashValue = hashFunction(key);
	bool keyExists = false;
	list<pair<int, string>>::iterator itemItr;

	//if key already exists, update the value
	for (auto it = hashTable[hashValue].begin(); it != hashTable[hashSize].end(); it++) {
		if (it -> first == key) {
			hashTable[hashValue].erase(it);
			keyExists = true;
			break;
		}
	}

	if (!keyExists) {
		cout << "[ERROR] Key not found." << endl;
	}

}

void HashTable::searchItem(int key) {

	int hashValue = hashFunction(key);

	//if key exists, remove the key
	for (auto kv : hashTable[hashValue]) {
		if (kv.first == key) {
			cout << "Value for " << key << " is " << kv.second << endl;
			return;
		}
	}

	//if key doesn't exists, throw error
	cout << "[ERROR] No key found.";
}

void HashTable::printTable() const {

	for (int idx = 0; idx < hashSize; idx++) {
		cout << idx << " ==> ";
		for (auto kv : hashTable[idx]) {
			cout << "(" << kv.first << ", " << kv.second << ") ";
		}
		cout << endl;
	}
}

int main() {

	HashTable mp;
	mp.insertItem(20, "Vishal");
	mp.insertItem(30, "Akshay");
	mp.insertItem(44, "Joe");
	mp.insertItem(20, "Rohan");
	mp.searchItem(20);
	mp.printTable();
	mp.removeItem(20);
	mp.searchItem(44);
	return 0;
}
