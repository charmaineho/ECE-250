#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {

public:

    int key;
    int value;
    Node *next;
    Node (int val, int k);

};

class unorderedht {

private:
    int size;

public: 
    
    Node **table;
    unorderedht();
    void unordered(int size);
    void insert(int k);
    void search(int k);
    void del(int k);

};