#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "unorderedht.h"

using namespace std;

Node::Node(int val, int k) {
    key = k;
    value = val;
    next = nullptr;
}

unorderedht::unorderedht() {

}

void unorderedht::unordered(int size) {
    delete [] table;
    this->size = size;
    table = new Node*[size];

    for (int i = 0; i < size; i++) {
        table[i] = nullptr;
    }

    cout << "success" << endl;
}

void unorderedht::insert(int k) {
    int index = k % size;
    Node *check = table[index];
    Node *cur = table[index];
    bool copy = false;

    while (check != nullptr) {
        if (check->key == k) {
            copy = true;
        }
        check = check->next;
    }

    if (!copy) {
        if (cur != nullptr) {
            while(cur->next != nullptr) {
                cur = cur->next;
                index++;
            }
            cur->next = new Node(index, k);
            cout << "success" << endl;
        } else {
            table[index] = new Node(index, k);
            cout << "success" << endl;
        }
    }
    if (copy) {
        cout << "failure" << endl;
    }
}

void unorderedht::search(int k) {
    int index = k % size;
    bool found = false;
    Node *cur = table[index];

    while (cur != nullptr) {
        if (cur->key == k) {
            found = true;
        }
        cur = cur->next;
    }

    if(found) {
        stringstream ss;
        ss << "found in " << index;
        cout << ss.str() << endl;
    } else {
        cout << "not found" << endl;
    }
}

void unorderedht::del(int k) {
    int index = k % size;
    bool found = false;
    Node *cur = table[index];
    Node * pre = nullptr;

    if(table[index] != nullptr) {
        if(table[index]->key == k) {
            pre = table[index];
            table[index] = table[index]->next;
            delete pre;
            found = true;
            cout << "success" << endl;
        }
    }
    while (cur != nullptr && (!found)) {
        if (cur->key == k) {
            found = true;
            pre->next = cur->next;
            delete cur;
            cout << "success" << endl;
        }
        pre = cur;
        cur = cur->next;
    }

    if(!found) {
        cout << "failure" << endl;
    }
}
