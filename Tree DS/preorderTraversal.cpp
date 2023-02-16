// Given the root of an n - ary tree, return the preorder traversal of its nodes' values. Nary - Tree input serialization is represented in their level order traversal.Each group of children is separated by the null value(See examples)

// Input : root = [ 1, null, 3, 2, 4, null, 5, 6 ] Output : [ 1, 3, 5, 6, 2, 4 ]

class Solution{

    struct Node{
        int val;
        vector<Node*> children;
        Solution(int x) : val(x) {}
    };
    
public:
    vector<int> preorder(Node* root){
        vector<int> ans;
        if(root == NULL)
            return ans;
        // stack of Node
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty()){
            Node* curr = s.top(); // get the top element of the stack
            s.pop(); // pop the top element
            ans.push_back(curr->val); // push the value of the current node into the vector
            for(int i = curr->children.size()-1; i >= 0; i--){ // push the children of the current node into the stack
                if(curr->children[i] != NULL) // if the child is not NULL
                    s.push(curr->children[i]); // push the child into the stack
            }
        }
        return ans; // return the final answer
    }
};