//2023_04_07 ±èµµÈÆ
//ÀÚ·á±¸Á¶ W6_P2

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
	//void DeleteNode(int v) {
	//	Node* deleteNode = FindNode(v);
	//	for (int i = 0; i < deleteNode->childList.size(); i++) {
	//		deleteNode->parent->childList.push_back(deleteNode->childList[i]);
	//		deleteNode->childList[i]->parent = deleteNode->parent;
	//	}
	//	for (int i = 0; i < deleteNode->parent->childList.size(); i++) {
	//		if (deleteNode->parent->childList[i] == deleteNode) {
	//			deleteNode->parent->childList.erase(deleteNode->parent->childList.begin() + i);
	//			break;
	//		}
	//	}
	//	for (int i = 0; i < nodeList.size(); i++) {
	//		if (nodeList[i] == deleteNode) {
	//			nodeList.erase(nodeList.begin() + i);
	//			break;
	//		}
	//	}
	//	delete deleteNode;
	//}
	void PreOrder(Node* v) {
		cout <<(v==root?0: v->parent->value) << " ";
		if (v->childList.size() != 0) {
			for (Node* child : v->childList) {
				PreOrder(child);
			}
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
		while (n--) {
			int p, c;
			cin >> p >> c;
			tree.InsertNode(p, c);
		}
		tree.PreOrder(tree.FindNode(1));
		cout << "\n";
	}
}
