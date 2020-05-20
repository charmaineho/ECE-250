#include <iostream>
#include <string>
#include <vector>

using namespace std;

class playlist {
    private:

    vector<string> song;

    public:

    playlist();
    void insert(string s);
    void play(int n, string num);
    void del(int n, string num);
};