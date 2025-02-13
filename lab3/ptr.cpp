#include <iostream>
#include <vector>
using namespace std;

void ReLU(vector<float> &vec)
{
    for (float &x : vec)
    {
        if (x < 0)
        {
            x = 0;
        }
    }
}

int main()
{
    vector<float> vec = {0, 0.6, -2.8, -4.1};
    ReLU(vec);
    return 0;
}
