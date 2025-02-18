#include <vector>

int *toDynamicArray(std::vector<int> vect)
{
  int *arr = new int[vect.size()];

  for (int i = 0; i < vect.size(); i++)
  {
    arr[i] = vect[i];
  }
  return arr;
}
