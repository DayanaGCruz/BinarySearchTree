// Dayana Gonzalez Cruz
// CST-215 (Wed/Fri 9AM)
// 11-13-22
// Binary Search Tree
// This is my own work 
static int e;
#include <cstddef>
#include <string>
#include <iostream>
#include <fstream>
struct node {
	std::string data;
	struct node* left;
	struct node* right;
};
struct node* root = NULL;
struct node* insert(struct node* node, std::string data) {
	if (node == NULL) {
		struct node* newNode = new struct node;
		newNode->data = data;
		newNode->left = NULL; newNode->right = NULL;
		return newNode;
	}
	else {
		if (node->data > data) { node->left = insert(node->left, data); }
		else { node->right = insert(node->right, data); }
		return node;
	}
}
node* searchRecursive(node* root, std::string key) {
	e++;
	if (root == NULL || root->data == key) {return root;}
	if (root->data > key) {
		return searchRecursive(root->left, key);
		//return searchRecursive(root->right, key);
	}
	else{ return searchRecursive(root->right, key); }
}
bool search(std::string key) {
	e = 0;
	node* temp = searchRecursive(root, key);
	if (temp != NULL) { return true; }
	return false;
}
//std::string minValue(node* root) {
//	std::string minVal = root->data;
//	while (root->left != NULL) {
//		minVal = root->left->data;
//		root = root->left;
//	}
//	return minVal;
//}
struct node* minValue(node* root) {
	struct node* current = root;
	while (current != NULL && current->left != NULL) {
		current = current->left;
	}
	return current;
}
node* deleteRecursive(node* temp, std::string key) {
	if (temp == NULL) { 
		return root; 
	}
	if (key < root->data) { 
		temp->left = deleteRecursive(temp->left, key); 
	}
	else if (key > temp->data) { 
		temp->right = deleteRecursive(temp->right, key); 
	}
	else {
		if (temp->left == NULL && temp->right == NULL) { 
			return root;
		}
		else if (temp->right == NULL) {
			return temp->left; 
		}
		else if (temp->left == NULL) {
			return temp->right;
		}
		else {
			//temp->data = minValue(temp->right);
			temp->data = minValue(temp->right)->data;
			temp->right = deleteRecursive(temp->right, temp->data);
		}
	}
	return temp;
}
void deleteKey(std::string key) { root = deleteRecursive(root, key); }
void newInsert(std::string data) {root = insert(root, data);}
//void display(node* temp) {
//	if (temp == NULL) {
//		return;
//	}
//	else { 
//		display(temp->left);
//		std::cout << temp->data << " ";
//		display(temp->right);
//	}
//}
void inOrderTraversal(node* root) {
	if (root != NULL) {
		inOrderTraversal(root->left);
		std::cout << root->data << " ";
		inOrderTraversal(root->right);
	}
}
void inOrder() {
	inOrderTraversal(root);
}
std::string removePunct(std::string s) {
	std::string apos = "'";
	std::string hyphen = "-";
	for (int i = 0; i < s.length(); i++) {
		if (ispunct(s[i]) && s[i] != apos[0] && s[i] != hyphen[0]) {
			return removePunct(s.substr(0, i) + s.substr(i + 1, s.length())); }
	}
	if (s[s.length() - 1] == '-') { return s.substr(0, s.length()-1); }
	return s;
}
int main() {
	std::string s;
	std::ifstream inputFile;
	inputFile.open("Input.in");
	if (inputFile.is_open()) {
		while (!inputFile.eof()) {
			inputFile >> s;
			s = removePunct(s);
			if (!search(s)) {newInsert(s);}
		}
	}
	//display(root);
	inOrder();
	inputFile.close();
	while (s != "-1") {
		std::cout << std::endl << std::endl << "Enter string to search for or -1 to exit: ";
		std::cin >> s;
		if (s != "-1") {
			if (search(s)) { std::cout << std::endl << "Inspected " << e << " elements" << std::endl << "'" + s + "'" + " located"; }
			else { std::cout << std::endl << "Inspected " << e << " elements" << std::endl << "'" + s + "'" + " not in tree"; }
		}
	}
	s = "";
	while (s != "-1") {
		std::cout << std::endl << std::endl << "Enter string to remove for or -1 to exit: ";
		std::cin >> s;
		deleteKey(s);
		//display(root);
		inOrder();
	}
	return 0;
}