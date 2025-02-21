#include "BST.hpp"
#include <iostream>


int main()
{
    BST <int>tree;
	// tree.insert(tree.createNode(20));

	// tree.insert(tree.createNode(8));
	// tree.insert(tree.createNode(22));
	// tree.insert(tree.createNode(4));
	// tree.insert(tree.createNode(12));
	// tree.insert(tree.createNode(10));
	// tree.insert(tree.createNode(14));

////////////////////////////////////////////////
	tree.insert(tree.createNode(10));
	tree.insert(tree.createNode(5));
	tree.insert(tree.createNode(15));
	tree.insert(tree.createNode(12));
	tree.insert(tree.createNode(18));
	tree.deleteNode(tree.getter(), 5);
/////////////////////////////////////////////////
	tree.printInOrder(tree.getter());
	// cout << endl;
	// tree.printPreOrder(tree.getter());
	// cout << endl;
	// tree.printPostOrder(tree.getter());
	// Node<int>* find = tree.search(tree.getter(), 61);
	// if (find)
	// 	cout <<"yhn->" << find->val<<endl;
	// else
	// 	cout << "not found\n";
	// Node<int>* pred = tree.predecessor(tree.getter(), 12);
	// if (pred)
	// 	cout << "predecessor of 10 is-> " << pred->val << endl;
	// Node<int>* succ = tree.successor(tree.getter(), 12);
	// if (succ)
	// 	cout << "successor of 10 is-> " << succ->val << endl;
}
