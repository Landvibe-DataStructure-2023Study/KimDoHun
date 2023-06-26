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

class Stack {
public:
	Node* head;
	Node* tail;
	Stack() {
		head = new Node();
		tail = new Node();
		head->next = tail;
	}
	void Push(int v) {
		Node* newNode = new Node();
		newNode->value = v;
		newNode->next = head->next;
		head->next = newNode;
	}
	 int Pop() {
		Node* curNode = head->next;
		head->next = curNode->next;
		return curNode->value;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		Stack stack;
		string c;
		cin >> c;
		for (int i = 0; i < c.size(); i++) {
			if (c[i] >= 48 && c[i] <= 57) {
				stack.Push(c[i]-'0');
			}
			else {
				int y = stack.Pop();
				int x = stack.Pop();
				int ans = 0;;
				switch (c[i]) {
				case'+':
					ans = x + y; break;
				case'-':
					ans = x - y; break;
				case'*':
					ans = x * y; break;
				}
				stack.Push(ans);
			}
		}
		int answer = stack.Pop();
		int a = 0;
		while (answer != 0) {
			a += answer % 10;
			answer /= 10;
		}
		if (a < 0) {
			a *= -1;
		}
		cout << a << "\n";

	}
}