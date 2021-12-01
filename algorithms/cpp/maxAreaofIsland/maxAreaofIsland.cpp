// Source : https://leetcode.com/problems/max-area-of-island/
// Author : https://github.com/xinsheng
// Date   : 2021-12-01

/*
ou are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Idea:
the same as https://github.com/xinsheng/leetcode/blob/main/algorithms/cpp/floodFill/floodFill.cpp
 */

class Solution {
public:
    void countArea(vector<vector<int>>* image, int i, int j, int m, int n) {
        if ((*image)[i][j] == 1) {
            (*image)[i][j] = 2;//mark as readed
            count++;
            if ((i>0) && (*image)[i-1][j] == 1) countArea(image, i-1, j, m, n);
            if (((i+1)< m) && (*image)[i + 1][j] == 1) countArea(image, i + 1, j, m, n);
            if (((j+1) < n) && (*image)[i][j+1] == 1) countArea(image, i , j + 1, m, n);
            if ((j > 0) && (*image)[i][j - 1] == 1) countArea(image, i, j - 1, m, n);
        }
        else {
            return;
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxCount = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count = 0;
                    countArea(&grid, i, j, m, n);
                    maxCount = max(maxCount, count);
                }
            }
        }
        return maxCount;
    }
private:
    int count = 0;
};

/*
Solution s;
vector<vector<int>> v;
v = { {0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0} };
EXPECT_EQ(s.maxAreaOfIsland(v), 6);
v = { {0,1},{0,1} };
EXPECT_EQ(s.maxAreaOfIsland(v), 2);
v = { {1},{1} };
EXPECT_EQ(s.maxAreaOfIsland(v), 2);
v = { {0},{0} };
EXPECT_EQ(s.maxAreaOfIsland(v), 0);
v = { {0, 0, 0, 0, 0, 0, 0, 0} };
EXPECT_EQ(s.maxAreaOfIsland(v), 0);
*/
	