#include<iostream>
using namespace std;

class Node {
public:
	Node* next;
	char value;
	Node() {
		next = nullptr;
		value = NULL;
	}
};
class Stack {
public:
	Node* head;
	Node* tail;
	int size;
	int emptyNum;
	Stack() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		size = 0;
		emptyNum = 0;
	}
	void Push(char x) {
		Node* newNode = new Node();
		newNode->value = x;
		newNode->next = head->next;
		head->next = newNode;
		size++;
	}
	void Pop() {
		Node* curNode = head->next;
		cout << curNode->value;
		head->next = curNode->next;
		size--;
		if (size == 0) {
			emptyNum++;
		}
	}
	char Top() {
		return head->next->value;
	}
};
int priority(char a) {
	if (a == '+' || a == '-') {
		return 1;
	}
	else if (a == '*') {
		return 2;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {

		Stack stack;
		string cmd;
		cin >> cmd;
		for (int i = 0; i < cmd.size(); i++) {
			if (cmd[i] - '0' >= 1 && cmd[i] - '0' <= 9) {
				cout << cmd[i];
			}
			else if (cmd[i] == '+' || cmd[i] == '-' || cmd[i] == '*') {
				if (stack.size == 0) {
					stack.Push(cmd[i]);
				}
				else if (priority(stack.Top()) < priority(cmd[i])) {
					stack.Push(cmd[i]);
				}
				else {
					while (stack.size != 0 || priority(stack.Top()) >= priority(cmd[i])) {
						stack.Pop();
					}
					stack.Push(cmd[i]);
				}
			}
		}
		while (stack.size != 0) {
			stack.Pop();
		}
		cout << " " << stack.emptyNum << "\n";
	}
}