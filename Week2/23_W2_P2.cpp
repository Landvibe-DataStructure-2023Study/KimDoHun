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
		head = tail = nullptr;
		size = 0;
	}
	void Print() {
		Node* curNode = head;
		if (size == 0) {
			cout << "empty\n";
			return;
		}
		while (curNode != tail) {
			cout << curNode->value << " ";
			curNode = curNode->next;
		}
		cout << curNode->value << "\n";
	}
	void AddBack(int x) {
		Node* newNode = new Node();
		newNode->value = x;
		if (size == 0) {
			head = tail = newNode;
		}
		else {
			Node* curNode = head;
			while (curNode != tail) {
				curNode = curNode->next;
			}
			curNode->next = newNode;
			tail = newNode;
		}
		size++;
	}
	void RemoveBack() {
		if (size == 0) {
			cout << "emtpy\n";
			return;
		}
		else if (size == 1) {
			cout << head->value << "\n";
			head = tail = nullptr;
		}
		else {
			Node* curNode = head;
			while (curNode->next != tail) {
				curNode = curNode->next;
			}
			cout << curNode->next->value << "\n";
			curNode->next = nullptr;
			tail = curNode;
		}
		size--;
	}
	void Update(int idx, int x) {
		if (idx >= size) {
			cout << "error\n";
			return;
		}
		Node* curNode = head;
		for (int i = 0; i < idx; i++) {
			curNode = curNode->next;
		}
		curNode->value = x;
	}
	void Max() {
		if (size == 0) {
			cout << "empty\n";
			return;
		}
		int max = head->value;
		int maxIdx = 0;
		int idx = 0;
		Node* curNode = head;
		for (int i = 0; i < size; i++) {
			if (curNode->value > max) {
				max = curNode->value;
				maxIdx = idx;
			}
			curNode = curNode->next;
			idx++;
		}
		cout << maxIdx<<" "<<max << "\n";
	}
};

int main() {
	SinglyLinkedList SLL;
	int m;
	cin >> m;
	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "Print") {
			SLL.Print();
		}
		else if (cmd == "AddBack") {
			int x;
			cin >> x;
			SLL.AddBack(x);
		}
		else if (cmd == "RemoveBack") {
			SLL.RemoveBack();
		}
		else if (cmd == "Update") {
			int i, x;
			cin >> i >> x;
			SLL.Update(i, x);
		}
		else if (cmd == "Max") {
			SLL.Max();
		}
	}
}