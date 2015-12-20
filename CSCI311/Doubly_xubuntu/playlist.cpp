/**
 * @file playlist.cpp   Implementation of a Playlist for music.
 *
 * @brief
 *    Implementation of a Playlist for music. A doubly linked list is
 *    used to store the song names.
 *
 * @author Judy Challinger
 * @Modified by: Akshay Joshi
 * @date 2/5/15
 */

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <sstream>

#include "playlist.h"
#include "doublylinkedlist.h"
using namespace std;
using std::string;
using std::cin;
using std::cout;
using std::endl;

/**
 * Process a playlist command.
 *
 * Gets an entire line from std::cin, extracts the first word as the command,
 * and calls the appropriate processing function. Invalid commands are
 * ignored.
 */
void Playlist::processCommand() 
{
  string s;
  (getline(cin, s));
  {
    string command = s.substr(0, s.find(' '));   // get first word in string
    s.erase(0, s.find(' ') + 1);                 // erase the command part
    if (command == "appendSong")
      {
	string *a = new string(s);               // calls append song function
	if(*a!="")
	{
	dll.append(*a);
	}
      }
    else if (command== "removeSong")             //calls remove song function 
      {
	dll.remove(s);
      }
    else if (command == "playForward")           // play forward function is called
      {
	string ptr;
	bool flag = false;
	bool empt_flag = false;
	empt_flag = dll.empty();
	cout << "\nplaying forward: \n";
	if (empt_flag == false)
	  {
	    ptr = dll.getData();
	    cout << ptr << endl;
	    flag = dll.next();
	    if (flag == true)
	      {
		while (flag != false)
		  {
		    ptr = dll.getData();
		    cout << ptr << endl;
		    flag = dll.next();
		  }
	      }
	  }
      }
    else if (command =="playReverse" )         //play reverse function is called
      {
	string ptr;
	bool flag = false;
	bool empt_flag = false;
	empt_flag = dll.empty();
	cout << "\nplaying reverse: \n";
	if (empt_flag == false)
	  {
	    ptr = dll.getData();
	    cout << ptr << endl;
	    flag = dll.prev();
	    if (flag == true)
	      {
		while (flag != false)
		  {
		    ptr = dll.getData();
		    cout << ptr << endl;
		    flag = dll.prev();
		  }
	      }
	  }
      }
    else if (command=="insertBefore")         // insert before function is called
      {
	string *a = new string(s);
	dll.insertBefore(*a);
      }
    else if (command == "insertAfter")        // insert after function is called
      {
	string *a = new string(s);
	dll.insertAfter(*a);
      }
    else if(command =="gotoFirstSong")        // goto first song function is called 
      {
	dll.begin();
      }
    else if (command == "gotoLastSong")       // goto last song function is called
      {
	dll.end();
      }
    else if (command == "playCurrent")        //play current function calling
      {  
	bool flag_empt = false;
	string ptr;
	flag_empt = dll.empty();
	if (flag_empt == true)
	  {
	    cout << "\nplaying current: ";
	  }
	else
	  {
	    ptr = dll.getData();
	    cout << "\nplaying current: " << ptr << endl;
	  }
      }
    else if (command == "gotoSong")       // goto song fucntion is called
      { 
	bool find_flag = false;
	find_flag=dll.find(s);
	if (find_flag==true)
	  {
	    
	  }	
      }
    else if (command == "nextSong")     // goto next song function is called
      {
	bool nextflag = false;
	nextflag=dll.next();
	if(nextflag==true)
	  {
	    
	  }
      }
    else if (command == "prevSong")     //goto prev song function is invoked
      {
	bool prevflag = false;
	prevflag = dll.prev();
	if (prevflag==true)
	  {
	    
	  }
      }
    else
      {
	
      }
  }
}

/**
 * The Playlist main loop will process command lines until eof.
 */
void Playlist::mainLoop() 
{
	while (!cin.eof()) processCommand();         // process all commands
}

/**
 * The main entry point for the program.
 */
int main()
{
	Playlist myPlaylist;
	myPlaylist.mainLoop();
	return 0;
}
