#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "openht.h"

using namespace std;

openht::openht() {

}

void openht::open(int m) {
    table.clear();
    this->size = m;

    for(int i = 0; i < m; i++) {
        table.push_back(-1);
    }
    cout << "success" << endl;
}

void openht::insert(int k) {
    bool found = false;
    bool full = true;
    int index = k % size;

    for (int i = 0; i < size; i++) {
        if (table[i] == k) {
            found = true;
        }
        if (table[i] == -1) {
            full = false;
        }
    }

    if (full || found) {
        cout << "failure" << endl;
    } 
    else {
        while (table[index] != -1) {
            index = (index + 1) % size;
        }
        table[index] = k;
        cout << "success" << endl; 
    }
}

void openht::search(int k) {
    int index = k % size;
    int count = 0;
    bool found = false;

    while (count != size) {
        if (table[index] == k) {
            stringstream ss;
            ss << "found in " << index;
            cout << ss.str() << endl; 
            found = true;
        }

        index = index + 1;
        count = count + 1;
    }

    if (!found) {
        cout << "not found" << endl;
    }
}

void openht::del(int k) {
    int index = k % size;
    int count = 0;
    bool found = false;
    int temp = 0;

    while (count != size) {
        if (table[index] == k) {
            temp = index;
            found = true;
        }

        index = (index + 1) % size;
        count = count + 1;
    }

    if(found) {
        cout << "success" << endl;
        table[temp] = -1;
    }
    if(!found) {
        cout << "failure" << endl;
    }
}