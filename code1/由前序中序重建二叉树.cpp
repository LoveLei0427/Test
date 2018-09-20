//1、已知先序和中序 重建二叉树
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        
        if(pre.size() == 0)
            return NULL;
        int length = pre.size();
        int rootval = pre[0];
        vector<int> left_pre;
        vector<int> left_vin;
        vector<int> right_pre;
        vector<int> right_vin;
        TreeNode* root = new TreeNode(rootval);
        int temp;
        for(int i = 0 ;i < length; ++i){
            if(vin[i] == rootval){
                temp = i;
                break;
            }
        }//for
        for(int i = 0; i < length; ++i){
            if(i < temp){
                left_pre.push_back(pre[i + 1]);
                left_vin.push_back(vin[i]);
                
            }//if
            else if(i > temp){
                right_pre.push_back(pre[i]);
                right_vin.push_back(vin[i]);
            }//else
        }
        root -> left = reConstructBinaryTree(left_pre,left_vin);
        root -> right = reConstructBinaryTree(right_pre,right_vin);
        
        return root;
    }
};

//方法二
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




