#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

int main(int, char**)
{
	char board[11][11];
	memset(board, ' ', 11*11);

	std::string line;

	for (int i = 0; i < 7; ++i)
	{
		std::getline(cin, line);
		memcpy(&board[i+2][2], line.c_str(), 7);
	}

	int moves = 0;
	for (int row = 0; row < 11; ++row)
	{
		for (int col = 0; col < 11; ++col)
		{
			if (board[row][col] == '.')
			{
				moves += (board[row+1][col] == 'o' && board[row+2][col] == 'o');
				moves += (board[row-1][col] == 'o' && board[row-2][col] == 'o');
				moves += (board[row][col+1] == 'o' && board[row][col+2] == 'o');
				moves += (board[row][col-1] == 'o' && board[row][col-2] == 'o');
			}
		}
	}

	cout << moves << endl;
	return 0;
}
