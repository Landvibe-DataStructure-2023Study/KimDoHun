#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
	vector<Node*> childList;
	Node* parent;
	int value;
	int cap;
	int lowcap;
	Node(Node* p, int v) {
		parent = p;
		value = v;
		cap = 0;
		lowcap = 0;
	}
};
class Tree {
public:
	vector<Node*> nodeList;
	Node* root;
	Tree() {
		root = new Node(nullptr, 1);
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
		Node* childNode = new Node(parentNode, y);
		parentNode->childList.push_back(childNode);
		nodeList.push_back(childNode);
	}
	void LowCapSum(Node* v,Node* nodeForSum) {
		nodeForSum->lowcap += v->cap;
		for (Node* c : v->childList) {
			LowCapSum(c,nodeForSum);
		}
	}
	void PostOrderLowCapSumPrint(Node* v,int cap) {
		for (Node* c : v->childList) {
			PostOrderLowCapSumPrint(c,cap);
		}
		if (v->lowcap > cap) {
			cout << v->value << " ";
		}
	}
	void PostOrderValue(Node* v) {
		for (Node* c : v->childList) {
			PostOrderValue(c);
		}
		cout << v->value << " ";
	}
	void PostOrderCap(Node* v) {
		for (Node* c : v->childList) {
			PostOrderCap(c);
		}
		cout << v->cap << " ";
	}
};
int main() {
	Tree tree;
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree.Insert(x, y);
	}
	tree.PostOrderValue(tree.FindNode(1));
	cout << "\n";
	for (int i = 0; i < n; i++) {
		int x, w;
		cin >> x >> w;
		tree.FindNode(x)->cap = w;
	}
	tree.PostOrderCap(tree.FindNode(1));
	cout << "\n";
	for (Node* v : tree.nodeList) {
		tree.LowCapSum(v,v);
	}
	tree.PostOrderLowCapSumPrint(tree.FindNode(1),c);
}