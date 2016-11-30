#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	std::string jon, doctor;
	cin >> jon >> doctor;
	cout << ((jon.size() >= doctor.size()) ? "go" : "no") << endl;
	return 0;
}
