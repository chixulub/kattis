#include <iostream>
#include <cstdint>

using namespace std;

int main(int, char**)
{
	std::string cryptostr;
	cin >> cryptostr;

	const char* crypto = cryptostr.c_str();
	const char* per = "PER";
	int count = 0;
	for (int i = 0; crypto[i]; ++i)
	{
		count += (crypto[i] != per[i%3]);
	}

	cout << count << endl;

	return 0;
}
