// Algorithm: Stack
// 1. Use a stack to store the left nodes of the current node
// 2. When next() is called, pop the top node and push all the left nodes of the right child of the top node
// 3. hasNext() is called to check if the stack is empty


class BSTIterator
{
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        for (; node != NULL; myStack.push(node), node = node->left)
            ;
    }
};