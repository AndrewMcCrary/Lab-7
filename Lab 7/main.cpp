#pragma once
#include <random>
#include "Listy.h"
#include "MidListy.h"
#include "WackyListy.h"
#include <iostream>

using namespace std;

int main(void) {

	for (int c = 1; c <= 10; c++) {

		Listy<int> list1 = Listy<int>();
		MidListy<int> list2 = MidListy<int>();
		WackyListy<int> list3 = WackyListy<int>();
		// rand() % 100, [0, 99]
		// rand() % 100 + 1, [1, 100]

		// adds 25 random items to each list 
		/**/
		for (int x = 1; x < 26; x++) {
			int num = rand() % 50 + 1;
			list1.addItem(num);
		}
		for (int x = 1; x < 26; x++) {
			int num = rand() % 50 + 1;
			list2.addItem(num);
		}
		for (int x = 1; x < 26; x++) {
			int num = rand() % 50 + 1;
			list3.addItem(num);
		}

		// removing 20 items from Listy
		int x = 1;
		while (x <= 20) {
			int index = rand() % list1.size();
			list1.removeItem(index);
			x++;
		}

		// removing 20 items from MidListy
		x = 1;
		while (x <= 20) {
			int index = rand() % list2.size();
			list2.removeItem(index);
			x++;
		}

		//// removing 20 items from WackyListy
		x = 1;
		while (x <= 20) {
			int index = rand() % list3.size();
			list3.removeItem(index);
			x++;
		}

		//cout << "Test " << c << ": " << endl;
		cout << "Listy comparisons/swaps      - adding: " << list1.getCA() << " / removing: " << list1.getCR() << endl;
		cout << "MidListy comparisons/swaps   - adding: " << list2.getCA() << " / removing: " << list2.getCR() << endl;
		cout << "WackyListy comparisons/swaps - adding: " << list3.getCA() << " / removing: " << list3.getCR() << endl << endl;
	}


	return 0;
}