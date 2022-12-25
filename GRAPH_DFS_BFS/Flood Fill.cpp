// TODO: 733. Flood Fill

// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color.You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4 - directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4 - directionally to those pixels(also with the same color), and so on.Replace the color of all of the aforementioned pixels with color.

// TODO: Return the modified image after performing the flood fill.

// Input : image = [ [ 1, 1, 1 ], [ 1, 1, 0 ], [ 1, 0, 1 ] ], sr = 1, sc = 1, color = 2 Output : [ [ 2, 2, 2 ], [ 2, 2, 0 ], [ 2, 0, 1 ] ]
// Explanation : From the center of the image with position(sr, sc) = (1, 1)(i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel(i.e., the blue pixels) are colored with the new color.Note the bottom corner is not colored 2, because it is not 4 - directionally connected to the starting pixel.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];
        if (oldColor != color)
        {
            dfs(image, sr, sc, oldColor, color);
        }
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int oldColor, int color)
    {
        if (image[sr][sc] == oldColor)
        {
            image[sr][sc] = color;
            if (sr >= 1)
            {
                dfs(image, sr - 1, sc, oldColor, color);
            }
            if (sc >= 1)
            {
                dfs(image, sr, sc - 1, oldColor, color);
            }
            if (sr + 1 < image.size())
            {
                dfs(image, sr + 1, sc, oldColor, color);
            }
            if (sc + 1 < image[0].size())
            {
                dfs(image, sr, sc + 1, oldColor, color);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = s.floodFill(image, sr, sc, color);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}