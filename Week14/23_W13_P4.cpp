//2023_05_28 김도훈
//자료구조
//23_W13_P4

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int graph[501][501];
int refuseList[501]{ 0 };
vector<int> vertexList;

void pushVec(vector<int>& vec, int a) {
	bool exist = 0;
	for (int num : vec) {
		if (num == a) exist = 1;
	}
	if (!exist) vec.push_back(a);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numOfSubscribers, numOfCmd, numOfRefuser;
	cin >> numOfSubscribers >> numOfCmd >> numOfRefuser;

	for (int i = 0; i < numOfRefuser; i++) {
		int numberOfRefuser;
		cin >> numberOfRefuser;
		refuseList[numberOfRefuser] = true;
	}

	for (int i = 1; i <= numOfSubscribers; i++) {
		for (int j = 1; j <= numOfSubscribers; j++) {
			cin >> graph[i][j];
			if (graph[i][j]) {
				pushVec(vertexList, i);
				pushVec(vertexList, j);
			}
		}
	}

	for (int i = 0; i < numOfCmd; i++) {
		int numberOfUser, S;
		vector <int> recommend;
		cin >> numberOfUser >> S;

		if (S == 1) {
			for (int numA : vertexList) {
				if (graph[numberOfUser][numA] && refuseList[numA]==0) {
					pushVec(recommend, numA);
				}
			}
		}
		else if (S == 2) {
			for (int numA : vertexList) {
				if (graph[numberOfUser][numA]) {
					if(refuseList[numA]==0) pushVec(recommend, numA);

					for (int numB : vertexList) {
						if (graph[numA][numB] && numB != numberOfUser && refuseList[numB]==0) {
							pushVec(recommend, numB);
						}
					}
				}
			}
		}

		sort(recommend.begin(), recommend.end());

		if (recommend.size() == 0) cout << "0\n";
		else {
			for (int num : recommend) {
				cout << num << " ";
			}
			cout << "\n";
		}
	}
}