//삽입정렬, 정렬된 벡터로 구현

#include<iostream>
#include<vector>

using namespace std;

class PQ {
public:
	vector<int>pq;
	void insert(int a) {
		if (pq.size() == 0) {
			pq.push_back(a);
		}
		else {
			vector<int>::iterator iter;
			for (iter = pq.begin(); iter != pq.end(); iter++) {
				if (*iter > a) {
					pq.insert(iter, a);
					return;
				}
			}
			pq.insert(iter, a);
		}
	}
	int pop() {
		if (pq.size() == 0)return 0;
		int a = pq.front();
		pq.erase(pq.begin());
		return a;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		PQ pq;
		vector<int>v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			pq.insert(v.front());
			v.erase(v.begin());
		}
		vector<int> sum;
		for (int i = 0; i < n; i++) {
			v.push_back(pq.pop());
			if (v.size() != 1) {
				sum.push_back(v.front() + v.back());
			}
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n - 1; i++) {
			cout << sum.front()<<" ";
			sum.erase(sum.begin());
		}
		cout << "\n";
	}
}