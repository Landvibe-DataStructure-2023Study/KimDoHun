//비정렬벡터 선택정렬 우선순위큐
//처음과 마지막 원소의 차

#include<iostream>
#include<vector>
using namespace std;

class PQ {
public:
	vector<int>pq;
	void insert(int a) {
		pq.push_back(a);
	}
	int pop() {
		int popNum = pq[0];
		int idx = 0;
		for (int i = 0; i < pq.size(); i++) {
			if (popNum < pq[i]) {
				popNum = pq[i];
				idx = i;
			}
		}
		pq.erase(pq.begin() + idx);
		return popNum;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector <int> v;
		PQ pq;

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
		vector<int> gap;
		for (int i = 0; i < n; i++) {
			v.push_back(pq.pop());
			if (i != 0) {
				gap.push_back(v.front() - v.back());
			}
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		for (int i = 0; i < n-1; i++) {
			cout << gap[i] << " ";
		}
		cout << "\n";
	}

}