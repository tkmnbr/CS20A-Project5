#ifndef BINARYSEARCHITEM_H
#define BINARYSEARCHITEM_H

#include<functional>
#include<iostream>
#include<assert.h>

// Node implementation: Implemented
template<typename Type>
struct Node {
	Node(Type i, Node* l, Node* r) :item(i), left(l), right(r) {}
	Node() :Node(0, nullptr, nullptr) {}

	Type item;
	Node* left, *right;
};

template<typename Type>
class BinarySearchTree {

public:
	// Public Interface Functions: All of these are implemented
	BinarySearchTree();
	~BinarySearchTree();

	void	printInorder() const;
	void	printPostorder() const;
	void	printPreorder() const;
	void	insert(Type item);

	void	remove(Type item);

	Type	min() const;
	Type	max() const;
	int		height() const;
	bool	search(Type item) const;

	bool	empty() const;

	void	printTree() const;

private:

	// Member variable root
	Node<Type>* root;

	//Auxillary recursive bst functions
	//public interface functions call these
	//You will implement these functions.

	// Tree traversal, second parameter is a "function" with 
	// return type void and parameter Node*, i.e: 
	//					void process(Node* )
	void inorder(Node<Type>* node, std::function<void(Node<Type>*)> proc);
	void preorder(Node<Type>* node, std::function<void(Node<Type>*)> proc);
	void postorder(Node<Type>* node, std::function<void(Node<Type>*)> proc);

	Node<Type>* min(Node<Type> *node) const;
	Node<Type>* max(Node<Type> *node) const;

	int   height(Node<Type>* node) const;

	bool  search(Node<Type>* node, Type item) const;

	Node<Type>* insert(Node<Type>* node, Type item);
	Node<Type>* remove(Node<Type>* node, Type item);
	
	void  printTree(Node<Type>* node, int space) const;
};




//----------------------------------------------------------
//-------------- Binary Search Tree Function Implementations 
// 
//  Public Interface functions
// 		Completley Implemented, nothing to do.  These functions 
//      call the recursive helper functions you will implement
//		below.

// Constructor
template<typename Type>
BinarySearchTree<Type>::BinarySearchTree() :root(nullptr) {}

// Destructor
template<typename Type>
BinarySearchTree<Type>::~BinarySearchTree() {

	//Use the post order traversal to delete the nodes.
	//lambda function to delete a node n: 
	//				[](Node* n) {delete n; } 
	postorder(root, [](Node<Type>* n) {delete n; });
}
template<typename Type>
void BinarySearchTree<Type>::printInorder() const {

	//Use inorder traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item << std::endl; }"
	const_cast<BinarySearchTree<Type>*>(this)->inorder(root,      [](Node<Type>* n) {std::cout << n->item << " "; });

	std::cout << std::endl;
}
template<typename Type>
void BinarySearchTree<Type>::printPreorder() const {

	//Use pre order traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item << std::endl; }"
	const_cast<BinarySearchTree<Type>*>(this)->preorder(root, [](Node<Type>* n) {std::cout << n->item << " "; });
	std::cout << std::endl;
}
template<typename Type>
void BinarySearchTree<Type>::printPostorder() const {

	//Use post order traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item << std::endl; }"
	const_cast<BinarySearchTree<Type>*>(this)->postorder(root, [](Node<Type>* n) {std::cout << n->item << " "; });
	std::cout << std::endl;
}
template<typename Type>
void BinarySearchTree<Type>::insert(Type item) {
	root = insert(root, item);
}
template<typename Type>
void BinarySearchTree<Type>::remove(Type item) {
	root = remove(root, item);
}
template<typename Type>
Type	BinarySearchTree<Type>::min() const {

	assert(root != nullptr);

	Node<Type>* node = min(root);
	return node->item;
}
template<typename Type>
Type	BinarySearchTree<Type>::max() const {

	assert(root != nullptr);

	Node<Type>* node = max(root);
	return node->item;
}
template<typename Type>
int	BinarySearchTree<Type>::height() const {

	return height(root);
}
template<typename Type>
bool BinarySearchTree<Type>::search(Type item) const {
	return search(root, item);
}
template<typename Type>
bool BinarySearchTree<Type>::empty() const {
	return (root == nullptr);
}
template<typename Type>
void BinarySearchTree<Type>::printTree() const {
	printTree(root, 0);
}

