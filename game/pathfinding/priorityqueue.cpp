#include "priorityqueue.h"

void PriorityQueue::emplace(int nX, int nY, int nCost)
{
    if (data.count(nX) == 0)
    {
        data[nX] = unordered_map<int, int>();
    }

    data[nX][nY] = nCost;
}

bool PriorityQueue::empty()
{
    return data.size() == 0;
}

vector<int> PriorityQueue::top()
{
    int nMinX = 0;
    int nMinY = 0;
    int nMinCost = INT_MAX;

    for (auto it = data.begin(); it != data.end(); it++)
    {
        int nX = it->first;
        auto costs = it->second;
        for (auto itcost = costs.begin(); itcost != costs.end(); itcost++)
        {
            int nY = itcost->first;
            int nCost = itcost->second;
            if (nCost < nMinCost)
            {
                nMinX = nX;
                nMinY = nY;
                nMinCost = nCost;
            }
        }
    }

    erase(nMinX, nMinY);

    return vector<int>{nMinX, nMinY, nMinCost};
}

void PriorityQueue::erase(int nX, int nY)
{
    data[nX].erase(nY);

    if (data[nX].size() == 0)
    {
        data.erase(nX);
    }

}

void PriorityQueue::pop()
{
}