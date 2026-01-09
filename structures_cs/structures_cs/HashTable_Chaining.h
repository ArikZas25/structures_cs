#pragma once
#include <list>
#include <vector>
#include <string>
class HashTable_Chaining
{

private:
	int m_size;
	int real_size;
	int max_list_size;
	std::vector<std::list<std::pair<int, std::string>>> table;//Dynamic array -> conncted lists -> data and name


public:
	void Init(int m) {
		m_size = m;
		real_size = 0;
		max_list_size = 0;
		table.resize(m_size);
	}
	int Insert(int key, std::string data);
	
	int Find(int key);
	

	int size() const {
		return real_size;
	}

	int Max_Length() {
		
		return max_list_size;
	}

	double Average_Length() {
		if (m_size == 0) return 0.0; // הגנה מפני חלוקה באפס
		double avg = real_size / double(m_size);
		return avg;
	}
};


