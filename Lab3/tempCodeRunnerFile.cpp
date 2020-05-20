			if (d == "NE")
				*direction = 0;
			if (d == "NW")
				*direction = 1;
			if (d == "SE")
				*direction = 2;
			if (d == "SW")
				*direction = 3; 
			
			start = tree.s(root, x, y);				//search to see if starting city exists
			if (start != nullptr)
			{
				max = tree.q_max(direction, attribute, start, max);
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

