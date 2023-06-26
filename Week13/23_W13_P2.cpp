#include<iostream>
#include<array>
#include<vector>

using namespace std;

bool edge[501][501]{ false };
vector <int> vertex;
int same[501]{ 0 };

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < d; i++) {
		int a, b;
		cin >> a >> b;
		same[a] = b;
		same[b] = a;
	}
	for (int i = 1; i <= n; i++) {/////////////////
		for (int o = 1; o <= n; o++) {
			cin >> edge[i][o];
			if (edge[i][o]) {
				vertex.push_back(i);//////////////////////
				vertex.push_back(o);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int k, s;
		cin >> k >> s;
		bool rec[501]{ false };
		if (s == 1) {
			for (int f : vertex) {
				if (edge[k][f]) {
					rec[f] = 1;
					rec[same[f]] = 1;/////////////
				}
			}
		}
		else if (s == 2) {
			for (int f : vertex) {
				if (edge[k][f]) rec[f] = 1;
				rec[same[f]] = 1;
				for (int ff : vertex) {
					if (edge[f][ff])rec[ff] = 1;
					rec[same[ff]] = 1;
				}
			}
		}
		rec[same[k]] = 0;
		rec[k] = 0;
		for (int o = 1; o < 501; o++) {
			if (rec[o])cout << o << " ";
		}
		cout << "\n";
	}
}