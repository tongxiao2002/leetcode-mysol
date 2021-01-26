/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int **NumofPaths;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        NumofPaths = new int *[m];
        for (int i = 0; i < m; i++)
        {
            NumofPaths[i] = new int [n];
            for (int j = 0; j < n; j++)
            {
                NumofPaths[i][j] = 0;
            }
        }
        NumofPaths[m - 1][n - 1] = 1;
        int Path_Num = CountPaths(obstacleGrid, 0, 0, m, n);
        for (int i = 0; i < m; i++)
        {
            delete [] NumofPaths[i];
        }
        delete [] NumofPaths;
        return Path_Num;
    }
    int CountPaths(vector<vector<int>> &obstacleGrid, int x, int y, int m, int n)
    {
        if (x >= m || y >= n || obstacleGrid[x][y] == 1)
        {
            return 0;
        }
        if (NumofPaths[x][y] != 0)
        {
            return NumofPaths[x][y];
        }
        NumofPaths[x][y] = CountPaths(obstacleGrid, x + 1, y, m, n) + CountPaths(obstacleGrid, x, y + 1, m, n);
        return NumofPaths[x][y];
    }
};
// @lc code=end

