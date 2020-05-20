#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "playlist.cpp"
using namespace std;


int main() {

    string line; 
	playlist list;

	while (getline(cin, line))
	{
		string song;
		int n;
		int pre = 0;
		int pos = line.find_first_of(" ", pre);
		string command = line.substr(pre, pos-pre);		// find the command
		pre = pos + 1;

		if (command == "i") 
		{
			song = line.substr(pre, pos-pre);
			list.insert(song);
		}
		else if (command == "p") 
		{
			string num = line.substr(pre, pos-pre);
			n = stoi(line.substr(pre, pos-pre));
			list.play(n, num);
		}
		else if (command == "e") 
		{
			string num = line.substr(pre, pos-pre);
			n = stoi(line.substr(pre, pos-pre));
			list.del(n, num);
		}
    }
    return 0;
}