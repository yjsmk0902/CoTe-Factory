#include<iostream>
using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* right;
};
Node* root = NULL;
Node* make_Tree(Node* node, int N) {
	if (node == NULL) {
		node = new Node();
		node->data = N;
		node->left = NULL;
		node->right = NULL;
	}
	else if (N < node->data) {
		node->left = make_Tree(node->left, N);
	}
	else {
		node->right = make_Tree(node->right, N);
	}
	return node;
}
void Postorder(Node* node) {
	if (node == NULL) {
		return;
	}
	Postorder(node->left);
	Postorder(node->right);
	cout << node->data << "\n";
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N) {
		root = make_Tree(root, N);
	}
	Postorder(root);
	return 0;
}