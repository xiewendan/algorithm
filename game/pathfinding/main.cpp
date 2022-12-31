#include "stl.h"
#include <iostream>

#include "bfs.h"
#include "djk.h"
#include "greedy.h"
#include "a_star.h"
using namespace std;

void handle_path(vector<int> &start, vector<int> &end, vector<vector<char>> &paths);

void print_path(vector<vector<char>> &paths, string szAlgorithmName);

int main()
{
    //   0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
    vector<vector<int>> mapData = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 2
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // a
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // c
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, // e
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int nRow = mapData.size();
    int nCol = mapData[0].size();

    // 起点，终点
    vector<int> start{14, 0};
    // vector<int> end{nRow - 1, nCol - 1};
    vector<int> end{10, 15};

    //========= bfs算法
    vector<vector<char>> bfs_paths(nRow, vector<char>(nCol, 'o'));
    bfs(mapData, start, end, bfs_paths);
    handle_path(start, end, bfs_paths); // 显示起点到终点的路径
    print_path(bfs_paths, "bfs");       // 打印路径

    //========= bfs算法
    vector<vector<char>> djk_paths(nRow, vector<char>(nCol, 'o'));
    djk(mapData, start, end, djk_paths);
    handle_path(start, end, djk_paths); // 显示起点到终点的路径
    print_path(djk_paths, "djk");       // 打印路径

    //========= greedy算法
    vector<vector<char>> greedy_paths(nRow, vector<char>(nCol, 'o'));
    greedy(mapData, start, end, greedy_paths);
    handle_path(start, end, greedy_paths); // 显示起点到终点的路径
    print_path(greedy_paths, "greedy");       // 打印路径

    //========= a*算法
    vector<vector<char>> a_star_paths(nRow, vector<char>(nCol, 'o'));
    a_star(mapData, start, end, a_star_paths);
    handle_path(start, end, a_star_paths); // 显示起点到终点的路径
    print_path(a_star_paths, "a_star");       // 打印路径
}

void handle_path(vector<int> &start, vector<int> &end, vector<vector<char>> &paths)
{
    int nCurX = end[0];
    int nCurY = end[1];
    unordered_map<char, pair<int, int>> mapDir;
    mapDir['v'] = make_pair(1, 0);
    mapDir['^'] = make_pair(-1, 0);
    mapDir['<'] = make_pair(0, -1);
    mapDir['>'] = make_pair(0, 1);

    while (!(nCurX == start[0] && nCurY == start[1]))
    {
        char charDir = paths[nCurX][nCurY];

        paths[nCurX][nCurY] = ' ';

        nCurX += mapDir[charDir].first;
        nCurY += mapDir[charDir].second;
    }

    paths[start[0]][start[1]] = 's';
    paths[end[0]][end[1]] = 'd';
}

void print_path(vector<vector<char>> &paths, string szAlgorithmName)
{
    int nRow = paths.size();
    int nCol = paths[0].size();
    cout << szAlgorithmName << endl;

    // 打印统计信息
    unordered_map<char, int> mapVisit;
    mapVisit['s'] = 1;
    mapVisit['<'] = 1;
    mapVisit['>'] = 1;
    mapVisit['v'] = 1;
    mapVisit['^'] = 1;
    mapVisit['d'] = 1;
    mapVisit[' '] = 1;
    mapVisit['o'] = 0;

    unordered_map<char, int> mapInPath;
    mapInPath['s'] = 1;
    mapInPath[' '] = 1;
    mapInPath['d'] = 1;
    mapInPath['<'] = 0;
    mapInPath['>'] = 0;
    mapInPath['^'] = 0;
    mapInPath['v'] = 0;
    mapInPath['o'] = 0;

    int nVisitCount = 0;
    int nInPathCount = 0;
    for (int i = 0; i < nRow; ++i)
    {
        for (int j = 0; j < nCol; ++j)
        {
            char charValue = paths[i][j];
            nVisitCount += mapVisit[charValue];
            nInPathCount += mapInPath[charValue];
        }
    }

    cout << "    visit node count:" << nVisitCount << endl;
    cout << "    path count:" << nInPathCount << endl;
    cout << endl;

    // 打印详细路径
    cout << "    0 1 2 3 4 5 6 7 8 9 a b c d e f" << endl;
    for (int i = 0; i < nRow; ++i)
    {
        cout << "    ";
        for (int j = 0; j < nCol; ++j)
        {
            cout << paths[i][j] << " ";
        }
        cout << " :" << i << endl;
    }
    cout << endl;
}