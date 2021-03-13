#pragma once
#include "SimpleVector.h"

template<class T>
class SearchableVector : public SimpleVector<T>
{
public:
	SearchableVector(int s) : SimpleVector<T>(s) {} //constructor
	SearchableVector(SearchableVector& obj) : SimpleVector<T>(obj) {} // Copy Constructor
	SearchableVector(SimpleVector<T>& obj) : SimpleVector<T>(obj) {} //Additional copy constructor
	int findItem(T); //Search for an item. reutnrs the subscript
};
//copy constructor
//template <class T>
//SearchableVector<T>::SearchableVector(SearchableVector& obj) : SimpleVector<T>(obj) {}

//looks for an item and return the subscript where its located

template<class T>
int SearchableVector<T>::findItem(T item)
{
	for (int i = 0; i < this->size(); i++)
	{
		if (this->operator[](i) == item) // compairs every item in the array vs. "item"
		{
			return i;
		}
	}

	return -1;
}