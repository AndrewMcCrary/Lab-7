#pragma once
#include <random>
#include "Listy.h"
#include "MidListy.h"
#include "WackyListy.h"

void add_25(Listy<int>* L){
	for (int x = 1; x < 26; x++){
		int num = rand() % 100 + 1;
		L->addItem(num);
	}
}

void remove_20(Listy<int>* L){
	for (int x = 1; x < 21; x++){
		int index = rand() % 25;
		L->removeItem(index);
	} 
}

int main(void) {
	// rand() % 100, [0, 99]
	// rand() % 100 + 1, [1, 100]

	Listy<int> list1 = Listy<int>();
	MidListy<int> list2 = MidListy<int>();
	WackyListy<int> list3 = WackyListy<int>();
	/*
	// adds 25 random items to each list 
	add_25(&list1);
	add_25(&list2);
	//add_25(&list3);
	// may not actually remove 20 items!
	// built to return NULL and not remove an item when index  
	remove_20(&list1);
	remove_20(&list2);
	//remove_20(&list3);
	*/
	
	list3.addItem(5);
 	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	list3.addItem(4);
	
	
	
	
	
	//int addCounter = 0;
	//int removeCounter = 0;
	//for (int i = 0; i < 50; i++) {
	//	int insertval = rand() % 51
	//	int removeval = rand() % list1.size()
	//	int addorremove = rand() % 2;
	//	if (addorremove == 0 && addcounter < 25) {
	//		list1.additem(insertval);
	//		list2.additem(insertval);		
	//		list3.additem(insertval);
	//		addcounter++;
	//	}
	//	if (addorremove == 1 && removecounter < 25) {
	//		list1.removeitem(rand() % list1->size);
	//		list2.removeitem(rand() % list2->size);
	//		list3.removeitem(rand() % list3->size);
	//		removecounter++;
	//	}

	//	return 0;
}