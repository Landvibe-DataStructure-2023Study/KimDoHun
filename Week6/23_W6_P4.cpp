#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	vector<Node*>childList;
	Node* parent;
	int value;
	int depth;
	Node(Node* p, int v, int d) {
		parent = p;
		value = v;
		depth = d;
	}
};

class Tree {
public:
	vector <Node*> nodeList;
	Node* root;
	Tree() {
		root = new Node(nullptr, 1, 0);
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
		Node* cNode = FindNode(y);
		if (parentNode == nullptr || cNode != nullptr) {
			cout << "-1\n";
			return;
		}
		Node* childNode = new Node(parentNode, y, parentNode->depth + 1);
		parentNode->childList.push_back(childNode);
		nodeList.push_back(childNode);
	}
	void PrintDepth(int x, int y) {
		Node* xNode = FindNode(x);
		Node* yNode = FindNode(y);
		if (xNode == nullptr || yNode == nullptr) {
			cout << "-1\n";
			return;
		}
		cout << xNode->depth + yNode->depth << "\n";
	}
};
int main() {
	Tree tree;
	int n, m;
	cin >> n >> m;
	while (n--) {
		int x, y;
		cin >> x >> y;
		tree.Insert(x, y);
	}
	while (m--) {
		int v, w;
		cin >> v >> w;
		tree.PrintDepth(v, w);
	}
}