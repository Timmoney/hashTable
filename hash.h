/*
hash.h --> implementation in C++
creating class
	1. #ifndef and #define
	2. class name has to be CAPITALIZED
	3. public for access
	4. ; at the end of the class
	5. #endif
*/
using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash{
private:
	static const int tableSize = 4;

	//linked list item
	struct item
	{
		string name;
		string drink;
		item* next;
	};
 
 	//each cell contains a item pointer
	item* HashTable[tableSize];

public:
	Hash(); //constructor
	int hash(string key);
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable(); //first item in the bucket
	void PrintItemsInIndex(int index);
	void FindDrink(string name); //searching for a key
	void RemoveItem(string name);
};

#endif