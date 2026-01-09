#include <random>
#include <iostream>
#include <string>
#include "HashTable_Chaining.h"
#include "HashTable_OpenAddressing.h"
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::fixed;
using std::setprecision;//to set the precision of the average length output

int main()
{
    string tableType;
    int m, n, seed;
    if (!(cin >> tableType >> m >> n >> seed)) {
        return 0;
    }
    bool valid = true;
    if (!m || tableType.size() == 0) valid = false;
    if (m <= 0 || n < 0) valid = false;
    if (tableType == "OpenAddressing" && n > m) valid = false;
    if (!valid) {
        cout << "wrong input" << endl;
        return 0;
    }
    std::mt19937 rng(seed);
    if (tableType == "Chaining") {
        HashTable_Chaining table;
        table.Init(m);
        cout << "Inserts:" << endl;
        for (int i = 0; i < n; i++) {
            int num = rng() % 1000000;
            string data = "User" + to_string(num);
            int res = table.Insert(num, data);
            cout << res << endl;
        }

        cout << "Size:" << endl << table.size() << endl;
        cout << "Max length:" << endl << table.Max_Length() << endl;
        cout << "Average length:" << endl << fixed << setprecision(4) << table.Average_Length() << endl;
        cout << "Find(100):" << endl;
        int tries = table.Find(100);   // Find prints "Not found" or "(key,data)"
        cout << tries << endl;

    }
     else if (tableType == "OpenAddressing") {
        HashTable_OpenAddressing table;
        table.Init(m);
        cout << "Inserts:" << endl;
        for (int i = 0; i < n; i++) {
            int num = rng() % 1000000;
            string data = "User" + to_string(num);
            int res = table.Insert(num, data);
            cout << res << endl;
        }

        cout << "Size:" << endl << table.size() << endl;
        cout << "Max length:" << endl << table.Max_Length() << endl;
        cout << "Average length:" << endl << fixed << setprecision(4) << table.Average_Length() << endl;
        cout << "Find(100):" << endl;
        int tries = table.Find(100);   // Find prints "Not found" or "(key,data)"
        cout << tries << endl;
    }
    
    else {
        cout << "wrong input" << endl;
    }

    return 0;

}