#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
};
struct Tree {
	Node* root;
};
struct Node* createNode(int val) {
	Node* newNode = new Node();
	newNode->val = val;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}
struct Tree* createTree(int val) {
	Tree* newTree = new Tree();
	newTree->root = createNode(val);
	return newTree;
}
bool isEmpty(Tree* tree) {
	return tree->root == nullptr;
}
void insertNode(Tree* tree, int val) {
	Node* newNode = createNode(val);
	if (tree->root == nullptr) {
		tree->root = newNode;
		return;
	}
	Node* current = tree->root;
	Node* parent = nullptr;
	while (true) {
		parent = current;
		if (val < current->val) {
			current = current->left;
			if (current == nullptr) {
				parent->left = newNode;
				return;
			}
		}
		else {
			current = current->right;
			if (current == nullptr) {
				parent->right = newNode;
				return;
			}
		}
	}
}
void preorder(Node* node) {
	if (node == nullptr) return;
	cout << node->val << ' ';
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node* node) {
	if (node == nullptr) return;
	inorder(node->left);
	cout << node->val << ' ';
	inorder(node->right);
}

void postorder(Node* node) {
	if (node == nullptr) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->val << ' ';
}
int main()
{
	Tree* tree = createTree(10);
	insertNode(tree, 5);
	insertNode(tree, 15);
	insertNode(tree, 3);
	insertNode(tree, 7);
	insertNode(tree, 12);
	insertNode(tree, 18);
	cout << "Preorder: ";
	preorder(tree->root);
	cout << endl;
	cout << "Inorder: ";
	inorder(tree->root);
	cout << endl;
	cout << "Postorder: ";
	postorder(tree->root);
	cout << endl;
	return 0;
}
