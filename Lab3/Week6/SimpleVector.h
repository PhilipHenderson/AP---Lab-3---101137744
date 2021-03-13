#pragma once
#include <iostream>
#include <cstdlib>
#include "vector"
#include "Algorithm"
using namespace std;

//assume we are creating a vector of ints
template <class T>
class SimpleVector
{
private:
	T* aptr;  // array of something
	int arraySize;
	void subError() const; // bound error msg

public:
	SimpleVector(int); // constructor that takes in a size
	SimpleVector(const SimpleVector&); // copy constructor
	~SimpleVector(); //destructor
	int size() const
	{
		return arraySize;
	}
	T& operator[](int);
	void print() const;
	void push_back(const T& obj);
	void pop_back();
	//void SortableVector();
	//void Sort(T& obj);
};

//constructor, sets the size of the array and allocates memory for it

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
	arraySize = s;
	aptr = new T[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = T(); // Assuming that the datatype being used has a default constructor. (Ex: if int is entered -- Set the value to 0)

	}
}

//Copy constructor

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& obj)
{
	arraySize = obj.arraySize;

	// aptr = obj.aptr; // BAD BAD BAD

	aptr = new T[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = obj.aptr[i];
	}

}

//Destructor

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
	{
		delete[] aptr;
	}
}

//subscript Error Function Display an eroror msg and terminate the program when sunscript is out of range

template <class T>
void SimpleVector<T>::subError() const
{
	cout << "ERROR: Subscript out of range.\n";
	exit(0);
}

//overloaded [] operator. takes in a subscript value and returns an element from the array

template <class T>
T& SimpleVector<T>::operator[](int sub)
{
	if (sub < 0 || sub >= arraySize)
	{
		//out of bounds
		subError();
	}

	return aptr[sub];
}

//print all the entries in the array

template <class T>
void SimpleVector<T>::print() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << aptr[i] << " ";
	}

	cout << endl;
}

// push_back
// Accept an argument and Insert the value at the end of the array
template <class T>
void SimpleVector<T>::push_back(const T& obj)
{
	//if size = capacity = array full
	if (arraySize == 15)
		cout << "Array Full\n\n";
	//if size < capacity = insert element
	else
	{
		aptr [arraySize++] = obj;
		cout << "Element Entered: " << obj << endl;
		cout << "New Array Size: " << arraySize << endl;
	}

}


// pop_back
//accepts no arguments and removes the last element from the array
template <class T>
void SimpleVector<T>::pop_back()
{
	//pop_back reduces size but not capacity
	if (arraySize > 0)
	{
		aptr[arraySize--];
	}
	if (arraySize == 0)
		cout << "Array is Empty" << endl;
}

//template <class T>
//void SimpleVector<T>::Sort(T& obj)
//{
//	sort(obj.begin(), obj.end());
//	sort(obj.begin(), obj.end(), less<>());
//	for (int i = 0; i < arraySize; i++)
//	{
//		cout << aptr[i] << " ";
//	}
//}
//
//template <class T>
//void SimpleVector<T>::SortableVector()
//{
//
//}
