#include <iostream>
#include <cstdint>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int main(int, char**)
{
	set<char> wovels = {'a','e','i','o','u','y'};
	while (cin.good())
	{
		std::string line;
		getline(cin, line);
		stringstream ss(line);

	  string delim = ""; 
		while (ss.good())
		{
			string word;
			ss >> word;

			if (word.length() == 0)
			{
				break;
			}

			if (word.length() == 1)
			{
				cout << delim << word << (wovels.count(word[0]) ? "yay" : "ay");
			}
			else if (wovels.count(word[0]))
			{
				cout << delim << word << "yay";
			}
			else
			{
				int i = 0;
				while (wovels.count(word[i]) == 0) {++i;}
				cout << delim << word.substr(i,string::npos) << word.substr(0, i) << "ay";
			}
			delim = " ";
		}

		cout << endl;
	}
	return 0;
}
