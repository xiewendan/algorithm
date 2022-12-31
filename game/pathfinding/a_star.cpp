
#include "a_star.h"
#include "PriorityQueue.h"

#include <iostream>
using namespace std;

static bool isToEnd(int nX, int nY, vector<int> &end);
static bool in_range(int nX, int nY, int nRow, int nCol);
static bool handle_dir(vector<vector<char>> &path, int nX, int nY, int nDirX, int nDirY, int nEndX, int nEndY, int nRow, int nCol, PriorityQueue &q, int nCost, vector<vector<int>> &costs, vector<vector<int>> &mapData);

static int manhattanDistance(int nSrcX, int nSrcY, int nDestX, int nDestY);
static int oulusDistance(int nSrcX, int nSrcY, int nDestX, int nDestY);

void a_star(vector<vector<int>> &mapData, vector<int> &start, vector<int> &end, vector<vector<char>> &path)
{
    int nRow = mapData.size();
    int nCol = mapData[0].size();

    PriorityQueue q;
    q.emplace(start[0], start[1], 0);

    path[0][0] = '<'; // 通过这个判断是否visit

    vector<vector<int>> costs(nRow, vector<int>(nCol, INT_MAX));
    costs[0][0] = 0;

    while (!q.empty())
    {
        auto data = q.top();
        q.pop();

        int nX = data[0];
        int nY = data[1];
        int nPriority = data[2];
        int nCost = costs[nX][nY];

        // 上
        if (handle_dir(path, nX, nY, -1, 0, end[0], end[1], nRow, nCol, q, nCost, costs, mapData))
        {
            break;
        }

        // 下
        if (handle_dir(path, nX, nY, +1, 0, end[0], end[1], nRow, nCol, q, nCost, costs, mapData))
        {
            break;
        }

        // 左
        if (handle_dir(path, nX, nY, 0, -1, end[0], end[1], nRow, nCol, q, nCost, costs, mapData))
        {
            break;
        }

        // 右
        if (handle_dir(path, nX, nY, 0, +1, end[0], end[1], nRow, nCol, q, nCost, costs, mapData))
        {
            break;
        }
    }
}

bool isToEnd(int nX, int nY, vector<int> &end)
{
    return nX == end[0] && nY == end[1];
}

bool in_range(int nX, int nY, int nRow, int nCol)
{
    return nX >= 0 && nX < nRow && nY >= 0 && nY < nCol;
}

bool handle_dir(vector<vector<char>> &path, int nX, int nY, int nDirX, int nDirY, int nEndX, int nEndY, int nRow, int nCol, PriorityQueue &q, int nCost, vector<vector<int>> &costs, vector<vector<int>> &mapData)
{

    int nNextX = nX + nDirX;
    int nNextY = nY + nDirY;
    if (!in_range(nNextX, nNextY, nRow, nCol))
    {
        return false;
    }

    if (mapData[nNextX][nNextY] == 1)
    {
        return false;
    }

    if (path[nNextX][nNextY] != 'o' && nCost + 1 >= costs[nNextX][nNextY])
    {
        return false;
    }

    // 入队
    int nPriority = nCost + 1 + oulusDistance(nNextX, nNextY, nEndX, nEndY);
    q.emplace(nNextX, nNextY, nPriority);
    costs[nNextX][nNextY] = nCost + 1;

    // path更新
    unordered_map<int, unordered_map<int, char>> mapDir;
    mapDir[-1] = unordered_map<int, char>();
    mapDir[-1][0] = 'v';

    mapDir[1] = unordered_map<int, char>();
    mapDir[1][0] = '^';

    mapDir[0] = unordered_map<int, char>();
    mapDir[0][-1] = '>';
    mapDir[0][1] = '<';

    path[nNextX][nNextY] = mapDir[nDirX][nDirY];

    // 检测终点
    return nNextX == nEndX && nNextY == nEndY;
}
static int manhattanDistance(int nSrcX, int nSrcY, int nDestX, int nDestY)
{
    return abs(nSrcX - nDestX) + abs(nSrcY - nDestY);
}
static int oulusDistance(int nSrcX, int nSrcY, int nDestX, int nDestY)
{
    return (nSrcX - nDestX) * (nSrcX - nDestX) + (nSrcY - nDestY) * (nSrcY - nDestY);
}