//----------------------------------------------------------
//
// Private Recursive Functions: You Implement These.
//

// Inorder Traversal: Implemented so you can see how passing a function into 
// another function works, other traversals remain for you to implement.  the second
// parameter, proc, is a function and we see that its return type is void and it 
// has a Node* as a parameter.  Any function of that form passed into inorder will be
// called as seen below.  
// If we assume that we use the printing lambda defined above you can imagine that proc 
// is defined as:
//		void proc(Node<Type> * n){std::cout << n->item << " "; }
template<typename Type>
void BinarySearchTree<Type>::inorder(Node<Type>* node, std::function<void(Node<Type>*)> proc) {
	if (node == nullptr)
		return;

	inorder(node->left, proc);
	proc(node);
	inorder(node->right, proc);

}

template<typename Type>
void BinarySearchTree<Type>::postorder(Node<Type>* node, std::function<void(Node<Type>*)> proc) {
	
	//********* TODO **********

}
template<typename Type>
void BinarySearchTree<Type>::preorder(Node<Type>* node, std::function<void(Node<Type>*)> proc) {
	
	//********* TODO **********
}

// BinarySearchTree::insert recursively inserts into the BST according 
// to the rules of the BST.  
template<typename Type>
Node<Type>* BinarySearchTree<Type>::insert(Node<Type>* node, Type item) {

	//********* TODO **********
	return nullptr;
}

// BinarySearchTree<Type>::search recursively searches the tree for item.
template<typename Type>
bool BinarySearchTree<Type>::search(Node<Type>* node, Type item) const {

	//********* TODO **********
	return false;
}

// BinarySearchTree<Type>::height
// Height of a binary tree is the height of the largest subtree + 1
// An empty tree has height 0;
template<typename Type>
int	BinarySearchTree<Type>::height(Node<Type>* node) const {

	//********* TODO **********
	return -2;
}
// BinarySearchTree<Type>::min recursively obtain the node with the minimum item
template<typename Type>
Node<Type>* BinarySearchTree<Type>::min(Node<Type>* node) const {

	//********* TODO **********
	return nullptr;
}

// BinarySearchTree<Type>::max recursively obtain the node with the minimum item
template<typename Type>
Node<Type>* BinarySearchTree<Type>::max(Node<Type>* node) const {
	
	//********* TODO **********
	return nullptr;
}

// BinarySearchTree<Type>::printTree
// Prints the BST in a tree format rotated -90 degrees.  Uses space to 
// signify the space between levels of the tree. Uses the inorder 
// traversal but traverses right first, rather than left. Cannot use
// any of the other travel functions because of this.
//
// parameter space determines the number of spaces needed for each level.
// Example binary shows 5 spaces between levels. 
//
// i.e. traverse right 
//		print appropriate number of spaces 
//		print item 
//		traverse left
template<typename Type>
void BinarySearchTree<Type>::printTree(Node<Type>* node, int space) const {

	//********* TODO **********
	
}


//BinarySearchTree<Type>::remove
//
// Make sure you're comfortable with the iterative approahed discussed in the lecture
// before thinking about how to do it recursively.
//
// Recursively removes an Item node in the binary tree.  The recursive algorithm will 
// be different than the iterative algorithm.  The iterative algorithm conisted
// of first finding the node using two pointers so that we know how to rearrange
// the children of the deleted node. In recursion, we are passing in the sub trees
// each recursive step, so by definition we already have a handle on each subtrees'
// parents (it is the node that is passed into the previous recursive step).
// After we search the node to remove (if it is in the tree) everything else is the same, we  
// handle the three cases: leaf, one child (which consist of two cases: left vs right),
// and two children.  With iterative algorithm there were subcases regardling if the 
// node was root or not, with recursion we get that for free.  
//
// In dealing with a node with two children, we choose items from one of the appropriate 
// nodes in either subtree.  We then just want to write the subtree node's item into the 
// node to be deleted, this will result having two instances of the subtree value. So we 
// can recurse on that subtree and recursively call remove on that item (not the original) 
// to remove that redundant node.  
// 
// It takes a bit to wrap your head around this, use the 6 steps, draw lots of pictures.
// 
template<typename Type>
Node<Type>* BinarySearchTree<Type>::remove(Node<Type>* node, Type item) {

	//********* TODO **********
	return nullptr;
}































































































































#endif//BINARYSEARCHITEM_H_H_MMXXI