//2023_05_25 김도훈
//자료구조
//22_W13_P4

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int graph[501][501];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numOfSubscribers, numOfCmd, numberOfUser, F;
	cin >> numOfSubscribers >> numOfCmd;

	for (int i = 1; i <= numOfSubscribers; i++) {
		for (int j = 1; j <= numOfSubscribers; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < numOfCmd; i++) {
		cin >> numberOfUser >> F; //numberOfUser를 t라고 명칭(너 t야?)

		if (F == 0) { //t의 동료의 동료를 찾는다.
			bool noPP = 1;
			vector<int>partnerOfPartner;
			//t와 j가 동료일 때 j의 동료 l이 t와 아무 관계가 아닌지 검사
			for (int j = 1; j <= numOfSubscribers; j++) {
				if (numberOfUser == j) continue;
				if (graph[numberOfUser][j]==2) {
					for (int l = 1; l <= numOfSubscribers; l++) {
						if (numberOfUser == l) continue;
						if (graph[j][l] == 2 && graph[numberOfUser][l] == 0) {
							bool existInVec = 0;
							for (int PF : partnerOfPartner) {
								if (PF == l) existInVec = 1;
							}
							if (existInVec == 0) {
								partnerOfPartner.push_back(l);
								noPP = 0;
							}
						}
					}
				}
			}
			if (noPP) cout << "0\n";
			else {
				sort(partnerOfPartner.begin(), partnerOfPartner.end());
				for (int PP : partnerOfPartner) {
					cout << PP << " ";
				}
				cout << "\n";
			}
		}
		else if (F == 1) { //t의 동료의 친구를 찾는다.
			bool noPF = 1;
			vector<int>partnerOfFriend;
			//t와 j가 동료일 때 j의 친구 l이 t와 아무 관계가 아닌지 검사
			for (int j = 1; j <= numOfSubscribers; j++) {
				if (numberOfUser == j) continue;
				if (graph[numberOfUser][j] == 2) {
					for (int l = 1; l <= numOfSubscribers; l++) {
						if (numberOfUser == l) continue;
						if (graph[j][l] == 1 && graph[numberOfUser][l] == 0) {
							bool existInVec = 0;
							for (int PF : partnerOfFriend) {
								if (PF == l) existInVec = 1;
							}
							if (existInVec == 0) {
								partnerOfFriend.push_back(l);
								noPF = 0;
							}
						}
					}
				}
			}
			if (noPF) cout << "0\n";
			else {
				sort(partnerOfFriend.begin(), partnerOfFriend.end());
				for (int PF : partnerOfFriend) {
					cout << PF << " ";
				}
				cout << "\n";
			}
		}

	}

}