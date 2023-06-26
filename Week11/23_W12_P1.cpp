#include<iostream>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

class Entry {
public:
	int key;
	string value;
	int valid;

	Entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	Entry(int k, string v) {
		key = k;
		value = v;
		valid = ISITEM;
	}
};

class HashTable {
public:
	Entry* hashTable;
	int capacity;
	HashTable(int c) {
		capacity = c;
		hashTable = new Entry[capacity];
	}

	int hashFunc(int k) {
		return k % capacity;
	}

	void put(int key, string value) {
		int index = hashFunc(key);
		int probing = 1;

		while (hashTable[index].valid == ISITEM && probing <= capacity) {
			index = hashFunc(index + 1);
			probing++;
		}
		hashTable[index] = Entry(key, value);
		cout << probing << " " << index << "\n";
	}

	void erase(int key) {
		int index = hashFunc(key);
		int probing = 1;

		while (hashTable[index].valid != NOITEM && probing <= capacity) {
			if (hashTable[index].key == key) {
				cout << hashTable[index].value << "\n";
				hashTable[index].key = 0;
				hashTable[index].value = "";
				hashTable[index].valid = AVAILABLE;
				return;
			}
			index = hashFunc(index + 1);
			probing++;
		}

		if (probing > capacity || hashTable[index].valid == NOITEM) {
			cout << "None\n";
		}
	}

	void find(int key) {
		int index = hashFunc(key);
		int probing = 1;

		while (hashTable[index].valid != NOITEM && probing <= capacity) {
			if (hashTable[index].key == key) {
				cout << hashTable[index].value << "\n";
				return;
			}
			index = hashFunc(index + 1);
			probing++;
		}

		if (probing > capacity || hashTable[index].valid == NOITEM) {
			cout << "None\n";
		}
	}

	void vacant() {
		int count = 0;
		int probing = 0;
		while (probing < capacity) {
			if (hashTable[probing].valid != ISITEM) {
				count++;
			}
			probing++;
		}
		cout << count << "\n";
	}
};


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numOfTest, sizeOfHashTable;
	cin >> numOfTest >> sizeOfHashTable;

	HashTable* hashTable = new HashTable(sizeOfHashTable);

	while (numOfTest--) {
		string cmd;
		cin >> cmd;

		if (cmd == "put") {
			int key;
			string value;
			cin >> key >> value;

			hashTable->put(key, value);
		}
		else if (cmd == "erase") {
			int key;
			cin >> key;

			hashTable->erase(key);
		}
		else if (cmd == "find") {
			int key;
			cin >> key;

			hashTable->find(key);
		}
		else if (cmd == "vacant") {
			hashTable->vacant();
		}
	}
}