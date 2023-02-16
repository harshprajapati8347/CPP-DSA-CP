// 74. Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Approach 1: Binary Search
// Time Complexity: O(log(m * n))
// Space Complexity: O(1)
// 1. 2D matrix can be represented as 1D array
// 2. mid/n gives row number and mid%n gives column number
// 3. if target is greater than mid then search in right half
// 4. if target is smaller than mid then search in left half

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int s = 0;
        // 2D matrix can be represented as 1D array
        int e = (m * n) - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            //! mid/n gives row number and mid%n gives column number
            if (matrix[mid / n][mid % n] == target)
            {
                return true;
            }
            else if (matrix[mid / n][mid % n] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    int target = 5;
    Solution ob;
    cout << ob.searchMatrix(matrix, target) << endl;

    return 0;
}