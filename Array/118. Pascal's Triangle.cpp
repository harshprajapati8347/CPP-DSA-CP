//! Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
//! Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

//! Algorithm:
// 1. Create a vector of vector<int> with size numRows
// 2. For each row, resize the vector to i + 1
// 3. Set the first and last element to 1
// 4. For each element in the row, set the value to the sum of the two elements above it

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> r(numRows);
        for (int i = 0; i < numRows; i++)
        {
            // resizing vector
            r[i].resize(i + 1);
            // 1st & last = 1
            r[i][0] = r[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                // rowElement = [prevRow][prevCol] + [prevRow][NextCol]
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> result = s.generate(5);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}