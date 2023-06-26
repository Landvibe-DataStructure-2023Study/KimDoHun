//ÃÖ¼Ò Èü
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
			if (v[parent] > v[i]) {
				swap(parent, i);
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
	int pop() {
		int popNum = v[1];
		swap(1, size);
		v.pop_back();
		size--;
		downHeap(1);
		return popNum;
	}
	int top() {
		return v[1];
	}
	void postorder(int i) {
		if (i * 2 <= size) {
			postorder(i * 2);
		}
		if (i * 2 + 1 <= size) {
			postorder(i * 2 + 1);
		}
		cout << v[i] << " ";
	}
};

int main() {

	int t;
	cin >> t;
	while (t--) {
		Heap heap;
		int n, p;
		cin >> n >> p;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			heap.insert(k);
		}


		int count = 0;


		while (heap.top()<p) {
			if (heap.size<=2) {
				count = -1;
				break;
			}

			int tmp1 = heap.pop();
			int tmp2 = heap.pop();
			int tmp3 = heap.pop();

			int tmp = (tmp1 + tmp3) / 2;
			heap.insert(tmp);
			count++;

		}
		if (count == -1) {
			cout << "False\n";
		}
		else {
			cout << count << "\n";
			heap.postorder(1);
			cout << "\n";
		}
	}
}