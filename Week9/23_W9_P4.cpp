
//비정렬벡터 선택정렬
#include<iostream>
#include<vector>
using namespace std;

class PQ {
public:
	vector<int>v;
	void insert(int a) {
		v.push_back(a);
	}
	int pop() {
		int popNum = v[0];
		int idx = 0;
		for (int i = 0; i < v.size(); i++) {
			if (popNum % 5 == 0 && v[i] % 5 != 0) {
				popNum = v[i];
				idx = i;
			}
			else if ( (popNum % 5 != 0 && v[i] % 5 != 0)||(popNum % 5 == 0 && v[i] % 5 == 0)) {
				popNum = (popNum < v[i] ? popNum:v[i]);
				idx = (popNum < v[i] ? idx:i);
				//삼항연산자 오류가 있었음
			}
		}
		v.erase(v.begin() + idx);
		return popNum;
	}
	void print() {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
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
			pq.insert(v.front());
			v.erase(v.begin());
		}

		for (int i = 0; i < n; i++) {
			v.push_back(pq.pop());
			pq.print();
		}
		for (int i = 0; i < n; i++) {
			cout << v[i]<<" ";
		}
		cout << "\n";
	}
}