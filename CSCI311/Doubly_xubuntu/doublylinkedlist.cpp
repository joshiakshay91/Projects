/**
 * @file doublylinkedlist.cpp   Implementation of a Doubly linkedlist for music.
 *
 * @brief
 *    This file implements the functions of doubly linked list
 *    
 *
 * @author Akshay Joshi
 * @date 2/5/15
 */
#include<iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "doublylinkedlist.h"
using std::cout;
using std::string;
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
  head = NULL;                       //dll constructor
  tail = NULL;
  current = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
  delete head;                      // dll destructor
  delete tail;
  delete current;
}
DoublyLinkedList::Node::Node()
{
  this->next = NULL;               //node constructor
  this->prev = NULL;
  this->data = '\0';
}

DoublyLinkedList::Node::~Node()
{
  this->data='\0';
  this->next = NULL;
  this->prev = NULL;
  delete data;
  delete next;                     //node destructor
  delete prev;
}
/*this function returns boolean value true when empty and when not empty false*/
bool DoublyLinkedList::empty()
{
  if ((head == tail) && (head == NULL) && (current==NULL) &&(tail==NULL))
    {
      return true;
    }
  else
    {
      return false;
    }
}
/*this function is responsible for append of string or append of node*/
void DoublyLinkedList::append(string &s)
{	
  bool flag = false;
  flag = empty();
  Node *temp = new Node();				//a temporary node is required
  if (flag == true)		                        // Check for Head is NULL or not.
	{				
	  current=tail=head = new Node();             // If head is null copy data value
	  head->data =  &s;
	  tail = head;
	  current = head;
	}
  else
    {
      tail->next = temp;
      temp->prev = tail;
      tail=tail->next;
      tail->data = &s;
      current = tail;
    }
}
/*This function is responsible for insert of node before the current node*/
void DoublyLinkedList::insertBefore(string &s)
{
  Node *temp_previous_node=new Node();
  Node *temporary = new Node();
  if (current != NULL)
    {
      if (current->prev == NULL)
	{
	  temporary->next = current;                         // two scenarios are considered if insert before instruction is applied on head node
	  temporary->prev = NULL;                            // and if insert before is applied on regular node like middle node and end node
	  temporary->data = &s;
	  current->prev = temporary;
	  current = temporary;
	  head = temporary;
	}
      else 
	{
	  temp_previous_node = current->prev;
	  temporary->next = current;
	  temporary->prev = temp_previous_node;
	  temporary->data = &s;
	  current->prev=temporary;
	  temp_previous_node->next = temporary;
	  current = temporary;
	}
    }
}

void DoublyLinkedList::insertAfter(string &s)
{
  Node *temp_next_node;
  Node *tempo = new Node();
  if (current != NULL)
    {
      if (current == tail)
	{
	  tail->next = tempo;
	  tempo->prev = tail;
	  tail = tail->next;
	  tail->data = &s;                                   // here also two sceanrios are considered for adding node on tail and adding it on other nodes
	  current = tail;
	  tempo = tempo->next;
	}
      else
	{
	  temp_next_node = current->next;
	  tempo->prev = current;
	  tempo->next = temp_next_node;
	  tempo->data = &s;
	  current->next = tempo;
	  temp_next_node->prev = tempo;
	  current = tempo;
	  current->data = &s;
	}
    }
}
/*remove function removes a specific node and calls delete function three cases are considered first that node is middle or head or tail*/
void DoublyLinkedList::remove(string &s)
{
  bool flag_empt = false;
  flag_empt = empty();
  if (flag_empt == false)
    {
      string *check = (&s);				     //to put the string in check cause cannot compare diectly with s
      Node *checker;
      Node *temp_prev;
      Node *temp_next;
      checker = head;
      while (checker != NULL)			            // then temp1 is used which traverse till end
	{
	  if ((*checker->data == *check) && (checker!=head) && (checker!=tail))   // for node not head and tail
	    {
	      temp_next = checker->next;			//made temp next node pointer
	      temp_prev = checker->prev;			// made temp previous node pointer
	      temp_prev->next = temp_next;
	      temp_next->prev = temp_prev;
	      current = temp_next;
	      delete checker;
	      break;
	    }
	  if ((*checker->data == *check) && (checker == head))   //for node that is head
	    {
	      if (head == tail)
		{
		  head = tail =current= NULL;
		  delete checker;
		  break;
		}
	      else
		{
		  head = head->next;
		  head->prev = NULL;
		  current = head;
		  delete checker;
		  break;
		}
	    }
	  if ((*checker->data == *check) && (checker==tail))  // for node that is tail
	    {
	      tail = tail->prev;
	      tail->next = NULL;
	      current = tail;
	      delete checker;
	      break;
	    }
	  checker = checker->next;
	}
    }
}
/*brings the value of current node to head that is current node is now head node*/
void DoublyLinkedList::begin()
{
  current = head;
}
/*brings the value of current node to tail that is current node is now tail node*/
void DoublyLinkedList::end()
{
  current = tail;
}
/*next is used to traverse current to next postion*/
bool DoublyLinkedList::next()
{
  if (current->next != NULL)
    {
      current = current->next;
      return true;
    }
  else
    {
      return false;
    }
}
/*prev is used totraverse current to previous position */
bool DoublyLinkedList::prev()
{
  if (current->prev != NULL)
    {
      current = current->prev;
      return true;
    }
  else
    {
      return false;
    }
}
/*find is used to find node and to goto that node for current node*/
bool DoublyLinkedList::find(string &s)
{
  bool flag_empt = false;
  flag_empt = empty();
  if (flag_empt == false)
    {
      string *check = (&s);			//to put the string in check cause cannot compare directly with s
      Node *checker;
      checker = head;
      while (checker != NULL)		  	// then temp1 is used which traverse till end
	{
	  if (*checker->data == *check)         // check the matching data and break at first occurance
	    {
	      current = checker;
	      break;
	    }
	  checker = checker->next;
	}
    }
  else
    {
      return false;
    }
  return true;
}
/*this function getsdata that is it gives the data of current node*/
const string &DoublyLinkedList::getData()
{
  string *a = '\0';
  if (current != NULL)
    {
      return *current->data;
    }
  else
    {
      return *a;
    }
}
