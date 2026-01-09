#include "HashTable_Chaining.h"
#include <iostream>
#include <string>


int HashTable_Chaining::Insert(int key, std::string data) {
	int i = key % m_size;
	int counter = 1;
	for (auto& current_pair : table[i]) {
		counter++;
		if (current_pair.first == key) {
			return -1;// Found a Duplicate
		}
	}
	real_size++;
	table[i].push_back({ key, data });
	int current_list_len = table[i].size();
	if (current_list_len > max_list_size) {
		max_list_size = current_list_len;
	}
	return counter;
}

int HashTable_Chaining::Find(int key) {
	int i = key % m_size;
	int location = 0;
	bool found = false;
	for (auto& current_pair : table[i]) {
		location++;
		if (current_pair.first == key) {
			std::cout << "(" << current_pair.first << "," << current_pair.second << ")" << std::endl;
			found = true;
			break;
		}
	}
	if (!found) {
		std::cout << "Not found" << std::endl;
	}


	return location;
}
