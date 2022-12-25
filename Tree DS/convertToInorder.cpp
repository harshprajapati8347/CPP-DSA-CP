// N - ary Tree Preorder Traversal
// Given the root of an n - ary tree, return the preorder traversal of its nodes' values.
// Example 1 :
// Input : root = [ 1, null, 3, 2, 4, null, 5, 6 ]
// Output : [ 1, 3, 5, 6, 2, 4 ]

#include <iostream>
#include <vector>
using namespace std;

class Solution
{

public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        stack<Node *> s;
        s.push(root);
        while (!s.empty())
        {
            Node *curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            for (int i = curr->children.size() - 1; i >= 0; i--)
            {
                s.push(curr->children[i]);
            }
        }
        return ans;
    }
};

