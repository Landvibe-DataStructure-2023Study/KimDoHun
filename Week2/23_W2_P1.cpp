#include<iostream>
using namespace std;

class Node {
public:
	Node* next;
	int value;
	Node() {
		next = nullptr;
		value = 0;
	}
};

class SinglyLinkedList {
public:
	Node* head;
	Node* tail;
	int size;
	SinglyLinkedList() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		size = 0;
	}
	void Print() {
		if (size == 0) {
			cout << "empty\n";
			return;
		}
		Node* curNode = head->next;
		while (curNode->next != nullptr) {
			cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << "\n";
	}
	void AddFront(int x) {
		Node* newNode = new Node;
		newNode->value = x;
		newNode->next = head->next;
		head->next = newNode;
		size++;
	}
	void RemoveFront() {
		if (size == 0) {
			cout << "empty\n";
			return;
		}
		Node* curNode = head->next;
		cout << curNode->value << "\n";
		head->next = curNode->next;
		size--;;
	}
	void Update(int idx,int x) {
		if (idx >= size) {
			cout << "error\n";
			return;
		}
		Node* curNode = head->next;
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}
		curNode->value = x;
	}
	void Min() {
		if (size == 0) {
			cout << "empty\n";
			return;
		}
		Node* curNode = head->next;
		int idx = 0;
		int minIdx = 0;
		int min = curNode->value;
		while (curNode->next != nullptr) {
			if (min > curNode->value) {
				min = curNode->value;
				minIdx = idx;
			}
			curNode = curNode->next;
			idx++;
		}
		cout <<minIdx<<" " << min << "\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int m;
	cin >> m;
	SinglyLinkedList SLL;
	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "Print") {
			SLL.Print();
		}
		else if (cmd == "AddFront") {
			int x;
			cin >> x;
			SLL.AddFront(x);
		}
		else if (cmd == "RemoveFront") {
			SLL.RemoveFront();
		}
		else if (cmd == "Update") {
			int i, x;
			cin >> i >> x;
			SLL.Update(i, x);
		}
		else if (cmd == "Min") {
			SLL.Min();
		}
	}
}