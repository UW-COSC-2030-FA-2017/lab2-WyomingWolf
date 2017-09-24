// LinkedList.cpp
//James Mock
//COSC 2030
//2017-09-23
// Definition of methods for the List class.

#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}


const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node *tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}

int List::size() const
{
	int size = 0;
	Node *ptr = first_;
	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next_;
	}
	return size;
}

double List::sum() const
{
	double sum = 0;
	Node *ptr = first_;
	while (ptr != NULL)
	{
		sum += ptr->entry_;
		ptr = ptr->next_;
	}
	return sum;
}

void List::insertAsLast(double x)
{
	if (empty())
	{
		insertAsFirst(x);
	}
	else
	{
		Node *ptr = first_;
		int length = size();
		for (int i = 0; i < length-1; i++)
		{
			ptr = ptr->next_;
		}
		Node *temp = new Node(x);
		ptr->next_ = temp;
	}
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}

	}
	outfile << " ]";
	outfile << "   size: " << size() << "   sum: " << sum() << endl;
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}


