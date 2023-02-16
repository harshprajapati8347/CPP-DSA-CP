//! 73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. Do it in-place.
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

//! Algorithm:
// 1. Check if the first row and first column has any zero element.
// 2. If yes, then set the row and column variable to true.
// 3. Iterate through the matrix and if any element is zero, then set the first element of that row and column to zero.
// 4. Iterate through the matrix again and if any element of the first row or first column is zero, then set that element to zero.
// 5. If row variable is true, then set all the elements of the first row to zero.
// 6. If column variable is true, then set all the elements of the first column to zero.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            // if the first element of row = 0 => set the column variable to zero.
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution s;
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// TC: O(m*n)
// SC: O(1)