#pragma once
#include <cstddef>
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T val;
    Node *left;
    Node *right;
    // Node(T val) {this->val = val;left = NULL;right = NULL;}
	// ~Node(){};
};

template <typename T>
class BST
{
private:
    Node<T> *root;
public:
    BST(){root = NULL;}
    Node<T>*	insert(Node<T>* root, Node<T>* node);
    Node<T>*	insert(Node<T>* node);
	void printInOrder(Node<T>* node) const;//Left->Root->Right
	void printPreOrder(Node<T>* node) const;//Root-?Left->Right
	void printPostOrder(Node<T>* node) const;//Left->Right->Root
	Node<T>*	search(Node<T>* root, T val);
    Node<T>*	createNode(T val);
	Node<T>*	predecessor(Node<T> *root, T val);
	Node<T>*	successor(Node<T> *root, T val);
	Node<T>*	deleteNode(Node<T>* root, T val);
	Node<T>*	getter(){return root;}
};

#include "BST.tpp"