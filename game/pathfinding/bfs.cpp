#include "bfs.h"

static bool in_range(int nX, int nY, int nRow, int nCol);
static bool handle_dir(vector<vector<char>> &path, int nX, int nY, int nDirX, int nDirY, int nEndX, int nEndY, int nRow, int nCol, queue<pair<int, int>> &q, vector<vector<int>> &mapData);

void bfs(vector<vector<int>> &mapData, vector<int> &start, vector<int> &end, vector<vector<char>> &path)
{
    int nRow = mapData.size();
    int nCol = mapData[0].size();

    queue<pair<int, int>> q;
    q.emplace(start[0], start[1]);
    path[0][0] = '<';

    while (!q.empty())
    {
        auto curPos = q.front();
        q.pop();

        int nX = curPos.first;
        int nY = curPos.second;

        // 上
        if (handle_dir(path, nX, nY, -1, 0, end[0], end[1], nRow, nCol, q, mapData))
        {
            break;
        }

        // 下
        if (handle_dir(path, nX, nY, +1, 0, end[0], end[1], nRow, nCol, q, mapData))
        {
            break;
        }

        // 左
        if (handle_dir(path, nX, nY, 0, -1, end[0], end[1], nRow, nCol, q, mapData))
        {
            break;
        }

        // 右
        if (handle_dir(path, nX, nY, 0, +1, end[0], end[1], nRow, nCol, q, mapData))
        {
            break;
        }
    }
}

bool in_range(int nX, int nY, int nRow, int nCol)
{
    return nX >= 0 && nX < nRow && nY >= 0 && nY < nCol;
}

bool handle_dir(vector<vector<char>> &path, int nX, int nY, int nDirX, int nDirY, int nEndX, int nEndY, int nRow, int nCol, queue<pair<int, int>> &q, vector<vector<int>> &mapData)
{
    int nNextX = nX + nDirX;
    int nNextY = nY + nDirY;
    if (!in_range(nNextX, nNextY, nRow, nCol))
    {
        return false;
    }

    if(mapData[nNextX][nNextY] == 1){
        return false;
    }

    if (path[nNextX][nNextY] != 'o')
    {
        return false;
    }

    // 入队
    q.emplace(nNextX, nNextY);

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
