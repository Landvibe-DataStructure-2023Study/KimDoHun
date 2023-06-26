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

	void Enqueue(int v) {
		Node* newNode = new Node();
		newNode->value = v;
		newNode->prev = tail->prev;
		tail->prev->next = newNode;
		newNode->next = tail;
		tail->prev = newNode;
		size++;
	}
	int Dequeue() {
		Node* curNode = head->next;
		head->next = curNode->next;
		curNode->next->prev = head;
		size--;
		return curNode->value;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		LinkedList queue1;
		LinkedList queue2;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			queue1.Enqueue(x);
		}
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			queue2.Enqueue(x);
		}
		int score1 = 0, score2 = 0;
		int ex1 = 0, ex2 = 0;

		for (int i = 0; i < n; i++) {
			cout << "Round" << i + 1<<" ";
			int x = queue1.Dequeue() + ex1;
			int y = queue2.Dequeue() + ex2;
			if (x > y) {
				cout << x << ">" << y<<" ";
				cout << ++score1 << ":" << score2 << "\n";
				ex1 = x - y;
				ex2 = 0;
			}
			else if (x < y) {
				cout << x << "<" << y << " ";
				cout << score1 << ":" << ++score2 << "\n";
				ex1 = 0;
				ex2 = y-x;
			}
			else {
				cout << x << "=" << y<<" ";
				cout << score1 << ":" << score2 << "\n";
				ex1 = 0;
				ex2 = 0;
			}
		}
		if (score1 > score2) {
			cout << "Winner P1\n";
		}
		else if (score1 < score2) {
			cout << "Winner P2\n";
		}
		else {
			cout << "Draw\n";
		}
	}
}