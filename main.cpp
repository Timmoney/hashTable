/*
hash.cpp --> implementation in C++
	1. define a class object
	2. and you can use its class function
*/

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "hash.h"
using namespace std;

int main(int argc, char* argv[]){
	Hash hashy; //creating object called the constructor
	string name = "";


	hashy.AddItem("Tim1","coffee");
	hashy.AddItem("Tim2","coffee1");
	hashy.AddItem("Tim3","coffee2");
	hashy.AddItem("Jeff","coffee3");
	hashy.AddItem("Tim5","coffee4");
	hashy.AddItem("Tim6","coffee5");
	hashy.AddItem("Alex","coffee6");
	hashy.AddItem("Tim8","coffee7");
	hashy.AddItem("Tom","coffee8");
	hashy.AddItem("Tim10","coffee9");
	hashy.AddItem("Tim11","coffee10");

	hashy.PrintTable();
	//hashy.PrintItemsInIndex(0);

	hashy.PrintItemsInIndex(3);

	while(name!="exit"){
		cout << "Remove ";
		cin >> name;
		if(name!="exit"){
			hashy.RemoveItem(name);
			hashy.PrintItemsInIndex(3);
		}
	}

}