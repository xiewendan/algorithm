#include "stl.h"
using namespace std;

class PriorityQueue
{
private:
    unordered_map<int, unordered_map<int, int>> data;

    void erase(int nX, int nY);

public:
    void emplace(int nX, int nY, int nCost);

    bool empty();

    vector<int> top();

    void pop();
};