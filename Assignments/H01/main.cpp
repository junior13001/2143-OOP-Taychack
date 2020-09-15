///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Junior Taychack
// Email:            jtaychack@yahoo.com
// Label:            H01
// Title:            Code Commenting
// Course:           CMPS 2143
// Semester:         FALL 2020
//
// Description:      This program is used to reinforce our commenting skills
//
//
// Usage:
//         N/A
//
// Files:  
//         main.cpp
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];					// Initializing a global array with 100 slots

/**
*	Struct:				 Node
*	
*	Description:		 A linked list that holds integers
*	
*	Methods:			 Node(int) - Initializes node
*
*/
struct Node
{
	int x;
	Node* next;
	Node()
	{
		x = -1;
		next = NULL;
	}
	Node(int n)
	{
		x = n;
		next = NULL;
	}
};

/**
*
*	Class: List
*
*	Description:
*			
*		Creates a linked list that you can add 
*		integers to, insert into, or print.
*
*	Public Methods:
*				List()
*		void	Push(int)
*		void	Insert(int)
*		void	PrintTail()
*		string	Print()
*		int		Pop()
*		List	operator+(const List& Rhs)
*		int     operator[](int)
*		friend	ostream& operator<<(ostream& os, List L)
*
*	Private Methods:
*		N/A
*
*	Usage:
*		List L1;			// Creates instance of List
*		L1.Push(i);			// Pushes new integer to the end of the list
*		L1.PrintTail();		// Prints tail of list
*		
*/
class List
{
private:
	Node* Head;		// Pointer to head
	Node* Tail;		// Pointer to tail
	int Size;		// int to keep track of size of list

public:
	List()			// Constructor
	{
		Head = Tail = NULL;
		Size = 0;
	}

/***********************************************
*
* Public : Push
*
* Description:
*         Adds new integer to the end of the list
*
* Params:
*         int val : number to be added
*
* Returns:
*         void
*
************************************************/

	void Push(int val)
	{
		// allocate new memory and init node
		Node* Temp = new Node(val);

		if (!Head && !Tail)
		{
			Head = Tail = Temp;
		}
		else
		{
			Tail->next = Temp;
			Tail = Temp;
		}
		Size++;
	}

/***********************************************
*
* Public : Insert
*
* Description:
*         Adds an integer to middle of the list
*
* Params:
*         int val : number to be added
*
* Returns:
*         void
*
************************************************/

	void Insert(int val)
	{
		// allocate new memory and init node
		Node* Temp = new Node(val);

		// figure out where it goes in the list

		Temp->next = Head;
		Head = Temp;
		if (!Tail)
		{
			Tail = Head;
		}
		Size++;
	}

/***********************************************
*
* Public : PrintTail
*
* Description:
*         Prints integer at the end of the list
*
* Params:
*         N/A
*
* Returns:
*         void
*
************************************************/

	void PrintTail()
	{
		cout << Tail->x << endl;
	}

/***********************************************
*
* Public : Print
*
* Description:
*         Prints entire list
*
* Params:
*         N/A
*
* Returns:
*         list : the entire list as a string
*
************************************************/

	string Print()
	{
		Node* Temp = Head;
		string list;

		while (Temp != NULL)
		{
			list += to_string(Temp->x) + "->";
			Temp = Temp->next;
		}

		return list;
	}

	// not implemented 
	int Pop()
	{
		Size--;
		return 0; //
	}
	
/***********************************************
*
* Public : operator+
*
* Description:
*         Saves current list and creates a clone for editing
*
* Params:
*         const List&	: Current list
*
* Returns:
*         list		    : Concatenated list
*
************************************************/

	List operator+(const List& Rhs)
	{
		// Create a new list that will contain both when done
		List NewList;

		// Get a reference to beginning of local list
		Node* Temp = Head;

		// Loop through local list and Push values onto new list
		while (Temp != NULL)
		{
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Get a reference to head of Rhs
		Temp = Rhs.Head;

		// Same as above, loop and push
		while (Temp != NULL)
		{
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Return new concatenated version of lists
		return NewList;
	}

	// Implementation of [] operator.  This function returns an
	// int value as if the list were an array.
	int operator[](int index)
	{
		Node* Temp = Head;

		if (index >= Size)
		{
			cout << "Index out of bounds, exiting";
			exit(0);
		}
		else
		{

			for (int i = 0; i < index; i++)
			{
				Temp = Temp->next;
			}
			return Temp->x;
		}
	}

/***********************************************
*
* Public : ostream
*
* Description:
*         Prints entire list
*
* Params:
*         os	:	the list
*
* Returns:
*         os
*
************************************************/

	friend ostream& operator<<(ostream& os, List L)
	{
		os << L.Print();
		return os;
	}
};

int main(int argc, char** argv)
{
	List L1;
	List L2;

	for (int i = 0; i < 25; i++)
	{
		L1.Push(i);
	}

	for (int i = 50; i < 100; i++)
	{
		L2.Push(i);
	}

	//cout << L1 << endl;
	L1.PrintTail();
	L2.PrintTail();

	List L3 = L1 + L2;
	cout << L3 << endl;

	cout << L3[5] << endl;
	return 0;
}