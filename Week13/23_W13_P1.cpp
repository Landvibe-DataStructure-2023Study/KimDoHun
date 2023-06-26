#include<iostream>
#include<vector>
#include<array>

using namespace std;

bool edge[10001][10001]{ false };
vector <int> vertex;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "insertVertex") {
			int s;
			bool exist = 0;
			cin >> s;
			for (int v : vertex) {
				if (v == s) {
					cout << "Exist\n";
					exist = 1;
					break;
				}
			}
			if (!exist) {
				vertex.push_back(s);
			}
		}
		else if (cmd == "insertEdge") {
			int s, d;
			cin >> s >> d;
			if (edge[s][d]) cout << "Exist\n";
			else {
				edge[s][d] = true;
				edge[d][s] = true;
			}
		}
		else if (cmd == "eraseEdge") {
			int s, d;
			cin >> s >> d;
			if (!edge[s][d]) cout << "None\n";
			else {
				edge[s][d] = false;
				edge[d][s] = false;
			}
		}
		else if (cmd == "isAdjacentOdd") {
			int s,adjacent=0;
			cin >> s;
			for (int v : vertex) {
				if (edge[s][v]) adjacent++;
			}
			if (adjacent % 2) {
				cout << "True " << adjacent << "\n";
			}
			else if(adjacent==0||adjacent%2==0) {
				cout << "False " << adjacent << "\n";
			}
		}
		else if (cmd == "minEdgeVertex") {
			bool noVertex = 1;
			int minEdgeVertex = -1;
			int minEdgeNum = 10000;
			for (int a : vertex) {
				int aEdge = 0;
				for (int b : vertex) {
					if (edge[a][b]) aEdge++;
				}
				if (minEdgeNum == aEdge) {
					minEdgeVertex = (minEdgeVertex > a ? a : minEdgeVertex);
				}
				else if (minEdgeNum > aEdge) {
					noVertex = 0;
					minEdgeVertex = a;
					minEdgeNum = aEdge;
				}
			}
			if (noVertex || minEdgeNum == 0) cout << "-1\n";
			else cout << minEdgeVertex << "\n";
		}
	}
}