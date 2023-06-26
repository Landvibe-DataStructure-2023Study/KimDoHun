#include<iostream>
#include<string>
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

class Stack {
public:
	Node* head;
	Node* tail;
	int size;
	Stack() {
		head = new Node;
		tail = new Node;
		head->next = tail;
		size = 0;
	}
	void Size() {
		cout << size << "\n";
	}
	void Empty() {
		cout << (size == 0) << "\n";
	}
	void Top() {
		if (size == 0) {
			cout << "-1\n";
			return;
		}
		cout << head->next->value << "\n";
	}
	void Push(int x) {
		Node* newNode = new Node;
		newNode->value = x;
		newNode->next = head->next;
		head->next = newNode;
		size++;
	}
	void Pop() {
		if (size == 0) {
			cout << "-1\n";
			return;
		}
		Node* curNode = head->next;
		cout << curNode->value << "\n";
		head->next = curNode->next;
		size--;
	}
};

int main() {
	int n;
	cin >> n;
	Stack stack;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "size") {
			stack.Size();
		}
		else if (cmd == "empty") {
			stack.Empty();
		}
		else if (cmd == "top") {
			stack.Top();
		}
		else if (cmd == "push") {
			int x;
			cin >> x;
			stack.Push(x);
		}
		else if (cmd == "pop") {
			stack.Pop();
		}
	}

}