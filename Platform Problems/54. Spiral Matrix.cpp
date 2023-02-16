// 54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// !Algorithm:
// 1. Create a vector to store the result.
// 2. Create four variables to store the boundaries of the matrix.
// 3. While the boundaries are valid, do the following:
// 4. Add the top row from left to right to the result.
// 5. Move the top boundary down.
// 6. Add the right column from top to bottom to the result.
// 7. Move the right boundary left.
// 8. If the top boundary is still valid, add the bottom row from right to left to the result.
// 9. Move the bottom boundary up.
// 10. If the left boundary is still valid, add the left column from bottom to top to the result.
// 11. Move the left boundary right.
// 12. Return the result.

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of columns
    
        int top = 0, bottom = m - 1, left = 0, right = n - 1; // boundaries

        while (top <= bottom && left <= right) // while the boundaries are valid
        {
            for (int i = left; i <= right; i++) // top row from left to right
                result.push_back(matrix[top][i]); // add to result
            top++; // move top boundary down
            for (int i = top; i <= bottom; i++) 
                result.push_back(matrix[i][right]);
            right--;
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    
    return 0;
}
