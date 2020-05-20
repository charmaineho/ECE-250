#include <iostream>
#include <string>
#include <vector>

using namespace std;

class openht {

private:

    vector <int> table;
    int size;

public:

    openht();
    void open(int m);
    void insert(int k);
    void search(int k);
    void del(int k);

};