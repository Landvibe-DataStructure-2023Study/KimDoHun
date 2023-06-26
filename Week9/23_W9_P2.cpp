//9_2 선택정렬 비정렬벡터
#include<iostream>
#include<vector>
using namespace std;

class PQ {
public:
	vector<int> pq;
	void push(int v) {
		pq.push_back(v);
	}
	int pop() {
		int popNum = pq[0];
		int idx = 0;
		for (int i = 0; i < pq.size(); i++) {
			if (popNum % 5 != 0 && pq[i] % 5 == 0) {
				popNum = pq[i];
				idx = i;
			}
			else if ((popNum % 5 == 0 && pq[i] % 5 == 0) || (popNum % 5 != 0 && pq[i] % 5 != 0)) {
				popNum = (popNum > pq[i] ? popNum : pq[i]);
				idx = (popNum > pq[i] ? idx : i);
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
		vector<int> v;
		PQ pq;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			v.push_back(a);
		}
		for (int i = 0; i < n; i++) {
			pq.push(v.front());
			v.erase(v.begin());
		}
		for (int i = 0; i < n; i++) {
			cout << pq.pop() << " ";
		}
		cout << "\n";
	}
}