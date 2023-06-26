#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	Node* next;
	Node* prev;
	int value;
	Node() {
		next = prev = nullptr;
		value = 10000;
	}
};

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	int size;
	DoublyLinkedList() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	void Print() {
		if (size == 0) {
			cout << "empty\n";
			return;
		}
		Node* curNode = head->next;
		while (curNode != tail) {
			cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << "\n";
	}
	void Insert(int idx, int x) {
		if (idx > size) {
			cout << "error\n";
			return;
		}
		Node* curNode = head;
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}
		Node* newNode = new Node();
		newNode->value = x;
		newNode->next = curNode->next;
		newNode->prev = curNode;
		curNode->next->prev = newNode;
		curNode->next = newNode;
		size++;
	}
	void Remove(int idx) {
		if (size == 0||idx>=size) {
			cout << "error\n";
			return;
		}
		Node* curNode = head->next;
		Node* prevNode = head->next;
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}
		cout << curNode->value << "\n";
		curNode->prev -> next = curNode->next;
		curNode->next->prev = curNode->prev;
		size--;
	}
	void RemoveAll(int x) {
		Node* curNode = head->next;
		int count = 0;
		while (curNode != tail) {
			if (curNode->value == x) {
				count++;
				curNode->prev->next = curNode->next;
				curNode->next->prev = curNode->prev;
				size--;
			}
			curNode = curNode->next;
		}
		if (count == 0) {
			cout << "not found\n";
		}
		else {
			cout << count << "\n";
		}
	}
	void NeighborMin(int idx) {
		if (idx >= size) {
			cout << "error\n";
			return;
		}
		Node* curNode = head->next;
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}
		int min = curNode->prev->value;
		if (min > curNode->next->value) {
			min = curNode->next->value;
		}
		cout <<min << "\n";
	}

};


int main() {
	int m;
	cin >> m;
	DoublyLinkedList DLL;
	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "Print") {
			DLL.Print();
		}
		else if (cmd == "Insert") {
			int i, x;
			cin >> i >> x;
			DLL.Insert(i, x);
		}
		else if (cmd == "Remove") {
			int i;
			cin >> i;
			DLL.Remove(i);
		}
		else if (cmd == "RemoveAll") {
			int x;
			cin >> x;
			DLL.RemoveAll(x);
		}
		else if (cmd == "NeighborMin") {
			int i;
			cin >> i;
			DLL.NeighborMin(i);
		}
	}
}