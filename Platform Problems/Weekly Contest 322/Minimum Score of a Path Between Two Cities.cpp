//  Minimum Score of a Path Between Two Cities
// You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

// The score of a path between two cities is defined as the minimum distance of a road in this path.

// Return the minimum possible score of a path between cities 1 and n.

// Note:

// A path is a sequence of roads between two cities.
// It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
// The test cases are generated such that there is at least one path between 1 and n.

// Input : n = 4, roads = [ [ 1, 2, 9 ], [ 2, 3, 6 ], [ 2, 4, 5 ], [ 1, 4, 7 ] ] Output : 5 
// Explanation : The path from city 1 to 4 with the minimum score is : 1->2->4. The score of this path is min(9, 5) = 5. It can be shown that no other path has less score.

#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]][roads[i][1]] = roads[i][2];
            adj[roads[i][1]][roads[i][0]] = roads[i][2];
        }
        vector<int> visited(n + 1, 0);
        int ans = INT_MAX;
        dfs(1, n, adj, visited, ans, 0);
        return ans;
    }
    void dfs(int node, int n, vector<vector<int>> &adj, vector<int> &visited, int &ans, int score)
    {
        if (node == n)
        {
            if (score < ans)
                ans = score;
            return;
        }
        visited[node] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (adj[node][i] != 0 && visited[i] == 0)
            {
                if (adj[node][i] < score)
                    dfs(i, n, adj, visited, ans, score);
                else
                    dfs(i, n, adj, visited, ans, adj[node][i]);
            }
        }
        visited[node] = 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> roads = { {1,2,2}, {1,3,4}, {3,4,7} };
    cout << s.minScore(4, roads);    
    return 0;
}