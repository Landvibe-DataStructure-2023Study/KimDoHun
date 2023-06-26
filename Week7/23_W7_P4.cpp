#include<iostream>
#include<vector>
using namespace std;

bool a = false;
class Node {
public:
	Node* parent;
	vector <Node*> childList;
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
	Node* root;
	vector <Node*> nodeList;
	Tree() {
		root = new Node(nullptr,1,0);
		nodeList.push_back(root);
	}
	Node* FindNode(int x) {
		for (Node* c : nodeList) {
			if (c->value == x) {
				return c;
			}
		}
		return nullptr;
	}
	void Insert(int x, int y) {
		Node* parentNode = FindNode(x);
		Node* childNode = new Node(parentNode, y,parentNode->depth+1);
		parentNode->childList.push_back(childNode);
		nodeList.push_back(childNode);

	}
	void preOrderFile(Node* v, int k) {
		Node* curNode = v;
		if (curNode->depth == k && curNode->childList.size() == 0) {
			cout << curNode->value << " ";
			a = true;
		}
		for (Node* c : curNode->childList) {
			preOrderFile(c, k);
		}
	}
};
int main() {
	Tree tree;
	int n, m;
	cin >> n >> m;
	n--;
	while (n--) {
		int x, y;
		cin >> x >> y;
		tree.Insert(x, y);
	}
	while (m--) {
		int x;
		cin >> x;
		tree.preOrderFile(tree.FindNode(1), x);
		if (a == false) {
			cout << "-1";
		}
		cout << "\n";
		a = false;
	}
}