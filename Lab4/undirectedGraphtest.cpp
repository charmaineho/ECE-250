#include <iostream>
#include <sstream>
#include <string>
#include "undirectedGraph.cpp"

using namespace std;

int main() 
{
    string line; 
    Graph graph;

    while (getline(cin, line)) {
        int pre = 0;
        int pos = line.find_first_of(" ", pre);
        string command = line.substr(pre, pos-pre);		// find the command
        pre = pos + 1;

        if (command == "i") {
        	string name = line.substr(pre, pos-pre);
        	graph.insert(name);
        } 
        else if (command == "setd") {
            double d;
			string name1, name2;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				name1 = line.substr(pre, pos-pre);
				pre = pos + 1;
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					name2 = line.substr(pre, pos-pre);
					pre = pos + 1;
				}
			}
			if (pre < line.length())
			{
				d = stod(line.substr(pre, pos-pre));
			}

            graph.setd(name1, name2, d);
        }
        else if (command == "s") {
        	string name = line.substr(pre, pos-pre);
        	Node* found = graph.search(name);

            if(found)
            {
                cout << "found " + name << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
        }
        else if (command == "degree") {
        	string name = line.substr(pre, pos-pre);
        	graph.degree(name);
        }
        else if (command == "graph_nodes") {
            graph.graph_nodes();
        }
        else if (command == "graph_edges") {
            graph.graph_edges();
        }
        else if (command == "d") {
            string name1;
			string name2;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				name1 = line.substr(pre, pos-pre);
				pre = pos + 1;
			}
			if (pre < line.length())
			{
				name2 = line.substr(pre, pos-pre);	
			}
            graph.distance(name1, name2);

        }
        else if (command == "shortest_d") {
            string name1;
			string name2;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				name1 = line.substr(pre, pos-pre);
				pre = pos + 1;
			}
			if (pre < line.length())
			{
				name2 = line.substr(pre, pos-pre);	
			}
            graph.short_d(name1, name2);
        }
        else if (command == "print_path") {
            string name1;
			string name2;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				name1 = line.substr(pre, pos-pre);
				pre = pos + 1;
			}
			if (pre < line.length())
			{
				name2 = line.substr(pre, pos-pre);	
			}
            graph.print_path(name1, name2);
        }
		else if (command == "clear") {
            graph.clear();
			cout << "success" << endl;
        }

    }
    return 0;
}
