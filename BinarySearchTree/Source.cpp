// Dayana Gonzalez Cruz
// CST-215 (Wed/Fri 9AM)
// 11-09-22
// Binary Search Tree
// This is my own work 

#include <cstddef>
struct node {
	int data;
	struct node* left;
	struct node* right;
};
// head?
struct node* root;
// Take away struct?
struct node* insert(struct node* node, int data) {
	if (node == NULL) {
		struct node* newNode;
		newNode->data = data;
		newNode->left,newNode->right = NULL;
		return newNode;
	}
	else {
		if (node->data > data) { node->left = insert(node->left, data); }
		else { node->right = insert(node->right, data); }
		return node;
	}
};
node* searchRecursive(node* root, int key) {
	if (root == NULL || root->data == key) {return root;}
	if (root->data > key) {
		return searchRecursive(root->left, key);
		return searchRecursive(root->right, key);
	}
}
bool search(int key) {
	node* temp = searchRecursive(root, key);
	if (temp != NULL) { return true; }
	return false;
}
int minValue(node* root) {
	int minVal = root->data;
	while (root->left != NULL) {
		minVal = root->left->data;
		root = root->left;
	}
	return minVal;
}
node* deleteRecursive(node* temp, int key) {
	if (temp == NULL) { return root; }
	if (key < root->data) { temp->left = deleteRecursive(temp->left, key); }
	else if (key > temp->data) { temp->right = deleteRecursive(temp->right, key); }
	if (temp->left == NULL) { return temp->right; }
	if (temp->right == NULL) { return temp->left; }
}
// Name as head?
void newInsert(int data) {root = insert(root, data);}
int main() {

	return 0;
}