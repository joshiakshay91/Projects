/**
 * This file is used to create RB tree and functions of RBT
 * These functions are inserting a node, deleting, finding
 *
 *
 *
 * @author Akshay Joshi
 * @date 04/13/2015
 **/

#include <iostream>
#include <iomanip>
#include "rbtree.h"

using std::cout;
using std::setw;
using std::endl;
/* Red Black tree node constructor*/
RBTree::Node::Node()
{
	parent = NULL;
	left = NULL;
	right = NULL;
	color = 'B';
}
/*RBT Node destructor*/
RBTree::Node::~Node()
{
	delete key;
	delete value;
}
/*RB Tree constructor*/
RBTree::RBTree()
{
	nil = new Node();
	root = nil;
}
/*This is destructor of the whole tree executed after quit or end of file */
RBTree::~RBTree()
{
	counterNodeDest(root);
{
		delete nil;
}
}
/*This function calls the reverse inorder print function which prints the RBT*/
void RBTree::rbPrintTree()
{
	reverseInOrderPrint(root, 0);
}
/*This function is used by destructor of tree ~RBT to traverse post order
and delete all nodes */
void RBTree::counterNodeDest(Node *x)
{
	if ( x != nil ) {
		counterNodeDest(x->right);
		counterNodeDest(x->left);
		delete x;
	}
}
/*Prints tree in reverse in order*/
void RBTree::reverseInOrderPrint(Node *x, int depth) {
	if ( x != nil ) {
		reverseInOrderPrint(x->right, depth+1);
		cout << setw(depth*4+4) << x->color << " ";
		cout << *(x->key) << " " << *(x->value) << endl;
		reverseInOrderPrint(x->left, depth+1);
	}
}
/* This functions, helps insert node it is passed to rbInsert function*/
void RBTree::rbInsert(const string& key, const string& value)
{
	Node* z= new Node(key, value, nil);
	rbInsert(z);
}
/*Values are assigned over here to the new node*/
RBTree::Node::Node(const string& key1, const string& data1, Node* initial)
{
	parent=initial;
	left=initial;
	right=initial;
	key=new string (key1);
	value= new string(data1);
	color='R';
}
/*This function adds node to RBT by the algorithm given in Cormen*/
void  RBTree::rbInsert(Node* z)
{
	Node *y=nil;
	Node *x=root;
	while (x!=nil)
	{
		y=x;
		if((*z->key)<(*x->key))
		{
			x=x->left;
		}
		else
		{
			x=x->right;
		}
	}
	z->parent=y;
	if (y == nil)
	{
		root = z;
	}
	else if (*z->key < *y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
	z->left = nil;
	z->right = nil;
	z->color = 'R';
	rbInsertFixup(z);
}
/*This function is used for fixup of added node by the algorithm given in
 Cormen*/
void  RBTree::rbInsertFixup(Node* z)
{
	Node* y;
	while (z->parent->color == 'R')
	{
		if (z->parent == z->parent->parent->left)
		{
			y = z->parent->parent->right;
			if (y->color == 'R')
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right)
				{
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color='B';
				z->parent->parent->color='R';
				rightRotate(z->parent->parent);
			}
		}
		else
		{
			y = z->parent->parent->left;
			if (y->color == 'R')
			{
				z->parent->color = 'B';
				y->color = 'B';
				z->parent->parent->color = 'R';
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					rightRotate(z);
				}
				z->parent->color='B';
				z->parent->parent->color='R';
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = 'B';
}
/*The find function calls search function which searches for node with
matching keys and if matching node is found then data is pushed in
vector*/
vector <const string*> RBTree::rbFind(const string& key)
{
	vector <const string*> data;
	Node *finder = nil;
	finder =rbTreeSearch(root, key);
	if( finder !=nil)
	{
		data.push_back(finder->value);
		Node* finder_pred= finder;
		while ( finder_pred != nil)
		{
			finder_pred= rbTreePredecessor(finder_pred);
			if (finder_pred != nil)
			{
				if(*finder_pred->key == key)
				{
					data.push_back(finder_pred->value);
				}
			}
		}

		Node* finder_succ=finder;
		while ( finder_succ != nil)
		{
			finder_succ= rbTreeSuccessor(finder_succ);
			if(finder_succ !=nil)
			{
				if(*finder_succ->key== key)
				{
					data.push_back(finder_succ->value);
				}
			}
		}
	}
	return data;
}

/*This function is called by the find function the key is compared and
accordingly tree is traveresd either to left or right and if key is found it
returns the node*/
RBTree::Node*  RBTree::rbTreeSearch(Node*  x, const string& key )
{
	while (x != nil )
	{
		if (*x->key == key) {  return x;   }
		else if (key < *x->key) {  x = x->left; }
		else {x = x->right;}
	}
	return x;
}

/*Here tree minimum is found from the node that is passed in the function
it traverses to left till it is not a nil node*/
RBTree::Node* RBTree::rbTreeMinimum(Node*  x)
{
	while (x->left != nil)
	{
		x = x->left;
	}
	return x;
}

/*Here tree maximum is found from the node that is passed in the function
it traverses to right till it is not a nil node*/
RBTree::Node*  RBTree::rbTreeMaximum(Node*  x)
{
	while (x->right != nil)
	{
		x = x->right;
	}
	return x;
}

/*The Predecessor of node is found here, it is the tree maximum of the
left child of the node that is passed, if it has right subtree to function else
it is another node mostly a parent node*/
RBTree::Node*  RBTree::rbTreePredecessor(Node* x)
{
	if (x->left != nil)
	{
		return rbTreeMaximum(x->left);
	}
	Node* y = x->parent;
	while ((y != nil) && (x == y->left))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/*The Successor of node is found here, it is the tree minimum of the
right child of the node that is passed here, if it has left subtree to function
else it is different right probably the parent node*/

RBTree::Node*  RBTree::rbTreeSuccessor(Node*  x)
{
	if (x->right != nil)
	{
		return rbTreeMinimum(x->right);
	}
	Node* y = x->parent;
	while ((y != nil) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

/*This function rotates the tree to right from the node that is passed here
as input*/
void  RBTree::rightRotate(Node* x)
{
	Node* y = x->left;
	x->left = y->right;
	if (y->right != nil)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil)
	{
		root = y;
	}
	else if (x == x->parent->right)
	{
		x->parent->right = y;
	}
	else
	{
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

/*This function rotates the tree to left from the node that is passed here
as input*/
void  RBTree::leftRotate(Node* x)
{
	Node* y = x->right;
	x->right = y->left;
	if (y->left != nil)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil)
	{
		root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}
/*This function finds the node with matching keys and values and passes it
to actual delete function, it uses predecessor and sucessor for additional
 nodes */
void RBTree::rbDelete(const string& key, const string& value)
{
	vector <Node*> data;
	Node *finder = nil;
	finder =rbTreeSearch(root, key);
	if( finder !=nil)
	{
		if(*finder->value== value)
		{data.push_back(finder);}
		Node* finder_pred= finder;
		while ( finder_pred != nil)
		{
			finder_pred= rbTreePredecessor(finder_pred);
			if (finder_pred != nil)
			{
				if(*finder_pred->key == key)
				{
					if(*finder_pred->value==value)
					{
						data.push_back(finder_pred);
					}
				}
			}
		}
		Node* finder_succ=finder;
		while ( finder_succ != nil)
		{
			finder_succ= rbTreeSuccessor(finder_succ);
			if(finder_succ !=nil)
			{
				if(*finder_succ->key== key)
				{
					if(*finder_succ->value==value)
					{data.push_back(finder_succ);}
				}
			}
		}
	}
	vector <Node*>::iterator it;
	it=data.begin();
	while(it < data.end())
	{
		rbDelete(*it);
		delete (*it);
		it++;
	}
}

/*this function deletes the node in the tree it  basically unlinks the node
and calls fixup function then that unlinked node is deleted so no memory
leaks happen*/
void  RBTree::rbDelete(Node* z)
{
	Node* x;
	Node* y;
	char y_o_color;
	y = z;
	y_o_color = y->color;
	if (z->left == nil)
	{
		x = z->right;
		rbTransplant(z, z->right);
	}
	else if (z->right == nil)
	{
		x = z->left;
		rbTransplant(z, z->left);
	}
	else
	{
		y = rbTreeMaximum(z->left);
		y_o_color = y->color;
		x = y->left;
		if (y->parent == z)
		{
			x->parent = y;
		}
		else
		{
			rbTransplant(y, y->left);
			y->left = z->left;
			y->left->parent = y;
		}
		rbTransplant(z, y);       //
		y->right = z->right;            //
		y->right->parent = y;      // This function is used by taking
		y->color = z->color;     //
	}
	if (y_o_color == 'B')
	{
		rbDeleteFixup(x);
	}
}

/*This is the red black tree delete fixup function as given in Cormen*/
void  RBTree::rbDeleteFixup(Node* x)
{
	Node* w;
	while ((x != root) && (x->color == 'B'))
	{
		if (x == x->parent->left)
		{
			w = x->parent->right;
			if (w->color == 'R')
			{
				w->color = 'B';
				x->parent->color = 'R';
				leftRotate(x->parent);
				w = x->parent->right;
			}
			if ((w->left->color == 'B') && (w->right->color == 'B'))
			{
				w->color = 'R';
				x = x->parent;
			}
			else
			{
				if(w->right->color=='B')
				{
					w->left->color='B';
					w->color = 'R';
					rightRotate(w);
					w=x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = 'B';
				w->right->color = 'B';
				leftRotate(x->parent);
				x = root;
			}
		}
		else
		{
			w = x->parent->left;
			if (w->color == 'R')
			{
				w->color = 'B';
				x->parent->color = 'R';
				rightRotate(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == 'B' && w->left->color == 'B')
			{
				w->color = 'R';
				x = x->parent;
			}
			else
			{
				if (w->left->color == 'B')
				{
					w->right->color = 'B';
					w->color = 'R';
					leftRotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = 'B';
				w->left->color = 'B';
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = 'B';
}

/*This is the transpant function here two nodes are passed for transplant
named as  u and v */
void  RBTree::rbTransplant(Node* u, Node*v)
{
	if (u->parent == nil)
	{
		root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	v->parent = u->parent;
}
