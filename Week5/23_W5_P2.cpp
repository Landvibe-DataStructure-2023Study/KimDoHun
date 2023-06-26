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

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	Node* p;
	int size;
	DoublyLinkedList() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
		begin();
		size = 0;
	}
	void push(int v) {
		Node* newNode = new Node();
		newNode->value = v;
		newNode->prev = tail->prev;
		newNode->next = tail;
		tail->prev->next = newNode;
		tail->prev = newNode;
	}
	void begin() {
		p = head->next;
	}
	void nextP() {
		if (p->next != nullptr) {
			p = p->next;
		}
	}
	void prevP() {
		if (p->prev != head) {
			p = p->prev;
		}
	}

};

int main() {
	int t;
	cin >> t;
	while (t--) {
		DoublyLinkedList ll;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int e;
			cin >> e;
			ll.push(e);
		}
		ll.begin();
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int k;
			cin >> k;
			if (k > 0) {
				for (int j = 0; j < k; j++) {
					ll.nextP();
				}
			}
			else if (k < 0) {
				for (int j = 0; j < -k; j++) {
					ll.prevP();
				}
			}
			int k2 = ll.p->value;
			if (k2 > 0) {
				for (int j = 0; j < k2; j++) {
					
					ll.nextP();
				}
			}
			else if (k2 < 0) {
				for (int j = 0; j < -k2; j++) {
					
					
					ll.prevP();
				}
			}
		}
		cout << ll.p->value << "\n";
	}
}