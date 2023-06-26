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
	int size;
	LinkedList() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	void Size() {
		cout << size << "\n";
	}
	void IsEmpty() {
		cout << (size == 0?"True":"False") << "\n";
	}
	void Front() {
		if (size == 0) {
			cout << "Empty\n";
			return;
		}
		cout << head->next->value << "\n";
	}
	void Rear() {
		if (size == 0) {
			cout << "Empty\n";
			return;
		}
		cout << tail->prev->value << "\n";
	}
	void Enqueue(int v) {
		Node* newNode = new Node();
		newNode->value = v;
		newNode->prev = tail->prev;
		tail->prev->next = newNode;
		newNode->next = tail;
		tail->prev = newNode;
		size++;
	}
	void Dequeue() {
		if (size == 0) {
			cout << "Empty\n";
			return;
		}
		Node* curNode = head->next;
		cout << curNode->value << "\n";
		head->next = curNode->next;
		curNode->next->prev = head;
		size--;
	}
};

int main() {
	int t;
	cin >> t;

	LinkedList queue;
	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "size") {
			queue.Size();
		}
		else if (cmd == "isEmpty") {
			queue.IsEmpty();
		}
		else if (cmd == "front") {
			queue.Front();
		}
		else if (cmd == "rear") {
			queue.Rear();
		}
		else if (cmd == "enqueue") {
			int v;
			cin >> v;
			queue.Enqueue(v);
		}
		else if (cmd == "dequeue") {
			queue.Dequeue();
		}
	}
}