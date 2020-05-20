#include <iostream>
#include <sstream>
#include <string>
#include "quadtree.cpp"

using namespace std;

int main() 
{
    string line; 
	quadtree tree;
	Node *root = nullptr;
	int tsize = 0;

	while (getline(cin, line)) 
	{
		int pre = 0;
		int pos = line.find_first_of(" ", pre);
		string command = line.substr(pre, pos-pre);		// find the command
		pre = pos + 1;

		if (command == "i") 
		{
			string name;
			double longitude;
			double latitude;
			int pop;
			int cost;
			int salary;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				name = line.substr(pre, pos-pre);
				pre = pos + 1;
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					longitude = stod(line.substr(pre, pos-pre));
					pre = pos + 1;
				}
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					latitude = stod(line.substr(pre, pos-pre));
					pre = pos + 1;
				}
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					pop = stoi(line.substr(pre, pos-pre));
					pre = pos + 1;
				}
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					cost = stoi(line.substr(pre, pos-pre));
					pre = pos + 1;
				}
			}
			if (pre < line.length())
			{
				salary = stoi(line.substr(pre, pos-pre));	
			}
			
			Node* n = new Node;             //new node to insert
			n->name = name;
			n->longitude = longitude;
			n->latitude = latitude;
			n->p = pop;
			n->r = cost;
			n->s = salary;
			n->NE = nullptr;
			n->NW = nullptr;
			n->SE = nullptr;
			n->SW = nullptr;

			if (!tsize) {
				root = tree.i(root, n);
				tsize++;
			}
			else {
				tree.i(root, n);
			}
		} 
		else if (command == "s") {
			double lon;
			double lat;
			Node* node = new Node;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				lon = stod(line.substr(pre, pos-pre));
				pre = pos + 1;
			}
			if (pre < line.length())
			{
				lat = stod(line.substr(pre, pos-pre));	
			}

			node = tree.s(root, lon, lat);

			if (node != nullptr) 
			{
				stringstream ss;
				ss << "found " << node->name;
				cout << ss.str() << endl;				
			}
			else
			{
				cout << "not found" << endl;
			}
		} 
		else if (command == "q_max") {
			double x, y;
			string d, attr;
			Node* start = new Node;
			int max = 0;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				x = stod(line.substr(pre, pos-pre));
				pre = pos + 1;
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					y = stod(line.substr(pre, pos-pre));
					pre = pos + 1;
				}
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					d = line.substr(pre, pos-pre);
					pre = pos + 1;
				}
			}
			if (pre < line.length())
			{
				attr = line.substr(pre, pos-pre);
			}

			start = tree.s(root, x, y);				//search to see if starting city exists
			if (d == "NE")
				start = start->NE;
			if (d == "NW")
				start = start->NW;
			if (d == "SE")
				start = start->SE;
			if (d == "SW")
				start = start->SW;
			
			if (start != nullptr)
			{
				max = tree.q_max(start, attr);
				if (max > 0)
				{
					stringstream ss;
					ss << "max " << max;
					cout << ss.str() << endl;
				}
				else
				{
					cout << "failure" << endl;
				}
			} 
			else
			{
				cout << "failure" << endl;
			}

		}
		else if (command == "q_min") {
			double x, y;
			string d, attr;
			Node* start = new Node;
			int min = 0;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				x = stod(line.substr(pre, pos-pre));
				pre = pos + 1;
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					y = stod(line.substr(pre, pos-pre));
					pre = pos + 1;
				}
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					d = line.substr(pre, pos-pre);
					pre = pos + 1;
				}
			}
			if (pre < line.length())
			{
				attr = line.substr(pre, pos-pre);
			}

			start = tree.s(root, x, y);				//search to see if starting city exists
			if (d == "NE")
				start = start->NE;
			if (d == "NW")
				start = start->NW;
			if (d == "SE")
				start = start->SE;
			if (d == "SW")
				start = start->SW;
			
			if (start != nullptr)
			{
				min = tree.q_min(start, attr);
				if (min > 0)
				{
					stringstream ss;
					ss << "min " << min;
					cout << ss.str() << endl;
				}
				else
				{
					cout << "failure" << endl;
				}
			} 
			else
			{
				cout << "failure" << endl;
			}
		}
		else if (command == "q_total") {
			double x, y;
			string d, attr;
			Node* start = new Node;
			int total = 0;

			while ((pos = line.find_first_of(" ;", pre)) != string::npos) 
			{
				x = stod(line.substr(pre, pos-pre));
				pre = pos + 1;
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					y = stod(line.substr(pre, pos-pre));
					pre = pos + 1;
				}
				if ((pos = line.find_first_of(" ;", pre)) != string::npos)
				{
					d = line.substr(pre, pos-pre);
					pre = pos + 1;
				}
			}
			if (pre < line.length())
			{
				attr = line.substr(pre, pos-pre);
			}

			start = tree.s(root, x, y);				//search to see if starting city exists
			if (d == "NE")
				start = start->NE;
			if (d == "NW")
				start = start->NW;
			if (d == "SE")
				start = start->SE;
			if (d == "SW")
				start = start->SW;
			
			if (start != nullptr)
			{
				total = tree.q_total(start, attr);
				if (total > 0)
				{
					stringstream ss;
					ss << "total " << total;
					cout << ss.str() << endl;
				}
				else
				{
					cout << "failure" << endl;
				}
			} 
			else
			{
				cout << "failure" << endl;
			}
		}
		else if (command == "print") {
			if (root == nullptr)
			{
				cout << " " << endl;
			}
			else
			{
				tree.print(root);
				cout << endl;
			}
		}
		else if (command == "clear") {
			root = tree.clear(root);
			tsize = 0;
			cout << "success" << endl;
		}
		else if (command == "size") {
			tree.size();
		}
	}
	return 0;
}