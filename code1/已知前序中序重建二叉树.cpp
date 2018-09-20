//6����֪ǰ������������(�����ظ�����)�ؽ�������
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
    //����������Ҹ��ڵ��ֵ
    int *rootInorder = startInorder;
    while(rootInorder<endInorder&&*rootInorder!=rootValue)
    {
        rootInorder++;
    }
    int leftLength = length - startInorder;
    int *leftPreorder = startInorder + leftLength;
    //�ݹ鹹��������
    if(leftLength>0)
    {
        root->left = ConstructCore(startPreorder+1,leftPreorder,startInorder,rootInorder-1);
    }
    //�ݹ鹹��������
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