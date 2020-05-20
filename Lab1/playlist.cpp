#include <iostream>
#include <string>
#include <vector>
#include "playlist.h"
using namespace std;

playlist:: playlist() {
    vector<string> song;
}

void playlist:: insert(string s) {
    bool find = false;

    for(int i = 0; i < song.size(); i++) {
        if (song.at(i) == s) {
            find = true;
        }
    }
    if (find) {
        cout << "can not insert " + s << endl;
    }
    else {
        song.push_back(s);
        cout << "success" << endl;
    }
}

void playlist:: play(int n, string num) {
    if (song.size() >= n) {
        cout << "played " + num + " " + song.at(n-1) << endl;
    }
    else {
        cout << "could not play " + num << endl;
    }
}

void playlist:: del(int n, string num) {
    if (song.size() >= n) {
        cout << "success" << endl;
        song.erase(song.begin() + (n-1));
    }
    else {
        cout << "could not erase " + num << endl;
    }

}