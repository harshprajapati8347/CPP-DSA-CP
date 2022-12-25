// Divide Nodes Into the Maximum Number of Groups

// You are given a positive integer n representing the number of nodes in an undirected graph.The nodes are labeled from 1 to n.

// You are also given a 2D integer array edges, where edges[i] = [ ai, bi ] indicates that there is a bidirectional edge between nodes ai and bi.Notice that the given graph may be disconnected.

// Divide the nodes of the graph into m groups(1 - indexed) such that :
// Each node in the graph belongs to exactly one group.
// For every pair of nodes in the graph that are connected by an edge[ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then | y - x | = 1. Return the maximum number of groups(i.e., maximum m) into which you can divide the nodes.Return - 1 if it is impossible to group the nodes with the given conditions.

// Input : n = 6, edges = [ [ 1, 2 ], [ 1, 4 ], [ 1, 5 ], [ 2, 6 ], [ 2, 3 ], [ 4, 6 ] ]
// Output : 4
// Explanation : As shown in the image we : -Add node 5 to the first group.- Add node 1 to the second group.- Add nodes 2 and 4 to the third group.- Add nodes 3 and 6 to the fourth group.We can see that every edge is satisfied.It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.

// Constraints :
// 1 <= n <= 500
// 1 <= edges.length <= 104
// edges[i].length == 2
// 1 <= ai, bi <= n
// ai != bi

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]][edges[i][1]] = 1;
            adj[edges[i][1]][edges[i][0]] = 1;
        }
        vector<int> visited(n + 1, 0);
        int ans = INT_MIN;
        dfs(1, n, adj, visited, ans, 0);
        return ans;
    }
    void dfs(int node, int n, vector<vector<int>> &adj, vector<int> &visited, int &ans, int score)
    {
        if (node == n)
        {
            if (score > ans)
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
    vector<vector<int>> edges = {{1, 2}, {1, 4}, {1, 5}, {2, 6}, {2, 3}, {4, 6}};
    cout << s.magnificentSets(6, edges);

    return 0;
}