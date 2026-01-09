#pragma once
#include <vector>
#include <string>


class HashTable_OpenAddressing {
private:
	struct cell {
		bool occupied = false;
		int key = 0;
		std::string data = "";
	};

	std::vector<cell> table;
	int m = 0;
	int currSize = 0;

	long long sumInsertAttempts = 0; // sum of attemprs for inset
	int successfulInserts = 0;
	int maxInsertAttempts = 0;

	int h(int key, int i) const; // that the function we got ((key % m) + i) % m

public:
	void Init(int m); // m is the size of the array 
	int Insert(int key, const std::string& data);
	int Find(int key) const;
	int size() const;
	int Max_Length() const;
	double  Average_Length() const;
};

