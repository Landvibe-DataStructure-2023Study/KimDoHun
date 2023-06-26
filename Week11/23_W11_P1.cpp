//이진탐색트리

#include<iostream>

using namespace std;

int sum = 0;

class Node {
public:
	Node* parent;
	Node* left;
	Node* right;
	int value;
	Node(int v) {
		value = v;
		parent = left = right = nullptr;
	}
};

class BST {
public:
	Node* root = nullptr;

	void insert(int v) {
		Node* newNode = new Node(v);
		if (root == nullptr) {
			root = newNode;
			return;
		}

		Node* curNode = root;
		Node* parNode = curNode->parent;

		while (curNode != nullptr) {
			if (curNode->value > v) {
				parNode = curNode;
				curNode = curNode->left;
			}
			else if (curNode->value < v) {
				parNode = curNode;
				curNode = curNode->right;
			}
		}

		newNode->parent = parNode;
		if (parNode->value > v) {
			parNode->left = newNode;
		}
		else if (parNode->value < v) {
			parNode->right = newNode;
		}
	}

	Node* search(int v) {
		Node* curNode = root;
		while (curNode != nullptr) {
			if (curNode->value == v) {
				return curNode;
			}
			else if (curNode->value > v) {
				curNode = curNode->left;
			}
			else if (curNode->value < v) {
				curNode = curNode->right;
			}
		}
		return nullptr;
	}

	void subSum(Node* node) {
		if (node == nullptr)return;
		subSum(node->left);
		subSum(node->right);
		sum++;
	}
};

int main() {
	BST bst;
	int n, m;
	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		bst.insert(x);
	}
	while (m--) {
		sum = 0;
		int x, y;
		cin >> x >> y;
		bst.subSum(bst.search(x)->left);
		bst.subSum(bst.search(y)->left);
		cout << sum << "\n";
	}
}