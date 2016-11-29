#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	int N;
	cin >> N;
	while(N--)
	{
		std::string name;
		int syear,smonth,sday;
		int byear,bmonth,bday;
		int courses;
		char slask;
		cin >> name >> syear >>slask>> smonth >>slask>> sday >> byear >>slask>> bmonth >>slask>> bday >> courses;

		cout << name << " ";
		if (syear >= 2010 || byear >= 1991)
		{
			cout << "eligible" << endl;
		}
		else if (courses > 40)
		{
			cout << "ineligible" << endl;
		}
		else
		{
			cout << "coach petitions" << endl;
		}
	}
	return 0;
}
