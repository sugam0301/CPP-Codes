void f(TreeNode *root)
    {
        if(!root)
            return;
        std::swap(root->left, root->right);
        f(root->left);
        f(root->right);
    }
    
TreeNode* invertTree(TreeNode* root) 
{
    if (!root)
        return root;
    f(root);
    return root;    
}
