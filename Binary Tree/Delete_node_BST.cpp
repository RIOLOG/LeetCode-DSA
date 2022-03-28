class Solution {
public:
    int findmax(TreeNode* root)
    {
        if (root==NULL)
        {
            return NULL;
        }
        if (root->right!=NULL)
        {
            return findmax(root->right);
        }
        else
        {
            return root->val;
        }
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root==NULL)
        {
            return NULL;
        }
        if (root->val>key)
        {
            root->left = deleteNode(root->left,key);
        }
        else if (root->val < key)
        {
            root->right =deleteNode(root->right,key);
        }
        else
        {
            if (root->right !=NULL and root->left !=NULL)
            {
                int left_max=findmax(root->left);
                root->val=left_max;
                root->left=deleteNode(root->left,left_max);
            }
            else if (root->left==NULL)
            {
                return root->right;
            }
            else if (root->right==NULL)
            {
                return root->left;
            }
            else
            {
                return NULL;
            }
        }
        return root;
    }
};
