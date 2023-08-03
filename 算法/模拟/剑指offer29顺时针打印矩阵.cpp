#include <vector>
class Solution {
  public:

    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;

        if (matrix.empty()) {
            return res;
        }
        if (matrix[0].empty()) {
            return res;
        }
        int xStep = 0;
        int yStep = 1;

        int xStart = -1;
        int xEnd = matrix.size();
        int yStart = -1;
        int yEnd = matrix[0].size();


        int x = 0;
        int y = 0;
        while (xStart < xEnd && yStart < yEnd && x > xStart && x < xEnd && y > yStart &&
                y < yEnd) {
            res.push_back(matrix[x][y]);
            if (x + xStep <= xStart ) {
                // 碰到上边界, 转右
                xStep = 0;
                yStep = 1;

                y = y + 1;
                yStart = yStart + 1;

            } else if (x + xStep >= xEnd) {
                // 碰到下边界, 转左
                xStep = 0;
                yStep = -1;

                y = y - 1;
                yEnd = yEnd - 1;
            } else  if (y + yStep <= yStart) {
                // 碰到左边界, 转上
                xStep = -1;
                yStep = 0;

                x = x - 1;
                xEnd = xEnd - 1;

            } else if (y + yStep >= yEnd) {
                // 碰到右侧边界, 转下
                xStep = 1;
                yStep = 0;

                x = x + 1;
                xStart = xStart + 1;
            } else {
                x = x + xStep;
                y = y + yStep;
            }
        }
        return res;
    }
};