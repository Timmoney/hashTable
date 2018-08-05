/*
hash.cpp --> implementation in C++
implementation from header file
	1. need to specific the class name 
	   Hash::hash(string key) --> using Hash class's hash function
	2. you DO NOT NEED ; at the end of implementation
*/

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "hash.h"
using namespace std;

//constructor, when you creating an object, you create this
Hash::Hash(){
	//run thru the table, and initialize the item 
	for(int i=0; i<tableSize; i++){
		//creating item object sett all to default
		HashTable[i] = new item; 
		HashTable[i] -> name = "empty";
		HashTable[i] -> drink = "empty";
		HashTable[i] -> next = NULL;
	}	
}

//information transformation, at each char integer value and module it
int Hash::hash(string key){
	int hash = 0;
	int index;

	//you can treat string as an char* as in C
	for(int i=0; i<key.length(); i++){
		hash = (hash + (int)key[i])*17; //you can modify here to change 
	}

	index = hash % tableSize;
	return index;
}

void Hash::AddItem(string name, string drink){
	//transforming the name into 0-9 index according to it's string
	int index = hash(name);
	//if the initial bucket does not have item, creating one
	if(HashTable[index]->name == "empty"){
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	//else pointer to the end of the list and add it there.
	else{
		item* ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		while(ptr->next!=NULL)
			ptr = ptr->next;

		ptr->next = n;
	}
}

//print how many items in the bucket
int Hash::NumberOfItemsInIndex(int index){
	int count = 0;

	if(HashTable[index]->name == "empty"){
		return count;
	}
	else{
		count++;
		item* ptr = HashTable[index];
		while(ptr->next!=NULL){
			count++;
			ptr = ptr->next;
		}
		return count;
	}
}

//print the whole table
void Hash::PrintTable(){
	int number;
	for(int i=0; i<tableSize; i++){
		number = NumberOfItemsInIndex(i);
		cout << "----------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "----------------\n";  
	}
}

//print the items in the bucket
void Hash::PrintItemsInIndex(int index){
	item* ptr = HashTable[index];

	if(ptr->name == "empty"){
		cout << "index = " << index << " is empty" << endl;
	}
	else{
		cout << "index = " << index << "  contains the following item\n";
		while(ptr!=NULL){
			cout << "-------------\n";
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "-------------\n";

			ptr = ptr->next;
		}
	}
}

void Hash::FindDrink(string name){
	int index = hash(name);
	bool foundName = false;
	string drink;

	item* ptr = HashTable[index];
	while(ptr!=NULL){
		if(ptr->name == name){
			foundName = true;
			drink = ptr->drink;
		}
		ptr = ptr->next;
	}
	if(foundName == true){
			cout << "favorite drink = "<< drink << endl;
	}
	else{
		cout << name << " was not found in the Hash Table\n";
	}
}

void Hash::RemoveItem(string name){
	int index = hash(name);

	item* delPtr;
	item* p1;
	item* p2;

	//case 0 - the bucket is empty
	if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty"){
		cout << name << " was not found in the hash table\n";
	}
	//case 1 - only one item in the bucket
	else if(HashTable[index]->name == name && HashTable[index]->next == NULL){
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
	}
	//case 2 - matching in the first item in the bucket, but there are more
	else if(HashTable[index]->name == name){
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;

		cout << name << " was removed from the Hash Table\n"; 
	}
	//case 3 - bucket contains items but the forst one is not matching
	else{
		p1 = HashTable[index]->next;
		p2 = HashTable[index];

		while(p1!=NULL && p1->name!=name){
			p2 = p1;
			p1 = p1 -> next;
		}
		//case 3.1 - no match
		if(p1 == NULL){
			cout << name << " was not found in the hash table\n";		
		}
		//case 3.2 - find
		else{
			delPtr = p1;
			p1 = p1->next;
			p2->next = p1;

			delete delPtr;
			cout << name << " was removed from the Hash Table\n";
		}
	}


}














