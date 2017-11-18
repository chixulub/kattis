
#include <iostream>

const int WIDTH = 30;
const int HEIGHT =  30;

static unsigned int mem[15][WIDTH*HEIGHT];

inline int cellIndexOf(int x, int y)
{
  x += WIDTH/2;
  y += HEIGHT/2;
  return (WIDTH * y) + x;
}

inline int neighbourIndexOf(int iCell, int iNeighbour)
{
  static const int offset[6] = {
      -WIDTH,
      -1,
      WIDTH - 1,
      WIDTH,
      1,
      1 - WIDTH
  };

  return iCell + offset[iNeighbour];
}

void initMem()
{
  for (int i = 0; i < WIDTH*HEIGHT; ++i)
  {
    mem[0][i] = 0;
  }

  mem[0][cellIndexOf(0,0)] = 1;

  for (int n = 1; n < 15; ++n)
  {
    for (int i = 0; i < WIDTH*HEIGHT; ++i)
    {
      mem[n][i] = -1;
    }
  }
}

unsigned int count(int iCell, int numSteps)
{
  unsigned int& cache = mem[numSteps][iCell];

  if (cache == -1)
  {
    unsigned int sum = 0;

    for (int i = 0; i < 6; ++i)
    {
      sum += count(neighbourIndexOf(iCell, i), numSteps-1);
    }

    cache = sum;
  }
  
  return cache;

}

int main(int, char**)
{
  initMem();

  int origin = cellIndexOf(0,0);
  int N;
  std::cin >> N;
  while (N--)
  {
    int n;
    std::cin >> n;
    std::cout << count(origin, n) << std::endl;
  }


  return 0;
}
