#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	vector <Node*> childList;
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
	vector<Node*> nodeList;
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
		Node* childNode = new Node(parentNode, y, parentNode->depth + 1);
		parentNode->childList.push_back(childNode);
		nodeList.push_back(childNode);
	}
	void Preorder(Node* curNode) {
		if (curNode->childList.size() == 0) {
			cout << curNode->depth<<" ";
		}
		else {
			cout << curNode->childList.size() << " ";
		}
		for (Node* v : curNode->childList) {
			Preorder(v);
		}
	}
};
int main() {
	int t;
	cin >> t;
	while (t--) {
		Tree tree;
		int n;
		cin >> n;
		for (int i = 0; i < n-1; i++) {
			int x, y;
			cin >> x >> y;
			tree.Insert(x, y);
		}
		tree.Preorder(tree.FindNode(1));
		cout << "\n";
	}
}