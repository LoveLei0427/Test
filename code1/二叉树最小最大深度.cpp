//最小深度
class Solution {
public:
int run(TreeNode *root)
    {
        if(root == nullptr) return 0;
        if(root->left == nullptr) 
        {
            return run(root->right)+1;
        }
        if(root->right == nullptr)
        {
            return run(root->left)+1;
        }
        int leftDepth = run(root->left);
        int rightDepth = run(root->right);
        return (leftDepth<rightDepth)?(leftDepth+1):(rightDepth+1);
    }
};

//104、二叉树的最大深度
//方法一、层次遍历
int maxDepth(TreeNode* root)
{
    if(!root)
        return 0;
    int depth = 0;
    queue<TreeNode*>queueNode;
    queueNode.push(root);
    while(!queueNode.empty())
    {
        ++depth;
        int length = queueNode.size();
        for(int i = 0; i < length; ++i)
        {
            TreeNode *current = queueNode.front();
            queueNode.pop();
            if(current -> left) queueNode.push(current -> left);
            if(current -> right) queueNode.push(current -> right);
        }//for
    }//while
    return depth;
}
//方法二、 递归实现
return 1+max(maxDepth(root->left),maxDepth(root->right));
