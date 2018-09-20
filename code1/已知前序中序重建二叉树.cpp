//6、已知前序中序遍历结果(不含重复数字)重建二叉树
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    TreeNode rootValue = startPreorder[0];
    BinaryTreeNode * root = new BinaryTreeNode();
    root->val = rootValue;
    root->left=root->right=NULL;
    if(startPreorder==endPreorder)
    {
        if(startInorder==endInorder && *startInorder==*endInorder)
        {
            return root;
        }
        else
            return false;
    }
    //中序遍历中找根节点的值
    int *rootInorder = startInorder;
    while(rootInorder<endInorder&&*rootInorder!=rootValue)
    {
        rootInorder++;
    }
    int leftLength = length - startInorder;
    int *leftPreorder = startInorder + leftLength;
    //递归构建左子树
    if(leftLength>0)
    {
        root->left = ConstructCore(startPreorder+1,leftPreorder,startInorder,rootInorder-1);
    }
    //递归构建右子树
    if(leftLength<endPreorder-startPreorder)
    {
        root->right = ConstructCore(leftPreorder+1,endPreorder,rootInorder+1,endInorder);
    }
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder==NULL || inorder==NULL || length <=0)
        return NULL;
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}