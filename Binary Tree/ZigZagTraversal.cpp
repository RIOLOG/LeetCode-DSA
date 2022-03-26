class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>bfs;
        if (root==NULL)
        {
            return bfs;
        }
        
        int res=0;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty())
        {
            int size=q.size();
            vector<int>currlevel;
            for (int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                currlevel.push_back(curr->val);
                if (curr->left!=NULL)
                {
                    q.push(curr->left);
                }
                if (curr->right!=NULL)
                {
                    q.push(curr->right);
                }
            }
            if (res%2!=0)
            {
                reverse(currlevel.begin(),currlevel.end());
            }
            bfs.push_back(currlevel);
            res+=1;
        }
        return bfs;
    }
};
