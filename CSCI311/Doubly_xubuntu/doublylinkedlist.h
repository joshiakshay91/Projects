/**
* @file doublylinkedlist.h   Declaration of a doublylinkedlist for music.
*
* @brief
*    Implementation of doublinkedlist.h functions. The functions are
*	 declared over here
*
* @author Akshay Joshi
* @date 2/1/13
*/
#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED
#include <string>
#include <vector>

using std::string;
using std::vector;

class DoublyLinkedList {

private:
	class Node
	{
	public:
		string *data;																									// Data of our node.
		Node *next;																									// Pointer for next address.
		Node *prev;																									// Pointer for previous address.
		Node();
		~Node();
	};

	Node *head;
	Node *tail;
	Node *current;

public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool empty();
	void append(string &s);
	void insertBefore(string &s);
	void insertAfter(string &s);
	void remove(string &s);
	void begin();
	void end();
	bool next();
	bool prev();
	bool find(string &s);
	const string &getData();

};


#endif