#include <iostream>
#include <algorithm>
using namespace std;

int piece[5];

void show()
{
  std::string delim = "";
  for (int i = 0; i < 5; ++i)
  {
    cout << delim << piece[i];
    delim = " ";
  }

  cout << endl;
}

bool validate()
{
  for (int i = 1; i <= 5; ++i)
  {
    if (piece[i-1] != i)
    {
       return false;
    }
  }

  return true;
}

int main(int, char**)
{

  for (int i = 0; i < 5; ++i)
  {
    cin >> piece[i];
  }

   while (!validate())
   {
     for (int i = 0; i < 4; ++i)
     {
       if (piece[i] > piece[i+1])
       {
        swap(piece[i], piece[i+1]);
        show();
       }
     }
   }

  return 0;
}
