class Solution {
public:
    bool ck(TreeNode* root,long mini,long maxi)
    {
        if(root==NULL)
        {
            return true;
        }
        if (root->val>mini and root->val <maxi)
        {
            return ck(root->left,mini,root->val) and ck(root->right,root->val,maxi);
        }
        return false;
    }
    
    
    bool isValidBST(TreeNode* root)
    {
        long mini=LONG_MIN;
        long maxi=LONG_MAX;
        return ck(root,mini,maxi);
    }
};
