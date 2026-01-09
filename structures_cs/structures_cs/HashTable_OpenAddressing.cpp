#include "HashTable_OpenAddressing.h"

#include <iostream>
#include <stdexcept>

int HashTable_OpenAddressing::h(int key, int i) const {
	return ((key % m) + i) % m;
}

void HashTable_OpenAddressing::Init(int m) {
	if (m <= 0) {
		this->m = 0;
		table.clear();
		currSize = 0;
		sumInsertAttempts = 0;
		successfulInserts = 0;
		maxInsertAttempts = 0;
		return;
	}

	this->m = m;

	table.assign(m, cell{});
	currSize = 0;

	sumInsertAttempts = 0;
	successfulInserts = 0;
	maxInsertAttempts = 0;

}

int HashTable_OpenAddressing::Insert(int key, const std::string& data) {
	if (m <= 0) return -1;
	if (key < 0) return -1;

	for (int i = 0; i < m; i++) {
		int index = h(key, i);
		int attempts = i + 1;

		if (table[index].occupied) {
			if (table[index].key == key) {
				return -1;
			}

		}
		else {
			table[index].occupied = true;
			table[index].key = key;
			table[index].data = data;

			currSize++;

			successfulInserts++;
			sumInsertAttempts += attempts;
			if (attempts > maxInsertAttempts) {
				maxInsertAttempts = attempts;
			}
			return attempts;
		}
	}
	return -1;
}

int HashTable_OpenAddressing::Find(int key) const {
	if (m <= 0) {
		std::cout << "Not found" << std::endl;
		return 0;
	}
	if (key < 0) {
		std::cout << "Not found" << std::endl;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int index = h(key, i); //find the index 
		int attempts = i + 1; //cout the nuber of trys 

		if (!table[index].occupied) { // if curr table index is not used 
			std::cout << "Not found" << std::endl;
			return attempts;
		}
		if (table[index].key == key) {
			std::cout << "(" << table[index].key << ", " << table[index].data << ")" << std::endl;
			return attempts;
		}
	}
	std::cout << "Not found" << std::endl;
	return m;
}

int HashTable_OpenAddressing::size() const {
	return currSize;
}

int HashTable_OpenAddressing::Max_Length() const {
	return maxInsertAttempts;
}

double HashTable_OpenAddressing::Average_Length()const {
	if (successfulInserts == 0) return -1.0;
	return static_cast<double>(sumInsertAttempts) / successfulInserts;
}


