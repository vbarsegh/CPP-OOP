#include "BST.hpp"


template <typename T>
Node<T>*	BST<T>::createNode(T val)
{
	Node<T>* node = new Node<T>;
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

template <typename T>
Node<T>*	BST<T>::insert(Node<T>* root, Node<T>* node)
{
	if (root == NULL)
	{
		cout << "thn\n";
		root = node;
		return node;
	}
	if (root->val < node->val)
		root->right = insert(root->right, node);
	else
		root->left = insert(root->left, node);
	return (root);
}

template <typename T>
Node<T>*	BST<T>::insert(Node<T>* node)
{
	if (root == NULL)
	{
		root = node;
		return (root);
	}
	root = insert(root, node);
	return root;
}

///////////////////////////////////
template <typename T>
void BST<T>::printInOrder(Node<T>* node) const{
	if (node == NULL)
		return;
	printInOrder(node->left);
	std::cout << node->val << " " << endl;
	printInOrder(node->right);
}

template <typename T>
void BST<T>::printPreOrder(Node<T>* node) const {
	if (node == NULL)
		return;
	std::cout << node->val << " " << endl;
	printPreOrder(node->left);
	printPreOrder(node->right);
}

template <typename T>
void BST<T>::printPostOrder(Node<T>* node) const {
	if (node == NULL)
		return;
	printPostOrder(node->left);
	printPostOrder(node->right);//4
	std::cout << node->val << " " << endl;
}

// template <typename T>
// Node<T>* BST<T>::search(Node<T>* root, T val)
// {
// 	if (root == NULL)
// 		throw std::runtime_error("Exception: Not found");
// 	if (root->val == val)
// 		return (root);
// 	if (val < root->val)
// 		root = search(root->left, val);
// 	else
// 		root = search(root->right, val);
// 	return (root);
// }//miqich erkar lucum

template <typename T>
Node<T>* BST<T>::search(Node<T>* root, T val)
{
	if (root == NULL)
		return (NULL);
	if (root->val == val)
		return (root);
	if (val < root->val)
		return search(root->left, val);
	return search(root->right, val);
}

template <typename T>
Node<T>*	BST<T>::predecessor(Node<T> *root ,T val)
{
	//////menak en depqy arac chi vor inchi predecessory vor man enq uzum ganq ,eti chka tree-um,menq nayelen enq ete tree-um chka et val-ov node NULL enq return anum, bayc lav klni dra logikane avelacnenq,xosqi  9-i predecessor-@ asenq vor 10-na
	Node<T>* predecessor = NULL;
	Node<T>* node = search(root, val);
	if (!node)
		return (NULL);
		// Construct a BST
    //            20
    //          /    \
    //         8      22
    //       /   \
    //      4    12
    //          /  \
    //         10   14
	// 12-i predecessor-@ 10-n e, 8-in@ 4-@
	////////////ete node-@ uni dzax subtree,apa ira predecessor-@ linelua et dzax subtree-i aji amenanerqevi node-@(leaf)
	if (node->left)
	{
		node = node->left;
		while (node->right)
			node = node->right;
		predecessor = node;
		return (predecessor);
	}
	/////////////
	////////////ete chuni node-@ dzax subtree,ira predecessor-@ pntrelu enq iranic verev,dra hamar lava rootic ijnel nerqev
	// 10-in@ 8-n e, 14-in@ 12-@
	Node<T>* tmp = root;
	while (tmp)
	{
		if (val < tmp->val)
			tmp = tmp->left;
		else if (val > tmp->val)
		{
			predecessor = tmp;
			tmp = tmp->right;
		}
		else
			break ;
	}
	return (predecessor);
}


template <typename T>
Node<T>*	BST<T>::successor(Node<T> *root ,T val)
{
	
	Node<T>* successor = NULL;
	Node<T>* node = search(root, val);
	if (!node)
		return (NULL);
		// Construct a BST
    //            20
    //          /    \
    //         8      22
    //       /   \
    //      4    12
    //          /  \
    //         10   14
	// 12-i predecessor-@ 14-n e, 8-in@ 10-@
	////////////ete node-@ uni aj subtree,apa ira successor-@ linelua et aj subtree-i dzaxi amenanerqevi node-@(leaf)
	if (node->right)
	{
		node = node->right;
		while (node->left)
			node = node->left;
		successor = node;
		return (successor);
	}
	/////////////
	////////////ete chuni node-@ aj subtree,ira predecessor-@ pntrelu enq iranic verev,dra hamar lava rootic ijnel nerqev
	// 10-in@ 12-n e, 14-in@ 20-@
	Node<T>* tmp = root;
	while (tmp)
	{
		if (val < tmp->val)
		{
			successor = tmp;
			tmp = tmp->left;
		}
		else if (val > tmp->val)
			tmp = tmp->right;
		else
			break ;
	}
	return (successor);
}

template <typename T>
Node<T>* BST<T>::deleteNode(Node<T>* root, T val)
{
	if (!root)
		return (NULL);
	if (val < root->val)
	{
		root->left = deleteNode(root->left, val);
	}
	else if (val > root->val)
	{
		root->right = deleteNode(root->right, val);
	}
	else
	{
		if (!root->left && !root->right)
		{
			delete root;
			return (NULL);
		}
		if (root->left && root->right)
		{
			Node<T>* tmp = this->successor(root, val);
			root->val = tmp->val;
			root->right = deleteNode(root->right, tmp->val);
		}
		else if (root->left)
		{
			Node<T> *tmp = root->left;
			delete root;
			return (tmp);
		}
		else
		{
			Node<T> *tmp = root->right;
			delete root;
			return (tmp);
		}
	}
	return (root);
}