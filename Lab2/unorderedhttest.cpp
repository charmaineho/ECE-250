#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "unorderedht.cpp"

using namespace std;

int main() {

    string line; 
	unorderedht ht;

	while (getline(cin, line)) {
		int pre = 0;
		int pos = line.find_first_of(" ", pre);
		string command = line.substr(pre, pos-pre);		// find the command
		pre = pos + 1;

		if (command == "n") {
            string num = line.substr(pre, pos-pre);
            ht.unordered(stoi(num));
		} 
		else if (command == "i") {
			string num = line.substr(pre, pos-pre);
			ht.insert(stoi(num));
		} 
		else if (command == "s") {
			string num = line.substr(pre, pos-pre);
			ht.search(stoi(num));
		}
		else if (command == "d") {
			string num = line.substr(pre, pos-pre);
			ht.del(stoi(num));
		}
	}
	return 0;
}