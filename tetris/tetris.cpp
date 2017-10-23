#include <iostream>
#include <cstdint>
#include <vector>
struct Piece
{
	// 4 of { width, with number of offsets, 0-padding}
	int config[4][5];
};

Piece blocks[] = {
	Piece(), //dummy
	Piece { // 1
		{
			{1,0,0,0,0},
			{4,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		}
	},
	Piece { // 2
		{
			{2,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		}
	},
	Piece { // 3
		{
			{3,0,0,1,0},
			{2,0,-1,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		}
	},
	Piece { // 4
		{
			{3,0,-1,-1,0},
			{2,0,1,0,0},
			{0,0,0,0,0},
			{0,0,0,0,0}
		}
	},
	Piece { // 5
		{
			{3,0,0,0,0},
			{2,0,1,0,0},
			{3,0,-1,0,0},
			{2,0,-1,0,0}
		}
	},
	Piece { // 6
		{
			{3,0,0,0,0},
			{2,0,0,0,0},
			{3,0,1,1,0},
			{2,0,-2,0,0}
		}
	},
	Piece { // 7
		{
			{3,0,0,0,0},
			{2,0,2,0,0},
			{3,0,0,-1,0},
			{2,0,0,0,0}
		}
	},
};

using namespace std;

int main(int, char**)
{
	int c, p;
	cin >> c >> p;

	vector<int> board(c);

	for (int i = 0; i < c; ++i)
	{
		cin >> board[i];
	}

	auto& block = blocks[p];

	int count = 0;

	for (int conf = 0; conf < 4 && block.config[conf][0]; ++conf)
	{
		int width = block.config[conf][0];
		for (int i = 0; i <= c-width; ++i)
		{
			int base = board[i];

			bool forbidden = false;
			for (int j = 0; j < width; ++j)
			{
				if (base != (board[i+j] - block.config[conf][j+1]))
				{
					forbidden = true;
					break;
				}
			}

			if (!forbidden)
			{
				++count;
			}
		}
	}

	cout << count << endl;

	return 0;
}
