//2023_04_11 ±èµµÈÆ
//ÀÚ·á±¸Á¶ 21_W7_P2

#include <iostream>
#include<vector>
using namespace std;

class Node {
public:
	Node* parent;
	int value;
	int depth;
	vector<Node*> childList;

	Node(Node* p, int v, int d) {
		parent = p;
		value = v;
		depth = d;
	}
};

class Tree {
private:
	Node* root;
	vector<Node*> nodeList;
public:
	Tree() {
		root = new Node(nullptr, 1, 0);
		nodeList.push_back(root);
	}
	Node* FindNode(int v) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (nodeList[i]->value == v) {
				return nodeList[i];
			}
		}
		return nullptr;
	}
	void InsertNode(int p, int c) {
		Node* parentNode = FindNode(p);
		Node* childNode = FindNode(c);
		if (parentNode == nullptr || childNode != nullptr) {
			cout << "-1\n";
			return;
		}
		Node* newNode = new Node(parentNode, c, parentNode->depth + 1);
		parentNode->childList.push_back(newNode);

		nodeList.push_back(newNode);
	}

	void PostOrder(Node* v) {

		if (v->childList.size() != 0) {
			for (Node* child : v->childList) {
				PostOrder(child);
			}
		}
		cout << (v == root ? 1 : v->value) << " ";
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		Tree tree;
		int n;
		cin >> n;
		vector<int> inputVector;
		for (int i = 0; i < n;i++) {
			int x;
			cin >> x;
			if (x != 1) {
				inputVector.push_back(x);
			}
		}
		Node* preNode = tree.FindNode(1);
		int preDepth = 0;
		for (int i = 0; i < n; i++) {
			int d;
			cin >> d;
			if (d == 0) continue;
			else if (preDepth == 0 || preDepth<d) {
				tree.InsertNode(preNode->value, inputVector.front());
				preNode = tree.FindNode(inputVector.front());
				preDepth = d;
				inputVector.erase(inputVector.begin());
			}
			else if(preDepth==d) {
				tree.InsertNode(preNode->parent->value, inputVector.front());
				preNode = tree.FindNode(inputVector.front());
				preDepth = d;
				inputVector.erase(inputVector.begin());
			}
			else {
				tree.InsertNode(preNode->parent->parent->value, inputVector.front());
				preNode = tree.FindNode(inputVector.front());
				preDepth = d;
				inputVector.erase(inputVector.begin());
			}
		}
		tree.PostOrder(tree.FindNode(1));
		cout <<"\n";
	}
}
