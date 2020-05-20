#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h.>
#include "polynomial.cpp"
using namespace std;

#include "Polynomial.h" // Class to represent polynomials

int main()
{
	polynomial p_1;
	polynomial p_2;
	polynomial p_add;
	polynomial p_get;
	polynomial mult;
	string line;

	while(getline(cin, line)){
		string command;
		int exp;
		double coeff;
		int pre = 0;
		int pos = line.find_first_of(" ;", pre);
		command = line.substr(pre, pos-pre);
		pre = pos + 1;

		if(command == "init") {
			init(stoi(line.substr(pre)));
		}
		else if(command == "coeff_p1") {
			p_1.del();
			while((pos = line.find_first_of(" ;", pre)) != string::npos) {
				if(pos > pre) {
					exp = stoi(line.substr(pre, pos-pre));
				}
				pre = pos + 1;
				if((pos = line.find_first_of(" ;", pre)) != string::npos){
					if(pos > pre) {
						coeff = stod(line.substr(pre, pos-pre));
						p_1.addNode(exp, coeff);
					}
					pre = pos + 1;
				}
			}
			if(pre < line.length()){
				coeff = stod(line.substr(pre, pos-pre));	
				p_1.addNode(exp, coeff);
			}
			cout << "success" << endl;
		}
		else if(command == "coeff_p2") {
			p_2.del();
			while((pos = line.find_first_of(" ;", pre)) != string::npos) {
				if(pos > pre) {
					exp = stoi(line.substr(pre, pos-pre));
				}
				pre = pos + 1;
				if((pos = line.find_first_of(" ;", pre)) != string::npos){
					if(pos > pre) {
						coeff = stod(line.substr(pre, pos-pre));
						p_2.addNode(exp, coeff);
					}
					pre = pos + 1;
				}
			}
			if(pre < line.length()){
				coeff = stod(line.substr(pre, pos-pre));	
				p_2.addNode(exp, coeff);
			}
			cout << "success" << endl;
		}
		else if(command == "add") {
			p_add.del();
			while((pos = line.find_first_of(" ;", pre)) != string::npos) {
				if(pos > pre) {
					exp = stoi(line.substr(pre, pos-pre));
				}
				pre = pos + 1;
				if((pos = line.find_first_of(" ;", pre)) != string::npos){
					if(pos > pre) {
						coeff = stod(line.substr(pre, pos-pre));
						p_add.addNode(exp, coeff);
					}
					pre = pos + 1;
				}
			}
			if(pre < line.length()){
				coeff = stod(line.substr(pre, pos-pre));	
				p_add.addNode(exp, coeff);
			}
			p_1.add(p_1, p_2, p_add);
		}
		else if(command == "get") {
			while((pos = line.find_first_of(" ;", pre)) != string::npos) {
				if(pos > pre) {
					exp = stoi(line.substr(pre, pos-pre));
				}
				pre = pos + 1;
				if((pos = line.find_first_of(" ;", pre)) != string::npos){
					if(pos > pre) {
						coeff = stod(line.substr(pre, pos-pre));
						p_get.addNode(exp, coeff);
					}
					pre = pos + 1;
				}
			}
			if(pre < line.length()){
				coeff = stod(line.substr(pre, pos-pre));	
				p_get.addNode(exp, coeff);
			}
			p_1.get(p_1, p_get);

		}
		else if(command == "eval") {
			double x;
			double val;
			while((pos = line.find_first_of(" ;", pre)) != string::npos) {
				if(pos > pre) {
					x = stod(line.substr(pre, pos-pre));
				}
				pre = pos + 1;
			}
			if(pre < line.length()){
				val = stod(line.substr(pre, pos-pre));	
			}
			p_1.eval(p_1, x, val);
		}
		else if(command == "mult") {
			// mult.del();
			// while((pos = line.find_first_of(" ;", pre)) != string::npos) {
			// 	if(pos > pre) {
			// 		exp = stoi(line.substr(pre, pos-pre));
			// 	}
			// 	pre = pos + 1;
			// 	if((pos = line.find_first_of(" ;", pre)) != string::npos){
			// 		if(pos > pre) {
			// 			coeff = stod(line.substr(pre, pos-pre));
			// 			mult.addNode(exp, coeff);
			// 		}
			// 		pre = pos + 1;
			// 	}
			// }
			// if(pre < line.length()){
			// 	coeff = stod(line.substr(pre, pos-pre));	
			// 	mult.addNode(exp, coeff);
			// }
			// p_1.mult(p_1, p_2, mult);
			cout << "success" << endl;
		}
		else {
			cerr << "Error: invalid command" << endl;
		}
	}
		return 0;
}
