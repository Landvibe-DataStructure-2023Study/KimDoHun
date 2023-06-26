#include<iostream>
#include<vector>
using namespace std;

class Heap {
public:
	vector<int> v;
	int size = 0;

	Heap() {
		v.push_back(-1);
	}

	void swap(int a, int b) {
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}

	void upHeap(int i) {
		if (i == 0)return;
		else {
			int parent = i / 2;
			if (v[i] < v[parent]) {
				swap(i, parent);
				upHeap(parent);
			}
		}
	}
	void downHeap(int i) {
		int left = i * 2;
		int right = i * 2 + 1;
		int minIndex = i;

		if (left <= size && v[left] < v[minIndex]) {
			minIndex = left;
		}
		if (right <= size && v[right] < v[minIndex]) {
			minIndex = right;
		}
		if (minIndex != i) {
			swap(i, minIndex);
			downHeap(minIndex);
		}
	}

	void insert(int a) {
		v.push_back(a);
		size++;
		upHeap(size);
	}
	bool isEmpty() {
		return size == 0;
	}
	int pop() {
		if (isEmpty()) {
			return -1;
		}
		else {
			int top = v[1];
			v[1] = v[size];
			size--;
			v.pop_back();
			downHeap(1);
			return top;
		}
	}
	void top() {
		if (isEmpty()) {
			cout << "-1\n";
		}
		else {
			cout << v[1] << "\n";
		}
	}
	void print() {
		if (isEmpty())cout << "-1\n";
		else {
			for (int i = 1; i <= size; i++) {
				cout << v[i]<<" ";
			}
			cout << "\n";
		}
	}
	

};

int main() {
	Heap heap;

	int t;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "insert") {
			int i;
			cin >> i;
			heap.insert(i);
		}
		else if (cmd == "size") {
			cout << heap.size<<"\n";
		}
		else if (cmd == "isEmpty") {
			cout << heap.isEmpty()<<"\n";
		}
		else if (cmd == "pop") {
			cout << heap.pop()<<"\n";
		}
		else if (cmd == "top") {
			heap.top();
		}
		else if (cmd == "print") {
			heap.print();
		}
	}
}