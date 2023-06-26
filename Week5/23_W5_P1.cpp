#include<iostream>
using namespace std;

class Node {
public:
	Node* next;
	Node* prev;
	int value;
	Node() {
		next = prev = nullptr;
		value = 0;
	}
};
class LinkedList {
public:
	Node* head;
	Node* tail;
	Node* p;
	int size;
	LinkedList() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
		size = 0;
		begin();
	}
	void begin() {
		p = head->next;
	}
	void end() {
		p = tail;
	}
	void insert(int e) {
		Node* newNode = new Node();
		newNode->value = e;
		newNode->prev = p->prev;
		newNode->next = p;
		p->prev->next = newNode;
		p->prev = newNode;
		size++;
	}
	void erase() {

		if (size == 0) {
			cout << "empty\n";
		}
		if (p == tail) {
		}
		else {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			begin();
			size--;
		}
	}
	void nextP() {
		if (p != tail) {
			p = p->next;
		}
	}
	void prevP() {
		if (p != head->next) {
			p = p->prev;
		}
	}
	void findmultiple(int e) {
		Node* curNode = head->next;
		bool ek = 0;
		for (int i = 0; i < size; i++) {
			if (curNode->value % e == 0) {
				cout << i << " ";
				ek = 1;
			}
			curNode = curNode->next;
		}
		if (ek == 0) {
			cout << -1;
		}
		cout << "\n";
	}
};

int main() {
	int n;
	cin >> n;
	LinkedList ll;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "begin") {
			ll.begin();
		}
		else if (cmd == "end") {
			ll.end();
		}
		else if (cmd == "insert") {
			int e;
			cin >> e;
			ll.insert(e);
		}
		else if (cmd == "erase") {
			ll.erase();
		}
		else if (cmd == "nextP") {
			ll.nextP();
		}
		else if (cmd == "prevP") {
			ll.prevP();
		}
		else if (cmd == "findmultiple") {
			int e;
			cin >> e;
			ll.findmultiple(e);
		}
	}
}