#include <iostream>
#include "SearchVect.h"

using namespace std;

int main()
{
	const int SIZE = 10;
	bool push;
	bool pop;

	SearchableVector<int> iTable(SIZE);
	SearchableVector<double> dTable(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		iTable[i] = (i * 2);
		dTable[i] = (i * 2.14);
	}

	cout << "The values in iTable are:\n";
	iTable.print();
	cout << "The Values in dTable are:\n";
	dTable.print();

	int results;
	cout << "Searching for the number 6 in iTable.\n";
	results = iTable.findItem(6);
	if (results == -1)
		cout << "6 was not found.\n";
	else
		cout << "6 was found at subscript " << results << endl;
	system("cls");
	while (true)
	{
		iTable.print();
		int menuPick = 0;
		cout << "Please Select an Option?\n1 - Push\n2 - Pop\n3 - Sort Vector\n0 - Exit Program\n";
		cin >> menuPick;
		//push_back
		if (menuPick == 1)
		{
			push = true;
			while (push == true)
			{
				iTable.print();
				int element = 0;
				cout << "Enter element to be inserted at the end of the array: \nEnter 0 to return to main menu.\n\n";
				cin >> element;
				cout << endl;
				if (element == 0)
				{
					cout << "Returning to main menu" << endl;
					push = false;
				}
				else
				{
					iTable.push_back(element);
					iTable.print();
					cout << endl;
				}
			}
		}
		//pop_back
		if (menuPick == 2)
		{
			pop = true;
			while (pop == true)
			{
				iTable.print();
				int input = 0;
				cout << "Pop_back? \n1 - Yes\n0- return to main menu\n";
				cin >> input;
				//if yes , pop back and destroy last element
				if (input == 1)
				{
					//if array has elements
					iTable.pop_back();
					iTable.print();
					
					//if array is empty
				}
				else if (input == 0)
				{
					pop = false;
				}
				else
				cout << "Invlaid Input" << endl;
			}

		}

		//if (menuPick == 3)
		//{
		//	iTable.print();
		//	sort(iTable, iTable, less<>());
		//}

		if (menuPick == 0)
		{
			cout << "Exiting Program";
			iTable = NULL;
			dTable = NULL;
			return 0;
		}
		else
			cout << "invalide input";
	}
}