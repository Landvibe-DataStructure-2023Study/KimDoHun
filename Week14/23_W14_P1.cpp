#include<iostream>
#include<vector>
using namespace std;



vector<int> graph[101];
bool visited[101];
int c = 0;

void dfs(int a,int b) {
	c++;
	if (a == b) cout << c << "\n";

	visited[a] = true;
	for (auto i : graph[a]) {
		if (!visited[i]) { dfs(i, b); }
	}
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		dfs(a, b);

		for (int i = 0; i <= 100; i++) {
			visited[i] = false;
		}
		c = 0;
	}

}