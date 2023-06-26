#include<iostream>
#include<vector>

using namespace std;

vector<int>graph[101];
bool visited[101];

int mNum = -1;
void dfs(int x) {
	if (mNum < x)mNum = x;
	visited[x] = true;
	for (auto i : graph[x]) {
		if (!visited[i])dfs(i);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		while (m--) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}
		while (q--) {
			int c;
			cin >> c;
			dfs(c);
			cout << mNum << "\n";
			for (int i = 0; i <= 100; i++) {
				visited[i] = 0;
			}
			mNum = -1;
		}
		for (int i = 1; i <= n; i++) {
			graph[i].clear();
		}
	}
}