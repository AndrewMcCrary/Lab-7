#pragma once
#include <random>
#include "Listy.h"
#include "MidListy.h"
#include "WackyListy.h"

int main(void) {

	Listy<int> list1 = Listy<int>();
	MidListy<int> list2 = MidListy<int>();
	WackyListy<int> list3 = classname<int>();

	int addCounter = 0;
	int removeCounter = 0;

	for (int i = 0; i < 50; i++) {
		int insertVal = rand() % 51
		int removeVal = rand() % list
		int addOrRemove = rand() % 2;
		if (addOrRemove == 0 && addCounter < 25) {
			list1.addItem(insertVal);
			list2.addItem(insertVal);		
			list3.addItem(insertVal);
			addCounter++;
		}
		if (addOrRemove == 1 && removeCounter < 25) {
			list1.removeItem(rand() % list1->size);
			list2.removeItem(rand() % list2->size);		
			list3.removeItem(rand() % list3->size);
			removeCounter++;
		}

	}

	return 0;
}