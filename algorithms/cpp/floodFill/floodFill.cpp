// Source : https://leetcode.com/problems/flood-fill/
// Author : https://github.com/xinsheng
// Date   : 2021-12-01

/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.
 */

#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Idea:
Using recursion to set newColor and around pixel if color is same as image[sr][sc]
 */

class Solution {
public:

    void fill(vector<vector<int>> * image, int sr, int sc, int newColor, int m, int n, int f) {
        if ((*image)[sr][sc] == f) {
            (*image)[sr][sc] = newColor;

            if ((sr>0) && (*image)[sr-1][sc] == f) fill(image, sr-1, sc, newColor, m, n, f);
            if (((sr+1)< m) && (*image)[sr + 1][sc] == f) fill(image, sr + 1, sc, newColor, m, n, f);
            if (((sc+1) < n) && (*image)[sr][sc+1] == f) fill(image, sr , sc + 1, newColor, m, n, f);
            if ((sc > 0) && (*image)[sr][sc - 1] == f) fill(image, sr, sc - 1, newColor, m, n, f);
        }
        else {
            return;
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        int f = image[sr][sc];
        if (f == newColor) return image;

        fill(&image, sr, sc, newColor, m, n, f);
        return image;
    }
};

/*
vector<vector<int>> v, r;
v = { {1, 1, 1},{1, 1, 0},{1, 0, 1 } };
s.floodFill(v, 1, 1, 2)

v = { {0,0,0},{0,1,1} };
s.floodFill(v, 1, 1, 1)
*/
	