#include<iostream>
using namespace std;

#define NOITEM 0
#define LOGIN 1
#define LOGOUT 2

class User {
public:
	string id;
	string pw;
	int valid;
	User() {
		id = pw = "";
		valid = NOITEM;
	}
	User(string _id, string _pw) {
		id = _id;
		pw = _pw;
		valid = LOGOUT;
	}
};

class HashTable {
public:
	int cap;
	User* table;
	HashTable() {
		cap = 800000;
		table = new User[cap];
	}
	int strToInt(string id) {
		int num = 0;
		for (int i = 0; i < 6; i++) {
			int a = 1;
			for (int l = 0; l < i; l++) {
				a *= 26;
			}
			num += a * id[i];
		}
		return num;
	}
	int hashFunc(int id) {
		return id % cap;
	}
	void signup(string id, string pw) {
		int index = hashFunc(strToInt(id));
		while (table[index].valid != NOITEM) {
			if (table[index].id == id) {
				cout << "Invalid " << table[index].pw << "\n";
				return;
			}
			index = hashFunc(index + 1);
		}
		table[index] = User(id, pw);
		cout << "Submit\n";
	}
	void login(string id, string pw) {
		int index = hashFunc(strToInt(id));
		while (table[index].valid != NOITEM) {
			if (table[index].id == id && table[index].pw == pw) {
				if (table[index].valid == LOGIN) {
					cout << "Quit\n";
					return;
				}
				else if (table[index].valid == LOGOUT) {
					table[index].valid = LOGIN;
					cout << "Submit\n";
					return;
				}
			}
			else if (table[index].id == id && table[index].pw != pw) {
				cout << "Invalid\n";
				return;
			}
			index = hashFunc(index + 1);
		}
		if (table[index].valid == NOITEM) {
			cout << "Invalid\n";
			return;
		}
	}
	void logout(string id) {
		int index = hashFunc(strToInt(id));
		while (table[index].valid != NOITEM) {
			if (table[index].id == id) {
				table[index].valid = LOGOUT;
				cout << "Submit\n";
				return;
			}
			index = hashFunc(index + 1);
		}
	}
	void change(string id, string pw) {
		int index = hashFunc(strToInt(id));
		while (table[index].valid != NOITEM) {
			if (table[index].id == id) {
				table[index].pw = pw;
				cout << "Submit\n";
				return;
			}
			index = hashFunc(index + 1);
		}
	}
};

int main() {
	HashTable hashTable;
	int t;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "signup") {
			string id, pw;
			cin >> id >> pw;
			hashTable.signup(id, pw);
		}
		else if (cmd == "login") {
			string id, pw;
			cin >> id >> pw;
			hashTable.login(id, pw);
		}
		else if (cmd == "logout") {
			string id;
			cin >> id;
			hashTable.logout(id);
		}
		else if (cmd == "change") {
			string id, pw;
			cin >> id >> pw;
			hashTable.change(id, pw);
		}
	}
}