#include<iostream>
#include<array>
#include<string>
using namespace std;

int main() {
	int t, n;
	cin >> t >> n;

	int* arr = new int[n] {0};
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "at") {
			int i;
			cin >> i;
			cout << arr[i] << "\n";
		}
		else if (cmd == "add") {
			int i, z;
			cin >> i >> z;
			for (int j = n - 2; j >= i; j--) {
				arr[j + 1] = arr[j];
			}
			arr[i] = z;
		}

		else if (cmd == "remove") {
			int i;
			cin >> i;
			for (int j = i + 1; j <= n - 1; j++) {
				arr[j - 1] = arr[j];
			}
			arr[n - 1] = 0;
		}
		else if (cmd == "set") {
			int i, z;
			cin >> i >> z;
			arr[i] = z;
		}
		else if (cmd == "find_max") {
			int max = arr[0];
			for (int i = 0; i < n; i++) {
				if (max < arr[i]) {
					max = arr[i];
				}
			}
			cout << max << "\n";
		}
		else if (cmd == "print") {
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
	}
}