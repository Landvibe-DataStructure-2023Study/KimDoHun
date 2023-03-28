//2023_03_22 ±èµµÈÆ
//DataStructure_2021_W4_P1
//LinkedListQueue

#include<iostream>
#include<string>
using namespace std;

class Node {
private:
	Node* next;
	int data;
public:
	Node() {
		next = nullptr;
		data = 0;
	}
	friend class LinkedList;
	friend class Queue;
};
class Queue {
public:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

	bool isEmpty() {
		return size == 0;
	}
	void Enqueue(int value) {
		Node* newNode = new Node;
		newNode->data = value;
		if (isEmpty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	void Dequeue() {
		if (isEmpty()) {
			cout << "Empty\n";
			return;
		}
		Node* curNode = head;
		cout << curNode->data << "\n";
		if (size == 1) {
			head = tail = nullptr;
		}
		else {
			head = head->next;
		}
		delete curNode;
		size--;
	}
	void Size() {
		cout << size << "\n";
	}
	void Empty() {
		cout << (isEmpty()?"True":"False") << "\n";
	}
	void Front() {
		if (isEmpty()) {
			cout << "Empty\n";
			return;
		}
		cout << head->data << "\n";
	}
	void Rear() {
		if (isEmpty()) {
			cout << "Empty\n";
			return;
		}
		cout << tail->data << "\n";
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	Queue newQueue;

	while (t--) {
		string order;
		cin >> order;

		if (order == "enqueue") {
			int value;
			cin >> value;
			newQueue.Enqueue(value);
		}
		else if (order == "dequeue") {
			newQueue.Dequeue();
		}
		else if (order == "size") {
			newQueue.Size();
		}
		else if (order == "isEmpty") {
			newQueue.Empty();
		}
		else if (order == "front") {
			newQueue.Front();
		}
		else if (order == "rear") {
			newQueue.Rear();
		}
	}
}