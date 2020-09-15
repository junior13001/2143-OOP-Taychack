//////////////////////////////////////////////////////////
//                   
// Author:           Junior Taychack
// Email:            jtaychack@yahoo.com
// Label:            P01
// Title:            Array Based Stack Example
// Course:           CMPS 2143
// Semester:         FALL 2020
//
// Description:
//		Example implementation of an array based stack
//      that holds integers.
//
// Usage:
//         N/A
//
// Files:  
//         main.cpp
//		   output.txt
//////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * Stack
 *
 * Description:
 *      Integer array based stack implementation
 *
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *
 */
class Stack {
private:
	int* S;       // array pointer
	int capacity; // max stack size
	int top;      // current top (index)
	int size;     // current num items
	int maximum;  // Highest size the stack reaches
	int start;	  // Starting size of stack
public:
	/**
	 * Stack:
	 *    Constructor.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     Void
	 */
	Stack() 
	{

		capacity = 10;          // set array size
		start = 10;				// set starting size
		S = new int[capacity];  // allocate new memory
		top = -1;               // initialize top of stack
		size = 0;               // set stack to empty

	}

	/**
	 * Stack:
	 *    Constructor.
	 * Params:
	 *    int : capacity
	 *
	 * Returns:
	 *     Void
	 */
	Stack(int cap) 
	{

		capacity = cap;         // set array size      
		start = cap;			// set starting size
		S = new int[capacity];  // allocate new memory
		top = -1;               // initialize top of stack
		size = 0;               // set stack to empty

	}

	/**
	 * Push:
	 *    Push item onto stack.
	 * Params:
	 *    int : data
	 *
	 * Returns:
	 *     Void
	 */
	void Push(int data) 
	{

		if (size == capacity)
		{

			top++;			// Increment top of the stack
			size++;			// Increment size
			cout << " + : " << capacity 
				<< "->" << capacity * 2 << endl;
			capacity *= 2;	// Double capacity

			int* twoStack = new int[capacity];
			for (int i = 0; i < capacity; i++)
			{

				twoStack[i] = S[i];				// Copies old stack
												// into new
			}
			delete[] S;
			S = twoStack;
			if (maximum < capacity)
			{

				maximum = capacity;

			}


		}

		top++;              // move top of stack up
		size++;             // increment size
		S[top] = data;      // add item to array

	}

	/**
	 * Pop:
	 *    remove item from stack.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     int
	 */
	int Pop() 
	{

		if (top < 0)
		{

			cout << "Error: Stack Empty!" << endl;
			return -1;

		}
		else if (size < capacity / 2)
		{

			cout << " - : " << capacity << "->" 
				<< capacity / 2 << endl;
			int* threeStack = new int[capacity / 2];
			capacity /= 2;

			for (int i = 0; i < capacity; i++)
			{

				threeStack[i] = S[i];

			}
			delete[] S;
			S = threeStack;

		}

		int data = S[top];  // pull item from stack
		top--;              // shrink the stack
		size--;             // update our size
		return data;        // send item back

	}

	/**
	 * Print:
	 *    Used so we can inspect our stack.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     void
	 */
	void Print()
	{

		for (int i = top; i >= 0; i--)
		{

			cout << S[i] << endl;
		
		}

	}
	/**
	 * returnStart:
	 *    returns starting size.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     int
	 */
	int returnStart()
	{

		return start;

	}

	/**
	 * returnMaximum:
	 *    returns nax size.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     int
	 */
	int returnMaximum()
	{

		return maximum;

	}

	/**
	 * returnEnd:
	 *    returns ending size.
	 * Params:
	 *    void
	 *
	 * Returns:
	 *     int
	 */
	int returnEnd()
	{

		return capacity;

	}

	/**
	 * Overloaded ostream <<
	 *    Lets us print a stack using cout
	 * Params:
	 *    ostream &os   : instance of ostream passed in by reference
	 *    const Stack   : instance of stack passed in using const so
	 *                    it cannot be changed
	 *
	 * Returns:
	 *     ostream
	 */
	friend ostream& operator<<(ostream& os, const Stack s) 
	{

		os << "Overloaded!!" << endl;
		for (int i = s.top; i >= 0; i--) 
		{

			os << s.S[i] << endl;
		
		}
		return os;
	
	}

};

int main() 
{

	int x;						// If push then integer for the 
								// integer in the input
	string line;				// Push or pop from input

	Stack s;					// Creates instance of stack
	ifstream infile;	
	ofstream outfile;
	infile.open("input.txt");	// Opens the input file for reading
	outfile.open("output.txt");	// Opens the output file for editing
	
	while (infile >> line)
	{

		if (line == "push")		// If the input is push then 
		{						// read the integer thats after

			infile >> x;
			s.Push(x);

		}
		else
		{

			s.Pop();

		}

	}
	infile.close();
	outfile << "Name: Junior Taychack" << endl;
	outfile << "Program: P01" << endl;
	outfile << "Date 15 Sep 2020" << endl;
	outfile << endl;
	outfile << "Start size: " << s.returnStart();
	outfile << endl;
	outfile << "Max size: " << s.returnMaximum();
	outfile << endl;
	outfile << "Ending size: " << s.returnEnd();
	outfile << endl;
	outfile.close();
	s.Print();

	system("pause");
	return 0;
	
}