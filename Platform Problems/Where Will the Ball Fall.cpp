// 1706. Where Will the Ball Fall

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        vector<int> ans;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            int j = i;
            for (int k = 0; k < m; k++)
            {
                if (grid[k][j] == 1)
                {
                    if (j + 1 < n && grid[k][j + 1] == 1)
                    {
                        j++;
                    }
                    else
                    {
                        j = -1;
                        break;
                    }
                }
                else
                {
                    if (j - 1 >= 0 && grid[k][j - 1] == -1)
                    {
                        j--;
                    }
                    else
                    {
                        j = -1;
                        break;
                    }
                }
            }
            ans.push_back(j);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}};
    Solution s;
    vector<int> ans = s.findBall(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}