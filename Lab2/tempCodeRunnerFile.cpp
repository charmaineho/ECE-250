
		string command = line.substr(pre, pos-pre);		// find the command
		pre = pos + 1;

		if (command == "n") {
            string num = line.substr(pre, pos-pre);
            ht.open(stoi(num));
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