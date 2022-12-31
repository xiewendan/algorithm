#include <iostream>
#include <vector>
#include <algorithm>


void build(std::vector<int> &vecData, std::vector<int> &vecTree, int nNode, int nL, int nR) {
    if (nL == nR) {
        vecTree[nNode] = vecData[nL];
        return;
    }

    int nLNode = nNode * 2 + 1;
    int nRNode = nNode * 2 + 2;
    int nM = nL + (nR - nL) / 2;

    build(vecData, vecTree, nLNode, nL, nM);
    build(vecData, vecTree, nRNode, nM + 1, nR);

    vecTree[nNode] = std::max(vecTree[nLNode], vecTree[nRNode]);
}

int query(std::vector<int> &vecTree, int nNode, int nNL, int nNR, int nL, int nR) {
    std::cout << "query:" << nNode << "," << nNL << "," << nNR << std::endl;
    if (nNR < nL) {
        return 0;
    }
    if (nNL > nR) {
        return 0;
    }
    if (nL <= nNL && nNR <= nR) {
        return vecTree[nNode];
    }

    int nLNode = nNode * 2 + 1;
    int nRNode = nNode * 2 + 2;
    int nNM = nNL + (nNR - nNL) / 2;
    int nLValue = query(vecTree, nLNode, nNL, nNM, nL, nR);
    int nRValue = query(vecTree, nRNode, nNM + 1, nNR, nL, nR);
    return std::max(nLValue, nRValue);
}

void update(std::vector<int> &vecData, std::vector<int> &vecTree, int nNode, int nL, int nR, int nIndex, int nValue) {
    if (nIndex < nL || nIndex > nR) {
        return;
    }

    if (nL == nR && nIndex == nL) {
        vecData[nIndex] = nValue;
        vecTree[nNode] = nValue;
        return;
    }

    int nLNode = nNode * 2 + 1;
    int nRNode = nNode * 2 + 2;
    int nM = nL + (nR - nL) / 2;

    update(vecData, vecTree, nLNode, nL, nM, nIndex, nValue);
    update(vecData, vecTree, nRNode, nM + 1, nR, nIndex, nValue);

    vecTree[nNode] = std::max(vecTree[nLNode], vecTree[nRNode]);
}

int main()
{
    std::vector<int> vecData(8, 0);
    vecData[0] = 1;
    vecData[1] = 4;
    vecData[2] = 3;
    vecData[3] = 5;
    vecData[4] = 7;
    vecData[5] = 6;
    vecData[6] = 8;
    vecData[7] = 10;
    std::vector<int> vecTree(4 * vecData.size(), 0);

    build(vecData, vecTree, 0, 0, vecData.size() - 1);

    for (int i = 0; i < vecTree.size(); i++) {
        std::cout << vecTree[i] << " ";
    }
    std::cout << std::endl;

    int nMax = query(vecTree, 0, 0, vecData.size()-1, 2, 5);
    std::cout << "max value:" << nMax << std::endl;

    update(vecData, vecTree, 0, 0, vecData.size() -1, 3, 11);
    for (int i = 0; i < vecTree.size(); i++) {
        std::cout << vecTree[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "hello world" << std::endl;
    return 1;
}