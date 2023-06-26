#include<iostream>
#include<vector>

using namespace std;

class Node {
public:
	Node* parent;
	vector <Node*> childList;
	int value;
	int depth;
	Node() {
		parent = nullptr;
		value = 0;
		depth = 0;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> nodeList;
	Tree() {
		root = new Node();
		root->value = 1;
		nodeList.push_back(root);
	}
	Node* FindNode(int x) {
		for (Node* v : nodeList) {
			if (v->value == x) {
				return v;
			}
		}
		return nullptr;
	}
	void Insert(int x, int y) {
		Node* parentNode = FindNode(x);
		Node* childNode = FindNode(y);
		if (parentNode == nullptr || childNode != nullptr) {
			cout << "-1\n";
			return;
		}
		Node* newNode = new Node();
		newNode->parent = parentNode;
		newNode->value = y;
		newNode->depth = parentNode->depth + 1;
		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void Delete(int x) {
		Node* deleteNode = FindNode(x);
		if (deleteNode == nullptr) {
			cout << "-1\n";
			return;
		}
		for (Node* v : deleteNode->childList) {
			deleteNode->parent->childList.push_back(v);
			v->parent = deleteNode->parent;
		}
		for (int i = 0; i < deleteNode->parent->childList.size(); i++) {
			if (deleteNode->parent->childList[i] == deleteNode) {
				deleteNode->parent->childList.erase(deleteNode->parent->childList.begin() + i);
			}
		}
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i] == deleteNode) {
				nodeList.erase(nodeList.begin() + i);
			}
		}
	}
	void Parent(int x) {
		Node* childNode = FindNode(x);
		if (childNode == nullptr) {
			cout << "-1\n";
			return;
		}
		cout << childNode->parent->value << "\n";
	}
	void Child(int x) {
		Node* parentNode = FindNode(x);
		if (parentNode == nullptr || parentNode->childList.size() == 0) {
			cout << "-1\n";
			return;
		}
		for (Node* v : parentNode->childList) {
			cout << v->value << " ";
		}
		cout << "\n";
	}
	void MinMaxChild(int x) {
		Node* parentNode = FindNode(x);
		if (parentNode == nullptr || parentNode->childList.size() < 2) {
			cout << "-1\n";
			return;
		}
		int min = parentNode->childList[0]->value;
		int max = parentNode->childList[0]->value;
		for (Node* v : parentNode->childList) {
			if (min > v->value) {
				min = v->value;
			}
			if (max < v->value) {
				max = v->value;
			}
		}
		cout << max - min << "\n";
	}
};
int main() {
	int t;
	cin >> t;
	Tree tree;
	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "insert") {
			int x, y;
			cin >> x >> y;
			tree.Insert(x, y);
		}
		else if (cmd == "delete") {
			int x;
			cin >> x;
			tree.Delete(x);
		}
		else if (cmd == "parent") {
			int x;
			cin >> x;
			tree.Parent(x);
		}
		else if (cmd == "child") {
			int x;
			cin >> x;
			tree.Child(x);
		}
		else if (cmd == "min_maxChild") {
			int x;
			cin >> x;
			tree.MinMaxChild(x);
		}
	}
}