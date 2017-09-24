// ListProcessor.cpp
//James Mock
//COSC 2030
//2017-09-23

// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"

int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cows.insertAsLast(5.43);
	cows.insertAsLast(3.21);
	cout << "cows list  :  " << cows << endl;

	cows.removeFirst();
	cout << "cows list  :  " << cows << endl;

	List horses(cows);
	cout << "cows list  :  " << cows;
	cout << "horses list:  " << horses << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	horses.insertAsLast(7.65);
	cows.insertAsFirst(6.78);
	cows.insertAsLast(8.76);
	cout << "cows list  :  " << cows;
	cout << "horses list:  " << horses << endl;

	List pigs;
	cout << "cows list  :  " << cows;
	cout << "horses list:  " << horses;
	cout << "pigs list  :  " << pigs << endl;

	pigs = cows;
	cout << "cows list  :  " << cows;
	cout << "horses list:  " << horses;
	cout << "pigs list  :  " << pigs << endl;

	pigs = horses;
	cout << "cows list  :  " << cows;
	cout << "horses list:  " << horses;
	cout << "pigs list  :  " << pigs << endl;

	cout << "End of code" << endl;

	return 0;
}
