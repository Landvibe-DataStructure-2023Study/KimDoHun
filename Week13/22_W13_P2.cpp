//2023_05_25 김도훈
//자료구조
//22_W13_P2

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int graph[501][501];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int numOfSubscribers, numOfCmd, numberOfUser,F;
	cin >> numOfSubscribers >> numOfCmd;

	for (int i = 1; i <= numOfSubscribers; i++) {
		for (int j = 1; j <= numOfSubscribers; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < numOfCmd; i++) {
		cin >> numberOfUser >> F; //numberOfUser를 t라고 명칭(너 t야?)
		if (F == 0) { //t의 친구의 친구를 찾는다.
			vector<int>friendOfFriend;
			bool noFF = 1; //t와 j의 친친이 아무도 없을경우 0을 출력
			//t와 j가 친구가 아니라면 t와 j가 친친인지 검사
			for (int j = 1; j <= numOfSubscribers; j++) {
				if (numberOfUser == j) continue; //numberOfUser와 j가 동일인물일 경우 검사하지 않는다.
				if (graph[numberOfUser][j]) continue; //t와 j가 친구라면 j는 검사하지 않는다.
				for (int l = 1; l <= numOfSubscribers; l++) { //l은 t와j와 각각 친구인지의 검사 대상임
					//ㅣ을 앞으로 고정
					if (numberOfUser == l) continue;
					bool jInVec = 0;
					if (graph[l][numberOfUser] && graph[l][j]) { //ㅣ이 t와 j와 각각 친구이므로 t와j는 친친임
						for (int numberOfFF : friendOfFriend) {
							if (numberOfFF == j) {
								jInVec = 1;
								break;
							}
						}
						if (!jInVec) {
							friendOfFriend.push_back(j);
							jInVec = 1;
							noFF = 0;
						}
					}
					if (jInVec) break;
				}
			}
			if (noFF) cout << "0\n";
			else {
				sort(friendOfFriend.begin(), friendOfFriend.end());
				for (int FF : friendOfFriend) {
					cout << FF << " ";
				}
				cout << "\n";
			}
		}
		else if (F == 1) { //t의 친구의 동료를 찾는다.
			bool noPF=1;
			vector<int>partnerOfFriend;
			//t와 j가 친구일 때 j의 동료 l이 t와 아무 관계가 아닌지 검사
			for (int j = 1; j <= numOfSubscribers; j++) {
				if (numberOfUser == j) continue;
				if (graph[numberOfUser][j]) {
					for (int l = 1; l <= numOfSubscribers; l++) {
						if (numberOfUser == l) continue;
						if (graph[j][l] == 2&&graph[numberOfUser][l]==0) {
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