class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //Method-1 (by Dfs traversal)
        if (root==NULL)
        {
            return NULL;
        }
        
        if (root->val == p->val  or root->val == q->val)
        {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if (left!=NULL and right!=NULL)
        {
            return root;
        }
        if (left!=NULL)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
};
