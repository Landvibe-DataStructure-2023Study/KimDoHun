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
		if (i == 1)return;
		else {
			int parent = i / 2;
			if (v[parent] < v[i]) {
				swap(parent, i);
				upHeap(parent);
			}
		}
	}
	void downHeap(int i) {
		int left = i * 2;
		int right = i * 2 + 1;
		int maxIndex = i;
		if (left <= size && v[left] > v[maxIndex]) {
			maxIndex = left;
		}
		if (right <= size && v[right] > v[maxIndex]) {
			maxIndex = right;
		}
		if (maxIndex != i) {
			swap(i, maxIndex);
			downHeap(maxIndex);
		}
	}
	void insert(int i) {
		v.push_back(i);
		size++;
		upHeap(size);
	}
	int pop() {
		int popNum = v[1];
		swap(1, size);
		v.pop_back();
		size--;
		downHeap(1);
		return popNum;
	}
	bool isEmpty() {
		return size == 0;
	}
	int top() {
		return v[1];
	}
	void print() {
		for (int i = 1; i <= size; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
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
			cout << heap.size << "\n";
		}
		else if (cmd == "isEmpty") {
			cout << heap.isEmpty() << "\n";
		}
		else if (cmd == "pop") {
			if (heap.isEmpty())cout << "-1\n";
			else cout << heap.pop() << "\n";
		}
		else if (cmd == "top") {
			if (heap.isEmpty()) cout << "-1\n";
			else cout << heap.top() << "\n";
		}
		else if (cmd == "print") {
			heap.print();
		}
	}
}